/***********************************************************************************
* FourQ: 4-dimensional decomposition on a Q-curve with CM in twisted Edwards form
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
*
* Abstract: main header file
*
* This code is based on the paper "FourQ: four-dimensional decompositions on a 
* Q-curve over the Mersenne prime" by Craig Costello and Patrick Longa, in Advances 
* in Cryptology - ASIACRYPT, 2015.
* Preprint available at http://eprint.iacr.org/2015/565.
************************************************************************************/  

#ifndef __FOURQ_H__
#define __FOURQ_H__


// For C++
#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stdbool.h>


// Definition of operating system

#define OS_WIN       1
#define OS_LINUX     2

#if defined(__WINDOWS__)        // Microsoft Windows OS
    #define OS_TARGET OS_WIN
#elif defined(__LINUX__)        // Linux OS
    #define OS_TARGET OS_LINUX 
#else
    #error -- "Unsupported OS"
#endif


// Definition of compiler

#define COMPILER_VC      1
#define COMPILER_GCC     2
#define COMPILER_CLANG   3

#if defined(_MSC_VER)           // Microsoft Visual C compiler
    #define COMPILER COMPILER_VC
#elif defined(__GNUC__)         // GNU GCC compiler
    #define COMPILER COMPILER_GCC   
#elif defined(__clang__)        // Clang compiler
    #define COMPILER COMPILER_CLANG   
#else
    #error -- "Unsupported COMPILER"
#endif


// Definition of the targeted architecture and basic data types
    
#define TARGET_AMD64        1
#define TARGET_x86          2
#define TARGET_ARM          3

#if defined(_AMD64_)
    #define TARGET TARGET_AMD64
    #define RADIX           64
    typedef uint64_t        digit_t;      // Unsigned 64-bit digit
    typedef int64_t         sdigit_t;     // Signed 64-bit digit
    #define NWORDS_FIELD    2             // Number of words of a field element
    #define NWORDS_ORDER    4             // Number of words of an element in Z_r 
#elif defined(_X86_)
    #define TARGET TARGET_x86
    #define RADIX           32
    typedef uint32_t        digit_t;      // Unsigned 32-bit digit
    typedef int32_t         sdigit_t;     // Signed 32-bit digit
    #define NWORDS_FIELD    4             
    #define NWORDS_ORDER    8 
#elif defined(_ARM_)
    #define TARGET TARGET_ARM
    #define RADIX           32
    typedef uint32_t        digit_t;      // Unsigned 32-bit digit
    typedef int32_t         sdigit_t;     // Signed 32-bit digit
    #define NWORDS_FIELD    4             
    #define NWORDS_ORDER    8 
#else
    #error -- "Unsupported ARCHITECTURE"
#endif


// Constants

#define RADIX64         64
#define NWORDS64_FIELD  2                 // Number of 64-bit words of a field element 
#define NWORDS64_ORDER  4                 // Number of 64-bit words of an element in Z_r 


// Instruction support

#define NO_SIMD_SUPPORT 0
#define AVX_SUPPORT     1
#define AVX2_SUPPORT    2

#if defined(_AVX2_)
    #define SIMD_SUPPORT AVX2_SUPPORT       // AVX2 support selection 
#elif defined(_AVX_)
    #define SIMD_SUPPORT AVX_SUPPORT        // AVX support selection 
#else
    #define SIMD_SUPPORT NO_SIMD_SUPPORT
#endif

#if defined(_ASM_)                          // Assembly support selection
    #define ASM_SUPPORT
#endif

#if defined(_GENERIC_)                      // Selection of generic, portable implementation
    #define GENERIC_IMPLEMENTATION
#endif


// Unsupported configurations
                         
#if defined(ASM_SUPPORT) && (OS_TARGET == OS_WIN)
    #error -- "Assembly is not supported on this platform"
#endif        

#if defined(ASM_SUPPORT) && defined(GENERIC_IMPLEMENTATION)
    #error -- "Unsupported configuration"
#endif        

#if (SIMD_SUPPORT != NO_SIMD_SUPPORT) && defined(GENERIC_IMPLEMENTATION)
    #error -- "Unsupported configuration"
#endif

#if (TARGET != TARGET_AMD64) && !defined(GENERIC_IMPLEMENTATION)
    #error -- "Unsupported configuration"
#endif
 

// Detect if fixed-base and double scalar multiplication are enabled 


#if !defined(_DISABLE_FIXED_MUL_)
    #define USE_FIXED_BASE_SM	
#endif 

#if !defined(_DISABLE_DOUBLE_MUL_)
#if (USE_ENDO == true)                           // Double-scala multiplications are only supported when using endomorphisms
    #define USE_DOUBLE_SM	
#endif
#endif


// Basic parameters for variable-base scalar multiplication (without using endomorphisms)
#define W_VARBASE             5 
#define NBITS_ORDER_PLUS_ONE  246+1 


// Basic parameters for fixed-base scalar multiplication
#ifdef USE_FIXED_BASE_SM
    #define W_FIXEDBASE       5                  // Memory requirement: 7.5KB (storage for 80 points).
    #define V_FIXEDBASE       5                  // W_FIXEDBASE and V_FIXEDBASE must be positive integers in the range [1, 10].  
#endif


// Basic parameters for double scalar multiplication
#ifdef USE_DOUBLE_SM
    #define WP_DOUBLEBASE          8              // Memory requirement: 24KB (storage for 256 points).
    #define WQ_DOUBLEBASE          4                 
#endif	
   

// FourQ's basic element definitions and point representations

typedef digit_t felm_t[NWORDS_FIELD];             // Datatype for representing 128-bit field elements 
typedef digit_t digit256_t[NWORDS_ORDER];         // Datatype for representing 256-bit elements in Z_r 
typedef felm_t f2elm_t[2];                        // Datatype for representing quadratic extension field elements
        
typedef struct { f2elm_t x; f2elm_t y; } point_affine; // Point representation in affine coordinates.
typedef point_affine point_t[1]; 


// FourQ's data structure
typedef struct
{    
    unsigned int     nbits;                            // 2 x targeted security level
    unsigned int     rbits;                            // Bitlength of the prime order subgroup
    uint64_t         prime[NWORDS64_FIELD];            // Prime
    uint64_t         a[NWORDS64_ORDER];                // Curve parameter "a"
    uint64_t         d[NWORDS64_ORDER];                // Curve parameter "d"
    uint64_t         order[NWORDS64_ORDER];            // Prime order of the curve subgroup 
    uint64_t         generator_x[NWORDS64_ORDER];      // x-coordinate of the generator
    uint64_t         generator_y[NWORDS64_ORDER];      // y-coordinate of the generator
    unsigned int     cofactor;                         // Co-factor of the curve group
} CurveStruct, *PCurveStruct;                                                                             


// FourQ's structure definition
extern CurveStruct curve4Q;


/**************** Public API ****************/

// Clear "nwords" integer-size digits from memory
void clear_words(void* mem, unsigned int nwords);

// Set generator (x,y)
void eccset(point_t P, PCurveStruct curve);

// Variable-base scalar multiplication Q = k*P using a 4-dimensional decomposition
bool ecc_mul(point_t P, digit_t* k, point_t Q, bool clear_cofactor, PCurveStruct curve);

#if defined(USE_FIXED_BASE_SM)

// Fixed-base scalar multiplication Q = k*P using the modified LSB-set comb method 
bool ecc_mul_fixed(digit_t* T_fixed, digit_t* k, point_t Q, PCurveStruct curve);

// Allocate memory dynamically for precomputation table "T_fixed" used during fixed-base scalar multiplications
// This function must be called before using ecc_precomp_fixed() to generate a precomputed table 
digit_t* ecc_allocate_precomp(void);

// Precomputation function for fixed-base scalar multiplication using affine coordinates with representation (x+y,y-x,2dt) 
bool ecc_precomp_fixed(point_t P, digit_t* T_fixed, bool clear_cofactor, PCurveStruct curve);

#endif

#if defined(USE_DOUBLE_SM)

// Double scalar multiplication R = k*P + l*Q, where the base point P is passed through P_table which contains multiples of P, Phi(P), Psi(P) and Phi(Psi(P))
bool ecc_mul_double(digit_t* P_table, digit_t* k, point_t Q, digit_t* l, point_t R, PCurveStruct curve);

// Allocates memory dynamically for the precomputation table used during double scalar multiplications
// This function must be called before using ecc_precomp_double() to generate a precomputed table 
digit_t* ecc_allocate_precomp_double(void);

// Generation of the precomputation table used by the double scalar multiplication function ecc_mul_double()
bool ecc_precomp_double(point_t P, digit_t* Table, PCurveStruct curve);

#endif


#ifdef __cplusplus
}
#endif


#endif
