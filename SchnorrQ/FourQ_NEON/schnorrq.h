//
// Created by hendrik on 26.02.17.
//

#ifndef FOURQ_NEON_SCHNORRQ_H
#define FOURQ_NEON_SCHNORRQ_H

#define MESSAGE_SIZE     140 // Byte
#define HASH_SIZE         64 // SHA512 --> 512 Bit == 64 Byte
#define SECRET_KEY_SIZE   32 // Paper definition 256 Bit = 32 Byte

typedef unsigned char schnorr_hash[HASH_SIZE];
typedef unsigned char schnorr_message[MESSAGE_SIZE];
typedef unsigned char schnorr_secret_key[SECRET_KEY_SIZE];

#endif //FOURQ_NEON_SCHNORRQ_H
