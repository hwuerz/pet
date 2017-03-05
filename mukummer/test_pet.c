#include "./signatures.h"
#include "./gfe.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Working out causes for errors on key generation.
 */

int test_keygen_faults(){
	int i,j;	

	union data256 private_key;		
	union data256 public_key;		
	union data384 signature;		
	union data512 dd;				

	int MSG_LEN = 140;
	int KEY_LEN = 32;
	unsigned char message[MSG_LEN];
	unsigned long long msg_len_long = (unsigned long long) MSG_LEN;

	printf("Message: ");
	for(i = 0; i < MSG_LEN; i++){
		srand(time(NULL)+i);
		message[i] = (unsigned char) rand() % UCHAR_MAX;
		printf("%d;", message[i]);
	}		
	printf("\n");

	printf("Seed:\n");
	for(j = 0; j < KEY_LEN; j++) {
		srand(time(NULL)+i+j);
		private_key.u8[j] = (unsigned char) rand() % UCHAR_MAX;
		printf("%d;", private_key.u8[j]);
	}
	printf("\n");

	keygen(&public_key, &dd, &private_key); //TODO: Bus Error and Segfault; but they seem to depend on the random seed! That is: If the random seed is constant, the result is always the same error! E.g. for all 0 -> Bus Error
	printf("I am confused...%d\n", MSG_LEN);//TODO: Returns trash, after execution of keygen
	//TODO: Apparantly things go wrong in kummer.c crypto_scalarmult ... but not sure.

	printf("Key: ");
	for(j = 0; j < KEY_LEN; j++)
		printf("%d;", dd.u8[j]);

	printf("\n");
	
	return 0;
}


/*
 * Testing on Segfault
 * Result:
 * > All Segfaults and Bus-Errors non-existent, if compiling without Optimization Niveau!
 * > Errors caused with all niveaus O1, O2, and O3
 */

int test_segfaults_funs(){
	printf("Int Length: %dByte, uint32_t Length: %dByte, unint length: %dByte,  gfe_length: %dByte, cgfe length: %dByte\n", sizeof(int), sizeof(uint32_t), sizeof(uint32), sizeof(gfe), sizeof(cgfe));
	
	//gfe fields
	cgfe  a = {1, 2, 3, 4};
	cgfe  b = {2, 3, 4, 1};
	gfe   c = {0, 0, 0, 0};

	//uint fields
	const uint32 d[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	const uint32 e[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint32 f[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint32 g[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	xpw; 	//force initialization - is an static, constant uint32 array with 12 elements
	Pdec; 	//alike - uint32 with 12 elements


	//Regular GFE-Operations with regular operands (gfe not uint32)
	gfe_mul(c, a, b); //c fun

	printf("Mul Result: %d, %d, %d, %d\n", c[0], c[1], c[2], c[3]);


	gfe_add(c, a, b); //asm fun //Caused Segfault
	printf("Add Result: %d, %d, %d, %d\n", c[0], c[1], c[2], c[3]);

	gfe_add(f, e, d); //asm fun //Caused Bus Error
	printf("Add Result: %d, %d, %d, %d\n", f[0], f[1], f[2], f[3]);


	gfe_sub(c, a, b); //asm fun //Caused Bus Error
	printf("Sub Result: %d, %d, %d, %d\n", c[0], c[1], c[2], c[3]);

	gfe_sub(f, e, d); //asm fun //Caused Bus Error
	printf("sub Result: %d, %d, %d, %d\n", f[0], f[1], f[2], f[3]);


	bigint_mul(g, a, b); //asm fun
	printf("BigIntMul Result: %d, %d, %d, %d\n", g[0], g[1], g[2], g[3]);
	
	bigint_mul(g, d, e); //asm fun //Caused Bus Error
	printf("BigIntMul Result: %d, %d, %d, %d\n", g[0], g[1], g[2], g[3]);
		
	return 0;
}

int main(void) {
	test_segfaults_funs();
	printf("No Segfaults under 'Lab Conditions'\n");
	test_keygen_faults();
	printf("No Segfaults at keygen\n");

	return 0;
}
