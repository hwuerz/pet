# prebuild OpenSSL library for Android (armeabi)

# How to build

Download [openssl-1.0.2g.tgz](https://www.openssl.org/source/openssl-1.0.2k.tar.gz).
see [Build the OpenSSL Library](https://wiki.openssl.org/index.php/Android#Build_the_OpenSSL_Library_2)
```
export NDK_HOME=$HOME/Android/Sdk/ndk-bundle/
```

```
tar xvf openssl-1.0.2g.tar.gz
. ./Setenv-android.sh
ANDROID_ARCH=arch-arm
ANDROID_EABI=arm-linux-androideabi-4.9
ANDROID_API=android-19
```
```
cd openssl-1.0.2g
perl -pi -e 's/install: all install_docs install_sw/install: install_docs install_sw/g' Makefile.org
./config shared no-ssl2 no-ssl3 no-comp no-hw no-engine --openssldir=$HOME/android-ssl
make depend
make -j8
make install CC=$ANDROID_TOOLCHAIN/arm-linux-androideabi-gcc RANLIB=$ANDROID_TOOLCHAIN/arm-linux-androideabi-ranlib
```

```
cd openssl-android
mkdir -p lib/armeabi
cp -a $HOME/android-ssl/lib/*.a lib/armeabi/
cp -a $HOME/android-ssl/lib/libcrypto.so.1.0.0 lib/armeabi/libcrypto.so
cp -a $HOME/android-ssl/lib/libssl.so.1.0.0 lib/armeabi/libssl.so
cp -a $HOME/android-ssl/include .
```

