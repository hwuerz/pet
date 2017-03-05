#include "./signatures.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

//TODO: Maybe don't use the same keys (the last generated) - could lead to statistical inaccuracy

/*
 * I oriented the use of the functions on the test.c example given in the original package (not exitent
 * in this cross compilable version). But can be found in the named file, if one downloads the arm-version
 * of mukummer on the originating website.
 */

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
int NUM_SIGN 	= 10000;		//number of signatures generated and verified
int SIG_LEN 	= 48;		//the signature itself will be a 64Byte value - has no effect on programm!


int main(void){
	int i, j, error = 0;
	clock_t time_start;
	double res_time = 0;

 	union data256 private_key;		//same type as public key
	union data256 public_key;		//is either 32*1Byte (char) or 8*32Bit (int) = 8*4Byte = 32Byte
	union data384 signature;		//is either 48*1Byte (char) or 12*32Bit (int) = 12*4Byte = 48Byte
	union data512 dd;				//meant to contain the hash of the private key; "compressed private key"
	unsigned char message[MSG_LEN]; //Bytestring as message
	unsigned long long msg_len_long = (unsigned long long) MSG_LEN;	//required format
	
	printf("Executing Benchmark\n");
	printf("Security Level %dByte, Message Size %dByte, Number Signatures %d\n", KEY_LEN, MSG_LEN, NUM_SIGN);

	xpw; 	//just to force initalization of static field	
	Pdec; 	//same

	//initalize message
	for(i = 0; i < MSG_LEN; i++){
		srand(time(NULL)+i);
		message[i] = (unsigned char) rand() % UCHAR_MAX;
	}	

	time_start = clock();
	for(i = 0; i < NUM_SIGN; i++) {
		//Randomize seed in private_key - seems to be necessary as private key is the seed as well
		for(j = 0; j < KEY_LEN; j++) {
			srand(i+j);
			private_key.u8[j] = (unsigned char) rand() % UCHAR_MAX;
		}

		/*
 		 * Keygen takes the pointer to public key and private key, as well as to dd and generates
		 * a public-private-keypair storing them in those variables. In dd the hash of the private
		 * key will be written for later use in signing.
		 */
		keygen(&public_key, &dd, &private_key);
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	printf("Generated %d key pairs. This took %fms on average.\n", NUM_SIGN, res_time);
	

	time_start = clock();
	for(i = 0; i < NUM_SIGN; i++){
		/*
		 * Signing requires the aim signature pointer, public-key, the message its length and dd.
		 * After keygen dd is derived from the secret key and generated by applying a hash-function.
		 */
		sign(&signature, &public_key, message, msg_len_long, &dd);
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	printf("Signed %d messages. This took %fms on average.\n", NUM_SIGN, res_time);

	
	time_start = clock();
	for(i = 0; i <NUM_SIGN; i++){
		/*
		 * Verification takes the public_key, the message and its length as well as the signature.
		 */
		error += !verify(&public_key, message, msg_len_long, &signature);	
	}
	time_start = clock() - time_start;
	res_time = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;
	
	printf("Verified %d signatures. This took %fms on average.\n", NUM_SIGN, res_time);
	if(error > 0)
		printf("WARNING: An error appeared at verification - signature and public key do not work out!\n");

	return 0;
}
