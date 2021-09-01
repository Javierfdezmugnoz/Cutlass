/***************************************************************************************************
 * Copyright (c) 2017-2021, NVIDIA CORPORATION.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of
 *       conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name of the NVIDIA CORPORATION nor the names of its contributors may be used
 *       to endorse or promote products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TOR (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **************************************************************************************************/

/*
  This example demonstrates how to call a CUTLASS GEMM kernel and provides a naive reference
  matrix multiply kernel to verify its correctness.

  The CUTLASS Gemm template is instantiated in the function CutlassSgemmNN. This is kernel computes
  the general matrix product (GEMM) using single-precision floating-point arithmetic and assumes
  all matrices have column-major layout.

  The threadblock tile size is chosen as 128x128x8 which offers good performance for large matrices.
  See the CUTLASS Parallel for All blog post for more exposition on the tunable parameters available
  in CUTLASS.

  https://devblogs.nvidia.com/cutlass-linear-algebra-cuda/

  Aside from defining and launching the SGEMM kernel, this example does not use any other components
  or utilities within CUTLASS. Such utilities are demonstrated elsewhere in other examples and are
  prevalent in the CUTLASS unit tests.

  This example has delibrately been kept similar to the basic_gemm example from cutass-1.3 to 
  highlight the minimum amount of differences needed to transition to cutlass-2.0.

  Cutlass-1.3 sgemm: https://github.com/NVIDIA/cutlass/blob/master/examples/00_basic_gemm/basic_gemm.cu
*/

// Standard Library includes
#include <iostream>
#include <sstream>
#include <vector>
// Helper methods to check for errors
#include "helper.h"



#define PUT_IN_REGISTER								 /* dummy definition  for Windows 32 */

typedef float    float32_t;
typedef union ui64_to_ui32 {
	uint64_t ui64;
	uint32_t ui32[2];
} ui64_to_ui32_t;

typedef float    float32_t;
typedef double   float64_t;
typedef void     void_t;

static void_t matrix2rand(float32_t * paf32_matrix, uint32_t ui32_max_rows, uint32_t ui32_max_columns)
{
	uint32_t ui32_idx;

	for (ui32_idx = 0u; ui32_idx < (ui32_max_rows * ui32_max_columns); ui32_idx++)
	{
		*paf32_matrix++ = (float32_t)rand();
	}
}

//
// CUTLASS includes needed for single-precision GEMM kernel
//

// Defines cutlass::gemm::device::Gemm, the generic Gemm computation template class.
#include "cutlass/gemm/device/gemm.h"

// Include Smmm.h (MMM employed in the previous paper)
//#include "cutlass/sequential_MMM/Smmm.h"

  // Definition of an struct to store th values of the Execution Signatures
  struct ESs{
    uint32_t A;
    uint32_t B;
    uint32_t C;
  };

 ESs smm_xor_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha,  float32_t*  paf32_ma,  float32_t*  paf32_mb, float32_t *paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

	/* XOR checksum */
  struct ESs ES;
  ES.A = 0u;
  ES.B = 0u;
  ES.C = 0u;


	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			ES.A ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* XOR checksum */
				ES.B ^= (uint32_t) *((uint32_t*)&f32_b);
        //printf("Value[%u]=%u\n",ui32_idx_b,(uint32_t) *((uint32_t*)&f32_b));
				ES.C ^= (uint32_t) *((uint32_t*)&f32_c);
			}
      //printf("%u\n",ES.B);
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	//ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;
	return ES;
}


/*==============================================================================================================
**									Name: smm_ones_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with One's checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_xor	Return the Execution signature of the MMM
==============================================================================================================*/
ESs smm_ones_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha,  float32_t*  paf32_ma,  float32_t*  paf32_mb, float32_t*  paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;


	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];
      Ones_Checksum_a.ui32[1] = 0;

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n;
				ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
				/* One's complement checksum */
				Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&f32_b);
				Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
				Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

				Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&f32_c);
				Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
				Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];

        Ones_Checksum_b.ui32[1] = 0;
        Ones_Checksum_c.ui32[1] = 0;
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
  /*
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64);
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	Ones_Checksum.ui64 += Ones_Checksum_c.ui64;
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
  */
   struct ESs ES;
  ES.A = Ones_Checksum_a.ui32[0];
  ES.B = Ones_Checksum_b.ui32[0];
  ES.C = Ones_Checksum_c.ui32[0];

	return ES;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
//
// This function defines a CUTLASS GEMM kernel instantiation, constructs its parameters object,
// and launches it on the CUDA device.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

/// Define a CUTLASS GEMM template and launch a GEMM kernel.
cudaError_t CutlassSgemmNN(
  int M,
  int N,
  int K,
  float alpha,
  float const *A,
  int lda,
  float const *B,
  int ldb,
  float beta,
  float *C,
  int ldc,
  uint32_t *d_ES_a,
  uint32_t *d_ES_b,
  uint32_t *d_ES_c) {

  // Define type definition for single-precision CUTLASS GEMM with column-major
  // input matrices and 128x128x8 threadblock tile size (chosen by default).
  //
  // To keep the interface manageable, several helpers are defined for plausible compositions
  // including the following example for single-precision GEMM. Typical values are used as
  // default template arguments. See `cutlass/gemm/device/default_gemm_configuration.h` for more details.
  //
  // To view the full gemm device API interface, see `cutlass/gemm/device/gemm.h`

  using ColumnMajor = cutlass::layout::ColumnMajor;

  using CutlassGemm = cutlass::gemm::device::Gemm<float,        // Data-type of A matrix
                                                  ColumnMajor,  // Layout of A matrix
                                                  float,        // Data-type of B matrix
                                                  ColumnMajor,  // Layout of B matrix
                                                  float,        // Data-type of C matrix
                                                  ColumnMajor>; // Layout of C matrix

  // Define a CUTLASS GEMM type
  CutlassGemm gemm_operator;

  //printf("\n Direction of h_ES_0: %p and value: %f \n", (void *) h_ES_0, h_ES_0[4]);

  // Construct the CUTLASS GEMM arguments object.
  //
  // One of CUTLASS's design patterns is to define gemm argument objects that are constructible
  // in host code and passed to kernels by value. These may include pointers, strides, scalars,
  // and other arguments needed by Gemm and its components.
  //
  // The benefits of this pattern are (1.) a structured, composable strategy for passing host-constructible
  // arguments to kernels and (2.) minimized initialization overhead on kernel entry.
  //
  CutlassGemm::Arguments args({M , N, K},  // Gemm Problem dimensions
                              {A, lda},    // Tensor-ref for source matrix A
                              {B, ldb},    // Tensor-ref for source matrix B
                              {C, ldc},    // Tensor-ref for source matrix C
                              {C, ldc},    // Tensor-ref for destination matrix D (may be different memory than source C matrix)
                              {alpha, beta},// Scalars used in the Epilogue
                              d_ES_a,   // Pointer to d_ES_a
                              d_ES_b,   // Pointer to d_ES_b
                              d_ES_c);  // Pointer to d_ES_c

  // Code included by JFdez: I have to include in args variable this: d_ES_0 and d_ES_1

  //
  // Launch the CUTLASS GEMM kernel.
  //
  
  cutlass::Status status = gemm_operator(args);

  //
  // Return a cudaError_t if the CUTLASS GEMM operator returned an error code.
  //

  if (status != cutlass::Status::kSuccess) {
    return cudaErrorUnknown;
  }

  // Return success, if no errors were encountered.
  return cudaSuccess;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// The source code after this point in the file is generic CUDA using the CUDA Runtime API
// and simple CUDA kernels to initialize matrices and compute the general matrix product.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

/// Kernel to initialize a matrix with small integers.
__global__ void InitializeMatrix_kernel(
  float *matrix,
  int rows,
  int columns,
  int seed = 0) {

  int i = threadIdx.x + blockIdx.x * blockDim.x;
  int j = threadIdx.y + blockIdx.y * blockDim.y;

  if (i < rows && j < columns) {
    int offset = i + j * rows;

    // Generate arbitrary elements.
    int const k = 16807;
    int const m = 16;
    float value = float(((offset + seed) * k % m) - m / 2);
    /*if(((offset+1)%columns)==0){
      printf("\n");
    }
    printf("Matrix[%d]=%f \t",offset,value);
    */
    matrix[offset] = value;
  }
}

/// Simple function to initialize a matrix to arbitrary small integers.
cudaError_t InitializeMatrix(float *matrix, int rows, int columns, int seed = 0) {

  dim3 block(16, 16);
  dim3 grid(
    (rows + block.x - 1) / block.x,
    (columns + block.y - 1) / block.y
  );

  InitializeMatrix_kernel<<< grid, block >>>(matrix, rows, columns, seed);

  return cudaGetLastError();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// Allocates device memory for a matrix then fills with arbitrary small integers.
cudaError_t AllocateMatrix(float **matrix, int rows, int columns, int seed = 0) {
  cudaError_t result;

  size_t sizeof_matrix = sizeof(float) * rows * columns;

  // Allocate device memory.
  result = cudaMalloc(reinterpret_cast<void **>(matrix), sizeof_matrix);

  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate matrix: "
      << cudaGetErrorString(result) << std::endl;
    return result;
  }

  // Clear the allocation.
  result = cudaMemset(*matrix, 0, sizeof_matrix);

  if (result != cudaSuccess) {
    std::cerr << "Failed to clear matrix device memory: "
      << cudaGetErrorString(result) << std::endl;
    return result;
  }

  // Initialize matrix elements to arbitrary small integers.
  // cHANGED BY Jfdez
  result = InitializeMatrix(*matrix, rows, columns, seed);

  if (result != cudaSuccess) {
    std::cerr << "Failed to initialize matrix: "
      << cudaGetErrorString(result) << std::endl;
    return result;
  }

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// Naive reference GEMM computation.
__global__ void ReferenceGemm_kernel(
  int M,
  int N,
  int K,
  float alpha,
  float const *A,
  int lda,
  float const *B,
  int ldb,
  float beta,
  float *C,
  int ldc) {

  int i = threadIdx.x + blockIdx.x * blockDim.x;
  int j = threadIdx.y + blockIdx.y * blockDim.y;

  if (i < M && j < N) {
    float accumulator = 0;

    for (int k = 0; k < K; ++k) {
      accumulator += A[i + k * lda] * B[k + j * ldb];
    }

    C[i + j * ldc] = alpha * accumulator + beta * C[i + j * ldc];
  }
}

/// Reference GEMM computation.
cudaError_t ReferenceGemm(
  int M,
  int N,
  int K,
  float alpha,
  float const *A,
  int lda,
  float const *B,
  int ldb,
  float beta,
  float *C,
  int ldc) {

  dim3 block(16, 16);
  dim3 grid(
    (M + block.x - 1) / block.x,
    (N + block.y - 1) / block.y
  );

  ReferenceGemm_kernel<<< grid, block >>>(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

  return cudaGetLastError();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// Allocate several matrices in GPU device memory and call a single-precision
/// CUTLASS GEMM kernel.
cudaError_t TestCutlassGemm(int M, int N, int K, float alpha, float beta) {
  cudaError_t result;

  //
  // Define several matrices to be used as operands to GEMM kernels.
  //

  // Compute leading dimensions for each matrix.
  int lda = M;
  int ldb = K;
  int ldc = M;

  // Compute size in bytes of the C matrix.
  size_t sizeof_C = sizeof(float) * ldc * N;

  // Define pointers to matrices in GPU device memory.
  float *A;
  float *B;
  float *C_cutlass;
  float *C_reference;

  // =============================================================
  // Author:  Javier Fdez
  // Date:    2021/08/17
  // Summary: In the following chunk of code are initialized in 
  //          CPU and GPU the variables ES_0 and ES_1 in which are 
  //          stored the Execution Signatures (1 per thread*SMP)
  // =============================================================

  // Definition of an struct with the values of the ES:
  struct ESs h_ES;
  struct ESs d_ES;

  // Define the number of elements of the ES 
  uint32_t nElem_ES = 256;
  size_t nBytes_ES = nElem_ES * sizeof(uint32_t);

  // Define pointers to ES_a, ES_b and ES_c in CPU (host)
  uint32_t *h_ES_a;
  uint32_t *h_ES_b;
  uint32_t *h_ES_c;

  // Allocate ES_0 y ES_1 in CPU 
  h_ES_a = (uint32_t *) malloc(nBytes_ES);
  h_ES_b = (uint32_t *) malloc(nBytes_ES);
  h_ES_c = (uint32_t *) malloc(nBytes_ES);

  // Initialice to 0 all values of ES_a, ES_b and ES_c
  memset(h_ES_a,0,nBytes_ES);
  memset(h_ES_b,0,nBytes_ES);
  memset(h_ES_c,0,nBytes_ES);

/*
h_ES_0[1] = 1;
h_ES_0[2] = 2;


for(int i=0;i<nElem_ES;i++){
  printf("ES[%i] = %u \n",i,h_ES_a[i]);
}
*/


  // Define pointers to ES_a, ES_b and ES_c in GPU (device)
  uint32_t *d_ES_a;
  uint32_t *d_ES_b;
  uint32_t *d_ES_c;

  // Allocate ES_0 y ES_1 in GPU
  cudaMalloc((uint32_t **) &d_ES_a, nBytes_ES);
  cudaMalloc((uint32_t **) &d_ES_b, nBytes_ES);
  cudaMalloc((uint32_t **) &d_ES_c, nBytes_ES);

  // Transfer data from host to device (first time it has no sense, it could
  // be directly initilized in GPU, but it will not be always initially zero)
  cudaMemcpy(d_ES_a, h_ES_a, nBytes_ES, cudaMemcpyHostToDevice);
  cudaMemcpy(d_ES_b, h_ES_b, nBytes_ES, cudaMemcpyHostToDevice);
  cudaMemcpy(d_ES_c, h_ES_c, nBytes_ES, cudaMemcpyHostToDevice);

  /* ==============================================================================
  Brief: Initialization of A, B, C_reference and C_cutlass. 
  Hypothesis: the values of A and B follow a pattern in the initialization if it 
  is done in with the GPU. This sequential implementation aid to avoid this.
  ==============================================================================*/
  uint32_t nBytes_a = M * K * sizeof(float);
  uint32_t nBytes_b = K * N * sizeof(float);
  uint32_t nBytes_c = M * N * sizeof(float);

  // Define pointers to h_a, h_b and h_c in CPU (host)
  float *h_a;
  float *h_b;
  float *h_c;

  // Allocate h_a, h_b and h_c in CPU 
  h_a     = (float *) malloc(nBytes_a);
  h_b     = (float *) malloc(nBytes_b);
  h_c     = (float *) malloc(nBytes_c);

  // Allocate memory on GPU
  result =  cudaMalloc(&A, nBytes_a);
  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate A: "
      << cudaGetErrorString(result) << std::endl;}

  result =  cudaMalloc(&B, nBytes_b);
  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate B: "
      << cudaGetErrorString(result) << std::endl;}

  result =  cudaMalloc(&C_cutlass, nBytes_c);
  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate C_cutlass: "
      << cudaGetErrorString(result) << std::endl;}

  result =  cudaMalloc(&C_reference, nBytes_c);
  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate C_reference: "
      << cudaGetErrorString(result) << std::endl;}
  

  // Initialice to 0 all values of h_c and h_c_reference
  memset(h_c,0,nBytes_c);
  
  // Initialization of the values of h_a and h_b
  matrix2rand(h_a,M,K);
  matrix2rand(h_b,K,N);

  // Copy the values initialized and stored in host to the device (h_a -> A, h_b -> B ...)
  result = cudaMemcpy (A,h_a,nBytes_a,cudaMemcpyHostToDevice);
 if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_a matrix to A: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  result = cudaMemcpy (B,h_b,nBytes_b,cudaMemcpyHostToDevice);
 if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_b matrix to B: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  result = cudaMemcpy (C_reference,h_c,nBytes_c,cudaMemcpyHostToDevice);
 if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_c matrix to C_reference: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  result = cudaMemcpy (C_cutlass,h_c,nBytes_c,cudaMemcpyHostToDevice);

  if (result != cudaSuccess) {
    std::cerr << "Failed to copy C_cutlass matrix to C_reference: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }




/*
  //
  // Allocate matrices in GPU device memory with arbitrary seeds.
  //

  //printf("Matrix A:\n");
  result = AllocateMatrix(&A, M, K, 0);

  if (result !=  cudaSuccess) {
    return result;
  }
  //printf("Matrix B:\n");
  result = AllocateMatrix(&B, K, N, 17);

  if (result !=  cudaSuccess) {
    cudaFree(A);
    return result;
  }

  result = AllocateMatrix(&C_cutlass, M, N, 101);

  if (result != cudaSuccess) {
    cudaFree(A);
    cudaFree(B);
    return result;
  }

  result = AllocateMatrix(&C_reference, M, N, 101);

  if (result != cudaSuccess) {
    cudaFree(A);
    cudaFree(B);
    cudaFree(C_cutlass);
    return result;
  }

  // Define pointers to matrices in CPU device memory
  float *h_A;
  float *h_B;

  // Allocate h_A and h_B in CPU 
  h_A = (float *) malloc(M*K*sizeof(float));
  h_B = (float *) malloc(N*K*sizeof(float));

  // Copy from device to host the value of the matrices A and B
  result = cudaMemcpy(h_A, A, M*K*sizeof(float), cudaMemcpyDeviceToHost);
  result = cudaMemcpy(h_B, B,  N*K*sizeof(float), cudaMemcpyDeviceToHost);

  // Define pointers to C_reference_sequential
  float *C_reference_sequential;

  // Allocate ES_0 y ES_1 in CPU 
  C_reference_sequential = (float *) malloc(M*N* sizeof(float32_t));

  // Initialice to 0 all values of ES_0 and ES_1
  memset(C_reference_sequential,0,M*N* sizeof(float32_t));


  result = cudaMemcpy(C_reference, C_cutlass, sizeof_C, cudaMemcpyDeviceToDevice);

  if (result != cudaSuccess) {
    std::cerr << "Failed to copy C_cutlass matrix to C_reference: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }
*/


  //
  // Launch CUTLASS GEMM.
  //

  //result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_cutlass, ldc);
  result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_cutlass, ldc, d_ES_a, d_ES_b, d_ES_c);


  if (result != cudaSuccess) {
    std::cerr << "CUTLASS GEMM kernel failed: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  // Copy to host the values of the ES of A, B and C performed and stored in the GPU device
  result = cudaMemcpy(h_ES_a, d_ES_a, nBytes_ES, cudaMemcpyDeviceToHost);
  result = cudaMemcpy(h_ES_b, d_ES_b, nBytes_ES, cudaMemcpyDeviceToHost);
  result = cudaMemcpy(h_ES_c, d_ES_c, nBytes_ES, cudaMemcpyDeviceToHost);

  if (result != cudaSuccess) {
    std::cerr << "CUTLASS GEMM kernel 2 failed: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

   d_ES.A = 0;
   d_ES.B = 0;
   d_ES.C = 0;

/* To use with XOR
  for(int i=0;i<nElem_ES;i++){
    printf("ES_a[%i] = %u \t ES_b = %u \t ES_c = %u\n",i,h_ES_a[i],h_ES_b[i],h_ES_c[i]);
    d_ES.A ^= h_ES_a[i];
    d_ES.B ^= h_ES_b[i];
    d_ES.C ^= h_ES_c[i];
  }
printf("Final ES (GPU)\n Es_a =%12u \t Es_b =%12u \t Es_c =%12u \n", d_ES.A, d_ES.B, d_ES.C);
*/

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
  
  printf("Initial values a=%u, b=%u, c=%u\n",Ones_Checksum_a.ui32[0],Ones_Checksum_b.ui32[0], Ones_Checksum_c.ui32[0]);
  for(int i=0;i<nElem_ES;i++){
    Ones_Checksum_a.ui64 += (uint64_t) h_ES_a[i];
		Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
		Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];
    Ones_Checksum_a.ui32[1] = 0;
    Ones_Checksum_b.ui64 += (uint64_t) h_ES_b[i];
		Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
		Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];
    Ones_Checksum_b.ui32[1] = 0;
    Ones_Checksum_c.ui64 += (uint64_t) h_ES_c[i];
		Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
		Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];
    Ones_Checksum_c.ui32[1] = 0;
    printf("ES_a[%i] = %u \t ES_b = %u \t ES_c = %u \n",i,h_ES_a[i],h_ES_b[i],h_ES_c[i]);
  }
    d_ES.A = Ones_Checksum_a.ui32[0];
    d_ES.B = Ones_Checksum_b.ui32[0];
    d_ES.C = Ones_Checksum_c.ui32[0];
printf("Final ES (GPU)\n Es_a =%12u \t Es_b =%12u \t Es_c =%12u \n", d_ES.A, d_ES.B, d_ES.C);


// Verify that with a sequential implementation we obtain the same value
//h_ES = smm_xor_internal((uint32_t) M,(uint32_t) N,(uint32_t) K, (float32_t) 1.0f, h_a, h_b, h_c);
printf(" Value of &B[0]=%p\n", d_ES_a);
h_ES = smm_ones_internal((uint32_t) M,(uint32_t) N,(uint32_t) K, (float32_t) 1.0f, h_a, h_b, h_c);

printf("Final ES_b(CPU)\n Es_a =%u \t Es_b =%u \t Es_c =%u \n", h_ES.A, h_ES.B, h_ES.C);



  //
  // Verify.
  //

  // Launch reference GEMM
  result = ReferenceGemm(M, N, K, alpha, A, lda, B, ldb, beta, C_reference, ldc);

  if (result != cudaSuccess) {
    std::cerr << "Reference GEMM kernel failed: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  // Copy to host and verify equivalence.
  std::vector<float> host_cutlass(ldc * N, 0);
  std::vector<float> host_reference(ldc * N, 0);

  result = cudaMemcpy(host_cutlass.data(), C_cutlass, sizeof_C, cudaMemcpyDeviceToHost);

  if (result != cudaSuccess) {
    std::cerr << "Failed to copy CUTLASS GEMM results: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  result = cudaMemcpy(host_reference.data(), C_reference, sizeof_C, cudaMemcpyDeviceToHost);
   result = cudaMemcpy(host_reference.data(), C_reference, sizeof_C, cudaMemcpyDeviceToHost);

  if (result != cudaSuccess) {
    std::cerr << "Failed to copy Reference GEMM results: "
      << cudaGetErrorString(result) << std::endl;

    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);

    return result;
  }

  //
  // Free device memory allocations.
  //

  cudaFree(C_reference);
  cudaFree(C_cutlass);
  cudaFree(B);
  cudaFree(A);

  //
  // Test for bit equivalence of results.
  //

  if (host_cutlass != host_reference) {
    std::cerr << "CUTLASS results incorrect." << std::endl;

    return cudaErrorUnknown;
  }

  return cudaSuccess;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// Entry point to basic_gemm example.
//
// usage:
//
//   00_basic_gemm <M> <N> <K> <alpha> <beta>
//
int main(int argc, const char *arg[]) {

  //F
  // Parse the command line to obtain GEMM dimensions and scalar values.
  //

  // GEMM problem dimensions.
  int problem[3] = { 128, 128, 128  };

  for (int i = 1; i < argc && i < 4; ++i) {
    std::stringstream ss(arg[i]);
    ss >> problem[i - 1];
  }

  // Scalars used for linear scaling the result of the matrix product.
  float scalars[2] = { 1, 0 };

  for (int i = 4; i < argc && i < 6; ++i) {
    std::stringstream ss(arg[i]);
    ss >> scalars[i - 4];
  }

  //
  // Run the CUTLASS GEMM test.
  //

  cudaError_t result = TestCutlassGemm(
    problem[0],     // GEMM M dimension
    problem[1],     // GEMM N dimension
    problem[2],     // GEMM K dimension
    scalars[0],     // alpha
    scalars[1]      // beta
  );

  if (result == cudaSuccess) {
    std::cout << "Passed." << std::endl;
  }

  // Exit.
  return result == cudaSuccess ? 0 : -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
