#include <stdio.h>
#include <iostream>

typedef float    float32_t;
typedef double   float64_t;
typedef void     void_t;
typedef __uint32_t uint32_t;

__device__ uint32_t __xor (uint32_t ui32_a, uint32_t ui32_b)
{
    uint32_t acc;
    asm ("xor.b32         %0, %1, %2;\n\t"
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
    asm ("add.cc.u32      %0, %1, %2;\n\t"
         "addc.u32        %0, %0, 0;\n\t"
         "not.b32         %0, %0;\n\t"
         : "=r"(acc)
         : "r"(ui32_a), "r"(ui32_b));
    return acc;
}

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


__global__ void kernel_ES (uint32_t *a_val, uint32_t *b_val,uint32_t *ES_val){
    ES_val[0] = __xor(a_val[0],b_val[0]);
    printf("\ta_val: %x \t b_val: %x\t ES_xor = %x\n", (uint32_t) *((uint32_t*) &a_val[0]),(uint32_t) *((uint32_t*) &b_val[0]),(uint32_t) *((uint32_t*) &ES_val[0]));
    ES_val[0] = __a2c(a_val[0],b_val[0]);
    printf("\ta_val: %x \t b_val: %x\t ES_a2  = %x\n", (uint32_t) *((uint32_t*) &a_val[0]),(uint32_t) *((uint32_t*) &b_val[0]),(uint32_t) *((uint32_t*) &ES_val[0]));
    ES_val[0] = __a1c(a_val[0],b_val[0]);
    printf("\ta_val: %x \t b_val: %x\t ES_a1  = %x\n", (uint32_t) *((uint32_t*) &a_val[0]),(uint32_t) *((uint32_t*) &b_val[0]),(uint32_t) *((uint32_t*) &ES_val[0]));

    //*ES_val = __xor((uint32_t) *((uint32_t*) &a_val[0]),(uint32_t) *((uint32_t*) &b_val[0]));
    // *ES_val = __a1c(u32_a_value,u32_b_value);
    return;
}

int main(void){
    // Define pointers to ES_a, ES_b
    uint32_t *h_ES_a;
    uint32_t *h_ES_b;
    uint32_t *h_ES_ES;

    // Allocate h_ES_a and h_ES_b
    h_ES_a = (uint32_t *) malloc(sizeof(uint32_t));
    h_ES_b = (uint32_t *) malloc(sizeof(uint32_t));
    h_ES_ES= (uint32_t *) malloc(sizeof(uint32_t));

    // Initialize values of h_ES_a and h_ES_b
    *h_ES_a = 0xfffeffee;
    *h_ES_b = 0x00101111;
    *h_ES_ES = 0u;    

    // Define pointers to d_ES_a,b
    uint32_t *d_ES_a;
    uint32_t *d_ES_b;
    uint32_t *d_ES_ES;

    // Allocate d_ES_a,b,c in GPU
    cudaError_t result;
    result = cudaMalloc((uint32_t **) &d_ES_a, sizeof(uint32_t));
    if (result != cudaSuccess) {
        std::cerr << "Failed to Allocate d_ES_a: "<< cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        return result;
    }
    result = cudaMalloc((uint32_t **) &d_ES_b, sizeof(uint32_t));
    if (result != cudaSuccess) {
        std::cerr << "Failed to Allocate d_ES_b: "<< cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        return result;
    }

    result = cudaMalloc((uint32_t **) &d_ES_ES, sizeof(uint32_t));
    if (result != cudaSuccess) {
        std::cerr << "Failed to Allocate d_ES_b: "<< cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        return result;
    }

    // Initialize d_ES_a and d_ES_b
    result = cudaMemcpy(d_ES_a, h_ES_a, sizeof(uint32_t), cudaMemcpyHostToDevice);
    if (result != cudaSuccess) {
        std::cerr << "Failed to copy h_ES_a matrix to d_ES_a: " << cudaGetErrorString(result) << std::endl;
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        return result;
    }

    result = cudaMemcpy(d_ES_b, h_ES_b, sizeof(uint32_t), cudaMemcpyHostToDevice);
    if (result != cudaSuccess) 
    {
        cudaFree(d_ES_a);
        cudaFree(d_ES_b);
        return result;
    }


    printf("Here we go!\n");
    dim3 block(1,1,1);
    dim3 grid(1,1,1);
    printf("u32_a_value: %x \tu32_b_value[1]: %x\t Xor = %x\n", *h_ES_b,*h_ES_a,*h_ES_ES);

    kernel_ES<<< grid, block >>>(d_ES_a,d_ES_b,d_ES_ES);
    result= cudaGetLastError();
    if (result != cudaSuccess) {
      std::cerr << "Failed execute kernel_ES" << cudaGetErrorString(result) << std::endl;
      cudaFree(h_ES_a);
      cudaFree(h_ES_b);
      return result;
    }


    // Copy to host the values of the ES of A, B and C performed and stored in the GPU device
    result = cudaMemcpy(h_ES_a, d_ES_a, sizeof(uint32_t), cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_a_DC_a matrix to h_ES_a (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(h_ES_a);
      cudaFree(h_ES_b);
      return result;
    }

    result = cudaMemcpy(h_ES_b, d_ES_b, sizeof(uint32_t), cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_b_DC_a matrix to h_ES_b (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(h_ES_a);
      cudaFree(h_ES_b);
      return result;
    }

    result = cudaMemcpy(h_ES_ES, d_ES_ES, sizeof(uint32_t), cudaMemcpyDeviceToHost);
    if (result != cudaSuccess) {
      std::cerr << "Failed to copy d_ES_b_DC_a matrix to h_ES_b (return)" << cudaGetErrorString(result) << std::endl;
      cudaFree(h_ES_a);
      cudaFree(h_ES_b);
      cudaFree(h_ES_ES);
      return result;
    }
    printf("u32_a_value: %x \tu32_b_value[1]: %x\t Xor = %x\n", h_ES_b[0],h_ES_a[0],h_ES_ES[0]);
    return 0;
}