/***********************************************************************************
* FourQ: 4-dimensional decomposition on a Q-curve with CM in twisted Edwards form
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
*
* Abstract: utility header file for tests
*
* This code is based on the paper "FourQ: four-dimensional decompositions on a 
* Q-curve over the Mersenne prime" by Craig Costello and Patrick Longa, in Advances 
* in Cryptology - ASIACRYPT, 2015.
* Preprint available at http://eprint.iacr.org/2015/565.
************************************************************************************/  

#ifndef __TEST_EXTRAS_H__
#define __TEST_EXTRAS_H__


// For C++
#ifdef __cplusplus
extern "C" {
#endif

    
// Access system counter for benchmarking
int64_t cpucycles(void);

// Comparing uint64_t digits of two quadratic extension field elements, ai=bi? : (0) equal, (1) unequal
int fp2compare64(uint64_t* a, uint64_t* b);

// Generating a pseudo-random scalar value in [0, 2^256-1] 
void random_scalar_test(uint64_t* a);

// Verification of the mLSB-set's recoding algorithm used in fixed-base scalar multiplication 
bool verify_mLSB_recoding(uint64_t* scalar, int* digits);


#ifdef __cplusplus
}
#endif


#endif