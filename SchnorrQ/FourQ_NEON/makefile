####  Makefile for compilation using GNU GCC or clang on ARM-based processors with NEON support  ####

OPT=-O3   # Optimization option by default

ifeq "$(CC)" "gcc"
    COMPILER=gcc
else ifeq "$(CC)" "clang"
    COMPILER=clang
endif

ifeq "$(ARCH)" "ARM"
    ARCHITECTURE=-D _ARM_
else
    ARCHITECTURE=UNSUPPORTED_ARCHITECTURE
endif

ADDITIONAL_SETTINGS=
ifeq "$(SET)" "EXTENDED"
    ADDITIONAL_SETTINGS=-fwrapv -fomit-frame-pointer -funroll-loops
endif

INLINING_SETTINGS=
ifeq "$(CC)" "gcc"
    INLINING_SETTINGS=-finline-functions -finline-limit=300
endif

ifeq "$(INTERLEAVE)" "TRUE"
    USE_INTERLEAVING=-D _INTERLEAVE_
endif

ifeq "$(MIX_ARM_NEON)" "TRUE"
    USE_ARM_NEON_MIX=-D _MIX_ARM_NEON_
endif

ifeq "$(DISABLE_FIXED_MUL)" "TRUE"
    NOT_USE_FIXED_MUL=-D _DISABLE_FIXED_MUL_
endif

ifeq "$(DISABLE_DOUBLE_MUL)" "TRUE"
    NOT_USE_DOUBLE_MUL=-D _DISABLE_DOUBLE_MUL_
endif

CFLAGS=-fPIC -march=armv7-a  -Wall -O3 -fomit-frame-pointer -static -c $(OPT) $(ADDITIONAL_SETTINGS) $(ARCHITECTURE) -D __LINUX__ -mfloat-abi=hard -mfpu=neon $(USE_INTERLEAVING) $(USE_ARM_NEON_MIX) $(NOT_USE_FIXED_MUL) $(NOT_USE_DOUBLE_MUL) $(INLINING_SETTINGS)
LDFLAGS=

OBJECTS=FourQ.o eccp2.o fp2_1271_NEON.o sha2.o
OBJECTS_ECC_TEST=ecc_tests.o test_extras.o $(OBJECTS)
OBJECTS_SCHNORRQ=schnorrq.o ecc_tests.o test_extras.o $(OBJECTS)
OBJECTS_ALL=$(OBJECTS) $(OBJECTS_ECC_TEST) $(OBJECTS_SCHNORRQ)

schnorrq: $(OBJECTS_SCHNORRQ)
	$(CC) -pie -march=armv7-a -mfloat-abi=hard -mfpu=neon -Wl,--fix-cortex-a8 -Wl,--no-warn-mismatch -lm_hard -o schnorrq $(OBJECTS_SCHNORRQ)

ecc_test: $(OBJECTS_ECC_TEST)
	$(CC) -pie -march=armv7-a -mfloat-abi=hard -mfpu=neon -Wl,--fix-cortex-a8 -Wl,--no-warn-mismatch -lm_hard -o ecc_test $(OBJECTS_ECC_TEST)

FourQ.o: FourQ.c FourQ_internal.h
	$(CC) $(CFLAGS) FourQ.c

eccp2.o: eccp2.c FourQ_internal.h
	$(CC) $(CFLAGS) eccp2.c

fp2_1271_NEON.o: ARM/fp2_1271_NEON.c
	$(CC) $(CFLAGS) ARM/fp2_1271_NEON.c

sha2.o: sha2.c sha2.h
	$(CC) $(CFLAGS) sha2.c

test_extras.o: test_extras.c FourQ_internal.h
	$(CC) $(CFLAGS) test_extras.c

ecc_tests.o: ecc_tests.c FourQ_internal.h
	$(CC) $(CFLAGS) ecc_tests.c

schnorrq.o: schnorrq.c FourQ_internal.h
	$(CC) $(CFLAGS) schnorrq.c

.PHONY: clean

clean:
	rm -f schnorrq ecc_test fp2_1271_NEON.o $(OBJECTS_ALL)

