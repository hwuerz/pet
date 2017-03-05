#include "crypto_sign.h"
#include "crypto_hash_sha512.h"
#include "ge.h"


int crypto_sign_keypair(unsigned char *pk,unsigned char *sk,unsigned char *seed)
{
  unsigned char h[64];
  ge_p3 A;
  int i;

  crypto_hash_sha512(h,seed,32); //randomization of seed
  h[0] &= 248;
  h[31] &= 63;
  h[31] |= 64;

  ge_scalarmult_base(&A,h);	//takes a ge_p3* and a unsigned char* - result stored in A
  ge_p3_tobytes(pk,&A);

  for (i = 0;i < 32;++i) sk[32 + i] = pk[i];
  for(i=0;i<32;i++) sk[i] = seed[i];
  return 0;
}
