//
// Created by hendrik on 26.02.17.
//

#include "schnorrq.h"
#include "FourQ_internal.h"
#include "FourQ.h"
#include "test_extras.h"
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * creates a message which can be signed
 * @param message Pointer to the message
 */
void init_message(schnorr_message* message)
{
    unsigned char* message_array = (unsigned char*) message;
    init_deterministic(message_array, MESSAGE_SIZE, 0xaa);
}

/**
 * Generates a random secret key which can be used to sign messages
 * @param key A pointer to the key
 */
void init_key(schnorr_secret_key* key)
{
    unsigned char* key_array = (unsigned char*) key;
    init_random(key_array, SECRET_KEY_SIZE);
}

/**
 * fills the passed array with random data
 * @param array The array which should be filled
 * @param size The size of the array in bytes
 */
void init_random(unsigned char* array, unsigned const int size)
{
    // Init random
    time_t t;
    srand((unsigned) time(&t)); // Init random number generator

    // Init message
    unsigned int i;
    for(i = 0; i < size; i++) {
        array[i] = rand();
    }
}

/**
 * fills the passed array with the passed char
 * @param array A pointer to the array which should be filled
 * @param size The size of the array
 * @param data The data which should be replicated in the array
 */
void init_deterministic(unsigned char* array, unsigned int size, unsigned char data)
{
    // Init message
    unsigned int i;
    for(i = 0; i < size; i++) {
        array[i] = data;
    }
}

/**
 * Setups B based on the SchnorrQ definition
 * @param B The point which should be used for B
 */
void setup_B(point_t B)
{
    felm_t* x = (felm_t*) B->x;

    /*
     * x_a = 133173070547236760532149241662440243363
     *     = 0x  64 30 33 4F  BA 2E DF 3E  69 DD EB 98  BE 40 80 A3
     *           -----------  -----------  -----------  -----------
     *               [3]          [2]           [1]          [0]
     */
    digit_t* x_a = x[0];
    x_a[0] = 0xBE4080A3;
    x_a[1] = 0x69DDEB98;
    x_a[2] = 0xBA2EDF3E;
    x_a[3] = 0x6430334F;
//    printf("x_a = \n");
//    print_hex(x_a, 16);

    /*
     * x_b = 72544766618652889802729346394492014752
     *     = 0x  36 93 9D 24  38 AD BB 4A  C7 85 90 8C  96 D0 90 A0
     *           -----------  -----------  -----------  -----------
     *               [3]          [2]           [1]          [0]
     */
    digit_t* x_b = x[1];
    x_b[0] = 0x96D090A0;
    x_b[1] = 0xC785908C;
    x_b[2] = 0x38ADBB4A;
    x_b[3] = 0x36939D24;
//    printf("x_b = \n");
//    print_hex(x_b, 16);


    felm_t* y = (felm_t*) B->y;

    /*
     * y_a = 465
     *     = 0x  00 00 00 00  00 00 00 00  00 00 00 00  00 00 01 D1
     *           -----------  -----------  -----------  -----------
     *               [3]          [2]           [1]          [0]
     */
    digit_t* y_a = y[0];
    y_a[0] = 0x01D1;
    y_a[1] = 0x0;
    y_a[2] = 0x0;
    y_a[3] = 0x0;
//    printf("y_a = \n");
//    print_hex(y_a, 16);

    /*
     * y_b = 0
     *     = 0x  00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00
     *           -----------  -----------  -----------  -----------
     *               [3]          [2]           [1]          [0]
     */
    digit_t* y_b = y[1];
    y_b[0] = 0x0;
    y_b[1] = 0x0;
    y_b[2] = 0x0;
    y_b[3] = 0x0;
//    printf("y_b = \n");
//    print_hex(y_b, 16);
}

/**
 * Checks whether the passed element is negative, based on the definition of SchnorrQ
 * @param x The element to be checked
 * @return True if x is negative, false otherwise
 */
bool is_negative(f2elm_t x)
{
    digit_t* x_a = x[0];
    digit_t* x_b = x[1];
    digit_t mask_for_126 = 0x40000000; // 2^30 == 1; other == 0

    // a_126 == 1 --> neg
    if((x_a[3] & mask_for_126) == mask_for_126) {
        return true;
    }

    // a == 0 && b_126 == 1 --> neg
    if(x_a[0] == 0 && x_a[1] == 0 && x_a[2] == 0 && x_a[3] == 0 && (x_b[3] & mask_for_126) == mask_for_126) {
        return true;
    }

    return false;
}

int main()
{

    // Declare variables
    schnorr_message message; // the message to be signed
    schnorr_hash hash; // The hash of the message
    schnorr_secret_key key; // The secret key used to sign

    // Init message
    init_message(message);
    printf("Message: \n");
    print_hex((char*)message, MESSAGE_SIZE);

//    // Generate Hash of the message (optional)
//    sha512(message, MESSAGE_SIZE, hash);
//    printf("Hash Message: \n");
//    print_hex(hash, HASH_SIZE);

    // Generate key
    init_key(key);
    printf("Secret key: \n");
    print_hex((char*)key, SECRET_KEY_SIZE);

    // Generate Hash
    sha512(key, SECRET_KEY_SIZE, hash);
    printf("Hash Key: \n");
    print_hex((char*)hash, HASH_SIZE);

    point_t B;
    setup_B(B);
    printf("B = \n");
    print_point_t(B);


    bool OK = true;

    OK = OK && ecc_test();         // Test FourQ's curve functions
    OK = OK && ecc_run();          // Benchmark FourQ's curve functions

    return OK;
}