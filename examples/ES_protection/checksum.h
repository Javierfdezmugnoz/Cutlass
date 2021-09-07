#pragma once
#ifndef CHECKSUM_H_
#define CHECKSUM_H_

/* ==============================================================================================================
* 										    INCLUDES
* ============================================================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* ==============================================================================================================
* 										    DEFINES
* ============================================================================================================== */
#define UNPROTECTED 0
#define XOR_CHECKSUM 1
#define ONES_CHECKSUM 2
#define TWOS_CHECKSUM 3
#define FLETCHER_CHECKSUM 4
#define CRC_CHECKSUM 5

#define EXTERNAL_ES UNPROTECTED
#define INTERMEDIATE_ES UNPROTECTED
#define INTERNAL_ES CRC_CHECKSUM

extern __shared__ uint32_t d_CRC_table_shared[];
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



 /* ==============================================================================================================
* 										PROTOTYPES OF LOCAL FUNCTIONS
* ============================================================================================================== */
//__device__ uint32_t __xor (uint32_t ui32_a, uint32_t ui32_b);
extern __device__ uint32_t __a1c (uint32_t ui32_a, uint32_t ui32_b);
extern __device__ uint32_t __a2c (uint32_t ui32_a, uint32_t ui32_b);
extern __device__ uint32_t Fletcher32c_ui32(uint32_t Prev_Fletcher, uint32_t ui32_data);
extern __device__ uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data);

#endif // !SMMM_H_