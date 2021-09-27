
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
//
#include <sched.h>
#include <string.h>

#ifndef NAME
  #define NAME "NO_NAME"
#endif

#ifndef CHAR_BIT
  #define CHAR_BIT 8u
#endif

// Defines cutlass::gemm::device::Gemm, the generic Gemm computation template class.
#include "cutlass/gemm/device/gemm.h"
#include <time.h>

// lock memory
#include <sys/mman.h>

#define PUT_IN_REGISTER								 /* dummy definition  for Windows 32 */

#ifndef TIMING_EXP
  #define TIMING_EXP 0u
#endif

#ifndef DC_EXP
  #define DC_EXP 0u
#endif 

#ifndef ES_EXP
  #define ES_EXP 0u
#endif 


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


// Include Smmm.h (MMM employed in the previous paper)
//#include "cutlass/sequential_MMM/Smmm.h"

  // Definition of an struct to store th values of the Execution Signatures
struct ESs{
    uint32_t A;
    uint32_t B;
    uint32_t C;
  };


#define DEF_TIME_VAR(t) clock_t t;
#define GET_TIME(t) t = clock();
#define GET_TIME_DIFF(tmr_start, tmr_end, f_time_interval) f_time_interval = ((tmr_end - tmr_start) > 0) ? ( (float32_t)  (tmr_end - tmr_start) / CLOCKS_PER_SEC) : ( (float32_t)  (tmr_start - tmr_end)/ CLOCKS_PER_SEC)

#define TIME_MEASUREMENT_LOOPS  200u
#define INITIAL_TIME_MEASUREMENT 10u
#define TIME_SEC2USEC       ((uint32_t) 1000000u) /*!< Microseconds per second*/

#if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
    #define CRC_table_elements 256u
    /* ==============================================================================================================
    * 										CONSTS
    * ============================================================================================================== */
    uint32_t kaui32_crc_table[CRC_table_elements] = 
    {
      0x00000000L, 0xF26B8303L, 0xE13B70F7L, 0x1350F3F4L,
      0xC79A971FL, 0x35F1141CL, 0x26A1E7E8L, 0xD4CA64EBL,
      0x8AD958CFL, 0x78B2DBCCL, 0x6BE22838L, 0x9989AB3BL,
      0x4D43CFD0L, 0xBF284CD3L, 0xAC78BF27L, 0x5E133C24L,
      0x105EC76FL, 0xE235446CL, 0xF165B798L, 0x030E349BL,
      0xD7C45070L, 0x25AFD373L, 0x36FF2087L, 0xC494A384L,
      0x9A879FA0L, 0x68EC1CA3L, 0x7BBCEF57L, 0x89D76C54L,
      0x5D1D08BFL, 0xAF768BBCL, 0xBC267848L, 0x4E4DFB4BL,
      0x20BD8EDEL, 0xD2D60DDDL, 0xC186FE29L, 0x33ED7D2AL,
      0xE72719C1L, 0x154C9AC2L, 0x061C6936L, 0xF477EA35L,
      0xAA64D611L, 0x580F5512L, 0x4B5FA6E6L, 0xB93425E5L,
      0x6DFE410EL, 0x9F95C20DL, 0x8CC531F9L, 0x7EAEB2FAL,
      0x30E349B1L, 0xC288CAB2L, 0xD1D83946L, 0x23B3BA45L,
      0xF779DEAEL, 0x05125DADL, 0x1642AE59L, 0xE4292D5AL,
      0xBA3A117EL, 0x4851927DL, 0x5B016189L, 0xA96AE28AL,
      0x7DA08661L, 0x8FCB0562L, 0x9C9BF696L, 0x6EF07595L,
      0x417B1DBCL, 0xB3109EBFL, 0xA0406D4BL, 0x522BEE48L,
      0x86E18AA3L, 0x748A09A0L, 0x67DAFA54L, 0x95B17957L,
      0xCBA24573L, 0x39C9C670L, 0x2A993584L, 0xD8F2B687L,
      0x0C38D26CL, 0xFE53516FL, 0xED03A29BL, 0x1F682198L,
      0x5125DAD3L, 0xA34E59D0L, 0xB01EAA24L, 0x42752927L,
      0x96BF4DCCL, 0x64D4CECFL, 0x77843D3BL, 0x85EFBE38L,
      0xDBFC821CL, 0x2997011FL, 0x3AC7F2EBL, 0xC8AC71E8L,
      0x1C661503L, 0xEE0D9600L, 0xFD5D65F4L, 0x0F36E6F7L,
      0x61C69362L, 0x93AD1061L, 0x80FDE395L, 0x72966096L,
      0xA65C047DL, 0x5437877EL, 0x4767748AL, 0xB50CF789L,
      0xEB1FCBADL, 0x197448AEL, 0x0A24BB5AL, 0xF84F3859L,
      0x2C855CB2L, 0xDEEEDFB1L, 0xCDBE2C45L, 0x3FD5AF46L,
      0x7198540DL, 0x83F3D70EL, 0x90A324FAL, 0x62C8A7F9L,
      0xB602C312L, 0x44694011L, 0x5739B3E5L, 0xA55230E6L,
      0xFB410CC2L, 0x092A8FC1L, 0x1A7A7C35L, 0xE811FF36L,
      0x3CDB9BDDL, 0xCEB018DEL, 0xDDE0EB2AL, 0x2F8B6829L,
      0x82F63B78L, 0x709DB87BL, 0x63CD4B8FL, 0x91A6C88CL,
      0x456CAC67L, 0xB7072F64L, 0xA457DC90L, 0x563C5F93L,
      0x082F63B7L, 0xFA44E0B4L, 0xE9141340L, 0x1B7F9043L,
      0xCFB5F4A8L, 0x3DDE77ABL, 0x2E8E845FL, 0xDCE5075CL,
      0x92A8FC17L, 0x60C37F14L, 0x73938CE0L, 0x81F80FE3L,
      0x55326B08L, 0xA759E80BL, 0xB4091BFFL, 0x466298FCL,
      0x1871A4D8L, 0xEA1A27DBL, 0xF94AD42FL, 0x0B21572CL,
      0xDFEB33C7L, 0x2D80B0C4L, 0x3ED04330L, 0xCCBBC033L,
      0xA24BB5A6L, 0x502036A5L, 0x4370C551L, 0xB11B4652L,
      0x65D122B9L, 0x97BAA1BAL, 0x84EA524EL, 0x7681D14DL,
      0x2892ED69L, 0xDAF96E6AL, 0xC9A99D9EL, 0x3BC21E9DL,
      0xEF087A76L, 0x1D63F975L, 0x0E330A81L, 0xFC588982L,
      0xB21572C9L, 0x407EF1CAL, 0x532E023EL, 0xA145813DL,
      0x758FE5D6L, 0x87E466D5L, 0x94B49521L, 0x66DF1622L,
      0x38CC2A06L, 0xCAA7A905L, 0xD9F75AF1L, 0x2B9CD9F2L,
      0xFF56BD19L, 0x0D3D3E1AL, 0x1E6DCDEEL, 0xEC064EEDL,
      0xC38D26C4L, 0x31E6A5C7L, 0x22B65633L, 0xD0DDD530L,
      0x0417B1DBL, 0xF67C32D8L, 0xE52CC12CL, 0x1747422FL,
      0x49547E0BL, 0xBB3FFD08L, 0xA86F0EFCL, 0x5A048DFFL,
      0x8ECEE914L, 0x7CA56A17L, 0x6FF599E3L, 0x9D9E1AE0L,
      0xD3D3E1ABL, 0x21B862A8L, 0x32E8915CL, 0xC083125FL,
      0x144976B4L, 0xE622F5B7L, 0xF5720643L, 0x07198540L,
      0x590AB964L, 0xAB613A67L, 0xB831C993L, 0x4A5A4A90L,
      0x9E902E7BL, 0x6CFBAD78L, 0x7FAB5E8CL, 0x8DC0DD8FL,
      0xE330A81AL, 0x115B2B19L, 0x020BD8EDL, 0xF0605BEEL,
      0x24AA3F05L, 0xD6C1BC06L, 0xC5914FF2L, 0x37FACCF1L,
      0x69E9F0D5L, 0x9B8273D6L, 0x88D28022L, 0x7AB90321L,
      0xAE7367CAL, 0x5C18E4C9L, 0x4F48173DL, 0xBD23943EL,
      0xF36E6F75L, 0x0105EC76L, 0x12551F82L, 0xE03E9C81L,
      0x34F4F86AL, 0xC69F7B69L, 0xD5CF889DL, 0x27A40B9EL,
      0x79B737BAL, 0x8BDCB4B9L, 0x988C474DL, 0x6AE7C44EL,
      0xBE2DA0A5L, 0x4C4623A6L, 0x5F16D052L, 0xAD7D5351L
    };
    __constant__ uint32_t d_CRC_table_constant[CRC_table_elements];
    __shared__ uint32_t d_CRC_table_shared[CRC_table_elements];


/* ==========================================================================
  Description: CRC function
=============================================================================*/
__host__ uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data)
{
	ui32_to_ui8_t u;
	u.ui32 = ui32_data;

	/* 4 bytes*/
  uint32_t prev_ui32_crc = ui32_crc;
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u);
  return ui32_crc;
}
#endif

/* ==========================================================================
  Description: Bit inversion function
=============================================================================*/
static void_t mem_fi(float32_t* const paf32_m, uint32_t ui32_bit_idx)
{
	uint32_t ui32_idx_flt = ui32_bit_idx / (sizeof(float32_t)*CHAR_BIT),
		ui32_idx_flt_bit = ui32_bit_idx % (sizeof(float32_t)*CHAR_BIT);
	uint32_t ui32_f_d = *((uint32_t *)&paf32_m[ui32_idx_flt]);

	ui32_f_d ^= (1u << ui32_idx_flt_bit);
	paf32_m[ui32_idx_flt] = *((float32_t *)&ui32_f_d);
}

// Definition of the sequential MMM (not required. It belongs to a test that try to compare sequential ES and parallel ES)
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
                              d_ES_c);   // Pointer to d_ES_c
                             

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



  /*==============================================================================
  //   1)                  CPU affinity
	==============================================================================*/
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(0, &mask);
	if(sched_setaffinity(0, sizeof(cpu_set_t), &mask) < 0)
	{
		perror("sched_setaffinity failed");
		exit(-1);
	}
  
  /*==============================================================================
	//   2)               Real-time priority
  ==============================================================================*/
	struct sched_param param;
	param.sched_priority = 98;
	if(sched_setscheduler(0, SCHED_FIFO, &param) < 0)
	{
		perror("sched_setscheduler failed");
		exit(-1);
	}
  
    /*==============================================================================
	//   3)                  Memory locking
	==============================================================================*/
	if(mlockall(MCL_CURRENT | MCL_FUTURE) < 0)
	{
		perror("mlockall failed");
		exit(-1);
	} 

  /*==============================================================================
  //                       Timing variables
  ==============================================================================*/
  struct timespec begin, end;
  uint64_t time_max_ns = 0;
  long long iteration_max_time = 0;
  uint64_t time_ns;

  /*==============================================================================
  //                      Statistical variables
  ==============================================================================*/

	double M_time = 0.0;
	double S_time = 0.0;

  DEF_TIME_VAR(tmr_start);
	DEF_TIME_VAR(tmr_end);
  float64_t time_interval;

    // Compute leading dimensions for each matrix.
    int lda = M;
    int ldb = K;
    int ldc = M;

    // Compute size in bytes of the C matrix.
    size_t sizeof_C = sizeof(float) * ldc * N;

  // =============================================================
  // Author:  Javier Fdez
  // Date:    2021/08/17
  // Summary: In the following chunk of code the variables ES_0 and  
  //          ES_1are initialized in CPU and GPU. In these variables 
  //          are stored the Execution Signatures (1 per thread*SMP)
  // =============================================================
  //  Definition of an struct with the values of the ES:
  struct ESs h_ES;
  struct ESs d_ES;

  // =============================================================
  //  4) Define the pointers to ES_a,b,c
  // =============================================================
  uint32_t nElem_ES = 256;
  size_t nBytes_ES = nElem_ES * sizeof(uint32_t);

  // Define pointers to ES_a, ES_b and ES_c in CPU (host)
  uint32_t *h_ES_a;
  uint32_t *h_ES_b;
  uint32_t *h_ES_c;
  #if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
    uint32_t *h_CRC_table;
  #endif

  // Allocate ES_a, ES_b and ES_c in CPU 
  h_ES_a = (uint32_t *) malloc(nBytes_ES);
  h_ES_b = (uint32_t *) malloc(nBytes_ES);
  h_ES_c = (uint32_t *) malloc(nBytes_ES);

  // Initialice to 0 all values of ES_a, ES_b and ES_c
  memset(h_ES_a,0,nBytes_ES);
  memset(h_ES_b,0,nBytes_ES);
  memset(h_ES_c,0,nBytes_ES);
  
  // =============================================================
  //   5) Define the pointers to ES_a_ref,b,c
  // =============================================================
  // Define pointers to ES_a_ref,b,c in CPU (host)
  uint32_t *h_ES_a_ref;
  uint32_t *h_ES_b_ref;
  uint32_t *h_ES_c_ref;

   // Allocate ES_a_ref, ES_b_ref and ES_c_ref in CPU 
  h_ES_a_ref = (uint32_t *) malloc(nBytes_ES);
  h_ES_b_ref = (uint32_t *) malloc(nBytes_ES);
  h_ES_c_ref = (uint32_t *) malloc(nBytes_ES);
  

  // Initialice to 0 all values of ES_a_ref, ES_b_ref and ES_c_ref
  memset(h_ES_a_ref,0,nBytes_ES);
  memset(h_ES_b_ref,0,nBytes_ES);
  memset(h_ES_c_ref,0,nBytes_ES);
  

  // =============================================================
  //   6) Define the pointers to d_ES_a,b,c
  // =============================================================
  // Define pointers to d_ES_a,b,c and CRC lookup table in GPU (device)
  uint32_t *d_ES_a;
  uint32_t *d_ES_b;
  uint32_t *d_ES_c;

  // Allocate d_ES_a,b,c in GPU
  result = cudaMalloc((uint32_t **) &d_ES_a, nBytes_ES);
  if (result != cudaSuccess) {
    std::cerr << "Failed to Allocate d_ES_a: "<< cudaGetErrorString(result) << std::endl;
    cudaFree(d_ES_a);
    return result;
  }
  result = cudaMalloc((uint32_t **) &d_ES_b, nBytes_ES);
  if (result != cudaSuccess) {
    std::cerr << "Failed to Allocate d_ES_b: "<< cudaGetErrorString(result) << std::endl;
    cudaFree(d_ES_a);
    cudaFree(d_ES_b);
    return result;
  }
  result = cudaMalloc((uint32_t **) &d_ES_c, nBytes_ES);
  if (result != cudaSuccess) {
    std::cerr << "Failed to Allocate d_ES_c: "<< cudaGetErrorString(result) << std::endl;
    cudaFree(d_ES_a);
    cudaFree(d_ES_b);
    cudaFree(d_ES_c);
    return result;
  }

  // =============================================================
  //   Transfer h_ES_a... -> d_ES_a... (from host to device)
  // =============================================================
  result = cudaMemcpy(d_ES_a, h_ES_a, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_ES_a matrix to d_ES_a: " << cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        cudaFree(d_ES_c);
        return result;
    }

    // Initialize d_ES_b to 0
    result = cudaMemcpy(d_ES_b, h_ES_b, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) 
    {
        std::cerr << "Failed to copy h_ES_b matrix to h_ES_b: " << cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        cudaFree(d_ES_c);
        return result;
    }

    // Initialize d_ES_c to 0
    cudaMemcpy(d_ES_c, h_ES_c, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_ES_c matrix to d_ES_c " << cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        cudaFree(d_ES_c);
        return result;
    }

#if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
  // =============================================================
  //  7) Copy the CRC lookup table from host to device
  // =============================================================
  result = cudaMemcpyToSymbol(d_CRC_table_constant, kaui32_crc_table, CRC_table_elements*sizeof(uint32_t));
  if (result != cudaSuccess) {
    std::cerr << "Failed to allocate Constant Memory: "
      << cudaGetErrorString(result) << std::endl;
      cudaFree(d_ES_a);
      cudaFree(d_ES_b);
      cudaFree(d_ES_c);
      cudaFree(d_CRC_table_constant);
    }
#endif


  // ==============================================================================
  // Brief: Initialization of A, B, C_reference and C_cutlass. 
  // Hypothesis: the values of A and B follow a pattern in the initialization if it 
  // is done in with the GPU. This sequential implementation aid to avoid this.
  //===============================================================================
  uint32_t nBytes_a = M * K * sizeof(float);
  uint32_t nBytes_b = K * N * sizeof(float);
  uint32_t nBytes_c = M * N * sizeof(float);

  // ==============================================================================
  // 8) Define pointers to h_a, h_b and h_c in CPU (host)
  // ==============================================================================
  float *h_a;
  float *h_b;
  float *h_c;

  // Allocate h_a, h_b and h_c in CPU 
  h_a     = (float *) malloc(nBytes_a);
  h_b     = (float *) malloc(nBytes_b);
  h_c     = (float *) malloc(nBytes_c);

  // Initialice to 0 all values of h_c
  memset(h_c,0,nBytes_c);
  
  // Initialization of the values of h_a and h_b
  #if (1==ES_EXP)
      matrix2rand(h_a,M,K);
      matrix2rand(h_b,K,N);
  #elif (1==TIMING_EXP)
      matrix2rand(h_a,M,K);
      matrix2rand(h_b,K,N);
  #elif (1==DC_EXP) 
      memset(h_a,0,nBytes_a);
      memset(h_b,0,nBytes_b);
  #endif


  // ==============================================================================
  //   8) Define pointers to matrices in GPU device memory, allocate, initialize.
  // ==============================================================================
  float *A;
  float *B;
  float *C_cutlass;
  float *C_reference;

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
  
  // Copy the values initialized and stored in host to the device (h_a -> A, h_b -> B ...)
  result = cudaMemcpy (A,h_a,nBytes_a,cudaMemcpyHostToDevice);
 if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_a matrix to A: " << cudaGetErrorString(result) << std::endl;
    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);
    return result;
  }

  result = cudaMemcpy (B,h_b,nBytes_b,cudaMemcpyHostToDevice);
 if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_b matrix to B: " << cudaGetErrorString(result) << std::endl;
    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);
    return result;
  }

  result = cudaMemcpy (C_cutlass,h_c,nBytes_c,cudaMemcpyHostToDevice);
  if (result != cudaSuccess) {
    std::cerr << "Failed to copy C_cutlass matrix to C_reference: " << cudaGetErrorString(result) << std::endl;
    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);
    return result;
  }

  result = cudaMemcpy (C_reference,h_c,nBytes_c,cudaMemcpyHostToDevice);
  if (result != cudaSuccess) {
    std::cerr << "Failed to copy C_cutlass matrix to C_reference: " << cudaGetErrorString(result) << std::endl;
    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);
    return result;
  }
  
  /* ==============================================================================
    Brief: Diagnostic Coverage experiments
  ==============================================================================*/
#if (1==DC_EXP)
  //size_t size_a,size_b;
	uint32_t ui32_idx_bit,
		ui32_dc_cnt_all,
		ui32_dc_cnt_a,
    ui32_dc_cnt_b;
	float32_t f32_alpha = 1.0f;

	DEF_TIME_VAR(tmr_start_exp);
	DEF_TIME_VAR(tmr_end_exp);
  printf("===============================\nDIAGNOSTIC COVERAGE EXPERIMENT\n===============================\n");

#if (ES_EXP==1)
  #define size_a  100u
  #define size_b  0u
#else
	#define size_a  (DIM_M * DIM_K * sizeof(float32_t) * CHAR_BIT)
	#define size_b  (DIM_N * DIM_K * sizeof(float32_t) * CHAR_BIT)
#endif

  // ==============================================================================
  //  0)             DC Set-up environment
  // ==============================================================================
	// Fault injection campaing 
	//uint32_t ui32_comb_a_max = size_a;
  uint32_t ui32_comb_a_max = size_a;
	uint32_t ui32_comb_b_max = size_b;

  ui32_dc_cnt_a = 0u;
  ui32_dc_cnt_b = 0u;
  ui32_dc_cnt_all = 0u;
  uint32_t ui32_idx_bit_aux = 0u;

  #define ui32_20_percent_a size_a*20/100
  #define ui32_40_percent_a size_a*40/100
  #define ui32_60_percent_a size_a*60/100
  #define ui32_80_percent_a size_a*80/100
  

  // =======================================================================================
  // 1) Store the ES_a,b and c that will be employed as reference
  // =======================================================================================
  // Launch the kernel to GPU and verify that has not return an error
    result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_reference, ldc, d_ES_a, d_ES_b, d_ES_c);
    cudaDeviceSynchronize();

    if (result != cudaSuccess) 
    {
        std::cerr << "CUTLASS GEMM kernel failed: " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
    }
    // Copy to host the values of the ES of A, B and C performed and stored in the GPU device (h_ES_a_ref)
    result = cudaMemcpy(h_ES_a_ref, d_ES_a, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_a matrix to h_ES_a (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    result = cudaMemcpy(h_ES_b_ref, d_ES_b, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_b matrix to h_ES_b (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    result = cudaMemcpy(h_ES_c_ref, d_ES_c, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_c matrix to h_ES_c (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }
  

  for (ui32_idx_bit = ui32_idx_bit_aux; ui32_idx_bit < ui32_comb_a_max; ui32_idx_bit++) 
  {
    // =======================================================================================
    // Modify a bit of the matrix A
    // =======================================================================================
    #if (ES_EXP==0)
      mem_fi(&h_a[0], ui32_idx_bit);
    #endif

    // =======================================================================================
    // Copy the values initialized and stored in host to the device (h_a -> A, h_b -> B ...)
    // =======================================================================================
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

    /*result = cudaMemcpy (B,h_b,nBytes_b,cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_b matrix to B: "
          << cudaGetErrorString(result) << std::endl;

        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);

        return result;
    }
    */

    result = cudaMemcpy (C_cutlass,h_c,nBytes_c,cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy C_cutlass matrix to C_reference: " << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    // =======================================================================================
    // 1) Initialize h_ES_a,b,c 
    // 2) Re-initialize d_ES_a,b,c with zero values
    // =======================================================================================
    // Initialice to 0 all values of h_ES_a,b,c
    memset(h_ES_a,0,nBytes_ES);
    memset(h_ES_b,0,nBytes_ES);
    memset(h_ES_c,0,nBytes_ES);

    result = cudaMemcpy(d_ES_a, h_ES_a, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_ES_a matrix to d_ES_a: " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
    }

    // Re-initialize d_ES_b
    result = cudaMemcpy(d_ES_b, h_ES_b, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) 
    {
        std::cerr << "Failed to copy h_ES_b matrix to h_ES_b: " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
    }

    // Re-initialize d_ES_c
    cudaMemcpy(d_ES_c, h_ES_c, nBytes_ES, cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_ES_c matrix to d_ES_c " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
    }

    // =======================================================================================
    // Launch the kernel to GPU and verify that has not return an error
    // =======================================================================================
    result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_cutlass, ldc, d_ES_a, d_ES_b, d_ES_c);
    cudaDeviceSynchronize();

    if (result != cudaSuccess) 
    {
        std::cerr << "CUTLASS GEMM kernel failed: " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
    }

    // =======================================================================================
    // Launch the kernel to GPU and verify that has not return an error
    // =======================================================================================
    // Copy to host the values of the ES of A, B and C performed and stored in the GPU device
    result = cudaMemcpy(h_ES_a, d_ES_a, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_a matrix to h_ES_a (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    result = cudaMemcpy(h_ES_b, d_ES_b, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_b matrix to h_ES_b (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    result = cudaMemcpy(h_ES_c, d_ES_c, nBytes_ES, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_c matrix to h_ES_c (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(C_reference);
      cudaFree(C_cutlass);
      cudaFree(B);
      cudaFree(A);
      return result;
    }

    // =======================================================================================
    // Verify that the ES_a,b,c is the same than the values stored in ES_a_ref,b,c
    // =======================================================================================
    if ((memcmp(h_ES_a,h_ES_a_ref,nBytes_ES)!=0) || (memcmp(h_ES_b,h_ES_b_ref,nBytes_ES)!=0) || (memcmp(h_ES_c,h_ES_c_ref,nBytes_ES)!=0)) {
          ui32_dc_cnt_a += 1u;
    }
    ui32_dc_cnt_all += 1u;

    // =======================================================================================
    // TO flip again the bit that was fliped in host
    // =======================================================================================
    #if (ES_EXP==0)
      mem_fi(&h_a[0], ui32_idx_bit);
    #endif

    // =======================================================================================
    // dummy way of now of the process is being 
    // =======================================================================================
    /*switch(ui32_idx_bit) 
    {
      case ui32_20_percent_a:
          printf("Processing: [\t20%%\t");
          break;
      case ui32_40_percent_a:
          printf("=>40%%\t");
          break;
      case ui32_60_percent_a:
          printf("=>60%%\t");
          break;
      case ui32_80_percent_a:
          printf("=>80%%\n");
          break;
    }*/
  }
  printf("Number of executions: %d\nDifferents ES: %d\n",ui32_comb_a_max, ui32_dc_cnt_a);






#if (ES_EXP==0)
  // =======================================================================================
  // Copy the values initialized and stored in host to the device (h_a -> A)
  // =======================================================================================
  result = cudaMemcpy (A,h_a,nBytes_a,cudaMemcpyHostToDevice);
  if (result != cudaSuccess) {
    std::cerr << "Failed to copy h_a matrix to A: " << cudaGetErrorString(result) << std::endl;
    cudaFree(C_reference);
    cudaFree(C_cutlass);
    cudaFree(B);
    cudaFree(A);
    return result;
  }

  for (ui32_idx_bit = ui32_idx_bit_aux; ui32_idx_bit < ui32_comb_b_max; ui32_idx_bit++) 
    {
      // =======================================================================================
      // Modify a bit of the matrix B
      // =======================================================================================
      mem_fi(&h_b[0], ui32_idx_bit);

      result = cudaMemcpy (B,h_b,nBytes_b,cudaMemcpyHostToDevice);
      if (result != cudaSuccess) {
          std::cerr << "Failed to copy h_b matrix to B: " << cudaGetErrorString(result) << std::endl;
          cudaFree(C_reference);
          cudaFree(C_cutlass);
          cudaFree(B);
          cudaFree(A);
          return result;
      }
      

      result = cudaMemcpy (C_cutlass,h_c,nBytes_c,cudaMemcpyHostToDevice);
      if (result != cudaSuccess) {
        std::cerr << "Failed to copy C_cutlass matrix to C_reference: " << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
      }

      // =======================================================================================
      // 1) Initialize h_ES_a,b,c 
      // 2) Re-initialize d_ES_a,b,c with zero values
      // =======================================================================================
      // Initialice to 0 all values of h_ES_a,b,c
      memset(h_ES_a,0,nBytes_ES);
      memset(h_ES_b,0,nBytes_ES);
      memset(h_ES_c,0,nBytes_ES);

      result = cudaMemcpy(d_ES_a, h_ES_a, nBytes_ES, cudaMemcpyHostToDevice);
      if (result != cudaSuccess) {
          std::cerr << "Failed to copy h_ES_a matrix to d_ES_a: " << cudaGetErrorString(result) << std::endl;
          cudaFree(C_reference);
          cudaFree(C_cutlass);
          cudaFree(B);
          cudaFree(A);
          return result;
      }

      // Re-initialize d_ES_b
      result = cudaMemcpy(d_ES_b, h_ES_b, nBytes_ES, cudaMemcpyHostToDevice);
      if (result != cudaSuccess) 
      {
          std::cerr << "Failed to copy h_ES_b matrix to h_ES_b: " << cudaGetErrorString(result) << std::endl;
          cudaFree(C_reference);
          cudaFree(C_cutlass);
          cudaFree(B);
          cudaFree(A);
          return result;
      }

      // Re-initialize d_ES_c
      cudaMemcpy(d_ES_c, h_ES_c, nBytes_ES, cudaMemcpyHostToDevice);
      if (result != cudaSuccess) {
          std::cerr << "Failed to copy h_ES_c matrix to d_ES_c " << cudaGetErrorString(result) << std::endl;
          cudaFree(C_reference);
          cudaFree(C_cutlass);
          cudaFree(B);
          cudaFree(A);
          return result;
      }

      // =======================================================================================
      // Launch the kernel to GPU and verify that has not return an error
      // =======================================================================================
      result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_cutlass, ldc, d_ES_a, d_ES_b, d_ES_c);
      cudaDeviceSynchronize();
      if (result != cudaSuccess) 
      {
          std::cerr << "CUTLASS GEMM kernel failed: " << cudaGetErrorString(result) << std::endl;
          cudaFree(C_reference);
          cudaFree(C_cutlass);
          cudaFree(B);
          cudaFree(A);
          return result;
      }

      // =======================================================================================
      // Launch the kernel to GPU and verify that has not return an error
      // =======================================================================================
      // Copy to host the values of the ES of A, B and C performed and stored in the GPU device
      result = cudaMemcpy(h_ES_a, d_ES_a, nBytes_ES, cudaMemcpyDeviceToHost);
      if (result != cudaSuccess) {
        std::cerr << "Failed to copy d_ES_a matrix to h_ES_a (return)" << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
      }

      result = cudaMemcpy(h_ES_b, d_ES_b, nBytes_ES, cudaMemcpyDeviceToHost);
      if (result != cudaSuccess) {
        std::cerr << "Failed to copy d_ES_b matrix to h_ES_b (return)" << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
      }

      result = cudaMemcpy(h_ES_c, d_ES_c, nBytes_ES, cudaMemcpyDeviceToHost);
      if (result != cudaSuccess) {
        std::cerr << "Failed to copy d_ES_c matrix to h_ES_c (return)" << cudaGetErrorString(result) << std::endl;
        cudaFree(C_reference);
        cudaFree(C_cutlass);
        cudaFree(B);
        cudaFree(A);
        return result;
      }

      // =======================================================================================
      // Verify that the ES_a,b,c is the same than the values stored in ES_a_ref,b,c
      // =======================================================================================
      if ((memcmp(h_ES_a,h_ES_a_ref,nBytes_ES)!=0) || (memcmp(h_ES_b,h_ES_b_ref,nBytes_ES)!=0) || (memcmp(h_ES_c,h_ES_c_ref,nBytes_ES)!=0)) {
            ui32_dc_cnt_b += 1u;
      }
      ui32_dc_cnt_all += 1u;

      // =======================================================================================
      // TO flip again the bit that was fliped in host
      // =======================================================================================
      mem_fi(&h_b[0], ui32_idx_bit);
    }

  printf("Number of executions: %d\nDifferents ES: %d\n",ui32_comb_b_max, ui32_dc_cnt_b);
#endif











/* ==============================================================================
    Brief: Store the timing measurements in a file (csv/xlsx)
  ==============================================================================*/
    FILE *p_file;
    char str_file_name[100u];
    char str_file_name_aux[100u] = NAME"_DC.csv";
    snprintf(str_file_name, 100,"%d_%d_%d_",DIM_M,DIM_N,DIM_K);
    strcat(str_file_name,str_file_name_aux);

    char str_file_time[100u];
    time_t time_now = time(NULL);
    struct tm *time_info;
    time_info = localtime(&time_now);
    strftime(str_file_time, sizeof(str_file_time), "%m_%d_%H_%M_%S.csv",time_info);

	if ((p_file = fopen(str_file_name, "a")) == NULL)
	{
		fprintf(stderr, "cannot open file '%s'\n", str_file_name);
		return cudaErrorInvalidValue;
	}

	if (!p_file)
	{
		perror("File opening failed");
		return cudaErrorInvalidValue;
	}
  
#if (ES_EXP==1)
	fprintf(p_file, "%s,%s,%d,%d,%d,%d,%d,%d,",NAME, str_file_time, DIM_M, DIM_N, DIM_K, ui32_dc_cnt_a,ui32_dc_cnt_all,ui32_comb_a_max);
  // Here i store in the csv file the content of the ES_a_ref,b_ref and c_ref
  for(uint32_t ui32_idx_ES_number=0;ui32_idx_ES_number<3;ui32_idx_ES_number++){
    if(ui32_idx_ES_number==0)       { fprintf(p_file,"\nES_a,");}
    else if (ui32_idx_ES_number==1) { fprintf(p_file,"\nES_b,");}
    else                            { fprintf(p_file,"\nES_c,");}
    
    for(uint32_t ui32_idx_ES=0;ui32_idx_ES<nElem_ES;ui32_idx_ES++){
      if(ui32_idx_ES_number==0)       { fprintf(p_file,"%u,",h_ES_a_ref[ui32_idx_ES]);}
      else if (ui32_idx_ES_number==1) { fprintf(p_file,"%u,",h_ES_b_ref[ui32_idx_ES]);}
      else                            { fprintf(p_file,"%u,",h_ES_c_ref[ui32_idx_ES]);}
    }
  }
  
#else
	fprintf(p_file, "%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,",NAME, str_file_time, DIM_M, DIM_N, DIM_K, ui32_dc_cnt_a,ui32_dc_cnt_b,ui32_dc_cnt_all,ui32_comb_a_max, ui32_comb_b_max);
#endif
  fprintf(p_file,"\n");
  fclose(p_file);

/*
			fprintf(p_file, "%u,", ui32_dc_cnt);
			fprintf(p_file_idx_fi, "\n");
			for (ui32_idx_bit = ui32_idx_bit_aux; ui32_idx_bit < ui32_comb_b_max; ui32_idx_bit++)
			{
				mem_fi(&paf32_mb_fi[0], ui32_idx_bit);
				aui32_dc_value[e_FI_VAR_B] = ptr_fn_smm_technique[e_tech](M, N, K, f32_alpha, (float32_t* const)paf32_ma, (float32_t* const)paf32_mb_fi, (float32_t* const)paf32_mc);
				if (aui32_dc_value[e_FI_VAR_NONE] != aui32_dc_value[e_FI_VAR_B]) {
					ui32_dc_cnt += 1u;
				}
				else {
					fprintf(p_file_idx_fi, "%u,", ui32_idx_bit);
				}
				mem_fi(&paf32_mb_fi[0], ui32_idx_bit);
			}
			fprintf(p_file, "%u,%u,%d,%d,%d,%u,%u,%u,%u", ui32_dc_cnt, (ui32_combinations_a + ui32_combinations_b), M, N, K, ui32_idx_bit_aux, ui32_comb_a_max, ui32_comb_b_max, launch_number);
  */
#endif




 
  /* ==============================================================================
    Brief: Timing measurements. The values are stored in a xlsx file
  ==============================================================================*/
  #if (1==TIMING_EXP)
    uint64_t timing_values[TIME_MEASUREMENT_LOOPS-INITIAL_TIME_MEASUREMENT];

    for (size_t i_loop = 0; i_loop < TIME_MEASUREMENT_LOOPS; i_loop++)
    {
        // Re-initialize ES_a
        result = cudaMemcpy(d_ES_a, h_ES_a, nBytes_ES, cudaMemcpyHostToDevice);
        if (result != cudaSuccess) {
            std::cerr << "Failed to copy h_ES_a matrix to d_ES_a: "
                << cudaGetErrorString(result) << std::endl;

            cudaFree(C_reference);
            cudaFree(C_cutlass);
            cudaFree(B);
            cudaFree(A);

            return result;
        }

        // Re-initialize ES_b
        result = cudaMemcpy(d_ES_b, h_ES_b, nBytes_ES, cudaMemcpyHostToDevice);
        if (result != cudaSuccess) 
        {
            std::cerr << "Failed to copy h_ES_b matrix to h_ES_b: "
                << cudaGetErrorString(result) << std::endl;

            cudaFree(C_reference);
            cudaFree(C_cutlass);
            cudaFree(B);
            cudaFree(A);

            return result;
        }

        // Re-initialize ES_c
        cudaMemcpy(d_ES_c, h_ES_c, nBytes_ES, cudaMemcpyHostToDevice);
        if (result != cudaSuccess) {
            std::cerr << "Failed to copy h_ES_c matrix to d_ES_c "
                << cudaGetErrorString(result) << std::endl;

            cudaFree(C_reference);
            cudaFree(C_cutlass);
            cudaFree(B);
            cudaFree(A);

            return result;
        }

        // Re-initialize C_cutlass
        result = cudaMemcpy (C_cutlass,h_c,nBytes_c,cudaMemcpyHostToDevice);
        if (result != cudaSuccess) {
            std::cerr << "Failed to copy h_c matrix to C_cutlass "
                << cudaGetErrorString(result) << std::endl;

            cudaFree(C_reference);
            cudaFree(C_cutlass);
            cudaFree(B);
            cudaFree(A);

            return result;
        }

        //GET_TIME(tmr_start);
        clock_gettime(CLOCK_MONOTONIC, &begin);
        result = CutlassSgemmNN(M, N, K, alpha, A, lda, B, ldb, beta, C_cutlass, ldc, d_ES_a, d_ES_b, d_ES_c);
        cudaDeviceSynchronize();
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        if (i_loop >= INITIAL_TIME_MEASUREMENT)
        {
            timing_values[i_loop-INITIAL_TIME_MEASUREMENT]= 1e9 * (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
        }

        // Time measurement (average/standard deviation)

        /*
        if (i_loop > INITIAL_TIME_MEASUREMENT)
		    {
            uint64_t time_ns = 1e9 * (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
            if(time_ns > time_max_ns)
            {
                time_max_ns = time_ns;
                iteration_max_time = i_loop;
            }
        
        if(i_loop == INITIAL_TIME_MEASUREMENT)
        {
          M_time = time_ns;
          S_time = 0.0;
        }
        double previousM = M_time;
        double previousS = S_time;
        M_time = previousM + (time_ns - previousM) / i_loop;
        S_time = previousS + (time_ns - previousM) * (time_ns - M_time);
		  }
      */

        //GET_TIME(tmr_end);
        //GET_TIME_DIFF(tmr_start, tmr_end, time_interval);
        //time_interval *= ((float64_t)TIME_SEC2USEC);
        //fprintf(p_file, "%f,", time_interval);
        

        if (result != cudaSuccess) 
        {
            std::cerr << "CUTLASS GEMM kernel failed: "
                << cudaGetErrorString(result) << std::endl;

            cudaFree(C_reference);
            cudaFree(C_cutlass);
            cudaFree(B);
            cudaFree(A);

            return result;
        }
    }
/* ==============================================================================
    Brief: Compute the timing values
  ==============================================================================*/
	double time_avg_us = M_time / 1000.0;
	double time_max_us = time_max_ns / 1000.0;
	double variance = S_time / (TIME_MEASUREMENT_LOOPS - INITIAL_TIME_MEASUREMENT);
	double standard_deviation = sqrt(variance) / 1000.0;
	
	//printf("Average time: %.1f us\n", time_avg_us);
	//printf("Maximum time: %.1f us (iteration %lld)\n", time_max_us, iteration_max_time);
	//printf("Standard deviation: %.1f us\n", standard_deviation);
	//printf("%d,%.1f,%.1f,%.1f,%lld\n", threads, time_avg_us, time_max_us, standard_deviation, iteration_max_time);

/* ==============================================================================
    Brief: Store the timing measurements in a file (csv/xlsx)
  ==============================================================================*/
    FILE *p_file;
    char str_file_name[100u];
    char str_file_time[100u];
    char str_file_name_aux[100u] = NAME;
    snprintf(str_file_name, 100,"%d_%d_%d_",DIM_M,DIM_N,DIM_K);
    time_t time_now = time(NULL);

    struct tm *time_info;
    time_info = localtime(&time_now);
    strftime(str_file_time, sizeof(str_file_time), "%m_%d_%H_%M_%S.csv",time_info);
    strcat(str_file_name,str_file_name_aux);


	if ((p_file = fopen(str_file_name, "a")) == NULL)
	{
		fprintf(stderr, "cannot open file '%s'\n", str_file_name);
		return cudaErrorInvalidValue;
	}

	if (!p_file)
	{
		perror("File opening failed");
		return cudaErrorInvalidValue;
	}
  
	fprintf(p_file, "%s,%s,%d,%d,%d,",NAME, str_file_time, DIM_M, DIM_N, DIM_K);
  /*fprintf(p_file, "%.1f,%.1f,%.1f,%.1f,%lld\n", time_avg_us, time_max_us, standard_deviation,variance, iteration_max_time);
  */
  for (size_t j_loop = 0; j_loop < (TIME_MEASUREMENT_LOOPS-INITIAL_TIME_MEASUREMENT); j_loop++)
  {
      fprintf(p_file, "%lu,", timing_values[j_loop]/1000);
  }
  fprintf(p_file,"\n");
  fclose(p_file);


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

  // =================================================================================================
  //                            Launch CUTLASS GEMM.
  // =================================================================================================
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

/* To use with One's complement checksum
	// One's complement checksum 
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
    //printf("ES_a[%i] = %u \t ES_b = %u \t ES_c = %u \n",i,h_ES_a[i],h_ES_b[i],h_ES_c[i]);
  }
    d_ES.A = Ones_Checksum_a.ui32[0];
    d_ES.B = Ones_Checksum_b.ui32[0];
    d_ES.C = Ones_Checksum_c.ui32[0];
printf("Final ES (GPU)\n Es_a =%12u \t Es_b =%12u \t Es_c =%12u \n", d_ES.A, d_ES.B, d_ES.C);
*/

/* To use with Fletcher



// To use with CRC
  for(int uint32_i=0;uint32_i<nElem_ES;uint32_i++){
     //printf("ES_a[%i] = %u \t ES_b = %u \t ES_c = %u \n",i,h_ES_a[i],h_ES_b[i],h_ES_c[i]);
    d_ES.A = singletable_crc32c_ui32(d_ES.A, h_ES_a[uint32_i]);
    d_ES.B = singletable_crc32c_ui32(d_ES.B, h_ES_b[uint32_i]);
    d_ES.C = singletable_crc32c_ui32(d_ES.C, h_ES_c[uint32_i]);
  }
printf("Final ES (GPU)\n Es_a =%12u \t Es_b =%12u \t Es_c =%12u \n", d_ES.A, d_ES.B, d_ES.C);
*/

// Verify that with a sequential implementation we obtain the same value
//h_ES = smm_xor_internal((uint32_t) M,(uint32_t) N,(uint32_t) K, (float32_t) 1.0f, h_a, h_b, h_c);
printf(" Value of &B[0]=%p\n", d_ES_a);
h_ES = smm_ones_internal((uint32_t) M,(uint32_t) N,(uint32_t) K, (float32_t) 1.0f, h_a, h_b, h_c);

//printf("Final ES_b(CPU)\n Es_a =%u \t Es_b =%u \t Es_c =%u \n", h_ES.A, h_ES.B, h_ES.C);

#endif

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

  //
  // Parse the command line to obtain GEMM dimensions and scalar values.
  //

  // GEMM problem dimensions.
  int problem[3] = { DIM_M, DIM_N, DIM_K  };

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

  cudaError_t result = TestCutlassGemm (
    problem[0],     // GEMM M dimension
    problem[1],     // GEMM N dimension
    problem[2],     // GEMM K dimension
    scalars[0],     // alpha
    scalars[1]      // beta
  );

  if (result == cudaSuccess) {
    std::cout << "Passed." << std::endl;
  }
  // Reset Device
  cudaDeviceReset();

  // Exit.
  return result == cudaSuccess ? 0 : -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
