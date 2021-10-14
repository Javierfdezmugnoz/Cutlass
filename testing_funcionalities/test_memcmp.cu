#include <stdio.h>
#include <string.h>

int  main(){
	// TEST 01: memset behaviour
	__uint32_t nElem_ES = 10;	
	__uint32_t *h_value_1;
	__uint32_t *h_value_2;
	__uint32_t *h_value_3;
	__uint32_t nBytes = nElem_ES * sizeof(__uint32_t);

	h_value_1 = (__uint32_t *) malloc(nBytes);
	h_value_2 = (__uint32_t *) malloc(nBytes);
	h_value_3 = (__uint32_t *) malloc(nBytes);
	memset(h_value_1, 0 , nBytes);
	memset(h_value_2, 0 , nBytes);
	memset(h_value_3, 0 , nBytes);

	printf("TEST 01: Verify behaviour of memcmp:\n");
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp detects 1)\n");
	}

	if((memcmp(h_value_1,h_value_2,nBytes)!=0) || (memcmp(h_value_1,h_value_3,nBytes)!=0)){
		printf("Memcmp detects the change 4)\n");
	}


	h_value_1[0]=1;
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp detects 2)\n");
	}

	if((memcmp(h_value_1,h_value_2,nBytes)!=0) || (memcmp(h_value_1,h_value_3,nBytes)!=0)){
		printf("Memcmp detects the change 3)\n");
	}



	printf("TEST 01\n");
	/*
	if(*h_value_1 != *h_value_2){
		printf("After memset");
	}
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp detects the change");
	}
	
	h_value_1[1]= 11u;
	if(*h_value_1 != *h_value_2){
		printf("I have modified the value of h_1[1]");
	}
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp detects the change o h_1[1]");
	}

	h_value_1[0]= 13u;
	if(*h_value_1 != *h_value_2){
		printf("I have modified the value of h_1[0]");
	}
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp detects the change of h_1[0]");
	}

	h_value_2[0]= 13u;
	h_value_2[1]= 11u;
	if(*h_value_1 != *h_value_2){
		printf("I have modified the values of h_2");
	}
	if(memcmp(h_value_1,h_value_2,nBytes)!=0){
		printf("Memcmp no detects");
	}
	*/
	
	// Test 02: 
	__uint32_t mod_operand = 123541;
	__uint32_t mod_divisor = 256;
	__uint32_t out_mod = 0;
	__uint32_t out_var = 0;
	out_mod = mod_operand % mod_divisor;
	out_var = (mod_operand & (mod_divisor-1));
	printf("value of mod_operand: %u\nvalue of var: %u\n",out_mod,out_var);

return 0;

}
