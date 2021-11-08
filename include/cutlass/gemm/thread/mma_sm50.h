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

#if (INTERNAL_ES!=UNPROTECTED) || (INTERMEDIATE_ES!=UNPROTECTED) || (EXTERNAL_ES!=UNPROTECTED)
  // Shared memory in device memory
    extern __shared__ uint32_t d_ES_a_shared[];
    extern __shared__ uint32_t d_ES_b_shared[];
    extern __shared__ uint32_t d_ES_c_shared[];
#endif

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
    // ,uint32_t *d_ES_a =nullptr,
    // uint32_t *d_ES_b =nullptr,
    // uint32_t *d_ES_c =nullptr
    ) {
    TensorRef<ElementA const, LayoutA> a_ref(
      reinterpret_cast<ElementA const *>(&A), LayoutA::packed({Shape::kM, Shape::kK}));

    TensorRef<ElementB const, LayoutB> b_ref(
      reinterpret_cast<ElementB const *>(&B), LayoutB::packed({Shape::kK, Shape::kN}));

    TensorRef<ElementC, LayoutC> d_ref(
      reinterpret_cast<ElementC *>(&D), LayoutC::packed({ Shape::kM, Shape::kN }));

    MmaOp mma_op;

    // Copy accumulators
    D = C;

    //printf("thread_idx:%u\n",thread_idx);
    // Compute matrix product
    if(thread_idx==0){
      printf("==============================================\n");
      printf("K=%i\t N=%i\t M=%i\n", Shape::kK, Shape::kN, Shape::kM);
    }

    // Definition of the registers where are stored the ES_a,b and c
    #if ((INTERNAL_ES!=UNPROTECTED) || (INTERMEDIATE_ES!=UNPROTECTED) || (EXTERNAL_ES!=UNPROTECTED))
      volatile uint32_t d_ES_a_reg = d_ES_a_shared[thread_idx];
      //  if(thread_idx==0)
       {
         printf("Previous value of d_ES_a_reg=%x\n",d_ES_a_reg);
         printf("==============================================\n");
         __syncthreads();
       }
      uint32_t d_ES_b_reg = d_ES_b_shared[thread_idx];
      uint32_t d_ES_c_reg = d_ES_c_shared[thread_idx];
      //uint32_t probando = 125u;
    #endif

    CUTLASS_PRAGMA_UNROLL
    for (int k = 0; k < Shape::kK; ++k) {
      Array<ElementC, 1> d;
      Array<ElementA, 1> a;
      Array<ElementB, 1> b;
      // if(threadIdx.x==1u){
      //   printf("kK = %u\t kN = %u\t kM=%u\n",Shape::kK,Shape::kN,Shape::kM);
      // }
      CUTLASS_PRAGMA_UNROLL
      for (int n = 0; n < Shape::kN; ++n) {
        CUTLASS_PRAGMA_UNROLL
        for (int m = 0; m < Shape::kM; ++m) {
          int m_serpentine = (n % 2) ? (Shape::kM - 1 - m) : m;
          
          MatrixCoord mn(m_serpentine, n);
          MatrixCoord mk(m_serpentine, k);
          MatrixCoord kn(k, n);

          d[0] = d_ref.at(mn);
          a[0] = a_ref.at(mk);
          b[0] = b_ref.at(kn);
          //printf("m_serpentine: %x, %x, %x\n", (uint32_t) d_ref.at(mn),(uint32_t) a_ref.at(mk),(uint32_t) b_ref.at(kn));
          //mma_op(d, a, b, d);
          
          uint32_t prev;
          mma_op(d, a, b, d); //, d_ES_a, d_ES_b, d_ES_c);

          // DELETE THIS LINE IN THE EXPERIMENTS (USEFULL ONLY IN DEBUG MODE)
          prev=d_ES_a_reg;
          
          #if (INTERNAL_ES==XOR_CHECKSUM)
            #if (INTERMEDIATE_ES!=UNPROTECTED)
                //atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            #endif
            d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
            d_ES_b_reg = _xor((uint32_t) *((uint32_t*) &b[0]), d_ES_b_reg);
            d_ES_c_reg = _xor((uint32_t) *((uint32_t*) &d[0]), d_ES_c_reg);
            // atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            // atomicXor(&d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            // atomicXor(&d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==ONES_CHECKSUM)
            #if (INTERMEDIATE_ES!=UNPROTECTED)
                //d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            #endif
            d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = __a1c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = __a1c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==TWOS_CHECKSUM)
            #if (INTERMEDIATE_ES!=UNPROTECTED)
                //d_ES_a_reg = __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            #endif
            d_ES_a_reg = __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = __a2c(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = __a2c(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==FLETCHER_CHECKSUM)
            #if (INTERMEDIATE_ES!=UNPROTECTED)
                //d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg,(uint32_t) *((uint32_t*) &a[0]));
            #endif
            d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg,(uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = Fletcher32c_ui32(d_ES_b_reg,(uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = Fletcher32c_ui32(d_ES_c_reg,(uint32_t) *((uint32_t*) &d[0]));
          #elif (INTERNAL_ES==CRC_CHECKSUM)
              #if (INTERMEDIATE_ES!=UNPROTECTED)
                  //d_ES_a_reg = singletable_crc32c_ui32(d_ES_a_reg,(uint32_t) *((uint32_t*) &a[0]));
              #endif
            d_ES_a_reg = singletable_crc32c_ui32(d_ES_a_reg,(uint32_t) *((uint32_t*) &a[0]));
            d_ES_b_reg = singletable_crc32c_ui32(d_ES_b_reg,(uint32_t) *((uint32_t*) &b[0]));
            d_ES_c_reg = singletable_crc32c_ui32(d_ES_c_reg,(uint32_t) *((uint32_t*) &d[0]));
          #else
            
          #endif
          // if(thread_idx==0)
          {
            //UNCOMMENT
            //printf("thread_Idx:%2u\t kN:%u, kM:%u, kK=%u, d_ES_a_reg_prev=%8x\t a=%8x \t d_ES_a_reg=%8x\t m_serpentine:%u\t b=%3.0f\t c=%7.0f\t a=%4.0f\n",thread_idx,n, m, k, prev,(uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg, m_serpentine, b[0], d[0], a[0]);
           __syncthreads();
          }
          // if(threadidx.x==0){
          //   printf("thread_Idx:%u\t kN:%u, kM:%u, kK=%u, d_ES_a_reg_prev=%8x\t a=%8x \t d_ES_a_reg=%8x\t m_serpentine:%u\t b=%3.0f\t c=%7.0f\t a=%4.0f\n",thread_idx, n, m, k, prev,(uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg, m_serpentine, b[0], d[0], a[0]);
          // }
          d_ref.at(mn) = d[0];
        }
      // ==============================================================================
      //    Implementation of the execution signature in the Intermediate loop (internal)
      // ==============================================================================
      #if (INTERMEDIATE_ES==UNPROTECTED)
        #if INTERNAL_ES==XOR_CHECKSUM
          d_ES_a_reg = _xor((uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
          //atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          /*if(1u==thread_idx)
          {
            printf("value a=%x \t value xor=%x \n",(uint32_t) *((uint32_t*) &a[0]), d_ES_a_reg);
            atomicXor(&d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
            printf("value xor=%x\n",d_ES_a_reg);
            probando = _xor((uint32_t) *((uint32_t*) &a[0]), probando);
            printf("value a=%u \t value _xor=%u \n",(uint32_t) *((uint32_t*) &a[0]), probando);
          }*/
        #elif INTERNAL_ES==ONES_CHECKSUM
          d_ES_a_reg = __a1c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        #elif INTERNAL_ES==TWOS_CHECKSUM
          d_ES_a_reg =  __a2c(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        #elif INTERNAL_ES==FLETCHER_CHECKSUM
          d_ES_a_reg = Fletcher32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        #elif INTERNAL_ES==CRC_CHECKSUM
          d_ES_a_reg = singletable_crc32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
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
          d_ES_a_reg = singletable_crc32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
          d_ES_b_reg = singletable_crc32c_ui32(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
          d_ES_c_reg = singletable_crc32c_ui32(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
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
        d_ES_a_reg = singletable_crc32c_ui32(d_ES_a_reg, (uint32_t) *((uint32_t*) &a[0]));
        d_ES_b_reg = singletable_crc32c_ui32(d_ES_b_reg, (uint32_t) *((uint32_t*) &b[0]));
        d_ES_c_reg = singletable_crc32c_ui32(d_ES_c_reg, (uint32_t) *((uint32_t*) &d[0]));
      #else
        
      #endif
    }
    #if ((INTERNAL_ES!=UNPROTECTED) || (INTERMEDIATE_ES!=UNPROTECTED) || (EXTERNAL_ES!=UNPROTECTED))
      d_ES_a_shared[thread_idx] = d_ES_a_reg;
      // printf("ES_a[%3u & %3u]=%x \t reg_a=%x\n",threadIdx.x, thread_idx,d_ES_a_shared[threadIdx.x], d_ES_a_reg);
      d_ES_b_shared[thread_idx] = d_ES_b_reg;
      d_ES_c_shared[thread_idx] = d_ES_c_reg;
      __threadfence();
    #endif
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
    // ,uint32_t *d_ES_a =nullptr,
    // uint32_t *d_ES_b =nullptr,
    // uint32_t *d_ES_c =nullptr
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

    mma(D, A, B, C, thread_idx); //,d_ES_a, d_ES_b, d_ES_c);
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace thread
} // namespace gemm
} // namespace cutlass

/////////////////////////////////////////////////////////////////////////////////////////////////
