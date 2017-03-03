#!/usr/bin/env bash

#export SYSROOT=/home/hendrik/Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
#export ADB=/home/hendrik/Android/Sdk/platform-tools/adb
#export CXX=/home/hendrik/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc
#export CC=/home/hendrik/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc

#MAXOPTIMIZATIONS = -DuECC_SQUARE_FUNC=1 -DuECC_SUPPORT_COMPRESSED_POINT=0 -DuECC_ENABLE_VLI_API=1 -DuECC_OPTIMIZATION_LEVEL=4
#CFLAGS = -Wall -O3 -fomit-frame-pointer -static
#
#$(CXX) $(CFLAGS) $(MAXOPTIMIZATIONS) --sysroot=$(SYSROOT)
#
#rm -r cmake-build-debug


clear

git clean -f -d

cmake ./CMakeLists.txt
cd cmake-build-debug
make
cd bin
./test_cp

cd ../../