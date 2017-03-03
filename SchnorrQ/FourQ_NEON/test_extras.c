/***********************************************************************************
* FourQ: 4-dimensional decomposition on a Q-curve with CM in twisted Edwards form
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
*
* Abstract: utility functions for tests
*
* This code is based on the paper "FourQ: four-dimensional decompositions on a 
* Q-curve over the Mersenne prime" by Craig Costello and Patrick Longa, in Advances 
* in Cryptology - ASIACRYPT, 2015.
* Preprint available at http://eprint.iacr.org/2015/565.
************************************************************************************/  

#include "FourQ_internal.h"
#include "test_extras.h"
#if (OS_TARGET == OS_LINUX) && (TARGET == TARGET_ARM)
    #include <time.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


int64_t cpu_nseconds(void)
{ // Access system counter for benchmarking
    struct timespec time;

    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)(time.tv_sec*1e9 + time.tv_nsec);
}


int fpcompare64(uint64_t* a, uint64_t* b)
{ // Comparing uint64_t digits of two field elements, a=b? : (0) equal, (1) unequal
  // NOTE: this function does not have constant-time execution. TO BE USED FOR TESTING ONLY.
    unsigned int i;

    for (i = 0; i < (NWORDS64_FIELD); i++) {
        if (a[i] != b[i]) return 1;
    }
    
    return 0; 
}

void print_point_t(point_t A)
{
    uint64_t* x = (uint64_t*)A->x;
    uint64_t* y = (uint64_t*)A->y;

    printf(" x");
    print_hex((char*)x, 32);

    printf(" y");
    print_hex((char*)y, 32);

    printf("\n");
}

void print_vpoint_t(vpoint_t VA)
{
    uint64_t* x = (uint64_t*)VA->x;
    uint64_t* y = (uint64_t*)VA->y;

    printf(" x  (320Bit):");
    print_hex((char*)x, 2*VWORDS_FIELD);

    printf("\n y  (320Bit):");
    print_hex((char*)y, 2*VWORDS_FIELD);

    printf("\n");
}

void print_vpoint_extproj_t(vpoint_extproj_t VP)
{
    uint64_t* x = (uint64_t*)VP->x;
    uint64_t* y = (uint64_t*)VP->y;
    uint64_t* z = (uint64_t*)VP->z;
    uint64_t* ta = (uint64_t*)VP->ta;
    uint64_t* tb = (uint64_t*)VP->tb;

    unsigned int i;
    printf(" x  (320Bit):");
    for (i = 0; i < (VWORDS_FIELD); i++) {
        printf(" %016llX", x[i]);
    }
    printf("\n y  (320Bit):");
    for (i = 0; i < (VWORDS_FIELD); i++) {
        printf(" %016llX", y[i]);
    }
    printf("\n z  (320Bit):");
    for (i = 0; i < (VWORDS_FIELD); i++) {
        printf(" %016llX", z[i]);
    }
    printf("\n ta (320Bit):");
    for (i = 0; i < (VWORDS_FIELD); i++) {
        printf(" %016llX", ta[i]);
    }
    printf("\n tb (320Bit):");
    for (i = 0; i < (VWORDS_FIELD); i++) {
        printf(" %016llX", tb[i]);
    }
    printf("\n");
}

void print_hex(const char* data, unsigned const int size)
{
    printf(" (%4d Bit):", (size*8));
    unsigned int i;
    for(i = 0; i < size; i++) {
        if(i % 8 == 0) { // every 64 Bit a space
            printf(" ");
        }
        printf("%02X", data[i]);
    }
    printf("\n");
}

int fp2compare64(uint64_t* a, uint64_t* b)
{ // Comparing uint64_t digits of two quadratic extension field elements, ai=bi? : (0) equal, (1) unequal
  // NOTE: this function does not have constant-time execution. TO BE USED FOR TESTING ONLY.
    unsigned int i;

    for (i = 0; i < (2*NWORDS64_FIELD); i++) {
        if (a[i] != b[i]) return 1;
    }
    
    return 0; 
}


void random_scalar_test(uint64_t* a)
{ // Generating a pseudo-random scalar value in [0, 2^256-1] 
  // NOTE: distribution is not fully uniform. TO BE USED FOR TESTING ONLY.
    unsigned char* string = (unsigned char*)&a[0];
    unsigned int i;

    for (i = 0; i < (sizeof(uint64_t)*NWORDS64_ORDER); i++) {
        string[i] = (unsigned char)rand();             
    }
}


void fp2random1271_test(f2elm_t a)
{ // Generating a pseudo-random GF(p^2) element a+b*i, where a,b in [0, 2^127-1] 
  // NOTE: distribution is not fully uniform. TO BE USED FOR TESTING ONLY.
    digit_t mask_7fff = (digit_t)-1 >> 1;

    random_scalar_test((uint64_t*)&a[0]);
    a[0][NWORDS_FIELD-1] &= mask_7fff;
    a[1][NWORDS_FIELD-1] &= mask_7fff;
}


void vrandom1271_test(velm_t a)
{ // Generating a vectorized pseudo-random GF(p) element in [0, 2^127-1] 
  // NOTE: distribution is not fully uniform. TO BE USED FOR TESTING ONLY.
    v2elm_t temp;
    velm_t b;
    
    v2random1271_test(temp);
    from_v2_to_v(temp, a, b);
}


void v2random1271_test(v2elm_t a)
{ // Generating a vectorized pseudo-random GF(p^2) element a+b*i, where a,b in [0, 2^127-1] 
  // NOTE: distribution is not fully uniform. TO BE USED FOR TESTING ONLY.
    digit_t mask_7fff = (digit_t)-1 >> 1;
    f2elm_t temp;
    
    random_scalar_test((uint64_t*)&temp[0]);
    temp[0][NWORDS_FIELD-1] &= mask_7fff;
    temp[1][NWORDS_FIELD-1] &= mask_7fff;
    from_std_to_ext(temp, a);
}


#if defined(USE_FIXED_BASE_SM)

bool verify_mLSB_recoding(uint64_t* scalar, int* digits)
{ // Verification of the mLSB-set's recoding algorithm used in fixed-base scalar multiplication 
    unsigned int j, l = L_FIXEDBASE, d = D_FIXEDBASE;
    uint64_t temp, temp2, carry, borrow, generated_scalar[NWORDS64_ORDER] = {0};
    int i, digit;

    for (i = (l-1); i >= 0; i--)
    {
        // Shift generated scalar to the left by 1 (multiply by 2)
        temp = ((generated_scalar[0] >> (RADIX64-1)) & 1) ;
        generated_scalar[0] = generated_scalar[0] << 1;

        for (j = 1; j < NWORDS64_ORDER; j++) {
            temp2 = ((generated_scalar[j] >> (RADIX64-1)) & 1) ;
            generated_scalar[j] = (generated_scalar[j] << 1) | temp;
            temp = temp2;
        }
     
        // generated scalar + digit_i
        if (i < (int)d) {
            digit = digits[i] | 1;
            if (digit >= 0) {
                generated_scalar[0] = generated_scalar[0] + digit;
                carry = (generated_scalar[0] < (unsigned int)digit);
                for (j = 1; j < NWORDS64_ORDER; j++)
                {
                    generated_scalar[j] = generated_scalar[j] + carry;    
                    carry = (generated_scalar[j] < carry);
                }
            } else {
                borrow = 0;
                temp = (uint64_t)(-digit);
                for (j = 0; j < NWORDS64_ORDER; j++)
                {
                    temp2 = generated_scalar[j] - temp;
                    carry = (generated_scalar[j] < temp);
                    generated_scalar[j] = temp2 - borrow;
                    borrow = carry || (temp2 < borrow);
                    temp = 0;
                }
            } 
        } else {
            digit = digits[i]*(digits[i-(i/d)*d] | 1);
            if (digit >= 0) {
                generated_scalar[0] = generated_scalar[0] + digit;
                carry = (generated_scalar[0] < (unsigned int)digit);
                for (j = 1; j < NWORDS64_ORDER; j++)
                {
                    generated_scalar[j] = generated_scalar[j] + carry;    
                    carry = (generated_scalar[j] < carry);
                }
            } else {
                borrow = 0;
                temp = (uint64_t)(-digit);
                for (j = 0; j < NWORDS64_ORDER; j++)
                {
                    temp2 = generated_scalar[j] - temp;
                    carry = (generated_scalar[j] < temp);
                    generated_scalar[j] = temp2 - borrow;
                    borrow = carry || (temp2 < borrow);
                    temp = 0;
                }
            } 
        }
    }

    for (j = 0; j < NWORDS64_ORDER; j++)
    {
        if (scalar[j] != generated_scalar[j]) 
            return false;
    }

    return true;
}

#endif
