#!/usr/bin/env bash

# Delete old files
make clean

export NDK=/home/hendrik/Android/Sdk/ndk-bundle-10e

SYSROOT=$NDK/platforms/android-21/arch-arm
MIDDLE=toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
PREF=arm-linux-androideabi-

MAXOPTIMIZATIONS="-DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4"

export CC="$NDK/$MIDDLE/${PREF}gcc --sysroot=$SYSROOT"
export CXX="$NDK/$MIDDLE/${PREF}g++ --sysroot=$SYSROOT"
export LD="$NDK/$MIDDLE/${PREF}ld --sysroot=$SYSROOT"
export CPP="$NDK/$MIDDLE/${PREF}cpp --sysroot=$SYSROOT"
export AS="$NDK/$MIDDLE/${PREF}as --sysroot=$SYSROOT"
export OBJCOPY="$NDK/$MIDDLE/${PREF}objcopy --sysroot=$SYSROOT"
export OBJDUMP="$NDK/$MIDDLE/${PREF}objdump --sysroot=$SYSROOT"
export STRIP="$NDK/$MIDDLE/${PREF}strip --sysroot=$SYSROOT"
export RANLIB="$NDK/$MIDDLE/${PREF}ranlib --sysroot=$SYSROOT"
export CCLD="$NDK/$MIDDLE/${PREF}gcc --sysroot=$SYSROOT"
export AR="$NDK/$MIDDLE/${PREF}ar --sysroot=$SYSROOT"

make CC="$NDK/$MIDDLE/${PREF}gcc --sysroot=$SYSROOT" ARCH=ARM INTERLEAVE=TRUE MIX_ARM_NEON=TRUE

adb push ecc_test /data/local/tmp
adb shell "cd /data/local/tmp && ./ecc_test"
adb shell "rm /data/local/tmp/ecc_test"