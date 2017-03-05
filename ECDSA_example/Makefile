MAXOPTIMIZATIONS = -DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4 
CFLAGS = -Wall -O3 -fomit-frame-pointer -static

# YOU NEED TO SET PATH FOR THESE INDIVIDUALLY
SYSROOT = /home/nils/Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
ADB = /home/nils/Android/Sdk/platform-tools/adb 
CXX = /home/nils/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc-4.9

all: newtest adb_newtest

newtest: newtest.c uECC.c sha256.c Makefile
	$(CXX) $(CFLAGS) $(MAXOPTIMIZATIONS) --sysroot=$(SYSROOT) -o newtest uECC.c sha256.c newtest.c

adb_newtest:
	$(ADB) push newtest /data/local/tmp

# DEPRECATED
#test_ecdsa:
#	$(CXX) -DuECC_OPTIMIZATION_LEVEL=2 --sysroot=/home/florian/Android/SDK/ndk-bundle/platforms/android-19/arch-arm/ -o test_ecdsa uECC.c test_ecdsa.c -static

clean:
	rm -f test_ecdsa newtest newtest_threaded

