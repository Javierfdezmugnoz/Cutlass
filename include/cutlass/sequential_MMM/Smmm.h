#pragma once
#ifndef SMMM_H_
#define SMMM_H_


/* ==============================================================================================================
* 												INCLUDES
* ============================================================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdint.h>
#ifdef AVX
	#include <intrin.h>
#endif
#include "assert.h"

/* ==============================================================================================================
* 										DEFINES
* ============================================================================================================== */
#define PUT_IN_REGISTER								 /* dummy definition  for Windows 32 */
#define INITIAL_REMAINDER 	((uint32_t) 0xFFFFFFFF)  /* Initial value of CRC */

#ifndef TRUE
#define TRUE  1u
#define FALSE 0u
#endif

/* ==============================================================================================================
 * 										TYPEDEFS
 * ============================================================================================================== */
typedef float    float32_t;
typedef double   float64_t;
typedef void     void_t;
typedef uint32_t bool32_t;

typedef union ui32_to_ui8 {
	uint32_t ui32;
	uint8_t ui8[4];
} ui32_to_ui8_t;

typedef union ui64_to_ui32 {
	uint64_t ui64;
	uint32_t ui32[2];
} ui64_to_ui32_t;

typedef union ui32_to_ui16 {
	uint32_t ui32;
	uint16_t ui16[2];
} ui32_to_ui16_t;

#ifdef AVX
	typedef union m256i_to_m128i {
		__m256i m512i;
		__m128i m256i[2];
	} m256i_to_m128i_t;
#endif

typedef enum
{
	eSIZE_MIN = 0u,
	eSIZE_20_20,
	eSIZE_40_40,
	eSIZE_80_80,
	eSIZE_160_160,
	eSIZE_320_320,
	eSIZE_640_640,
	eSIZE_MAX
} e_enum_size_2d;

typedef enum
{
	e_FI_VAR_NONE = 0u,
	e_FI_VAR_A,
	e_FI_VAR_B,
	e_FI_VAR_C,
	e_FI_VAR_MAX
} e_fi_var;

/* ==============================================================================================================
* 										PROTOTYPES OF LOCAL FUNCTIONS
* ============================================================================================================== */
 /*e_enum_size_2d process_args(int32_t argc, char *argv[], bool32_t *pb32_time_exp, bool32_t *pb32_dc_exp, bool32_t *pb32_ut_exp, bool32_t *pab32_selected_tech);
 bool32_t execute_unit_test(bool32_t ab32_selected_tech[TECH_MAX], float32_t* const paf32_ma, float32_t* const paf32_mb, float32_t* const paf32_mc, float32_t* const paf32_mc_ref);
 int32_t measure_time(e_enum_size_2d e_size_max, bool32_t ab32_selected_tech[TECH_MAX], float32_t* const paf32_ma, float32_t* const paf32_mb, float32_t* const paf32_mc);
 int32_t measure_dc__error_bit_parallelized(e_enum_size_2d e_size_max, bool32_t ab32_selected_tech[TECH_MAX], bool32_t b32_double_error,
	float32_t* const paf32_ma, float32_t* const paf32_mb, float32_t* const paf32_mc,
	float32_t* const paf32_ma_fi, float32_t* const paf32_mb_fi,
	char *argv[]);
 int32_t measure_dc__error_random_values(e_enum_size_2d e_size_max, bool32_t ab32_selected_tech[TECH_MAX], bool32_t b32_consecutive, uint32_t ui32_n_length, uint32_t ui32_n_iterations,
	float32_t* const paf32_ma, float32_t* const paf32_mb, float32_t* const paf32_mc,
	float32_t* const paf32_ma_fi, float32_t* const paf32_mb_fi,
	float32_t* const paf32_ma_rand, float32_t* const paf32_mb_rand, float32_t* const paf32_mc_rand);
 int32_t measure_dc__error_random_value(e_enum_size_2d e_size_max, bool32_t ab32_selected_tech[TECH_MAX],
	float32_t* const paf32_ma, float32_t* const paf32_mb, float32_t* const paf32_mc,
	float32_t* const paf32_ma_fi, float32_t* const paf32_mb_fi,
	float32_t* const paf32_ma_rand, float32_t* const paf32_mb_rand, float32_t* const paf32_mc_rand);
 void_t print_help_commands(const char *pstr_exec_name);
 */

/* ==============================================================================================================
* 	a) Matrix initialization (matrix2zeros and matrix 2 rand)
*   b) Fault insertion function in an specific and in a random position (mem_fi and mem_fi_random_value)
* ============================================================================================================== */
 void_t mem_fi(float32_t* const paf32_m, uint32_t ui32_bit_idx);
 void_t mem_fi_random_value(float32_t* const paf32_m, uint32_t ui32_max_dim, uint32_t ui32_n_length, bool32_t b32_consecutive);
 void_t matrix2zeros(float32_t  * paf32_matrix, uint32_t ui32_max_rows, uint32_t ui32_max_columns);
 void_t matrix2rand(float32_t  * paf32_matrix, uint32_t ui32_max_rows, uint32_t ui32_max_columns);

/* ==============================================================================================================
* 											Experiment 0 : optimization
==============================================================================================================*/
 uint32_t smm_no_dc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_no_dc_opt(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);

/* ==============================================================================================================
* 											Experiment 1 : individual
==============================================================================================================*/
/* 1.1) XOR */
 uint32_t smm_xor_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_xor_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_xor_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha,  float32_t* paf32_ma,  float32_t* paf32_mb,  float32_t* paf32_mc);
/* 1.2) 1's complement */
 uint32_t smm_ones_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_ones_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_ones_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
/* 1.3) 2's complement */
 uint32_t smm_twos_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_twos_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_twos_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
/* 1.4) Fletcher */
 uint32_t smm_fletcher_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_fletcher_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_fletcher_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 inline uint32_t Fletcher32c_ui32(ui32_to_ui16_t Fletcher, uint32_t ui32_data);
/* 1.5) CRC */
 uint32_t smm_crc_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_crc_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_crc_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 inline uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data);

/*==============================================================================================================
* 											Experiment 2 : combinations 1.0
==============================================================================================================*/
 uint32_t smm_xor_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_xor_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_twos_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_twos_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_ones_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_ones_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_flet_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);


/*==============================================================================================================
* 											Experiment 3 : combinations 2.0 (JoP)
==============================================================================================================*/
 uint32_t smm_crc_intermediate_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_crc_internal_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
 uint32_t smm_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);

/*==============================================================================================================
* 											Experiment 4 : AVX intel
==============================================================================================================*/
#ifdef AVX
	uint32_t smm_gemm_nn_intrincs_intel(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_xor_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_xor_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_xor_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_twos_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_twos_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_twos_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_ones_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_ones_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_ones_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_fletcher_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_fletcher_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_fletcher_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_crc_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_crc_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_crc_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_xor_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_xor_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_twos_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_twos_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_ones_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_ones_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
	uint32_t smm_intel_flet_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc);
#endif

#endif // !SMMM_H_
