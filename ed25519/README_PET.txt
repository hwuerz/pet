                            Hinweise für das PET Projekt
                            ============================

___ Lauffähig machen & Ausführen ____

1. Analog des ECDSA Beispiels die Variablen in der Makefile setzen. D.h.
	> SYSROOT nach .../Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
	> ADB nach .../Android/Sdk/platform-tools/adb
	> CXX nach .../Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc-4.9

2. Kompilieren und Laden per "make all"

3. Per "adb shell" in "/data/local/tmp" wechseln und "./test_ed25519" ausführen


___ Verändern der Ausführungsparameter ___

1. In main_pet.c die Variablen "MSG_LEN", "NUM_SIGN" verändern

2. Neu kompilieren und ausführen
