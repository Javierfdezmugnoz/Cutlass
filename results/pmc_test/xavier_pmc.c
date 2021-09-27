#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// github: https://github.com/zhiyisun/enable_arm_pmu/blob/dev/ko/enable_arm_pmu.c

#define ARMV8_PMEVTYPER_EVTCOUNT_MASK  0x3ff
#define ARMV8_PMCR_E                (1 << 0)      /*  Enable all counters */
#define ARMV8_PMCNTENSET_EL0_ENABLE (1<<31)       /* *< Enable Perf count reg */
#define ARMV8_PMUSERENR_EN_EL0      (1 << 0)      /*  EL0 access enable */
#define ARMV8_PMUSERENR_ER          (1 << 3)     /*  Event counter read enable */
#define ARMV8_PMUSERENR_CR          (1 << 2)     /*  Cycle counter read enable */
int main(int argc, char *argv[])
{
/*Enable user-mode access to counters. */
asm volatile("msr pmuserenr_el0, %0" : : "r"((a64l)ARMV8_PMUSERENR_EN_EL0|ARMV8_PMUSERENR_ER|ARMV8_PMUSERENR_CR));

/*   Performance Monitors Count Enable Set register bit 30:0 disable, 31 enable. Can also enable other event counters here. */ 
asm volatile("msr pmcntenset_el0, %0" : : "r" (ARMV8_PMCNTENSET_EL0_ENABLE));

/* Enable counters */
uint64_t val=0;
asm volatile("mrs %0, pmcr_el0" : "=r" (val));
asm volatile("msr pmcr_el0, %0" : : "r" (val|ARMV8_PMCR_E));



uint32_t r = 0;
/* Access cycle counter */
asm volatile("mrs %0, pmccntr_el0" : "=r" (r));

/* Setup PMU counter to record specific event */
/* evtCount is the event id */
evtCount &= ARMV8_PMEVTYPER_EVTCOUNT_MASK;
asm volatile("isb");
/* Just use counter 0 here */
asm volatile("msr pmevtyper0_el0, %0" : : "r" (evtCount));
/*   Performance Monitors Count Enable Set register bit 30:1 disable, 31,1 enable */

asm volatile("mrs %0, pmcntenset_el0" : "=r" (r));
asm volatile("msr pmcntenset_el0, %0" : : "r" (r|1));
 /* sleep */
  sleep(1);

/* Read counter */
asm volatile("mrs %0, pmevcntr0_el0" : "=r" (r));

 if(val == 0){
    printf("Test failed\n value of counter 1 is: 0x%lx -> Counter has been disabled!!!\n",val);
  }else{
    printf("Test successful (Value of counter 1 is: 0x%lx)\n",val);
  }  
  
/*   Disable PMU counter 0. Performance Monitors Count Enable Set register: clear bit 0*/
asm volatile("mrs %0, pmcntenset_el0" : "=r" (r));
asm volatile("msr pmcntenset_el0, %0" : : "r" (r&&0xfffffffe));

  return 0;
}