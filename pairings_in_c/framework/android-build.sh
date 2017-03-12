#!/usr/bin/env bash

ARCHITECTURE=ARCH_ARM_ANDROID

export NDKROOT=/opt/android-ndk
$NDKROOT/build/tools/make-standalone-toolchain.sh --platform=android-19 --install-dir=$NDKROOT/android_armeabi
export CC="$NDKROOT/android_armeabi/bin/arm-linux-androideabi-gcc --sysroot=$NDKROOT/android_armeabi/sysroot"
export CXX="$NDKROOT/android_armeabi/bin/arm-linux-androideabi-g++ --sysroot=$NDKROOT/android_armeabi/sysroot"
export AR="$NDKROOT/android_armeabi/bin/arm-linux-androideabi-ar"
export SYSROOT="$NDKROOT/android_armeabi/sysroot"
export PATH="$NDKROOT/android_armeabi/bin":$PATH
export RANLIB="$NDKROOT/android_armeabi/bin/arm-linux-androideabi-ranlib"


#cmake clean
mkdir build
cd build
cmake ../framework/ -DARCHITECTURE=${ARCHITECTURE}
#cmake --build .
make ibe_demo
make bench
#make XYZ
