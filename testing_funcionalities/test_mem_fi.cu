#include <stdio.h>

typedef float    float32_t;
typedef double   float64_t;
typedef void     void_t;
typedef __uint32_t uint32_t;

static void_t mem_fi(float32_t* const paf32_m, uint32_t ui32_bit_idx)
{
	uint32_t ui32_idx_flt = ui32_bit_idx / (sizeof(float32_t)*CHAR_BIT),
		ui32_idx_flt_bit = ui32_bit_idx % (sizeof(float32_t)*CHAR_BIT);
	uint32_t ui32_f_d = *((uint32_t *)&paf32_m[ui32_idx_flt]);

	ui32_f_d ^= (1u << ui32_idx_flt_bit);
	paf32_m[ui32_idx_flt] = *((float32_t *)&ui32_f_d);
}

int main(void){
    float32_t f32_var1[3] = {0};
    for (__uint32_t ui32_loop_i=0; ui32_loop_i<64; ui32_loop_i++)
    {
        printf("value of ui32_var1[0]: %x ui32_var1[1]: %x ui32_var1[2]: %x\n",(uint32_t) *((uint32_t*) &f32_var1[0]), (uint32_t) *((uint32_t*) &f32_var1[1]),(uint32_t) *((uint32_t*) &f32_var1[2]));
        mem_fi(&f32_var1[0],ui32_loop_i);
        printf("value of ui32_var1[0]: %x ui32_var1[1]: %x ui32_var1[2]: %x\n\n",(uint32_t) *((uint32_t*) &f32_var1[0]),(uint32_t) *((uint32_t*) &f32_var1[1]),(uint32_t) *((uint32_t*) &f32_var1[2]));
        mem_fi(&f32_var1[0],ui32_loop_i);
    }
    return 0;
}