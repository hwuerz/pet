MAXOPTIMIZATIONS = -DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4 
CFLAGS = -Wall -O3 -fomit-frame-pointer -static

# YOU NEED TO SET PATH FOR THESE INDIVIDUALLY
SYSROOT = /home/nils/Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
ADB = /home/nils/Android/Sdk/platform-tools/adb 
CXX = /home/nils/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc-4.9
MODULES = ed25519-supercop-ref10/ge_frombytes.c ed25519-supercop-ref10/fe_frombytes.c ed25519-supercop-ref10/ge_tobytes.c ed25519-supercop-ref10/fe_sq.c ed25519-supercop-ref10/ge_scalarmult_base.c ed25519-supercop-ref10/sc_reduce.c ed25519-supercop-ref10/ge_p2_0.c ed25519-supercop-ref10/ge_sub.c ed25519-supercop-ref10/fe_sub.c ed25519-supercop-ref10/ge_p2_dbl.c ed25519-supercop-ref10/ge_double_scalarmult.c ed25519-supercop-ref10/fe_0.c ed25519-supercop-ref10/ge_p3_to_p2.c ed25519-supercop-ref10/ge_precomp_0.c ed25519-supercop-ref10/fe_cmov.c ed25519-supercop-ref10/sc_muladd.c ed25519-supercop-ref10/fe_isnegative.c ed25519-supercop-ref10/ge_p3_dbl.c ed25519-supercop-ref10/ge_add.c ed25519-supercop-ref10/fe_neg.c ed25519-supercop-ref10/ge_p3_0.c ed25519-supercop-ref10/fe_1.c ed25519-supercop-ref10/ge_madd.c ed25519-supercop-ref10/fe_tobytes.c ed25519-supercop-ref10/sign.c ed25519-supercop-ref10/fe_copy.c ed25519-supercop-ref10/ge_p1p1_to_p2.c ed25519-supercop-ref10/fe_isnonzero.c ed25519-supercop-ref10/open.c ed25519-supercop-ref10/fe_sq2.c ed25519-supercop-ref10/ge_msub.c ed25519-supercop-ref10/fe_add.c ed25519-supercop-ref10/fe_mul.c ed25519-supercop-ref10/fe_pow22523.c ed25519-supercop-ref10/fe_invert.c ed25519-supercop-ref10/ge_p3_tobytes.c ed25519-supercop-ref10/ge_p1p1_to_p3.c ed25519-supercop-ref10/ge_p3_to_cached.c ed25519-supercop-ref10/sha512-blocks.c ed25519-supercop-ref10/sha512-hash.c ed25519-supercop-ref10/verify.c ed25519-supercop-ref10/keypair.c ed25519-supercop-ref10/py.c main_pet.c
HFILES = ed25519-supercop-ref10/crypto_sign.h

all: newtest adb_newtest

newtest: $(MODULES) $(HFILES) Makefile
	$(CXX) $(CFLAGS) $(MAXOPTIMIZATIONS) --sysroot=$(SYSROOT) -o test_ed25519 $(MODULES) $(HFILES)

adb_newtest:
	$(ADB) push test_ed25519 /data/local/tmp

clean:
	rm -f test_ed25519
