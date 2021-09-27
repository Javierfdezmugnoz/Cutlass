#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
Compiled by: gcc test.c -o test -O0
*/
#define ARMV8_PMCR_E            (1 << 0) /* Enable all counters */

int main(int argc, char *argv[])
{
  uint32_t val;
  /* setup */
  
  asm volatile("mrs %0, pmcr_el0" : "=r" (val));
  asm volatile("msr pmcr_el0, %0" : : "r" (val|ARMV8_PMCR_E));
  asm volatile("msr pmcntenset_el0, %0" : : "r" (0x80000003));
  asm volatile("msr pmevtyper1_el0, %0" : : "r" (0x8)); // ins retired
  printf("Starting test...\n");
  /*first read*/  
  asm volatile("mrs %0, pmevcntr1_el0" : "=r" (val)); //read
  printf("Value of counter 1: 0x%x\n",val);
  /* sleep */
  sleep(1);
  /* second read */
  asm volatile("mrs %0, pmevcntr1_el0" : "=r" (val)); //read
  if(val == 0){
    printf("Test failed\n value of counter 1 is: 0x%x -> Counter has been disabled!!!\n",val);
  }else{
    printf("Test successful (Value of counter 1 is: 0x%x)\n",val);
     }  
  return 0;
}