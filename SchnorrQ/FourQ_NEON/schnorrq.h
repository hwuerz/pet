//
// Created by hendrik on 26.02.17.
//

#ifndef FOURQ_NEON_SCHNORRQ_H
#define FOURQ_NEON_SCHNORRQ_H

#include "FourQ_internal.h"
#include "FourQ.h"
#include "test_extras.h"
#include <malloc.h>
#include <stdio.h>

#define MESSAGE_SIZE     140 // Byte
#define HASH_SIZE         64 // SHA512 --> 512 Bit == 64 Byte
#define SECRET_KEY_SIZE   32 // Paper definition 256 Bit = 32 Byte

typedef unsigned char schnorr_hash[HASH_SIZE];
typedef unsigned char schnorr_message[MESSAGE_SIZE];
typedef unsigned char schnorr_secret_key[SECRET_KEY_SIZE];

void init_message(schnorr_message* message);
void init_key(schnorr_secret_key* key);
void init_random(unsigned char* array, unsigned const int size);
void init_deterministic(unsigned char* array, unsigned int size, unsigned char data);
void setup_B(point_t B);
bool is_negative(f2elm_t x);

#endif //FOURQ_NEON_SCHNORRQ_H
