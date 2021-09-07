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
//#include "../../examples/ES_protection/checksum.h"
//#include "../../examples/ES_protection/checksum.h"
//#include "checksum.h"
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

    //printf("\n Value of EXTERNAL:%d INTERMEDIATE:%d INTERNAL: %d \n",EXTERNAL_ES, INTERMEDIATE_ES, INTERNAL_ES);
    #if INTERNAL_ES ==  XOR_CHECKSUM
      atomicXor(&ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
      atomicXor(&ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
      atomicXor(&ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    #elif INTERNAL_ES == ONES_CHECKSUM
      ES_a[0] = __a1c(ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
      ES_b[0] = __a1c(ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
      ES_c[0] = __a1c(ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    #elif INTERNAL_ES == TWOS_CHECKSUM
      ES_a[0] =  __a2c(ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
      ES_b[0] =  __a2c(ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
      ES_c[0] =  __a2c(ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    #elif INTERNAL_ES == FLETCHER_CHECKSUM
      ES_a[0] = Fletcher32c_ui32(ES_a[0],(uint32_t) *((uint32_t*) &a[0]));
      ES_b[0] = Fletcher32c_ui32(ES_b[0],(uint32_t) *((uint32_t*) &b[0]));
      ES_c[0] = Fletcher32c_ui32(ES_c[0],(uint32_t) *((uint32_t*) &d[0]));
    #elif INTERNAL_ES == CRC_CHECKSUM
      ES_a[0] = singletable_crc32c_ui32(ES_a[0],(uint32_t) *((uint32_t*) &a[0]));
      ES_b[0] = singletable_crc32c_ui32(ES_b[0],(uint32_t) *((uint32_t*) &b[0]));
      ES_c[0] = singletable_crc32c_ui32(ES_c[0],(uint32_t) *((uint32_t*) &d[0]));
    #else
      
    #endif

    

    // Uncomment the desired Checksum in the internal loop
    /* // XOR checksum
    atomicXor(&ES_a[0], (uint32_t) *((uint32_t*) &a[0]));
    atomicXor(&ES_b[0], (uint32_t) *((uint32_t*) &b[0]));
    atomicXor(&ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    */


/*
    if(threadIdx.x == 0){
    printf("previous_ES_c:%x \tcurrent_ES_c:%x \tb_value:%x \n", prev_ES_c, ES_c[0], (uint32_t) *((uint32_t*) &c[0]));
//    printf("thread.x:%d \ty:%d \tz:%d \t previous_ES_b:%u \tES_b:%p \tval:%x \tb_value:%x \n",threadIdx.x, threadIdx.y, threadIdx.z, prev_ES_b, ES_b, (uint32_t) *((uint32_t*) &ES_b[0]), (uint32_t) *((uint32_t*) &b[0]));
      //printf("Previous ES_c : %x \t Ones_addition: %x \t d_value=%x \n", prev_ES_c,  ES_c[0], (uint32_t) *((uint32_t*) &d[0]));
    }
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
