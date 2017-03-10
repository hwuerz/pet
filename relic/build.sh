#!/bin/bash

export NDK=/home/nils/Android/Sdk/android-ndk-r14

SYSROOT=$NDK/platforms/android-18/arch-arm
MIDDLE=toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/
PREF=arm-linux-androideabi-
ADB=/home/nils/Android/Sdk/platform-tools/adb

MAXOPTIMIZATIONS="-DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4"
CFLAGS="-Wall -O3 -fomit-frame-pointer -static"
export CC="$NDK/$MIDDLE/${PREF}gcc-4.9 --sysroot=$SYSROOT"
export CXX="$NDK/$MIDDLE/${PREF}g++-4.9 --sysroot=$SYSROOT"
export LD="$NDK/$MIDDLE/${PREF}ld --sysroot=$SYSROOT"
export CPP="$NDK/$MIDDLE/${PREF}cpp --sysroot=$SYSROOT"
export AS="$NDK/$MIDDLE/${PREF}as --sysroot=$SYSROOT"
export OBJCOPY="$NDK/$MIDDLE/${PREF}objcopy --sysroot=$SYSROOT"
export OBJDUMP="$NDK/$MIDDLE/${PREF}objdump --sysroot=$SYSROOT"
export STRIP="$NDK/$MIDDLE/${PREF}strip --sysroot=$SYSROOT"
export RANLIB="$NDK/$MIDDLE/${PREF}ranlib --sysroot=$SYSROOT"
export CCLD="$NDK/$MIDDLE/${PREF}gcc --sysroot=$SYSROOT"
export AR="$NDK/$MIDDLE/${PREF}ar --sysroot=$SYSROOT"

cmake -DWITH="DV;BN;MD;FP;EP;FPX;EPX;PP;PC;CP" -DCHECK=off -DARITH=arm-asm-254 -DARCH=ARM -DCOLOR=off -DOPSYS=DROID -DFP_PRIME=254 -DFP_QNRES=on -DFP_METHD="INTEG;INTEG;INTEG;MONTY;EXGCD;SLIDE" -DFPX_METHD="INTEG;INTEG;LAZYR" -DPP_METHD="LAZYR;OATEP" -DCOMP="-Wall -O3 -funroll-loops -fomit-frame-pointer -I$SYSROOT/usr/include -DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4 -fPIC" -DLINK="-L$SYSROOT/usr/lib/ -llog -pie" -DTIMER=HREAL -DWORD=32 -DSTLIB=on -DBN_PRECI=3072 -DBENCH=10 -DSHLIB=off $1

make
$ADB push bin/bench_cp /data/local/tmp
$ADB shell "cd /data/local/tmp && ./bench_cp"
