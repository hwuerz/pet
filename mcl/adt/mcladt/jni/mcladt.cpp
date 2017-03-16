#include <jni.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <mcl/bn256.hpp>
#include <time.h>

//number of generated keys and signatures and verified signatures
int NUM_SIGN 	= 10000;

double bn256_sample(double* sign, double* verify, double* keygen)
{
	const char *aa = "12723517038133731887338407189719511622662176727675373276651903807414909099441";
	const char *ab = "4168783608814932154536427934509895782246573715297911553964171371032945126671";
	const char *ba = "13891744915211034074451795021214165905772212241412891944830863846330766296736";
	const char *bb = "7937318970632701341203597196594272556916396164729705624521405069090520231616";

	using namespace mcl::bn256;

	bn256init();
	G2 Q(Fp2(aa, ab), Fp2(ba, bb));
	G1 P(-1, 1);

	const mpz_class a = 123;
	const mpz_class b = 456;
	Fp12 e1, e2;
	BN::pairing(e1, P, Q);
	
	//PK
	G2 aQ;
	//Signature
	G1 bP;
	
	//KeyGen
	clock_t time_start = clock();
	for(int i = 0; i < NUM_SIGN; i++) {
		G2::mul(aQ, Q, a);
	}
	time_start = clock() - time_start;
	*keygen = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;

	//Signature creation
	time_start = clock();
	for(int i = 0; i < NUM_SIGN; i++) {
		G1::mul(bP, P, b);
	}
	time_start = clock() - time_start;
	*sign = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;
	
	//Signature verification
	time_start = clock();
	for(int i = 0; i < NUM_SIGN; i++) {
		BN::pairing(e2, bP, aQ);
		Fp12::pow(e1, e1, a * b);
	}
	time_start = clock() - time_start;
	*verify = ((double)time_start)/CLOCKS_PER_SEC/NUM_SIGN*1000;
	return e1 == e2 ? 0 : 1;
}

extern "C" JNIEXPORT jstring JNICALL Java_com_herumi_mcladt_MainActivity_mclTest(JNIEnv *env, jobject thiz)
	try
{
	std::ostringstream oss;
	double sign, verify, keygen;
	bn256_sample(&sign, &verify, &keygen);
	oss << "\nKeyGen: " << keygen << "\nSign: " << sign << "\nVerify: " << verify;
	return env->NewStringUTF(oss.str().c_str());
} catch (std::exception& e) {
	return env->NewStringUTF(e.what());
}
