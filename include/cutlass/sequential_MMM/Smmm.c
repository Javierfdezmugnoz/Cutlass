#pragma once

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
#include "Smmm.h"

/* ==============================================================================================================
 * 										MACROS
 * ============================================================================================================== */
#define SINGLETABLE_CRC32_UI32(ui32_crc, ui32_data, u) \
    u.ui32 = ui32_data; \
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u); \
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u); \

 /* ==============================================================================================================
 * 										CONSTS
 * ============================================================================================================== */
const uint32_t kaui32_crc_table[256u] = /*! CRC Look-Up Table; See: web.mit.edu � freebsd � head � sys � libkern � crc32*/
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



/*==============================================================================================================
* 											Experiment 0
==============================================================================================================*/

/* ==============================================================================================================
* 	Name: smm_no_dc
* ============================================================================================================== */
 uint32_t smm_no_dc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i,
		ui32_idx_j,
		ui32_idx_k;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++)
		{
			PUT_IN_REGISTER float32_t A_PART = f32_alpha * paf32_ma[(ui32_idx_i * ui32_k) + ui32_idx_k];
			for (ui32_idx_j = 0u; ui32_idx_j < ui32_n; ui32_idx_j++)
			{
				paf32_mc[(ui32_idx_i * ui32_n) + ui32_idx_j] += A_PART * paf32_mb[(ui32_idx_k * ui32_n) + ui32_idx_j];
			}
		}
	}
	return 0u;
}

/* ==============================================================================================================
* 	Name: smm_no_dc_opt
* ============================================================================================================== */
 uint32_t smm_no_dc_opt(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
     printf("Has arrived\n");
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return 0u;
}

/*==============================================================================================================
* 								 Experiment 1: Individual checksum
==============================================================================================================*/

/*==============================================================================================================
**									Name: smm_xor_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_xor	Return the Execution signature of the MMM
==============================================================================================================*/

 uint32_t smm_xor_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
		ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);
		ui32_xor_b ^= (uint32_t) *((uint32_t*)&f32_b);
		ui32_xor_c ^= (uint32_t) *((uint32_t*)&f32_c);
	}
	ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;
	return ui32_xor;
}

/*==============================================================================================================
**									Name: smm_xor_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
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
 uint32_t smm_xor_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;

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
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			/* XOR checksum */
			ui32_xor_b ^= (uint32_t) *((uint32_t*)&f32_b);
			ui32_xor_c ^= (uint32_t) *((uint32_t*)&f32_c);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;
	return ui32_xor;
}


/*==============================================================================================================
**									Name: smm_xor_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
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
 uint32_t smm_xor_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha,  float32_t*  paf32_ma,  float32_t*  paf32_mb, float32_t *paf32_mc)
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
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;

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
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&f32_b);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&f32_c);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;
	return ui32_xor;
}

/*==============================================================================================================
**									Name: smm_one_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with One's checksum in the external loop
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
 uint32_t smm_ones_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			ui32_idx_b_ref += ui32_n;
		}

		/* One's complement checksum */
		Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
		Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
		Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

		Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&f32_b);
		Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
		Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

		Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&f32_c);
		Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
		Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];

		ui32_idx_c_ref += ui32_n;
	}
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64) + Ones_Checksum_c.ui64;
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	return Ones_Checksum.ui32[0];
}

/*==============================================================================================================
**									Name: smm_one_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with One's checksum in the intermediate loop
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
 uint32_t smm_ones_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			/* One's complement checksum */
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

			Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&f32_b);
			Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
			Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

			Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&f32_c);
			Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
			Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64) + Ones_Checksum_c.ui64;
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	return Ones_Checksum.ui32[0];
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
 uint32_t smm_ones_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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
const
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
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64);
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	Ones_Checksum.ui64 += Ones_Checksum_c.ui64;
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	return Ones_Checksum.ui32[0];
}

/*==============================================================================================================
**									Name: smm_twos_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with Two's checksum in the external loop
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
 uint32_t smm_twos_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum;

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
			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			ui32_idx_b_ref += ui32_n;
		}
		/* Two's complement checksum */
		Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
		Twos_Checksum_a = (~Twos_Checksum_a) + 1;
		Twos_Checksum_b += (uint32_t) * (uint32_t*)&f32_b;
		Twos_Checksum_b = (~Twos_Checksum_b) + 1;
		Twos_Checksum_c += (uint32_t) * (uint32_t*)&f32_c;
		Twos_Checksum_c = (~Twos_Checksum_c) + 1;

		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum = (Twos_Checksum_a + Twos_Checksum_b) + Twos_Checksum_c;
	Twos_Checksum = (~Twos_Checksum) + 1;

	return Twos_Checksum;
}

/*==============================================================================================================
**									Name: smm_twos_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with Two's checksum in the intermediate loop
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
 uint32_t smm_twos_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			/* Two's complement checksum */
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;

			Twos_Checksum_b += (uint32_t) * (uint32_t*)&f32_b;
			Twos_Checksum_b = (~Twos_Checksum_b) + 1;

			Twos_Checksum_c += (uint32_t) * (uint32_t*)&f32_c;
			Twos_Checksum_c = (~Twos_Checksum_c) + 1;

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum = (Twos_Checksum_a + Twos_Checksum_b) + Twos_Checksum_c;
	Twos_Checksum = (~Twos_Checksum) + 1;

	return Twos_Checksum;
}


/* ==============================================================================================================
* 	Name: smm_twos_internal
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with Two's checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_xor	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_twos_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum;

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
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* Two's complement checksum */
				Twos_Checksum_b += (uint32_t) * (uint32_t*)&f32_b;
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;

				Twos_Checksum_c += (uint32_t) * (uint32_t*)&f32_c;
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum = (Twos_Checksum_a + Twos_Checksum_b);
	Twos_Checksum = (~Twos_Checksum) + 1;
	Twos_Checksum = (Twos_Checksum + Twos_Checksum_c);
	Twos_Checksum = (~Twos_Checksum) + 1;
	return Twos_Checksum;
}


/* ==============================================================================================================
* 	Name: smm_fletcher_external
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with Fletcher checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_fletcher_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher_a,
		Fletcher_b,
		Fletcher_c,
		Fletcher;

	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			ui32_idx_b_ref += ui32_n;
		}
		/* Fletcher */
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);
		Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t*)&f32_b);
		Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t*)&f32_c);

		ui32_idx_c_ref += ui32_n;
	}
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Fletcher_c.ui32);
	return Fletcher.ui32;
}

/* ==============================================================================================================
* 	Name: smm_fletcher_intermediate
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with Fletcher checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_fletcher_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher_a,
		Fletcher_b,
		Fletcher_c,
		Fletcher;

	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			/* Fletcher */
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);
			Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t*)&f32_b);
			Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t*)&f32_c);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Fletcher_c.ui32);

	return Fletcher.ui32;
}


/* ==============================================================================================================
* 	Name: smm_fletcher_internal
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with Fletcher checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_fletcher_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher_a,
		Fletcher_b,
		Fletcher_c,
		Fletcher;

	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;

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
			/* Fletcher */
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
				/* Fletcher */
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t*)&f32_b);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t*)&f32_c);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
	Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Fletcher_c.ui32);

	return Fletcher.ui32;
}

/* ==============================================================================================================
* 	Name: smm_crc_external
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with CRC checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_crc_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			ui32_idx_b_ref += ui32_n;
		}
		/* CRC */
		ui32_crc_a = singletable_crc32c_ui32(ui32_crc_a, (uint32_t) * (uint32_t*)&f32_a_part);
		ui32_crc_b = singletable_crc32c_ui32(ui32_crc_b, (uint32_t) * (uint32_t*)&f32_b);
		ui32_crc_c = singletable_crc32c_ui32(ui32_crc_c, (uint32_t) * (uint32_t*)&f32_c);

		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = singletable_crc32c_ui32(ui32_crc_a, ui32_crc_b);
	ui32_crc = singletable_crc32c_ui32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/* ==============================================================================================================
* 	Name: smm_crc_intermediate
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with CRC checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_crc_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

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

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
			}
			/* CRC */
			ui32_crc_a = singletable_crc32c_ui32(ui32_crc_a, (uint32_t) * (uint32_t*)&f32_a_part);
			ui32_crc_b = singletable_crc32c_ui32(ui32_crc_b, (uint32_t) * (uint32_t*)&f32_b);
			ui32_crc_c = singletable_crc32c_ui32(ui32_crc_c, (uint32_t) * (uint32_t*)&f32_c);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = singletable_crc32c_ui32(ui32_crc_a, ui32_crc_b);
	ui32_crc = singletable_crc32c_ui32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}


/* ==============================================================================================================
* 	Name: smm_crc_internal
* ============================================================================================================== */
/*!
** @brief Matrix-matrix multiplication (MMM) with CRC checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_crc_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

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
			ui32_crc_a = singletable_crc32c_ui32(ui32_crc_a, (uint32_t) * (uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
				/* CRC */
				ui32_crc_b = singletable_crc32c_ui32(ui32_crc_b, (uint32_t) * (uint32_t*)&f32_b);
				ui32_crc_c = singletable_crc32c_ui32(ui32_crc_c, (uint32_t) * (uint32_t*)&f32_c);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = singletable_crc32c_ui32(ui32_crc_a, ui32_crc_b);
	ui32_crc = singletable_crc32c_ui32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/*==============================================================================================================
* 											Experiment 2
==============================================================================================================*/
/* ==============================================================================================================
* 	Name: smm_xor_flet (XOR in the internal and Fletcher in the intermediate loop)
* ============================================================================================================== */
 uint32_t smm_xor_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);


	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher;
	Fletcher.ui32 = 0u;


	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];
				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&f32_b);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&f32_c);
			}
			/* XOR checksum */
			ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;

			/* Fletcher checksum */
			Fletcher.ui32 = Fletcher32c_ui32(Fletcher, ui32_xor);
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return Fletcher.ui32;
}


/* ==============================================================================================================
* 	Name: smm_xor_flet (XOR in the internal and CRC in the intermediate loop)
* ============================================================================================================== */
 uint32_t smm_xor_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* CRC */
	uint32_t ui32_crc = INITIAL_REMAINDER;

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;


	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			/* XOR checksum */
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&f32_b);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&f32_c);
			}
			/* XOR checksum */
			ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;

			/* CRC */
			ui32_crc = singletable_crc32c_ui32(ui32_crc, ui32_xor);
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return ui32_crc;
}


/* ==============================================================================================================
* 	Name: smm_ones_flet
* ============================================================================================================== */
 uint32_t smm_ones_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher;
	Fletcher.ui32 = 0;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];

			/* One's complement checksum */
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
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

			}
			/* One's complement checksum */
			Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64) + Ones_Checksum_c.ui64;
			Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
			Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
			/* Fletcher checksum */
			Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Ones_Checksum.ui32[0]);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return Fletcher.ui32;
}



/* ==============================================================================================================
* 	Name: smm_ones_crc
* ============================================================================================================== */
 uint32_t smm_ones_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* CRC */
	uint32_t ui32_crc = INITIAL_REMAINDER;

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];

			/* One's complement checksum */
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
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
			}
			/* One's complement checksum */
			Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64) + Ones_Checksum_c.ui64;
			Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
			Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];

			/* CRC */
			ui32_crc = singletable_crc32c_ui32(ui32_crc, Ones_Checksum.ui32[0]);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return ui32_crc;
}

/* ==============================================================================================================
* 	Name: smm_twos_flet (Two's complement addition in the internal and Fletcher in the intermediate loop)
* ============================================================================================================== */
 uint32_t smm_twos_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum;

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher;
	Fletcher.ui32 = 0;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];

			/* Two's complement checksum */
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* Two's complement checksum */
				Twos_Checksum_b += (uint32_t) * (uint32_t*)&f32_b;
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;
				Twos_Checksum_c += (uint32_t) * (uint32_t*)&f32_c;
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;

			}
			/* Two's complement checksum */
			Twos_Checksum = (Twos_Checksum_a + Twos_Checksum_b) + Twos_Checksum_c;
			Twos_Checksum = (~Twos_Checksum) + 1;

			/* Fletcher checksum */
			Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Twos_Checksum);
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return Fletcher.ui32;
}

/* ==============================================================================================================
* 	Name: smm_twos_crc (Two's complement addition in the internal and CRC in the internal loop)
* ============================================================================================================== */
 uint32_t smm_twos_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* CRC */
	uint32_t ui32_crc = INITIAL_REMAINDER;

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			/* Two's complement checksum */
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;



			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* Two's complement checksum */
				Twos_Checksum_b += (uint32_t) * (uint32_t*)&f32_b;
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;
				Twos_Checksum_c += (uint32_t) * (uint32_t*)&f32_c;
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;
			}
			/* Two's complement checksum */
			Twos_Checksum = (Twos_Checksum_a + Twos_Checksum_b) + Twos_Checksum_c;
			Twos_Checksum = (~Twos_Checksum) + 1;

			/* CRC */
			ui32_crc = singletable_crc32c_ui32(ui32_crc, Twos_Checksum);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return ui32_crc;
}

/* ==============================================================================================================
* 	Name: smm_flet_crc
* ============================================================================================================== */
 uint32_t smm_flet_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
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

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	/* CRC */
	uint32_t ui32_crc = INITIAL_REMAINDER;

	/* Fletcher checksum */
	ui32_to_ui16_t Fletcher_a,
		Fletcher_b,
		Fletcher_c,
		Fletcher;

	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u; ui32_idx_k < ui32_k; ui32_idx_k++, ui32_idx_a++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			/* Fletcher */
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				/* Fletcher */
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t*)&f32_b);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t*)&f32_c);
			}
			Fletcher.ui32 = (Fletcher_a.ui32 ^ Fletcher_b.ui32) ^ Fletcher_c.ui32;

			/* CRC */
			ui32_crc = singletable_crc32c_ui32(ui32_crc, Fletcher.ui32);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return ui32_crc;
}

/*==============================================================================================================
* 	CRC    See: web.mit.edu � freebsd � head � sys � libkern � crc32
* ============================================================================================================== */

/*==============================================================================================================
* 							Fletcher
* ============================================================================================================== */
 inline uint32_t Fletcher32c_ui32(ui32_to_ui16_t Fletcher, uint32_t ui32_data)
{
	ui32_to_ui16_t v;
	v.ui32 = ui32_data;

	Fletcher.ui16[0] += v.ui16[0];
	Fletcher.ui16[1] += Fletcher.ui16[0];
	Fletcher.ui16[0] += v.ui16[1];
	Fletcher.ui16[1] += Fletcher.ui16[0];
	Fletcher.ui16[0] %= 255;
	Fletcher.ui16[1] %= 255;

	return Fletcher.ui32;
}

/*==============================================================================================================
* 							Experiment 3 : Additionals cheksums added by JOP
==============================================================================================================*/

/* ==============================================================================================================
* 	Name: smm_crc_intermediate_comb
* ============================================================================================================== */
 uint32_t smm_crc_intermediate_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i,
		ui32_idx_j,
		ui32_idx_k,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_c_ref = 0u;
	float32_t f32_a_part;
	uint32_t  ui32_XOR = 0u;
	uint32_t  ui32_crc = INITIAL_REMAINDER;
	ui32_to_ui8_t u;

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		for (ui32_idx_k = 0u, ui32_idx_b = 0u; ui32_idx_k < ui32_k; ui32_idx_k++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a++];
			ui32_XOR ^= *((uint32_t *)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				paf32_mc[ui32_idx_c] += (f32_a_part * paf32_mb[ui32_idx_b]);

				ui32_XOR ^= *((uint32_t *)&paf32_mb[ui32_idx_b]);
				ui32_XOR ^= *((uint32_t *)&paf32_mc[ui32_idx_c]);
			}
			/* CRC */
			SINGLETABLE_CRC32_UI32(ui32_crc, ui32_XOR, u);
		}
		ui32_idx_c_ref += ui32_n;
	}

	return ui32_crc;
}


/* ==============================================================================================================
* 	Name: smm_crc_internal
* ============================================================================================================== */
 uint32_t smm_crc_internal_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;
	uint32_t ui32_XOR = 0u;
	uint32_t ui32_crc = INITIAL_REMAINDER;
	ui32_to_ui8_t u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

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
			ui32_XOR ^= *((uint32_t *)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				ui32_XOR ^= *((uint32_t *)&f32_b);
				ui32_XOR ^= *((uint32_t *)&f32_c);

				/* CRC */
				SINGLETABLE_CRC32_UI32(ui32_crc, ui32_XOR, u);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return ui32_crc;
}

 uint32_t smm_comb(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t* const paf32_ma, const float32_t* const paf32_mb, float32_t* const paf32_mc)
{
	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor;
	uint32_t ui32_crc = INITIAL_REMAINDER;
	ui32_to_ui8_t u;

	float32_t f32_a_part = 0.0f,
		f32_b = 0.0f,
		f32_c = 0.0f;

	// Verification of the input values
	assert(paf32_ma != NULL);
	assert(paf32_mb != NULL);
	assert(paf32_mc != NULL);

	for (ui32_idx_i = 0u; ui32_idx_i < ui32_m; ui32_idx_i++)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0u, ui32_idx_b = 0u; ui32_idx_k < ui32_k; ui32_idx_k++)
		{
			PUT_IN_REGISTER f32_a_part = f32_alpha * paf32_ma[ui32_idx_a++];
			ui32_xor_a ^= *((uint32_t *)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < ui32_n; ui32_idx_j++, ui32_idx_b++, ui32_idx_c++)
			{
				f32_b = paf32_mb[ui32_idx_b];
				paf32_mc[ui32_idx_c] += f32_a_part * f32_b;
				f32_c = paf32_mc[ui32_idx_c];

				ui32_xor_b ^= *((uint32_t *)&f32_b);
				ui32_xor_c ^= *((uint32_t *)&f32_c);
			}
			/* CRC */
			ui32_xor = (ui32_xor_a ^ ui32_xor_b) ^ ui32_xor_c;
			SINGLETABLE_CRC32_UI32(ui32_crc, ui32_xor, u);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}

	return ui32_crc;
}
#ifdef AVX
/*==============================================================================================================
* 											Experiment 4
==============================================================================================================*/
/*==============================================================================================================
**									Name: smm_intel_xor_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return __m256  	m256_xor	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_xor_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* XOR checksum */
	/*
	__m256 m256_xor_a = _mm256_setzero_ps(),
		m256_xor_b = _mm256_setzero_ps(),
		m256_xor_c = _mm256_setzero_ps(),
		m256_xor;
	*/
	__m256i m256_xor_a = _mm256_setzero_si256(),
		m256_xor;

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor = 0u;

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}
		m256_xor_a = _mm256_xor_si256(_mm256_castps_si256(a256), _mm256_castps_si256(b256));
		m256_xor = _mm256_xor_si256(_mm256_castps_si256(result256), m256_xor_a);
		ui32_idx_c_ref += ui32_n;
	}
	/*
		// Evaluation of the ES (A value)
		m256_xor_a = _mm256_xor_ps(m256_xor_a, a256);

		// Evaluation of the ES (B value)
		m256_xor_b = _mm256_xor_ps(m256_xor_b, b256);

		// Evaluation of the ES (C value)
		m256_xor_c = _mm256_xor_ps(m256_xor_c, result256);

		ui32_idx_c_ref += ui32_n;
	}
	m256_xor = _mm256_xor_ps(m256_xor_a, m256_xor_b);
	m256_xor = _mm256_xor_ps(m256_xor, m256_xor_c);
		*/
	uint32_t val[8];
	memcpy(val, &m256_xor, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		ui32_xor ^= (uint32_t) *((uint32_t*)&val[ui32_idx_i]);
	}
	return ui32_xor;

}

/*==============================================================================================================
**									Name: smm_intel_xor_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
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
 uint32_t smm_intel_xor_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* XOR checksum */
	__m256i m256_xor_b = _mm256_setzero_si256(),
		m256_xor_c = _mm256_setzero_si256(),
		m256_xor;

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor = 0u;

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			// Evaluation of the ES (A value)
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			// Evaluation of the ES (B value)
			m256_xor_b = _mm256_xor_si256(m256_xor_b, _mm256_castps_si256(b256));

			// Evaluation of the ES (C value)
			m256_xor_c = _mm256_xor_si256(m256_xor_c, _mm256_castps_si256(result256));

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_xor ^= (ui32_xor_b ^ ui32_xor_a) ^ ui32_xor_c;

	m256_xor = _mm256_xor_si256(m256_xor_b, m256_xor_c);

	uint32_t val[8];
	memcpy(val, &m256_xor, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		ui32_xor ^= (uint32_t) *((uint32_t*)&val[ui32_idx_i]);
	}

	return ui32_xor;
}

/*==============================================================================================================
**									Name: smm_intel_xor_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_xor	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_xor_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* XOR checksum */
	__m256i m256_xor_b = _mm256_setzero_si256(),
		m256_xor_c = _mm256_setzero_si256(),
		m256_xor;

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor = 0u;

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			// Evaluation of the ES (A value)
			ui32_xor_a ^= (uint32_t) *((uint32_t*)&f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Evaluation of the ES (B value)
				m256_xor_b = _mm256_xor_si256(m256_xor_b, _mm256_castps_si256(b256));

				// Evaluation of the ES (C value)
				m256_xor_c = _mm256_xor_si256(m256_xor_c, _mm256_castps_si256(result256));
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_xor ^= (ui32_xor_b ^ ui32_xor_a) ^ ui32_xor_c;

	m256_xor = _mm256_xor_si256(m256_xor_b, m256_xor_c);

	uint32_t val[8];
	memcpy(val, &m256_xor, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		ui32_xor ^= (uint32_t) *((uint32_t*)&val[ui32_idx_i]);
	}

	return ui32_xor;
}
/*==============================================================================================================
**									Name: smm_intel_twos_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return __m256  	m256_twos	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_twos_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* Twos checksum */
	__m256i m256i_twos_b = _mm256_setzero_si256(),
		m256i_twos_c = _mm256_setzero_si256(),
		m256i_twos;

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum = 0u;

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256i m256i_singleOne = _mm256_set1_epi32(1);

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}

		// Evaluation of the ES (A value)
		Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
		Twos_Checksum_a = (~Twos_Checksum_a) + 1;

		// Evaluation of the ES (B value)
		m256i_twos_b = _mm256_add_epi32(m256i_twos_b, _mm256_castps_si256(b256));
		m256i_twos_b = _mm256_xor_si256(m256i_twos_b, m256i_Ones);
		m256i_twos_b = _mm256_add_epi32(m256i_twos_b, m256i_singleOne);

		// Evaluation of the ES (C value)
		m256i_twos_c = _mm256_add_epi32(m256i_twos_c, _mm256_castps_si256(result256));
		m256i_twos_c = _mm256_xor_si256(m256i_twos_c, m256i_Ones);
		m256i_twos_c = _mm256_add_epi32(m256i_twos_c, m256i_singleOne);

		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum = Twos_Checksum_a;

	m256i_twos = _mm256_add_epi32(m256i_twos_b, m256i_twos_c);
	m256i_twos = _mm256_xor_si256(m256i_twos, m256i_Ones);
	m256i_twos = _mm256_add_epi32(m256i_twos, m256i_singleOne);

	uint32_t val[8];
	memcpy(val, &m256i_twos, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* Two's complement checksum */
		Twos_Checksum += (uint32_t) * (uint32_t*)&val[ui32_idx_i];
		Twos_Checksum = (~Twos_Checksum) + 1;
	}
	return Twos_Checksum;
}

/*==============================================================================================================
**									Name: smm_intel_twos_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_twos	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_twos_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* Twos checksum */
	__m256i m256i_twos_b = _mm256_setzero_si256(),
		m256i_twos_c = _mm256_setzero_si256(),
		m256i_twos;

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum = 0u;

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256i m256i_singleOne = _mm256_set1_epi32(1);

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
			}

			// Evaluation of the ES (A value)
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;

			// Evaluation of the ES (B value)
			m256i_twos_b = _mm256_add_epi32(m256i_twos_b, _mm256_castps_si256(b256));
			m256i_twos_b = _mm256_xor_si256(m256i_twos_b, m256i_Ones);
			m256i_twos_b = _mm256_add_epi32(m256i_twos_b, m256i_singleOne);

			// Evaluation of the ES (C value)
			m256i_twos_c = _mm256_add_epi32(m256i_twos_c, _mm256_castps_si256(result256));
			m256i_twos_c = _mm256_xor_si256(m256i_twos_c, m256i_Ones);
			m256i_twos_c = _mm256_add_epi32(m256i_twos_c, m256i_singleOne);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum += Twos_Checksum_b + Twos_Checksum_a;
	Twos_Checksum = (~Twos_Checksum) + 1;
	Twos_Checksum += Twos_Checksum_c;
	Twos_Checksum = (~Twos_Checksum) + 1;

	m256i_twos = _mm256_add_epi32(m256i_twos_b, m256i_twos_c);
	m256i_twos = _mm256_xor_si256(m256i_twos, m256i_Ones);
	m256i_twos = _mm256_add_epi32(m256i_twos, m256i_singleOne);

	uint32_t val[8];
	memcpy(val, &m256i_twos, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* Two's complement checksum */
		Twos_Checksum += val[ui32_idx_i];
		Twos_Checksum = (~Twos_Checksum) + 1;
	}

	return Twos_Checksum;
}

/*==============================================================================================================
**									Name: smm_intel_twos_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_twos	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_twos_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	/* Twos checksum */
	__m256i m256i_twos_b = _mm256_setzero_si256(),
		m256i_twos_c = _mm256_setzero_si256(),
		m256i_twos;

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum = 0u;

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256i m256i_singleOne = _mm256_set1_epi32(1);

	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			// Evaluation of the ES (A value)
			Twos_Checksum_a += (uint32_t) * (uint32_t*)&f32_a_part;
			Twos_Checksum_a = (~Twos_Checksum_a) + 1;


			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Evaluation of the ES (B value)
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, _mm256_castps_si256(b256));
				m256i_twos_b = _mm256_xor_si256(m256i_twos_b, m256i_Ones);
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, m256i_singleOne);

				// Evaluation of the ES (C value)
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, _mm256_castps_si256(result256));
				m256i_twos_c = _mm256_xor_si256(m256i_twos_c, m256i_Ones);
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, m256i_singleOne);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* Twos checksum */
				Twos_Checksum_b += (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;
				Twos_Checksum_c += (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Twos_Checksum += Twos_Checksum_b + Twos_Checksum_a;
	Twos_Checksum = (~Twos_Checksum) + 1;
	Twos_Checksum += Twos_Checksum_c;
	Twos_Checksum = (~Twos_Checksum) + 1;

	m256i_twos = _mm256_add_epi32(m256i_twos_b, m256i_twos_c);
	m256i_twos = _mm256_xor_si256(m256i_twos, m256i_Ones);
	m256i_twos = _mm256_add_epi32(m256i_twos, m256i_singleOne);

	uint32_t val[8];
	memcpy(val, &m256i_twos, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* Two's complement checksum */
		Twos_Checksum += val[ui32_idx_i];
		Twos_Checksum = (~Twos_Checksum) + 1;
	}

	return Twos_Checksum;
}

/*==============================================================================================================
**									Name: smm_intel_ones_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return __m256  	m256_ones	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_ones_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Variables to store the ES
	__m256i  Ones_checksum_b_hi = _mm256_setzero_si256(),
		Ones_checksum_b_lo = _mm256_setzero_si256(),
		Ones_checksum_c_hi = _mm256_setzero_si256(),
		Ones_checksum_c_lo = _mm256_setzero_si256();

	__m256i b_aux_lo, b_aux_hi,
		c_aux_lo, c_aux_hi,
		m256i_zeros = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
	Ones_Checksum.ui64 = 0u;

	float f32_a_part;
	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}
			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}
		// Evaluation of the ES (A value)
		Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
		Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
		Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

		// Evaluation of the ES (B value)
		b_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(b256), m256i_zeros);
		Ones_checksum_b_hi = _mm256_add_epi64(Ones_checksum_b_hi, b_aux_hi);
		Ones_checksum_b_hi = _mm256_hadd_epi32(Ones_checksum_b_hi, Ones_checksum_b_hi);
		Ones_checksum_b_hi = _mm256_xor_si256(Ones_checksum_b_hi, m256i_Ones);
		Ones_checksum_b_hi = _mm256_unpackhi_epi32(Ones_checksum_b_hi, m256i_zeros);

		b_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(b256), m256i_zeros);
		Ones_checksum_b_lo = _mm256_add_epi64(Ones_checksum_b_lo, b_aux_lo);
		Ones_checksum_b_lo = _mm256_hadd_epi32(Ones_checksum_b_lo, Ones_checksum_b_lo);
		Ones_checksum_b_lo = _mm256_xor_si256(Ones_checksum_b_lo, m256i_Ones);
		Ones_checksum_b_lo = _mm256_unpackhi_epi32(Ones_checksum_b_lo, m256i_zeros);


		// Evaluation of the ES (C value)
		c_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(result256), m256i_zeros);
		Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, c_aux_hi);
		Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
		Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
		Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);


		c_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(result256), m256i_zeros);
		Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, c_aux_lo);
		Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
		Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
		Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);

		ui32_idx_c_ref += ui32_n;
	}
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64);

	// Evaluation of the ES (C value)
	Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_b_hi);
	Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
	Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);
	Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);

	Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, Ones_checksum_b_lo);
	Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
	Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
	Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);

	uint32_t val[8];
	memcpy(val, &Ones_checksum_c_lo, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}
	memcpy(val, &Ones_checksum_c_hi, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}

	return Ones_Checksum.ui32[0];
}

/*==============================================================================================================
**									Name: smm_intel_ones_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_ones	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_ones_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Variables to store the ES
	__m256i  Ones_checksum_b_hi = _mm256_setzero_si256(),
		Ones_checksum_b_lo = _mm256_setzero_si256(),
		Ones_checksum_c_hi = _mm256_setzero_si256(),
		Ones_checksum_c_lo = _mm256_setzero_si256();

	__m256i b_aux_lo, b_aux_hi,
		c_aux_lo, c_aux_hi,
		m256i_zeros = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
	Ones_Checksum.ui64 = 0u;

	float f32_a_part;
	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			// Evaluation of the ES (A value)
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			// Evaluation of the ES (B value)
			b_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(b256), m256i_zeros);
			Ones_checksum_b_hi = _mm256_add_epi64(Ones_checksum_b_hi, b_aux_hi);
			Ones_checksum_b_hi = _mm256_hadd_epi32(Ones_checksum_b_hi, Ones_checksum_b_hi);
			Ones_checksum_b_hi = _mm256_xor_si256(Ones_checksum_b_hi, m256i_Ones);
			Ones_checksum_b_hi = _mm256_unpackhi_epi32(Ones_checksum_b_hi, m256i_zeros);


			b_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(b256), m256i_zeros);
			Ones_checksum_b_lo = _mm256_add_epi64(Ones_checksum_b_lo, b_aux_lo);
			Ones_checksum_b_lo = _mm256_hadd_epi32(Ones_checksum_b_lo, Ones_checksum_b_lo);
			Ones_checksum_b_lo = _mm256_xor_si256(Ones_checksum_b_lo, m256i_Ones);
			Ones_checksum_b_lo = _mm256_unpackhi_epi32(Ones_checksum_b_lo, m256i_zeros);


			// Evaluation of the ES (C value)
			c_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(result256), m256i_zeros);
			Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, c_aux_hi);
			Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
			Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
			Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);


			c_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(result256), m256i_zeros);
			Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, c_aux_lo);
			Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
			Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
			Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);


			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* One's complement checksum */
				Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
				Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

				Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
				Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	if (0 != (ui32_n % 8)) {
		Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];

		Ones_Checksum.ui64 += Ones_Checksum_c.ui64;
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}
	else {
		Ones_Checksum.ui64 = (Ones_Checksum_a.ui64);
	}

	// Evaluation of the ES (C value)
	Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_b_hi);
	Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
	Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);
	Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);

	Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, Ones_checksum_b_lo);
	Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
	Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
	Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);

	uint32_t val[8];
	memcpy(val, &Ones_checksum_c_lo, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}
	memcpy(val, &Ones_checksum_c_hi, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}

	return Ones_Checksum.ui32[0];
}

/*==============================================================================================================
**									Name: smm_intel_ones_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_ones	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_ones_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Variables to store the ES
	__m256i  Ones_checksum_b_hi = _mm256_setzero_si256(),
		Ones_checksum_b_lo = _mm256_setzero_si256(),
		Ones_checksum_c_hi = _mm256_setzero_si256(),
		Ones_checksum_c_lo = _mm256_setzero_si256();

	__m256i b_aux_lo, b_aux_hi,
		c_aux_lo, c_aux_hi,
		m256i_zeros = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	/* One's complement checksum */
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
	Ones_Checksum.ui64 = 0u;

	float f32_a_part;
	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			// Evaluation of the ES (A value)
			Ones_Checksum_a.ui64 += (uint64_t) * ((uint32_t*)&f32_a_part);
			Ones_Checksum_a.ui32[0] += Ones_Checksum_a.ui32[1];
			Ones_Checksum_a.ui32[0] = ~Ones_Checksum_a.ui32[0];

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Evaluation of the ES (B value)
				b_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_hi = _mm256_add_epi64(Ones_checksum_b_hi, b_aux_hi);
				Ones_checksum_b_hi = _mm256_hadd_epi32(Ones_checksum_b_hi, Ones_checksum_b_hi);
				Ones_checksum_b_hi = _mm256_xor_si256(Ones_checksum_b_hi, m256i_Ones);
				Ones_checksum_b_hi = _mm256_unpackhi_epi32(Ones_checksum_b_hi, m256i_zeros);


				b_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_lo = _mm256_add_epi64(Ones_checksum_b_lo, b_aux_lo);
				Ones_checksum_b_lo = _mm256_hadd_epi32(Ones_checksum_b_lo, Ones_checksum_b_lo);
				Ones_checksum_b_lo = _mm256_xor_si256(Ones_checksum_b_lo, m256i_Ones);
				Ones_checksum_b_lo = _mm256_unpackhi_epi32(Ones_checksum_b_lo, m256i_zeros);


				// Evaluation of the ES (C value)
				c_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, c_aux_hi);
				Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
				Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
				Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);


				c_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, c_aux_lo);
				Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
				Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
				Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* One's complement checksum */
				Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
				Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

				Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
				Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	Ones_Checksum.ui64 = (Ones_Checksum_a.ui64 + Ones_Checksum_b.ui64);
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	Ones_Checksum.ui64 += Ones_Checksum_c.ui64;
	Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
	Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];

	// Evaluation of the ES (C value)
	Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_b_hi);
	Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
	Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
	Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);


	Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, Ones_checksum_b_lo);
	Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
	Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
	Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);


	uint32_t val[8];
	memcpy(val, &Ones_checksum_c_lo, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}
	memcpy(val, &Ones_checksum_c_hi, sizeof(val));
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 8; ui32_idx_i++)
	{
		/* One's complement checksum */
		Ones_Checksum.ui64 += (uint64_t) * ((uint32_t*)&val[ui32_idx_i]);
		Ones_Checksum.ui32[0] += Ones_Checksum.ui32[1];
		Ones_Checksum.ui32[0] = ~Ones_Checksum.ui32[0];
	}

	return Ones_Checksum.ui32[0];
}

/*==============================================================================================================
**									Name: smm_intel_fletcher_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return __m256  	m256_xor	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_fletcher_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Fletcher Checksum with SIMD instructions(B and C)
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher.ui32 = 0u;

	__m256i aux_256i_b, aux_256i_c;
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float f32_a_part;
	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}
			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}
		// Casting of the variables (B and C values)
		aux_256i_b = _mm256_castps_si256(b256);
		aux_256i_c = _mm256_castps_si256(result256);

		// Evaluation of the ES (A value)
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

		// Fletcher computation B
		aux_128i_b_lo = _mm256_extractf128_si256(aux_256i_b, 0);
		aux_128i_b_hi = _mm256_extractf128_si256(aux_256i_b, 1);

		m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
		m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
		m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
		m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


		// Fletcher computation C
		aux_128i_c_lo = _mm256_extractf128_si256(aux_256i_c, 0);
		aux_128i_c_hi = _mm256_extractf128_si256(aux_256i_c, 1);

		m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
		m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
		m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
		m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

		memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
		memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
		memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
		memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
		for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
		{
			Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
			Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
			Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
			val_b_lo[ui32_idx_l] = Fletcher.ui32;
			Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
			Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
			Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
			val_b_hi[ui32_idx_l] = Fletcher.ui32;
			Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
			Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
			Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
			val_c_lo[ui32_idx_l] = Fletcher.ui32;
			Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
			Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
			Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
			val_c_hi[ui32_idx_l] = Fletcher.ui32;
		}
		memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
		memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
		memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
		memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);

		ui32_idx_c_ref += ui32_n;
	}
	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	Fletcher.ui32 = Fletcher_a.ui32;
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}

/*==============================================================================================================
**									Name: smm_intel_fletcher_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_fletcher	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_fletcher_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Fletcher Checksum with SIMD instructions(B and C)
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher.ui32 = 0u;

	__m256i aux_256i_b, aux_256i_c;
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float f32_a_part;
	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			// =====================================================
			//				FLETCHER Intermediate
			// =====================================================
			// Casting of the variables (B and C values)
			aux_256i_b = _mm256_castps_si256(b256);
			aux_256i_c = _mm256_castps_si256(result256);

			// Evaluation of the ES (A value)
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			// Fletcher computation B
			aux_128i_b_lo = _mm256_extractf128_si256(aux_256i_b, 0);
			aux_128i_b_hi = _mm256_extractf128_si256(aux_256i_b, 1);

			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


			// Fletcher computation C
			aux_128i_c_lo = _mm256_extractf128_si256(aux_256i_c, 0);
			aux_128i_c_hi = _mm256_extractf128_si256(aux_256i_c, 1);

			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

			// Fletcher checksum requires a modulo operation. This algebraic operation is not implemented with
			// SIMD instructions, and therefore, it has to be implemented with sequential instructions and it will
			// produce an increment in the performance impact
			memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
			memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
			memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
			memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
			{
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_hi[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_hi[ui32_idx_l] = Fletcher.ui32;
			}
			memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t *)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t *)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	if (0 != (ui32_n % 8)) {
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_c.ui32);
	}

	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	Fletcher.ui32 = Fletcher_a.ui32;
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}

/*==============================================================================================================
**									Name: smm_intel_fletcher_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_fletcher	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_fletcher_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// Fletcher Checksum with SIMD instructions(B and C)
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	// __m128i m128i_mod_255 = _mm_set1_epi32(255);

	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher.ui32 = 0u;

	__m256i aux_256i_b, aux_256i_c;
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float f32_a_part;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Casting of the variables (B and C values)
				aux_256i_b = _mm256_castps_si256(b256);
				aux_256i_c = _mm256_castps_si256(result256);

				// =====================================================
				//				FLETCHER INTERNAL
				// =====================================================
				// Fletcher computation B
				aux_128i_b_lo = _mm256_extractf128_si256(aux_256i_b, 0);
				aux_128i_b_hi = _mm256_extractf128_si256(aux_256i_b, 1);

				m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
				m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
				m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
				m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


				// Fletcher computation C
				aux_128i_c_lo = _mm256_extractf128_si256(aux_256i_c, 0);
				aux_128i_c_hi = _mm256_extractf128_si256(aux_256i_c, 1);

				m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
				m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
				m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
				m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

				// Fletcher checksum requires a modulo operation. This algebraic operation is not implemented with
				// SIMD instructions, and therefore, it has to be implemented with sequential instructions and it will
				// produce an increment in the performance impact
				memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
				memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
				memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
				memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
				for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
				{
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_b_lo[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_b_hi[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_c_lo[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_c_hi[ui32_idx_l] = Fletcher.ui32;
				}
				memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t *)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t *)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			// Evaluation of the ES (A value)
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	if (0 != (ui32_n % 8)) {
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_c.ui32);
	}

	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	Fletcher.ui32 = Fletcher_a.ui32;
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}
/*==============================================================================================================
**									Name: smm_intel_crc_external
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the external loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return __m256  	m256_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_crc_external(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t val_b[8], val_c[8];

	float A_PART;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			A_PART = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(A_PART);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += A_PART * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}
		// Evaluation of the ES (A value)
		ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) * (uint32_t*)&A_PART);

		memcpy(val_b, &b256, sizeof(float32_t) * 8);
		memcpy(val_c, &result256, sizeof(float32_t) * 8);
		for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
		{
			ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
			ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
		}

		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/*==============================================================================================================
**									Name: smm_intel_crc_intermediate
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha Correction factor
** @param[in] paf32_ma 	Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 	Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 	Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_crc_intermediate(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t val_b[8], val_c[8];

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			float A_PART = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(A_PART);

			// Evaluation of the ES (A value)
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) * (uint32_t*)&A_PART);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			memcpy(val_b, &b256, sizeof(val_b));
			memcpy(val_c, &result256, sizeof(val_c));
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
			{
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += A_PART * paf32_mb[ui32_idx_b + ui32_idx_j];
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/*==============================================================================================================
**									Name: smm_intel_crc_internal
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_crc_internal(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	uint32_t val_b[8], val_c[8];

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			float A_PART = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(A_PART);

			// Evaluation of the ES (A value)
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) * (uint32_t*)&A_PART);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				memcpy(val_b, &b256, sizeof(val_b));
				memcpy(val_c, &result256, sizeof(val_c));
				for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
				{
					ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
					ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
				}
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += A_PART * paf32_mb[ui32_idx_b + ui32_idx_j];
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = singletable_crc32c_ui32(ui32_crc_a, ui32_crc_b);
	ui32_crc = singletable_crc32c_ui32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/* ==============================================================================================================
* 	Name: smm_gemm_nn_instrics_intel
* ============================================================================================================== */
 uint32_t smm_gemm_nn_intrincs_intel(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			float A_PART = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(A_PART);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += A_PART * paf32_mb[ui32_idx_b + ui32_idx_j];
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	return 0u;
}

/*==============================================================================================================
**									Name: smm_intel_xor_flet
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_xor	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_xor_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			XOR VARIABLES
	// ==================================
	/* XOR checksum */
	__m256i m256i_xor_b = _mm256_setzero_si256(),
		m256i_xor_c = _mm256_setzero_si256();

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor = 0u;

	// ==================================
	//			FLETCHER VARIABLES
	// ==================================
	/* Fletcher Checksum with SIMD instructions(B and C) */
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;

	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher, Fletcher_aux;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher_aux.ui32 = 0u;
	Fletcher.ui32 = 0u;

	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Evaluation of the ES (B value)
				m256i_xor_b = _mm256_xor_si256(m256i_xor_b, _mm256_castps_si256(b256));

				// Evaluation of the ES (C value)
				m256i_xor_c = _mm256_xor_si256(m256i_xor_c, _mm256_castps_si256(result256));
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			// Fletcher computation A
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			// Fletcher computation B
			aux_128i_b_lo = _mm256_extractf128_si256(m256i_xor_b, 0);
			aux_128i_b_hi = _mm256_extractf128_si256(m256i_xor_b, 1);

			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


			// Fletcher computation C
			aux_128i_c_lo = _mm256_extractf128_si256(m256i_xor_c, 0);
			aux_128i_c_hi = _mm256_extractf128_si256(m256i_xor_c, 1);

			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

			memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
			memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
			memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
			memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
			{
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_hi[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_hi[ui32_idx_l] = Fletcher.ui32;
			}
			memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);

			if (0 != (ui32_n % 8)) {
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, ui32_xor_b);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, ui32_xor_c);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	if (0 != (ui32_n % 8)) {
		printf("I am here again \n\t");
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_c.ui32);
	}

	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	Fletcher = Fletcher_a;
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}

/*==============================================================================================================
**									Name: smm_intel_xor_crc
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with XOR checksum in the internal loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_xor_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			XOR VARIABLES
	// ==================================
	/* XOR checksum */
	__m256i m256i_xor_b = _mm256_setzero_si256(),
		m256i_xor_c = _mm256_setzero_si256();

	/* XOR checksum */
	uint32_t ui32_xor_a = 0u,
		ui32_xor_b = 0u,
		ui32_xor_c = 0u,
		ui32_xor = 0u;

	// ==================================
	//			CRC VARIABLES
	// ==================================
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;
	uint32_t val_b[8], val_c[8];

	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				// =====================================================
				//				INTERNAL XOR
				// =====================================================
				// Evaluation of the ES (B value)
				m256i_xor_b = _mm256_xor_si256(m256i_xor_b, _mm256_castps_si256(b256));

				// Evaluation of the ES (C value)
				m256i_xor_c = _mm256_xor_si256(m256i_xor_c, _mm256_castps_si256(result256));
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* XOR checksum */
				ui32_xor_b ^= (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				ui32_xor_c ^= (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}

			// =====================================================
			//				INTERMEDIATE CRC
			// =====================================================
			memcpy(val_b, &m256i_xor_b, sizeof(val_b));
			memcpy(val_c, &m256i_xor_c, sizeof(val_c));
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
			{
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
			}

			if (0 != (ui32_n % 8)) {
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, ui32_xor_b);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, ui32_xor_c);
			}
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) *((uint32_t*)&f32_a_part));

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/*==============================================================================================================
**									Name: smm_intel_twos_flet
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with TWOS checksum in the internal loop and Fletcher checksum in the
**        intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_twos_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			ONES VARIABLES
	// ==================================
	// AVX variables
	__m256i m256i_twos_b = _mm256_setzero_si256(),
		m256i_twos_c = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256i m256i_singleOne = _mm256_set1_epi32(1);


	// C variables
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum = 0u;

	// ==================================
	//			FLETCHER VARIABLES
	// ==================================
	/* Fletcher Checksum with SIMD instructions(B and C) */
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher, Fletcher_aux;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher_aux.ui32 = 0u;
	Fletcher.ui32 = 0u;


	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				// =====================================================
				//				INTERNAL TWOS
				// =====================================================
				// Evaluation of the ES (B value)
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, _mm256_castps_si256(b256));
				m256i_twos_b = _mm256_xor_si256(m256i_twos_b, m256i_Ones);
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, m256i_singleOne);

				// Evaluation of the ES (C value)
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, _mm256_castps_si256(result256));
				m256i_twos_c = _mm256_xor_si256(m256i_twos_c, m256i_Ones);
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, m256i_singleOne);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];

				/* XOR checksum */
				Twos_Checksum_b += (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;
				Twos_Checksum_c += (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;
			}
			// =====================================================
			//				INTERMEDIATE FLETCHER
			// =====================================================
			// Evaluation of the ES (A value)
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			// Fletcher computation B
			aux_128i_b_lo = _mm256_extractf128_si256(m256i_twos_b, 0);
			aux_128i_b_hi = _mm256_extractf128_si256(m256i_twos_b, 1);

			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


			// Fletcher computation C
			aux_128i_c_lo = _mm256_extractf128_si256(m256i_twos_c, 0);
			aux_128i_c_hi = _mm256_extractf128_si256(m256i_twos_c, 1);

			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

			memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
			memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
			memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
			memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
			{
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_hi[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_hi[ui32_idx_l] = Fletcher.ui32;
			}
			memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);

			if (0 != (ui32_n % 8)) {
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, Twos_Checksum_b);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, Twos_Checksum_c);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	if (0 != (ui32_n % 8)) {
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, Fletcher_c.ui32);
	}
	else
	{
		Fletcher.ui32 = Fletcher_a.ui32;
	}

	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}

/*==============================================================================================================
**									Name: smm_intel_twos_crc
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with TWO's complement checksum in the internal loop and CRC in the
**        intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_twos_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			TWOS VARIABLES
	// ==================================
	__m256i m256i_twos_b = _mm256_setzero_si256(),
		m256i_twos_c = _mm256_setzero_si256();

	/* Two's complement checksum */
	uint32_t Twos_Checksum_a = 0u,
		Twos_Checksum_b = 0u,
		Twos_Checksum_c = 0u,
		Twos_Checksum = 0u;

	__m256i m256i_Ones = _mm256_set1_epi32(-1);
	__m256i m256i_singleOne = _mm256_set1_epi32(1);

	// ==================================
	//			CRC VARIABLES
	// ==================================
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;
	uint32_t val_b[8], val_c[8];

	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				// =====================================================
				//				INTERNAL TWOS
				// =====================================================
				// Evaluation of the ES (B value)
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, _mm256_castps_si256(b256));
				m256i_twos_b = _mm256_xor_si256(m256i_twos_b, m256i_Ones);
				m256i_twos_b = _mm256_add_epi32(m256i_twos_b, m256i_singleOne);

				// Evaluation of the ES (C value)
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, _mm256_castps_si256(result256));
				m256i_twos_c = _mm256_xor_si256(m256i_twos_c, m256i_Ones);
				m256i_twos_c = _mm256_add_epi32(m256i_twos_c, m256i_singleOne);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				/* XOR checksum */
				Twos_Checksum_b += (uint32_t) *((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Twos_Checksum_b = (~Twos_Checksum_b) + 1;
				Twos_Checksum_c += (uint32_t) *((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Twos_Checksum_c = (~Twos_Checksum_c) + 1;
			}
			// =====================================================
			//				INTERMEDIATE CRC
			// =====================================================
			memcpy(val_b, &m256i_twos_b, sizeof(val_b));
			memcpy(val_c, &m256i_twos_c, sizeof(val_c));
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
			{
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
			}

			if (0 != (ui32_n % 8)) {
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, Twos_Checksum_b);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, Twos_Checksum_c);
			}
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) *((uint32_t*)&f32_a_part));

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}


/*==============================================================================================================
**									Name: smm_intel_ones_crc
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with ONES checksum in the internal loop and CRC checksum in the
**        intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	ui32_crc	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_ones_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			ONES VARIABLES
	// ==================================
	// AVX variables
	__m256i  Ones_checksum_b_hi = _mm256_setzero_si256(),
		Ones_checksum_b_lo = _mm256_setzero_si256(),
		Ones_checksum_c_hi = _mm256_setzero_si256(),
		Ones_checksum_c_lo = _mm256_setzero_si256();

	__m256i b_aux_lo, b_aux_hi,
		c_aux_lo, c_aux_hi,
		m256i_zeros = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);

	// C variables
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
	Ones_Checksum.ui64 = 0u;

	// ==================================
	//			CRC VARIABLES
	// ==================================
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;
	uint32_t val_b[8], val_c[8];

	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				// =====================================================
				//				INTERNAL ONES COMPLEMENT
				// =====================================================
				// Evaluation of the ES (B value)
				b_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_hi = _mm256_add_epi64(Ones_checksum_b_hi, b_aux_hi);
				Ones_checksum_b_hi = _mm256_hadd_epi32(Ones_checksum_b_hi, Ones_checksum_b_hi);
				Ones_checksum_b_hi = _mm256_xor_si256(Ones_checksum_b_hi, m256i_Ones);
				Ones_checksum_b_hi = _mm256_unpackhi_epi32(Ones_checksum_b_hi, m256i_zeros);

				b_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_lo = _mm256_add_epi64(Ones_checksum_b_lo, b_aux_lo);
				Ones_checksum_b_lo = _mm256_hadd_epi32(Ones_checksum_b_lo, Ones_checksum_b_lo);
				Ones_checksum_b_lo = _mm256_xor_si256(Ones_checksum_b_lo, m256i_Ones);
				Ones_checksum_b_lo = _mm256_unpackhi_epi32(Ones_checksum_b_lo, m256i_zeros);


				// Evaluation of the ES (C value)
				c_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, c_aux_hi);
				Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
				Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
				Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);

				c_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, c_aux_lo);
				Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
				Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
				Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];

				/* One's complement checksum */
				Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
				Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

				Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
				Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];
			}
			// =====================================================
			//				INTERMEDIATE CRC
			// =====================================================
			// Evaluation of the ES (C value)
			Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_c_lo);
			Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
			Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
			Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);

			Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_b_hi, Ones_checksum_b_lo);
			Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
			Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
			Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);


			memcpy(val_b, &Ones_checksum_c_hi, sizeof(val_b));
			memcpy(val_c, &Ones_checksum_c_lo, sizeof(val_c));
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 8; ui32_idx_l++)
			{
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c[ui32_idx_l]);
			}

			if (0 != (ui32_n % 8)) {
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, Ones_Checksum_b.ui32[0]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, Ones_Checksum_c.ui32[0]);
			}
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) *((uint32_t*)&f32_a_part));

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}

/*==============================================================================================================
**									Name: smm_intel_ones_flet
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with ONES checksum in the internal loop and Fletcher checksum in the
**        intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_ones_flet(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			ONES VARIABLES
	// ==================================
	// AVX variables
	__m256i  Ones_checksum_b_hi = _mm256_setzero_si256(),
		Ones_checksum_b_lo = _mm256_setzero_si256(),
		Ones_checksum_c_hi = _mm256_setzero_si256(),
		Ones_checksum_c_lo = _mm256_setzero_si256();

	__m256i b_aux_lo, b_aux_hi,
		c_aux_lo, c_aux_hi,
		m256i_zeros = _mm256_setzero_si256();

	__m256i m256i_Ones = _mm256_set1_epi32(-1);

	// C variables
	ui64_to_ui32_t Ones_Checksum_a,
		Ones_Checksum_b,
		Ones_Checksum_c,
		Ones_Checksum;

	Ones_Checksum_a.ui64 = 0u;
	Ones_Checksum_b.ui64 = 0u;
	Ones_Checksum_c.ui64 = 0u;
	Ones_Checksum.ui64 = 0u;

	// ==================================
	//			FLETCHER VARIABLES
	// ==================================
	/* Fletcher Checksum with SIMD instructions(B and C) */
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher, Fletcher_aux;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher_aux.ui32 = 0u;
	Fletcher.ui32 = 0u;


	// ==================================
	//			AUX VARIABLES
	// ==================================
	__m256 a256, b256, c256, result256;    // AVX
	float f32_a_part;

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);


				// =====================================================
				//				INTERNAL ONES COMPLEMENT
				// =====================================================
			// Evaluation of the ES (B value)
				b_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_hi = _mm256_add_epi64(Ones_checksum_b_hi, b_aux_hi);
				Ones_checksum_b_hi = _mm256_hadd_epi32(Ones_checksum_b_hi, Ones_checksum_b_hi);
				Ones_checksum_b_hi = _mm256_xor_si256(Ones_checksum_b_hi, m256i_Ones);
				Ones_checksum_b_hi = _mm256_unpackhi_epi32(Ones_checksum_b_hi, m256i_zeros);

				b_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(b256), m256i_zeros);
				Ones_checksum_b_lo = _mm256_add_epi64(Ones_checksum_b_lo, b_aux_lo);
				Ones_checksum_b_lo = _mm256_hadd_epi32(Ones_checksum_b_lo, Ones_checksum_b_lo);
				Ones_checksum_b_lo = _mm256_xor_si256(Ones_checksum_b_lo, m256i_Ones);
				Ones_checksum_b_lo = _mm256_unpackhi_epi32(Ones_checksum_b_lo, m256i_zeros);


				// Evaluation of the ES (C value)
				c_aux_hi = _mm256_unpackhi_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, c_aux_hi);
				Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
				Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
				Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);

				c_aux_lo = _mm256_unpacklo_epi32(_mm256_castps_si256(result256), m256i_zeros);
				Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, c_aux_lo);
				Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
				Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
				Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];

				/* One's complement checksum */
				Ones_Checksum_b.ui64 += (uint64_t) * ((uint32_t*)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Ones_Checksum_b.ui32[0] += Ones_Checksum_b.ui32[1];
				Ones_Checksum_b.ui32[0] = ~Ones_Checksum_b.ui32[0];

				Ones_Checksum_c.ui64 += (uint64_t) * ((uint32_t*)&paf32_mc[ui32_idx_c + ui32_idx_j]);
				Ones_Checksum_c.ui32[0] += Ones_Checksum_c.ui32[1];
				Ones_Checksum_c.ui32[0] = ~Ones_Checksum_c.ui32[0];
			}
			// =====================================================
			//				INTERMEDIATE FLETCHER
			// =====================================================
			// Evaluation of the ES (C value)
			/*Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_b_hi);
			Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
			Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
			Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);

			Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_c_lo, Ones_checksum_b_lo);
			Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
			Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
			Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);
			*/

			// Evaluation of the ES (C value)
			Ones_checksum_c_hi = _mm256_add_epi64(Ones_checksum_c_hi, Ones_checksum_c_lo);
			Ones_checksum_c_hi = _mm256_hadd_epi32(Ones_checksum_c_hi, Ones_checksum_c_hi);
			Ones_checksum_c_hi = _mm256_xor_si256(Ones_checksum_c_hi, m256i_Ones);
			Ones_checksum_c_hi = _mm256_unpackhi_epi32(Ones_checksum_c_hi, m256i_zeros);

			Ones_checksum_c_lo = _mm256_add_epi64(Ones_checksum_b_hi, Ones_checksum_b_lo);
			Ones_checksum_c_lo = _mm256_hadd_epi32(Ones_checksum_c_lo, Ones_checksum_c_lo);
			Ones_checksum_c_lo = _mm256_xor_si256(Ones_checksum_c_lo, m256i_Ones);
			Ones_checksum_c_lo = _mm256_unpackhi_epi32(Ones_checksum_c_lo, m256i_zeros);

			// Evaluation of the ES (A value)
			Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, (uint32_t) * (uint32_t*)&f32_a_part);

			// Fletcher computation B
			aux_128i_b_lo = _mm256_extractf128_si256(Ones_checksum_c_hi, 0);
			aux_128i_b_hi = _mm256_extractf128_si256(Ones_checksum_c_hi, 1);

			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
			m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
			m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


			// Fletcher computation C
			aux_128i_c_lo = _mm256_extractf128_si256(Ones_checksum_c_lo, 0);
			aux_128i_c_hi = _mm256_extractf128_si256(Ones_checksum_c_lo, 1);

			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
			m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
			m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

			memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
			memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
			memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
			memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
			{
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_b_hi[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_lo[ui32_idx_l] = Fletcher.ui32;
				Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
				Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
				Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
				val_c_hi[ui32_idx_l] = Fletcher.ui32;
			}
			memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
			memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);

			if (0 != (ui32_n % 8)) {
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, Ones_Checksum_b.ui32[0]);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, Ones_Checksum_c.ui32[0]);
			}
			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	if (0 != (ui32_n % 8)) {
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_b.ui32);
		Fletcher_a.ui32 = Fletcher32c_ui32(Fletcher_a, Fletcher_c.ui32);
	}

	// Fletcher computation
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_lo);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
	m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, m128i_Fletcher_c_hi);
	m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);

	memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
	memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
	for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
	{
		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_lo[ui32_idx_l] = Fletcher.ui32;

		Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
		Fletcher.ui16[0] %= 255;
		Fletcher.ui16[1] %= 255;
		val_b_hi[ui32_idx_l] = Fletcher.ui32;
	}

	Fletcher.ui32 = Fletcher_a.ui32;
	for (uint32_t ui32_idx_i = 0; ui32_idx_i < 4; ui32_idx_i++)
	{
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_lo[ui32_idx_i]);
		Fletcher.ui32 = Fletcher32c_ui32(Fletcher, val_b_hi[ui32_idx_i]);
	}
	return Fletcher.ui32;
}


/*==============================================================================================================
**									Name: smm_intel_flet_crc
==============================================================================================================*/
/*!
** @brief Matrix-matrix multiplication (MMM) with ONES checksum in the internal loop and Fletcher checksum in the
**        intermediate loop
**
** @param[in] ui32_m 		Number of matrix A rows 								[0…ui32_m]
** @param[in] ui32_n 		Number of matrix B columns 								[0…ui32_n]
** @param[in] ui32_k 		Number of matrix A columns / Number of matrix B rows 	[0…ui32_k]
** @param[in] f32_alpha		Correction factor
** @param[in] paf32_ma 		Pointer to the first position of an array of floats (A matrix direction)
** @param[in] paf32_mb 		Pointer to the first position of an array of floats (B matrix direction)
** @param[in] paf32_mc 		Pointer to the first position of an array of floats (B matrix direction)
**
** @return uint32_t  	Fletcher.ui32	Return the Execution signature of the MMM
==============================================================================================================*/
 uint32_t smm_intel_flet_crc(uint32_t ui32_m, uint32_t ui32_n, uint32_t ui32_k, float32_t f32_alpha, const float32_t * const paf32_ma, const float32_t * const paf32_mb, float32_t * const paf32_mc)
{
	// ==================================
	//			FLETCHER VARIABLES
	// ==================================
	// Fletcher Checksum with SIMD instructions(B and C)
	__m128i m128i_Fletcher_b_lo = _mm_setzero_si128(),
		m128i_Fletcher_b_hi = _mm_setzero_si128(),
		m128i_Fletcher_c_lo = _mm_setzero_si128(),
		m128i_Fletcher_c_hi = _mm_setzero_si128(),
		aux_128i_b_lo, aux_128i_b_hi,
		aux_128i_c_lo, aux_128i_c_hi;
	// __m128i m128i_mod_255 = _mm_set1_epi32(255);

	/* Fletcher checksum sequential */
	ui32_to_ui16_t Fletcher_a, Fletcher_b, Fletcher_c, Fletcher;
	Fletcher_a.ui32 = 0u;
	Fletcher_b.ui32 = 0u;
	Fletcher_c.ui32 = 0u;
	Fletcher.ui32 = 0u;

	uint32_t val_b_lo[4], val_b_hi[4], val_c_lo[4], val_c_hi[4];

	// ==================================
	//			CRC VARIABLES
	// ==================================
	uint32_t ui32_crc_a = INITIAL_REMAINDER,
		ui32_crc_b = INITIAL_REMAINDER,
		ui32_crc_c = INITIAL_REMAINDER,
		ui32_crc = INITIAL_REMAINDER;

	__m256i aux_256i_b, aux_256i_c;
	__m256 a256, b256, c256, result256;    // AVX

	uint32_t ui32_idx_i = 0u,
		ui32_idx_j = 0u,
		ui32_idx_k = 0u,
		ui32_idx_a = 0u,
		ui32_idx_b = 0u,
		ui32_idx_c = 0u,
		ui32_idx_b_ref = 0u,
		ui32_idx_c_ref = 0u;

	float f32_a_part;

	for (ui32_idx_i = 0; ui32_idx_i < ui32_m; ++ui32_idx_i)
	{
		ui32_idx_b_ref = 0u;
		for (ui32_idx_k = 0; ui32_idx_k < ui32_k; ++ui32_idx_k, ui32_idx_a++)
		{
			f32_a_part = f32_alpha * paf32_ma[ui32_idx_a];
			a256 = _mm256_set1_ps(f32_a_part);

			for (ui32_idx_j = 0u, ui32_idx_b = ui32_idx_b_ref, ui32_idx_c = ui32_idx_c_ref; ui32_idx_j < (ui32_n - 8); ui32_idx_j += 8, ui32_idx_b += 8, ui32_idx_c += 8)
			{
				b256 = _mm256_loadu_ps(&paf32_mb[ui32_idx_b]);
				c256 = _mm256_loadu_ps(&paf32_mc[ui32_idx_c]);
				// FMA - Intel Haswell (2013), AMD Piledriver (2012)
				//result256 = _mm256_fmadd_ps(a256, b256, c256);
				result256 = _mm256_mul_ps(a256, b256);

				result256 = _mm256_add_ps(result256, c256);
				_mm256_storeu_ps(&paf32_mc[ui32_idx_c], result256);

				// Casting of the variables (B and C values)
				aux_256i_b = _mm256_castps_si256(b256);
				aux_256i_c = _mm256_castps_si256(result256);


				// =====================================================
				//				FLETCHER INTERNAL
				// =====================================================
				// Fletcher computation B
				aux_128i_b_lo = _mm256_extractf128_si256(aux_256i_b, 0);
				aux_128i_b_hi = _mm256_extractf128_si256(aux_256i_b, 1);

				m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_lo);
				m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);
				m128i_Fletcher_b_lo = _mm_add_epi32(m128i_Fletcher_b_lo, aux_128i_b_hi);
				m128i_Fletcher_b_hi = _mm_add_epi32(m128i_Fletcher_b_hi, m128i_Fletcher_b_lo);


				// Fletcher computation C
				aux_128i_c_lo = _mm256_extractf128_si256(aux_256i_c, 0);
				aux_128i_c_hi = _mm256_extractf128_si256(aux_256i_c, 1);

				m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_lo);
				m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);
				m128i_Fletcher_c_lo = _mm_add_epi32(m128i_Fletcher_c_lo, aux_128i_c_hi);
				m128i_Fletcher_c_hi = _mm_add_epi32(m128i_Fletcher_c_hi, m128i_Fletcher_c_lo);

				// Fletcher checksum requires a modulo operation. This algebraic operation is not implemented with
				// SIMD instructions, and therefore, it has to be implemented with sequential instructions and it will
				// produce an increment in the performance impact
				memcpy(val_b_lo, &m128i_Fletcher_b_lo, sizeof(float32_t) * 4);
				memcpy(val_b_hi, &m128i_Fletcher_b_hi, sizeof(float32_t) * 4);
				memcpy(val_c_lo, &m128i_Fletcher_c_lo, sizeof(float32_t) * 4);
				memcpy(val_c_hi, &m128i_Fletcher_c_hi, sizeof(float32_t) * 4);
				for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
				{
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_b_lo[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_b_hi[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_c_lo[ui32_idx_l] = Fletcher.ui32;
					Fletcher.ui32 = (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l];
					Fletcher.ui16[0] = Fletcher.ui16[0] % 255;
					Fletcher.ui16[1] = Fletcher.ui16[1] % 255;
					val_c_hi[ui32_idx_l] = Fletcher.ui32;
				}
				memcpy(&m128i_Fletcher_b_lo, val_b_lo, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_b_hi, val_b_hi, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_c_lo, val_c_lo, sizeof(float32_t) * 4);
				memcpy(&m128i_Fletcher_c_hi, val_c_hi, sizeof(float32_t) * 4);
			}

			int prev_end = (ui32_n % 8 == 0) ? (ui32_n - 8) : ((ui32_n / 8) * 8);
			for (ui32_idx_j = 0u; ui32_idx_j < (ui32_n - prev_end); ++ui32_idx_j) {
				paf32_mc[ui32_idx_c + ui32_idx_j] += f32_a_part * paf32_mb[ui32_idx_b + ui32_idx_j];
				Fletcher_b.ui32 = Fletcher32c_ui32(Fletcher_b, (uint32_t) * (uint32_t *)&paf32_mb[ui32_idx_b + ui32_idx_j]);
				Fletcher_c.ui32 = Fletcher32c_ui32(Fletcher_c, (uint32_t) * (uint32_t *)&paf32_mc[ui32_idx_c + ui32_idx_j]);
			}
			// =====================================================
			//				INTERMEDIATE CRC
			// =====================================================
			// CRC computation C
			ui32_crc_a = _mm_crc32_u32(ui32_crc_a, (uint32_t) *((uint32_t*)&f32_a_part));

			for (uint32_t ui32_idx_l = 0; ui32_idx_l < 4; ui32_idx_l++)
			{
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b_lo[ui32_idx_l]);
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, (uint32_t) * (uint32_t*)&val_b_hi[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c_lo[ui32_idx_l]);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, (uint32_t) * (uint32_t*)&val_c_hi[ui32_idx_l]);
			}

			if (0 != (ui32_n % 8)) {
				ui32_crc_b = _mm_crc32_u32(ui32_crc_b, Fletcher_b.ui32);
				ui32_crc_c = _mm_crc32_u32(ui32_crc_c, Fletcher_c.ui32);
			}

			ui32_idx_b_ref += ui32_n;
		}
		ui32_idx_c_ref += ui32_n;
	}
	ui32_crc = _mm_crc32_u32(ui32_crc_a, ui32_crc_b);
	ui32_crc = _mm_crc32_u32(ui32_crc, ui32_crc_c);
	return ui32_crc;
}
#endif

/*==============================================================================================================
**		Fault insertion functions:
**	Name: mem_fi
**  Name: mem_fi_random_value
**==============================================================================================================*/

 void_t mem_fi(float32_t* const paf32_m, uint32_t ui32_bit_idx)
{
	uint32_t ui32_idx_flt = ui32_bit_idx / (sizeof(float32_t)*CHAR_BIT),
		ui32_idx_flt_bit = ui32_bit_idx % (sizeof(float32_t)*CHAR_BIT);
	uint32_t ui32_f_d = *((uint32_t *)&paf32_m[ui32_idx_flt]);

	ui32_f_d ^= (1u << ui32_idx_flt_bit);
	paf32_m[ui32_idx_flt] = *((float32_t *)&ui32_f_d);
}

 void_t mem_fi_random_value(float32_t* const paf32_m, uint32_t ui32_max_dim, uint32_t ui32_n_length, bool32_t b32_consecutive)
{
	uint32_t ui32_idx_error,
		ui32_idx;
	uint32_t *pui32_m = (uint32_t *)paf32_m;

	if (b32_consecutive)
	{
		ui32_idx_error = ((uint32_t)rand() % ui32_max_dim);
		//printf("\n ui32_idx_error = %u / %u; ui32_n_length = %u", ui32_idx_error, ui32_max_dim, ui32_n_length);
		for (ui32_idx = 0u; ui32_idx < ui32_n_length; ui32_idx++)
		{
			if ((ui32_idx_error + ui32_idx) < ui32_max_dim)
			{
				//printf("fi-");
				pui32_m[ui32_idx_error + ui32_idx] = (uint32_t)rand();
			}
		}
	}
	else
	{
		for (ui32_idx = 0u; ui32_idx < ui32_n_length; ui32_idx++)
		{
			//printf("fi-");
			ui32_idx_error = ((uint32_t)rand() % ui32_max_dim);
			//printf("\n ui32_idx_error = %u / %u; ", ui32_idx_error, ui32_max_dim);
			pui32_m[ui32_idx_error] = (uint32_t)rand();
		}
	}
}

/*==============================================================================================================
**	Initialization functions:
**	Name: matrix2zeros
**  Name: matrix2rand
**==============================================================================================================*/
 void_t matrix2zeros(float32_t * paf32_matrix, uint32_t ui32_max_rows, uint32_t ui32_max_columns)
{
	uint32_t ui32_idx;

	for (ui32_idx = 0u; ui32_idx < (ui32_max_rows * ui32_max_columns); ui32_idx++)
	{
		*paf32_matrix++ = 0.0f;
	}
}

 void_t matrix2rand(float32_t * paf32_matrix, uint32_t ui32_max_rows, uint32_t ui32_max_columns)
{
	uint32_t ui32_idx;

	for (ui32_idx = 0u; ui32_idx < (ui32_max_rows * ui32_max_columns); ui32_idx++)
	{
		*paf32_matrix++ = (float32_t)rand();
	}
}

 inline uint32_t singletable_crc32c_ui32(uint32_t ui32_crc, uint32_t ui32_data)
{
	ui32_to_ui8_t u;
	u.ui32 = ui32_data;

	/* 4 bytes*/
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[0u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[1u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[2u]) & 0x00ffu] ^ (ui32_crc >> 8u);
	ui32_crc = kaui32_crc_table[(ui32_crc ^ u.ui8[3u]) & 0x00ffu] ^ (ui32_crc >> 8u);

	return ui32_crc;
}
