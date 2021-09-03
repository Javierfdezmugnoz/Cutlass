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
/*! \file
    \brief Matrix multiply
*/

#pragma once

#include "cutlass/arch/mma.h"
#include "cutlass/complex.h"

#include "cutlass/layout/matrix.h"
#include "cutlass/gemm/gemm.h"

// Included by JFdez
#include "cutlass/gemm/threadblock/mma_pipelined.h"

/* ==========================================================================
  Descritption: Addition of two values using PTX (parallel thread execution) 
  and ISA (parallel thread execution with instruction set architecture) adding
  the carry bit. After that, one's complement is implemented (bit negation). 
  Additional info:
  url: https://docs.nvidia.com/cuda/parallel-thread-execution/index.html or
  https://docs.nvidia.com/pdf/ptx_isa_5.0.pdf 
=============================================================================*/
__device__ uint32_t __a1c (uint32_t a, uint32_t b)
{
    uint32_t acc;
    asm ("add.cc.u32      %0, %1, %2;\n\t"
         "addc.u32        %0, %0, 0;\n\t"
         "not.b32         %0, %0;\n\t"
         : "=r"(acc)
         : "r"(a), "r"(b));
    return acc;
}

/* ==========================================================================
  Description: Addition of two values using PTX (parallel thread execution) 
  and ISA (parallel thread execution with instruction set architecture) with
  not carry-bit addition. This operation is followed by the two's complement
  implementation (bit negation and then, addition of 1)
  Additional info:
  url: https://docs.nvidia.com/cuda/parallel-thread-execution/index.html or
  https://docs.nvidia.com/pdf/ptx_isa_5.0.pdf
=============================================================================*/
__device__ uint32_t __a2c (uint32_t a, uint32_t b)
{
    uint32_t acc = 0;
    asm ("add.u32     %0, %1, %2;\n\t"
         "not.b32     %0, %0;\n\t"
         "add.u32     %0, %0, 1;\n\t"
         : "=r"(acc)
         : "r"(a), "r"(b));
    return acc;
}

typedef union ui32_to_ui8 {
	uint32_t ui32;
	uint8_t ui8[4];
} ui32_to_ui8_t;


/* ==========================================================================
  Description: CRC environment
=============================================================================*/
/*
#define SINGLETABLE_CRC32_UI32(ui32_crc, ui32_data, u) \
    u.ui32 = ui32_data; \
	ui32_crc = d_CRC_table[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = d_CRC_table[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = d_CRC_table[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = d_CRC_table[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
*/
// extern __constant__ uint32_t d_CRC_table[];
extern __shared__ uint32_t d_CRC_table_shared[];
__device__  uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data)
{
	ui32_to_ui8_t u;
	u.ui32 = ui32_data;

	/* 4 bytes*/
  uint32_t prev_ui32_crc = ui32_crc;
	ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u);
  /*printf("prev_ui32_c = %x prev_ui32_c >> 8u = %x value of d_CRC_table[%x & 0x00ffu = %x]: %x \t ui32_crc = %x \n",
                prev_ui32_crc,
                prev_ui32_crc >> 8,
                (prev_ui32_crc ^ u.ui8[0u]), 
                (prev_ui32_crc ^ u.ui8[0u]) & 0x00ffu, 
                d_CRC_table[(prev_ui32_crc ^ u.ui8[0u]) & 0x00ffu],
                d_CRC_table[(prev_ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (prev_ui32_crc >> 8u));*/
	ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u);
  //printf("Shared_Mem[1]= %u\n",d_CRC_table_shared[1]);
  //uint32_t Global_mem, Constant_mem, Shared_mem = 0u;
  //Global_mem = __isGlobal(d_CRC_table);
  //printf(" Global: %3s \n", (Global_mem ? "yes" : "nou"));
  //Shared_mem = __isShared(d_CRC_table);
  //Constant_mem = __isConstant(d_CRC_table);
  //printf("Constant: %3s \t Shared:%3s \t Global: %3s \n",(Constant_mem ? "yes" : "no"),(Shared_mem ? "yes" : "no"),(Global_mem ? "yes" : "no") );
	return ui32_crc;
}


/////////////////////////////////////////////////////////////////////////////////////////////////

namespace cutlass {
namespace arch {

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<gemm::GemmShape<1, 1, 1>, 1, float, LayoutA, float, LayoutB, float, LayoutC, OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAdd;

  CUTLASS_HOST_DEVICE
  void operator()(
  //void operator()(
    Array<float, 1> &d,
    Array<float, 1> const &a,
    Array<float, 1> const &b,
    Array<float, 1> const &c,
    // Included by JFdez
    uint32_t *ES_a =nullptr,
    uint32_t *ES_b =nullptr,
    uint32_t *ES_c =nullptr,
    uint32_t *d_CRC_table = nullptr
  ) {
    //int lane_idx = threadIdx.x % 32;
    d[0] = a[0] * b[0] + c[0];

    ES_a[0] = singletable_crc32c_ui32(ES_a[0],(uint32_t) *((uint32_t*) &a[0]));
    ES_b[0] = singletable_crc32c_ui32(ES_b[0],(uint32_t) *((uint32_t*) &b[0]));
    ES_c[0] = singletable_crc32c_ui32(ES_c[0],(uint32_t) *((uint32_t*) &d[0]));

    // Uncomment the desired Checksum in the internal loop
    /* // XOR checksum
    atomicXor(&ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    atomicXor(&ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    atomicXor(&ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    */

    
    // One's complement
    /* Option 1:
    ES_a[0] = __a1c(ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    ES_b[0] = __a1c(ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    ES_c[0] = __a1c(ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    
    // Option 2:
    atomicAdd((uint32_t*) &ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    atomicAdd((uint32_t*) &ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    atomicAdd((uint32_t*) &ES_c[0], (uint32_t) *((uint32_t*) &d[0]));  

    ES_a[0] =  ~ES_a[0];
    ES_b[0] =  ~ES_b[0];
    ES_c[0] =  ~ES_c[0];
    */
    


    // Two's complement 
    /* Option 1:
    ES_a[0] =  __a2c(ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    ES_b[0] =  __a2c(ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    ES_c[0] =  __a2c(ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    
    // Option 2
    // Two's complement (negation of all values and addition of one)
    atomicAdd((uint32_t*) &ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    atomicAdd((uint32_t*) &ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    atomicAdd((uint32_t*) &ES_c[0], (uint32_t) *((uint32_t*) &d[0]));

    ES_a[0] =  ~ES_a[0];
    ES_b[0] =  ~ES_b[0];
    ES_c[0] =  ~ES_c[0]

    atomicAdd((uint32_t*) &ES_a[0], 1u);
    atomicAdd((uint32_t*) &ES_b[0], 1u);
    atomicAdd((uint32_t*) &ES_c[0], 1u);  
    */

/*
    if(threadIdx.x == 0){
    printf("previous_ES_c:%x \tcurrent_ES_c:%x \tb_value:%x \n", prev_ES_c, ES_c[0], (uint32_t) *((uint32_t*) &c[0]));
//    printf("thread.x:%d \ty:%d \tz:%d \t previous_ES_b:%u \tES_b:%p \tval:%x \tb_value:%x \n",threadIdx.x, threadIdx.y, threadIdx.z, prev_ES_b, ES_b, (uint32_t) *((uint32_t*) &ES_b[0]), (uint32_t) *((uint32_t*) &b[0]));
      //printf("Previous ES_c : %x \t Ones_addition: %x \t d_value=%x \n", prev_ES_c,  ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    }
*/


/* Code Included to test the function __add32
    uint32_t val_a = 4294967295;
    uint32_t val_b = 1;
    uint32_t val_c;
    val_c = 0;
    printf("Before a: %u b: %u c: %u\n",val_a,val_b,val_c);
    val_c = __add32( val_a, val_b);
    printf("Ones a: %u b: %u c: %u\n",val_a,val_b,val_c);
*/
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<gemm::GemmShape<1, 1, 1>, 1, double, LayoutA, double, LayoutB, double, LayoutC, OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAdd;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<double, 1> &d,
    Array<double, 1> const &a,
    Array<double, 1> const &b,
    Array<double, 1> const &c
  ) {

    d[0] = a[0] * b[0] + c[0];
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<gemm::GemmShape<1, 1, 1>, 1, int, LayoutA, int, LayoutB, int, LayoutC, OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAdd;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<int, 1> &d,
    Array<int, 1> const &a,
    Array<int, 1> const &b,
    Array<int, 1> const &c
  ) {

    d[0] = a[0] * b[0] + c[0];
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  complex<float>, 
  LayoutA, 
  complex<float>, 
  LayoutB, 
  complex<float>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<float>, 1> &d,
    Array<complex<float>, 1> const &a,
    Array<complex<float>, 1> const &b,
    Array<complex<float>, 1> const &c
  ) {

    d[0].real() = a[0].real() * b[0].real() + c[0].real();
    d[0].imag() = a[0].imag() * b[0].real() + c[0].imag();
    d[0].real() = -a[0].imag() * b[0].imag() + d[0].real();
    d[0].imag() = a[0].real() * b[0].imag() + d[0].imag();
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  complex<float>, 
  LayoutA, 
  float, 
  LayoutB, 
  complex<float>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<float>, 1> &d,
    Array<complex<float>, 1> const &a,
    Array<float, 1> const &b,
    Array<complex<float>, 1> const &c
  ) {

    d[0].real() = a[0].real() * b[0] + c[0].real();
    d[0].imag() = a[0].imag() * b[0] + c[0].imag();
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  float, 
  LayoutA, 
  complex<float>, 
  LayoutB, 
  complex<float>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<float>, 1> &d,
    Array<float, 1> const &a,
    Array<complex<float>, 1> const &b,
    Array<complex<float>, 1> const &c
  ) {

    d[0].real() = a[0] * b[0].real() + c[0].real();
    d[0].imag() = a[0] * b[0].imag() + d[0].imag();
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  complex<double>, 
  LayoutA, 
  complex<double>, 
  LayoutB, 
  complex<double>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<double>, 1> &d,
    Array<complex<double>, 1> const &a,
    Array<complex<double>, 1> const &b,
    Array<complex<double>, 1> const &c
  ) {

    d[0].real() = a[0].real() * b[0].real() + c[0].real();
    d[0].imag() = a[0].imag() * b[0].real() + c[0].imag();
    d[0].real() = -a[0].imag() * b[0].imag() + d[0].real();
    d[0].imag() = a[0].real() * b[0].imag() + d[0].imag();
  }
};

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  complex<double>, 
  LayoutA, 
  double, 
  LayoutB, 
  complex<double>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<double>, 1> &d,
    Array<complex<double>, 1> const &a,
    Array<double, 1> const &b,
    Array<complex<double>, 1> const &c
  ) {

    d[0].real() = a[0].real() * b[0] + c[0].real();
    d[0].imag() = a[0].imag() * b[0] + c[0].imag();
  }
};

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<
  gemm::GemmShape<1, 1, 1>,
  1,
  double, 
  LayoutA, 
  complex<double>, 
  LayoutB, 
  complex<double>, 
  LayoutC, 
  OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAddComplex;

  CUTLASS_HOST_DEVICE
  void operator()(
    Array<complex<double>, 1> &d,
    Array<double, 1> const &a,
    Array<complex<double>, 1> const &b,
    Array<complex<double>, 1> const &c
  ) {

    d[0].real() = a[0] * b[0].real() + c[0].real();
    d[0].imag() = a[0] * b[0].imag() + d[0].imag();
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Matrix multiply-add operation
template <
  /// Layout of A matrix
  typename LayoutA,
  /// Layout of B matrix
  typename LayoutB,
  /// Layout of C matrix
  typename LayoutC
>
struct Mma<gemm::GemmShape<1, 1, 1>, 1, half_t, LayoutA, half_t, LayoutB, float, LayoutC, OpMultiplyAdd> {

  using Shape = gemm::GemmShape<1, 1, 1>;
  using Operator = OpMultiplyAdd;
  
  CUTLASS_HOST_DEVICE
  void operator()(
    Array<float, 1> &d,
    Array<half_t, 1> const &a,
    Array<half_t, 1> const &b,
    Array<float, 1> const &c
  ) {
    d[0] = float(a[0]) * float(b[0]) + c[0];
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

}
}
