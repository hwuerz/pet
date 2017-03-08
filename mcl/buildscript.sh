#!/bin/bash
cd adt/mcladt

#####################################################
# Path to Android SDK
#####################################################
export ANDROID_HOME=/home/david/Android/Sdk
#####################################################
# Path to Android NDK
#####################################################
export ANDROID_NDK_HOME=${ANDROID_HOME}/ndk-bundle
#####################################################
# Path to pre built toolchain
#####################################################
export TC=${ANDROID_NDK_HOME}/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
#####################################################
# Path to JDK
#####################################################
export JDK=/usr/lib/jvm/java-8-openjdk-amd64/bin
#####################################################
# Path to ANT
#####################################################
export ANT=/usr/share/ant/bin
#####################################################
# Add Java, Ant, Android SDK and NDK to PATH
#####################################################
export PATH="${ANDROID_HOME}/tools:${ANDROID_HOME}/platform-tools:${TC}:${ANDROID_NDK_HOME}:${JDK}:${ANT}:$PATH"

ndk-build
ant debug
echo "INSTALLING APK..."
adb install -r bin/MainActivity-debug.apk
echo "STARTING APP ON YOUR DEVICE..."
adb shell am start -n com.herumi.mcladt/com.herumi.mcladt.MainActivity
