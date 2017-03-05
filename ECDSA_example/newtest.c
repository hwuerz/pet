#include "uECC.h"
#include "sha256.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

uint8_t houtput[33] = {0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55};
const uint8_t strinput[] = "The quick brown fox jumps over the lazy dog";
const uint8_t hexpected[] = {0xd7,0xa8,0xfb,0xb3,0x07,0xd7,0x80,0x94,0x69,0xca,0x9a,0xbc,0xb0,0x08,0x2e,0x4f,0x8d,0x56,0x51,0xe4,0x6d,0x3c,0xdb,0x76,0x2d,0x02,0xd0,0xbf,0x37,0xc9,0xe5,0x92};

int main() {
    int i;
    uint8_t private[24] = {0};
    uint8_t public[48] = {0};
    uint8_t sig[48] = {0};
    uint8_t hash[32] = {0};

    int iter = 10000;
    clock_t t;
    double time_taken;

    const struct uECC_Curve_t * curves[1];
    printf("Using Curve secp192r1\n");
    curves[0] = uECC_secp192r1();

    printf("Generating Key Pair\n");
    if (!uECC_make_key(public, private, curves[0])) {
        printf("uECC_make_key() failed\n");
        return 1;
    }
    memcpy(hash, public, sizeof(hash));

    printf("Generating Hash %d times\n", iter);
    t = clock();
    for (i = 0; i < iter; i++) {
        SHA256(houtput, strinput, sizeof(strinput) - 1);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC/iter*1000;
    printf("Hash operation took %f ms to execute...\n", time_taken);
    // checking correct operation
    for (i = 0; i < sizeof(hexpected); i++) {
        if (houtput[i] != hexpected[i])
            printf("houtput != hexpected at position %i\n", i);
    }

    printf("Generating Signature %d times\n", iter);
    t = clock();
    for (i = 0; i < iter; i++) {
        if (!uECC_sign(private, hash, sizeof(hash), sig, curves[0])) {
            printf("uECC_sign() failed\n");
            return 1;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC/iter*1000;
    printf("Signing operation took %f ms to execute...\n", time_taken);

    printf("Verifying Signature %d times\n", iter);
    t = clock();
    for (i = 0; i < iter; i++) {
        if (!uECC_verify(public, hash, sizeof(hash), sig, curves[0])) {
            printf("uECC_verify() failed\n");
            return 1;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC/iter*1000;
    printf("Verification operation took %f ms to execute...\n", time_taken);


    /*
    const struct uECC_Curve_t * curves[1];
    printf("Using Curve secp160r1\n");
    curves[0] = uECC_secp160r1();

    printf("Generating Key Pair\n");
    if (!uECC_make_key(public, private, curves[0])) {
        printf("uECC_make_key() failed\n");
        return 1;
    }
    memcpy(hash, public, sizeof(hash));

    iter = 10000;
    printf("Generating Signature %d times\n", iter);
    t = clock();
    for (i = 0; i < iter; i++) {
        if (!uECC_sign(private, hash, sizeof(hash), sig, curves[c])) {
            printf("uECC_sign() failed\n");
            return 1;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC/iter*1000;
    printf("Signing operation took %f ms to execute...\n", time_taken);

    iter = 10000;
    printf("Verifying Signature %d times\n", iter);
    t = clock();
    for (i = 0; i < iter; i++) {
        if (!uECC_verify(public, hash, sizeof(hash), sig, curves[c])) {
            printf("uECC_verify() failed\n");
            return 1;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC/iter*1000;
    printf("Verification operation took %f ms to execute...\n", time_taken);
    */

    return 0;
}
