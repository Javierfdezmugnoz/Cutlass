#pragma once

#include "cuda_runtime.h"

/* ==============================================================================================================
* 										    DEFINES
* ============================================================================================================== */
#define UNPROTECTED 0
#define XOR_CHECKSUM 1
#define ONES_CHECKSUM 2
#define TWOS_CHECKSUM 3
#define FLETCHER_CHECKSUM 4
#define CRC_CHECKSUM 5
#define DEFAULT_DIM 128
#define FLET_DIVISOR 255 

#ifndef EXTERNAL_ES
  #define EXTERNAL_ES UNPROTECTED
#endif

#ifndef INTERMEDIATE_ES
  #define INTERMEDIATE_ES UNPROTECTED
#endif

#ifndef INTERNAL_ES
  #define INTERNAL_ES UNPROTECTED
#endif

#ifndef DIM_M
  #define DIM_M DEFAULT_DIM
#endif

#ifndef DIM_N
  #define DIM_N DEFAULT_DIM
#endif

#ifndef DIM_K
  #define DIM_K DEFAULT_DIM
#endif

#if ((INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES))
  extern __shared__ uint32_t d_CRC_table_shared[];
#endif



// extern __constant__ uint32_t d_CRC_table[];

/* ==============================================================================================================
 * 										    TYPEDEFS
 * ============================================================================================================== */
typedef union ui32_to_ui8 {
	uint32_t ui32;
	uint8_t ui8[4];
} ui32_to_ui8_t;

typedef union ui32_to_ui16 {
	uint32_t ui32;
	uint16_t ui16[2];
} ui32_to_ui16_t;


/* ==========================================================================
  Descritption: Addition of two values using PTX (parallel thread execution) 
  and ISA (parallel thread execution with instruction set architecture) adding
  the carry bit. After that, one's complement is implemented (bit negation). 
  Additional info:
  url: https://docs.nvidia.com/cuda/parallel-thread-execution/index.html or
  https://docs.nvidia.com/pdf/ptx_isa_5.0.pdf 
=============================================================================*/
__device__ uint32_t _xor (uint32_t ui32_a, uint32_t ui32_b)
{
    uint32_t acc;
    asm volatile ("xor.b32  %0, %1, %2;\n\t"
                : "=r"(acc)
                : "r"(ui32_a), "r"(ui32_b));
    return acc;
}


/* ==========================================================================
  Descritption: Addition of two values using PTX (parallel thread execution) 
  and ISA (parallel thread execution with instruction set architecture) adding
  the carry bit. After that, one's complement is implemented (bit negation). 
  Additional info:
  url: https://docs.nvidia.com/cuda/parallel-thread-execution/index.html or
  https://docs.nvidia.com/pdf/ptx_isa_5.0.pdf 
=============================================================================*/
__device__ uint32_t __a1c (uint32_t ui32_a, uint32_t ui32_b)
{
    uint32_t acc;
    asm volatile ("add.cc.u32      %0, %1, %2;\n\t"
         "addc.u32        %0, %0, 0;\n\t"
         "not.b32         %0, %0;\n\t"
         : "=r"(acc)
         : "r"(ui32_a), "r"(ui32_b));
    return acc;
}


/* ==========================================================================
  Descritption: Ones complement with atomic instructions
=============================================================================*/
__device__ uint32_t a1c_atomic (uint32_t ui32_a, uint32_t ui32_b)
{
    atomicAdd((uint32_t*) &ui32_a, ui32_b);
    ui32_a = ~ui32_a;
    return ui32_a;
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
__device__ uint32_t __a2c (uint32_t ui32_a, uint32_t ui32_b)
{
    uint32_t acc = 0;
    asm volatile ("add.u32     %0, %1, %2;\n\t"
         "not.b32     %0, %0;\n\t"
         "add.u32     %0, %0, 1;\n\t"
         : "=r"(acc)
         : "r"(ui32_a), "r"(ui32_b));
    return acc;
}

/* ==========================================================================
  Descritption: Two's complement with atomic instructions
=============================================================================*/
__device__ uint32_t a2c_atomic (uint32_t ui32_a, uint32_t ui32_b)
{
    atomicAdd((uint32_t*) &ui32_a, ui32_b);
    ui32_a = ~ui32_a;
    atomicAdd((uint32_t*) &ui32_a, 1u);
    return ui32_a;
}

/* ==========================================================================
  Description: CRC checksum
=============================================================================*/
#if ((INTERNAL_ES==CRC_CHECKSUM) || (INTERMEDIATE_ES==CRC_CHECKSUM) || (CRC_CHECKSUM==EXTERNAL_ES))
__device__  uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data)
  {
    ui32_to_ui8_t u;
    u.ui32 = ui32_data;

    /* 4 bytes*/
    ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u);
    ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u);
    ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u);
    ui32_crc = d_CRC_table_shared[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u);
    return ui32_crc;
  }
#endif

/* ==========================================================================
  Description: Fletcher checksum
=============================================================================*/
__device__ uint32_t Fletcher32c_ui32(uint32_t Prev_Fletcher, uint32_t ui32_data)
{
	  ui32_to_ui16_t v;
    ui32_to_ui16_t Fletcher;
    v.ui32        = ui32_data;
    Fletcher.ui32 = Prev_Fletcher;

	Fletcher.ui16[0] += v.ui16[0];
	Fletcher.ui16[1] += Fletcher.ui16[0];
	Fletcher.ui16[0] += v.ui16[1];
	Fletcher.ui16[1] += Fletcher.ui16[0];
  /*
  Fletcher.ui16[0] = Fletcher.ui16[0] % 255
  Fletcher.ui16[0] = Fletcher.ui16[0] & (FLET_DIVISOR-1)
  */

	Fletcher.ui16[0] %= 255;
	Fletcher.ui16[1] %= 255;

	return Fletcher.ui32;
}


#define CUTLASS_CHECK(status)                                                                    \
  {                                                                                              \
    cutlass::Status error = status;                                                              \
    if (error != cutlass::Status::kSuccess) {                                                    \
      std::cerr << "Got cutlass error: " << cutlassGetStatusString(error) << " at: " << __LINE__ \
                << std::endl;                                                                    \
      exit(EXIT_FAILURE);                                                                        \
    }                                                                                            \
  }

#define CUDA_CHECK(status)                                              \
  {                                                                     \
    cudaError_t error = status;                                         \
    if (error != cudaSuccess) {                                         \
      std::cerr << "Got bad cuda status: " << cudaGetErrorString(error) \
                << " at line: " << __LINE__ << std::endl;               \
      exit(EXIT_FAILURE);                                               \
    }                                                                   \
  }

/*
mkdir build
cp init_cmake.sh build/.
cd build
bash init_cmake $EXTERNAL_ES $INTERMEDIATE_ES $INTERNAL_ES
cd examples/18_Simt
cmake --build . 
./18_Simt
mv Global* ../../../timing_measurements/.
cd ../../../.
rm -rf build
*/