CC= /home/nils/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc
ADB = /home/nils/Android/Sdk/platform-tools/adb 
SYSROOT = /home/nils/Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
CFLAGS= --sysroot=$(SYSROOT) -static -Wall -fomit-frame-pointer -DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4 -mcpu=cortex-a53 #-O3
#static -> necessary for object files without linking
#-O3 -> Optimization level 3 - causes segmentation faults at working with the assembly files
ASFLAGS= -mfloat-abi=soft -mcpu=cortex-a53
#using cortex-m3 as it seems to be regularly used and allows assembly
#currently using cortex-a53 as that is the arch of my own smartphones processor

MODULES = Keccak-inplace32BI.c kummer.c modN.c gfe.c jac.c signatures.c keyexchange.c hadamard.c main_pet.c
HFILES = gfe.h crypto_hash.h jac.h Keccak-inplace-settings.h keyexchange.h kummer.h signatures.h modN.h
ASMFILES = gfe_pack.s bigint_red.s gfe_mulconst.s bigint_mul.s gfe_sub.s gfe_neg.s gfe_add.s bigint_sqr.s #hadamard.s
CASMFILES= gfe_pack.o bigint_red.o gfe_mulconst.o bigint_mul.o gfe_sub.o gfe_neg.o gfe_add.o bigint_sqr.o #hadamard.o

all: asmfiles newtest adb_newtest

asmfiles: $(ASMFILES) Makefile
	$(CC) $(ASFLAGS) gfe_pack.s -c
	$(CC) $(ASFLAGS) bigint_red.s -c
	$(CC) $(ASFLAGS) gfe_mulconst.s -c
	#$(CC) $(ASFLAGS) hadamard.s -c
	$(CC) $(ASFLAGS) bigint_mul.s -c
	$(CC) $(ASFLAGS) gfe_sub.s -c
	$(CC) $(ASFLAGS) gfe_neg.s -c
	$(CC) $(ASFLAGS) gfe_add.s -c
	$(CC) $(ASFLAGS) bigint_sqr.s -c

newtest: $(MODULES) $(HFILES) Makefile
	$(CC) $(CFLAGS) $(CASMFILES) $(HFILES) $(MODULES) -o newtest_mukummer

adb_newtest:
	$(ADB) push newtest_mukummer /data/local/tmp
	
clean:
	-rm newtest_mukummer gfe_pack.o bigint_red.o gfe_mulconst.o hadamard.o bigint_mul.o gfe_sub.o gfe_neg.o gfe_add.o bigint_sqr.o
