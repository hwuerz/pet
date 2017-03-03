####  Makefile for compilation using GNU GCC or clang  ####

OPT=-O3     # Optimization option by default

ifeq "$(CC)" "gcc"
    COMPILER=gcc
else ifeq "$(CC)" "clang"
    COMPILER=clang
endif

ifeq "$(ARCH)" "x64"
    ARCHITECTURE=_AMD64_
else ifeq "$(ARCH)" "x86"
    ARCHITECTURE=_X86_
else ifeq "$(ARCH)" "ARM"
    ARCHITECTURE=_ARM_
endif

ADDITIONAL_SETTINGS=
ifeq "$(SET)" "EXTENDED"
    ADDITIONAL_SETTINGS= -fwrapv -fomit-frame-pointer -march=native
endif

ifeq "$(ASM)" "TRUE"
    USE_ASM=-D _ASM_
endif

ifeq "$(GENERIC)" "TRUE"
    USE_GENERIC=-D _GENERIC_
endif

ifeq "$(AVX2)" "TRUE"
    USE_AVX2=-D _AVX2_
    SIMD=-mavx2
else ifeq "$(AVX)" "TRUE"
    USE_AVX=-D _AVX_
    SIMD=-mavx
endif

ifeq "$(ARCH)" "ARM"
    ARM_SETTING=-lrt
endif

ifeq "$(USE_ENDO)" "TRUE"
    USE_ENDOMORPHISMS=-D USE_ENDO
endif

ifeq "$(SERIAL_PUSH)" "TRUE"
    USE_SERIAL_PUSH=-D PUSH_SET
endif

ifeq "$(DISABLE_FIXED_MUL)" "TRUE"
    NOT_USE_FIXED_MUL=-D _DISABLE_FIXED_MUL_
endif

ifeq "$(DISABLE_DOUBLE_MUL)" "TRUE"
    NOT_USE_DOUBLE_MUL=-D _DISABLE_DOUBLE_MUL_
endif

cc=$(COMPILER)
CFLAGS=-c $(OPT) $(ADDITIONAL_SETTINGS) $(SIMD) -D $(ARCHITECTURE) -D __LINUX__ $(USE_AVX) $(USE_AVX2) $(USE_ASM) $(USE_GENERIC) $(USE_ENDOMORPHISMS) $(USE_SERIAL_PUSH) $(NOT_USE_FIXED_MUL) $(NOT_USE_DOUBLE_MUL)
LDFLAGS=
ifneq "$(GENERIC)" "TRUE"
ifeq "$(AVX2)" "TRUE"
    ASM_OBJECTS=consts.o fp2_1271_AVX2.o
else
    ASM_OBJECTS=consts.o fp2_1271.o
endif 
endif
OBJECTS=FourQ.o eccp2.o eccp2_no_endo.o eccp2_core.o $(ASM_OBJECTS)
OBJECTS_ECC_TEST=ecc_tests.o $(OBJECTS) test_extras.o 
OBJECTS_ALL=$(OBJECTS) $(OBJECTS_ECC_TEST)

ecc_test: $(OBJECTS_ECC_TEST)
	$(CC) -o ecc_test $(OBJECTS_ECC_TEST) $(ARM_SETTING)

FourQ.o: FourQ.c FourQ_internal.h
	$(CC) $(CFLAGS) FourQ.c

eccp2_core.o: eccp2_core.c FourQ_internal.h AMD64/fp_x64.h
	$(CC) $(CFLAGS) eccp2_core.c

eccp2.o: eccp2.c FourQ_internal.h
	$(CC) $(CFLAGS) eccp2.c

eccp2_no_endo.o: eccp2_no_endo.c FourQ_internal.h
	$(CC) $(CFLAGS) eccp2_no_endo.c
    
ifeq "$(AVX2)" "TRUE"
    consts.o: AMD64/consts.c
	    $(CC) $(CFLAGS) AMD64/consts.c
    fp2_1271_AVX2.o: AMD64/fp2_1271_AVX2.S
	    $(CC) $(CFLAGS) AMD64/fp2_1271_AVX2.S
else
    consts.o: AMD64/consts.c
	    $(CC) $(CFLAGS) AMD64/consts.c
    fp2_1271.o: AMD64/fp2_1271.S
	    $(CC) $(CFLAGS) AMD64/fp2_1271.S
endif

test_extras.o: test_extras.c FourQ_internal.h
	$(CC) $(CFLAGS) test_extras.c

ecc_tests.o: ecc_tests.c FourQ_internal.h
	$(CC) $(CFLAGS) ecc_tests.c

.PHONY: clean

clean:
	rm -f ecc_test fp2_1271.o fp2_1271_AVX2.o $(OBJECTS_ALL)

