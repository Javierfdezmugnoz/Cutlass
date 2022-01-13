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
    \brief Templates exposing architecture support for multiply-add operations
*/

#pragma once

#include "cutlass/cutlass.h"
#include "cutlass/tensor_ref.h"
#include "cutlass/layout/matrix.h"
#include "cutlass/arch/mma.h"
#include "cutlass/gemm/gemm.h"
#include "cutlass/gemm/thread/mma.h"
#include "helper.h"

//#include "../../examples/ES_protection/checksum.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace cutlass {
namespace gemm {
namespace thread {

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Gemplate that handles all packed matrix layouts
template <
  /// Size of the Gemm problem - concept: gemm::GemmShape<>
  typename Shape_,
  /// Data type of A elements
  typename ElementA_,
  /// Layout of A matrix (concept: layout::MapFunc)
  typename LayoutA_,
  /// Data type of B elements
  typename ElementB_,
  /// Layout of B matrix (concept: layout::MapFunc)
  typename LayoutB_,
  /// Element type of C matrix
  typename ElementC_,
  /// Layout of C matrix (concept: layout::MapFunc)
  typename LayoutC_,
  /// Operator used to compute GEMM
  typename Operator_
>
struct MmaGeneric {

  /// Size of the Gemm problem - concept: gemm::GemmShape<>
  using Shape = Shape_;

  /// Data type of operand A
  using ElementA = ElementA_;

  /// Layout of A matrix (concept: layout::MapFunc)
  using LayoutA = LayoutA_;

  /// Data type of operand B
  using ElementB = ElementB_;

  /// Layout of B matrix (concept: layout::MapFunc)
  using LayoutB = LayoutB_;

  /// Element type of operand C
  using ElementC = ElementC_;

  /// Layout of C matrix (concept: layout::MapFunc)
  using LayoutC = LayoutC_;

  /// Underlying mathematical operator
  using Operator = Operator_;

  /// A operand storage
  using FragmentA = Array<ElementA, Shape::kMK>;

  /// B operand storage
  using FragmentB = Array<ElementB, Shape::kKN>;

  /// C operand storage
  using FragmentC = Array<ElementC, Shape::kMN>;

  /// Instruction
  using MmaOp = arch::Mma<
    gemm::GemmShape<1,1,1>,
    1,
    ElementA, LayoutA,
    ElementB, LayoutB,
    ElementC, LayoutC,
    Operator>;

  //
  // Methods
  //

  /// Computes a matrix product D = A * B + C
  CUTLASS_HOST_DEVICE
  void operator()(
 // uint32_t* operator()(
    FragmentC & D,
    FragmentA const & A,
    FragmentB const & B,
    FragmentC const & C,
    uint32_t thread_idx
    ,uint32_t *d_ES_a =nullptr,
    uint32_t *d_ES_b =nullptr,
    uint32_t *d_ES_c =nullptr
    #if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
      ,uint32_t *d_CRC_shared = nullptr
    #endif
    )
    {
    TensorRef<ElementA const, LayoutA> a_ref(
      reinterpret_cast<ElementA const *>(&A), LayoutA::packed({Shape::kM, Shape::kK}));

    TensorRef<ElementB const, LayoutB> b_ref(
      reinterpret_cast<ElementB const *>(&B), LayoutB::packed({Shape::kK, Shape::kN}));

    TensorRef<ElementC, LayoutC> d_ref(
      reinterpret_cast<ElementC *>(&D), LayoutC::packed({ Shape::kM, Shape::kN }));

    MmaOp mma_op;

    // Copy accumulators
    D = C;

    // Definition of the registers where are stored the ES_a,b and c
    #if ((INTERNAL_ES!=UNPROTECTED) || (INTERMEDIATE_ES!=UNPROTECTED) || (EXTERNAL_ES!=UNPROTECTED))
      uint32_t d_ES_a_reg = 0u;
      uint32_t d_ES_b_reg = 0u;
      uint32_t d_ES_c_reg = 0u;
      uint32_t prev       = 0u;
      d_ES_a_reg = d_ES_a[thread_idx];
      d_ES_b_reg = d_ES_b[thread_idx];
      d_ES_c_reg = d_ES_c[thread_idx];
      prev = 0u;
      // if(thread_idx==0u){
      //   printf("Initially: d_ES_a[%u]=%u\t d_ES_a_reg=%u \td_ES_a_reg_prev=%u\n",thread_idx, d_ES_a[thread_idx],d_ES_a_reg, prev);
      // }
    #endif

    CUTLASS_PRAGMA_UNROLL
    for (int k = 0; k < Shape::kK; ++k) {
      Array<ElementC, 1> d;
      Array<ElementA, 1> a;
      Array<ElementB, 1> b;

      CUTLASS_PRAGMA_UNROLL
      for (int n = 0; n < Shape::kN; ++n) {
        CUTLASS_PRAGMA_UNROLL
        for (int m = 0; m < Shape::kM; ++m) {
          int m_serpentine = (n&1) ? (Shape::kM - 1 - m) : m;

          MatrixCoord mn(m_serpentine, n);
          MatrixCoord mk(m_serpentine, k);
          MatrixCoord kn(k, n);

          d[0] = d_ref.at(mn);
          a[0] = a_ref.at(mk);
          b[0] = b_ref.at(kn);

          mma_op(d, a, b, d);

           d_ref.at(mn) = d[0];      

          #if (INTERNAL_ES==XOR_CHECKSUM)
            d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
            d_ES_b_reg = _xor((uint32_t) *((uint32_t*) &b[0]), d_ES_b_reg);
            d_ES_c_reg = _xor((uint32_t) *((uint32_t*) &d[0]), d_ES_c_reg);
          #elif (INTERNAL_ES==ONES_CHECKSUM)
            d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = __a1c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = __a1c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==TWOS_CHECKSUM)
            d_ES_a_reg = __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = __a2c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = __a2c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==FLETCHER_CHECKSUM)
            d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg,(uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = Fletcher32c_ui32(d_ES_b_reg,(uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = Fletcher32c_ui32(d_ES_c_reg,(uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==CRC_CHECKSUM)
            d_ES_a_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));            
            d_ES_b_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #else

          #endif
                    
          if(thread_idx==0u){
            // printf("ES_b_prev:%u\t a_value=%0.0f\t b_value=%0.0f\t ES_b_reg=%u\n",prev, a[0], b[0], d_ES_b_reg);
            //printf("kK = %u\t kN = %u\t kM=%u\t",Shape::kK,Shape::kN,Shape::kM);
          }
        }
      // prev=d_ES_b_reg;
      // ==============================================================================
      //    Implementation of the execution signature in the Intermediate loop (internal)
      // ==============================================================================
      //prev=d_ES_a_reg;
      #if (INTERMEDIATE_ES==UNPROTECTED)
        #if INTERNAL_ES==XOR_CHECKSUM
          d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
          d_ES_b_reg = _xor((uint32_t) *((uint32_t*) &b[0]), d_ES_b_reg);
        #elif INTERNAL_ES==ONES_CHECKSUM
          d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          d_ES_b_reg = __a1c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        #elif INTERNAL_ES==TWOS_CHECKSUM
          d_ES_a_reg =  __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          d_ES_b_reg =  __a2c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        #elif INTERNAL_ES==FLETCHER_CHECKSUM
          d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          d_ES_b_reg = Fletcher32c_ui32(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        #elif INTERNAL_ES==CRC_CHECKSUM
          d_ES_a_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          d_ES_b_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        #else

        #endif
      #endif

      // ==============================================================================
      //    Implementation of the execution signature in the Intermediate loop
      // ==============================================================================
      #if INTERMEDIATE_ES==XOR_CHECKSUM
        // atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        // atomicXor(&d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        // atomicXor(&d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
        d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
        d_ES_b_reg = _xor((uint32_t) *((uint32_t*) &b[0]), d_ES_b_reg);
        d_ES_c_reg = _xor((uint32_t) *((uint32_t*) &d[0]), d_ES_c_reg);
      #elif INTERMEDIATE_ES==ONES_CHECKSUM
        d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg = __a1c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = __a1c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif INTERMEDIATE_ES==TWOS_CHECKSUM
        d_ES_a_reg =  __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg =  __a2c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg =  __a2c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif INTERMEDIATE_ES==FLETCHER_CHECKSUM
        d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg = Fletcher32c_ui32(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = Fletcher32c_ui32(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif INTERMEDIATE_ES==CRC_CHECKSUM
        d_ES_a_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));            
        d_ES_b_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #else

      #endif
      }
      // ==============================================================================
      //    Implementation of the execution signature in the External loop
      // ==============================================================================
      #if (EXTERNAL_ES==XOR_CHECKSUM)
        // atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        // atomicXor(&d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        // atomicXor(&d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
        d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
        d_ES_b_reg = _xor((uint32_t) *((uint32_t*) &b[0]), d_ES_b_reg);
        d_ES_c_reg = _xor((uint32_t) *((uint32_t*) &d[0]), d_ES_c_reg);
      #elif (EXTERNAL_ES==ONES_CHECKSUM)
        d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg = __a1c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = __a1c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif (EXTERNAL_ES==TWOS_CHECKSUM)
        d_ES_a_reg =  __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg =  __a2c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg =  __a2c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif (EXTERNAL_ES==FLETCHER_CHECKSUM)
        d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg = Fletcher32c_ui32(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = Fletcher32c_ui32(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #elif (EXTERNAL_ES==CRC_CHECKSUM)
        d_ES_a_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));            
        d_ES_b_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = singletable_crc32c_ui32(d_CRC_shared, d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #else

      #endif
    }
    #if ((INTERNAL_ES!=UNPROTECTED) || (INTERMEDIATE_ES!=UNPROTECTED) || (EXTERNAL_ES!=UNPROTECTED))
      /* =================================================================================
        Memory copy of ES_a,b and c values from shared GPU memory to Global GPU memory
      ==================================================================================== */
      d_ES_a[thread_idx] = d_ES_a_reg;
      d_ES_b[thread_idx] = d_ES_b_reg;
      d_ES_c[thread_idx] = d_ES_c_reg;
      __syncthreads();
    #endif
    // if(threadIdx.x==0){
    //    printf("CRC[1]=%x\n",d_CRC_shared[1],thread_idx_);
    // }
  }
};


/////////////////////////////////////////////////////////////////////////////////////////////////

/// Gemplate that handles conventional layouts for FFMA and DFMA GEMM
template <
  /// Size of the Gemm problem - concept: gemm::GemmShape<>
  typename Shape_,
  /// Data type of A elements
  typename ElementA_,
  /// Layout of A matrix (concept: layout::MapFunc)
  typename LayoutA_,
  /// Data type of B elements
  typename ElementB_,
  /// Layout of B matrix (concept: layout::MapFunc)
  typename LayoutB_,
  /// Element type of C matrix
  typename ElementC_,
  /// Layout of C matrix (concept: layout::MapFunc)
  typename LayoutC_
>
struct Mma<
  Shape_,
  ElementA_,
  LayoutA_,
  ElementB_,
  LayoutB_,
  ElementC_,
  LayoutC_,
  arch::OpMultiplyAdd,
  bool> {

  /// Size of the Gemm problem - concept: gemm::GemmShape<>
  using Shape = Shape_;

  /// Data type of operand A
  using ElementA = ElementA_;

  /// Layout of A matrix (concept: layout::MapFunc)
  using LayoutA = LayoutA_;

  /// Data type of operand B
  using ElementB = ElementB_;

  /// Layout of B matrix (concept: layout::MapFunc)
  using LayoutB = LayoutB_;

  /// Element type of operand C
  using ElementC = ElementC_;

  /// Layout of C matrix (concept: layout::MapFunc)
  using LayoutC = LayoutC_;

  /// Underlying mathematical operator
  using Operator = arch::OpMultiplyAdd;

  /// A operand storage
  using FragmentA = Array<ElementA, Shape::kMK>;

  /// B operand storage
  using FragmentB = Array<ElementB, Shape::kKN>;

  /// C operand storage
  using FragmentC = Array<ElementC, Shape::kMN>;

  /// Underlying matrix multiply operator (concept: arch::Mma)
  using ArchMmaOperator = typename MmaGeneric<
                                    Shape,
                                    ElementA,
                                    LayoutA,
                                    ElementB,
                                    LayoutB,
                                    ElementC,
                                    LayoutC,
                                    Operator>::MmaOp;
  //
  // Methods
  //

  /// Computes a matrix product D = A * B + C
  CUTLASS_HOST_DEVICE
  void operator()(
    FragmentC & D,
    FragmentA const & A,
    FragmentB const & B,
    FragmentC const & C,
    uint32_t thread_idx
    ,uint32_t *d_ES_a =nullptr,
    uint32_t *d_ES_b =nullptr,
    uint32_t *d_ES_c =nullptr
    #if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
      , uint32_t *d_CRC_shared =nullptr
    #endif
    ) {

    MmaGeneric<
      Shape,
      ElementA,
      LayoutA,
      ElementB,
      LayoutB,
      ElementC,
      LayoutC,
      Operator> mma;

    #if (INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES)
      mma(D, A, B, C, thread_idx, d_ES_a, d_ES_b, d_ES_c,d_CRC_shared);
    #else
      mma(D, A, B, C, thread_idx, d_ES_a, d_ES_b, d_ES_c);
    #endif
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace thread
} // namespace gemm
} // namespace cutlass

/////////////////////////////////////////////////////////////////////////////////////////////////
