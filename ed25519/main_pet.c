#include "./ed25519-supercop-ref10/crypto_sign.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

//TODO: Maybe don't use the same keys (the last generated) - could lead to statistical inaccuracy

/** 
  * ___Benchmark parameters___
  *
  * Security Level: 		128 Bit <-> For Elipitic Curve Crypto: Keysize in 256 to 383 Bit
  * Message Size:   		140 Byte
  * Number of Signatures: 	10000
  *
  */

int KEY_LEN 	= 32; 		//32Byte = 32*8Bit = 256Bit <=> Security Level of 128 Bit
int MSG_LEN 	= 140;		//in Byte
int NUM_SIGN 	= 10000;	//number of signatures generated and verified

int SEED_SIZE 	= 32;
int SIG_LEN 	= 64;		//the signature itself will be a 64Byte value


int main(void){
	int i, j;
	clock_t time_start;
	double res_time = 0;

	unsigned char sm[MSG_LEN + SIG_LEN];			//signature+message
	unsigned long long smlen = MSG_LEN + SIG_LEN;	//signature+message length
	unsigned char m[MSG_LEN + SIG_LEN];				//message (space to zero fill instead of signature...)
	unsigned long long mlen = MSG_LEN;				//message length
	unsigned char sk[KEY_LEN];						//secret key
	unsigned char pk[KEY_LEN];						//public key
	unsigned char seed[SEED_SIZE];					//seed for hash
	
	
	printf("Executing Benchmark\n");
	printf("Security Level %dByte, Message Size %dByte, Number Signatures %d\n", KEY_LEN, MSG_LEN, NUM_SIGN);

	//initalize message
	for(i = 0; i < MSG_LEN; i++){
		srand(time(NULL)+i);
		m[i] = (unsigned char) rand() % UCHAR_MAX;
	}	

	//Seed randomization (optional)
	for(j = 0; j < SEED_SIZE; j++) {
		srand(time(NULL)+i+j);
		seed[j] = (unsigned char) rand() % UCHAR_MAX;
	}

	time_start = clock();
	for(i = 0; i < NUM_SIGN; i++) {
		/*
 		 * crypto_sign_keypair generates a keypair based on the random seed of length 32byte. Which
		 * is given into sha512_hash and results in a 64byte hash value used as actual seed. Therefore
		 * the above randomization might not be necessary.
		 * 
		 * Afterwards executes a scalar multiplication of h with the curve (I assume...), which results
		 * in ge_p3 (ge = group element) - a struct containing 4 fe-fields, where fe = finite field element,
		 * which in turn is an array of 10 components each of the type crypto_int32 - a simple Integer (32bit).
		 *
		 * This product is turned into bytes and written into pk; which has to have exatly 32byte than; the
		 * secret key is of equal length - hence 32byte.
		 *
		 * The resulting keys are stored in pk and sk.
		 */
		if(crypto_sign_keypair(pk, sk, seed)) {	
			printf("Key generation for ed25519 failed.\n");
			return 1;
		}
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	printf("Generated %d key pairs. This took %fms on average.\n", NUM_SIGN, res_time);
	

	time_start = clock();
	for(i = 0; i < NUM_SIGN; i++){
		/*
		 * crypto_sign takes the char array, where the signature will be stored. The smlen is
	 	 * set depending on the message length (msg_len + 64) and hence a pointer as well. Finally the 
		 * message of length mlen is given, hashed (using sha512) and signed with the secret key sk.
		 *
		 */
		if(crypto_sign(sm, &smlen, m, mlen, sk)) {
			printf("Signing for ed25519 failed.\n");
			return 1;
		}	
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	printf("Signed %d messages. This took %fms on average.\n", NUM_SIGN, res_time);

	
	time_start = clock();
	for(i = 0; i <NUM_SIGN; i++){
		/*
		 * cypto_sign_open takes the message as a char array and the its length, which will be set
		 * afterwards to the calcualted message length. Further on it takes the signature-message
		 * char array, as well as its length and the public key. If the signature is valid - what
		 * it should be according to correctness of the signing algorithm - returns 0.
		 *
		 */
		j = crypto_sign_open(m, &mlen, sm, smlen, pk);
		if(j){		
			printf("Verification for ed25519 failed - either wrong signature or failed at processing %d.\n", j);
			return 1;
		}
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	printf("Verified %d signatures. This took %fms on average.\n", NUM_SIGN, res_time);

	return 0;
}
