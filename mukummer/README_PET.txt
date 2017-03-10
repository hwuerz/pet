                            Hinweise für das PET Projekt
                            ============================

___ Probleme und Hinweise der Version ___

> Fehlerbehaftete hadamard.s:
- Das Projekt lässt sich nicht mit der originalen Implementierung der Hadamard-Transformation (hadamard.s) kompilieren, da dies
  immer einen Segmentation-Fault verursacht (wird sowohl bei Key-Generation, Signatur, Verifikation verwendet). Als Lösung habe
  ich, da ich mich mit ARM Assembler Code nicht auskenne, einfach die Datei "hadamard.s" dekompiliert; in der Annahme, dass
  die C-Version äquivalent (nur weniger effizient) ist, habe ich deshalb eine "hadamard.c" mit dem dekompilierten Code hinzugefügt,
  welche auch tatsächlich lauffähig ist. Allerdings werden nun valide Signaturen nicht als solche erkannt.
- Außerdem: In "hadamard.c" ist eine Inline-Assembly-Version zu finden - welche auch Segmentation-Faults verursacht - und eine 
  Referenzversion von github, welche allerdings für die gegebenen Probleme nicht äquivalent ist; ich kenne mich jedoch selbst mit den
  Details der Elliptic Curve Cryptography zu wenig aus. Beide Varianten könnte man weiterentwickeln.

> Fehler durch Optimierungsniveaus:
- Durch einiges Suchen (siehe: test_pet.c) habe ich herausgefunden, dass jede Optimierungsstufe (-O1, -O2, -O3) zu Segmentation-Faults
  oder Address-BUS-Errors führt.


___ Lauffähig machen & Ausführen ___

1. Analog des ECDSA Beispiels die Variablen in der Makefile setzen. D.h.
	> SYSROOT nach .../Android/Sdk/ndk-bundle/platforms/android-19/arch-arm/
	> ADB nach .../Android/Sdk/platform-tools/adb
	> CXX nach .../Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc-4.9

2. Kompilieren und Laden per "make all"

3. Per "adb shell" in "/data/local/tmp" wechseln und "./test_ed25519" ausführen


___ Verändern der Ausführungsparameter ___

1. In main_pet.c die Variablen "MSG_LEN", "NUM_SIGN" verändern

2. Neu kompilieren und ausführen


___ Quellen: ___
https://cryptojedi.org/papers/mukummer-20160407.pdf

http://www.cs.ru.nl/~jrenes/
