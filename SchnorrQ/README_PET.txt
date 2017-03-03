                            Hinweise für das PET Projekt
                            ============================

1. Übersicht definierter Typen in FourQ
   ------------------------------------

Name            | Besteht aus                         | Größe
----------------------------------------------------------------------------------------------
digit_t         | uint32_t                            | 32 Bit
felm_t          | Array[4] aus digit_t                | 4*32  = 128 Bit
f2elm_t         | Array[2] aus felm_t                 | 2*128 = 256 Bit
digit256_t      | Array[8] aus digit_t element in Z_r | 8*32  = 256 Bit
point_affine    | Punkt in affinen Koordinaten        | 2*256 = 512 Bit
    .x [f2elm_t]|                                     |
    .y [f2elm_t]|                                     |
point_t         | Array[1] aus point_affine           | Genutzt von A (= Generator der Kurve)
                |                                     |
                |                                     |
                |                                     |
velm_t          | Array[5] aus unit32_t               | 5*32  = 160 Bit
v2elm_t         | Array[10] aus uint32_t              | 10*32 = 320 Bit genutzt 4*64 = 256 Bit
vpoint_affine   | Tupel aus zwei v2elm_t              | 2*320 = 640 Bit
    .x [v2elm_t]|                                     |
    .y [v2elm_t]|                                     |
vpoint_t        | Array[1] aus vpoint_affine          | Genutzt von VA
                |                                     |
                |                                     |
vpoint_extproj  | Punktrepräsenation in erweiterten Koordinaten     Genutzt von VP
    .v2elm_t x  |                                     |
    .v2elm_t y  |                                     |
    .v2elm_t z  |                                     |
    .v2elm_t ta |                                     |
    .v2elm_t tb |                                     |
vpoint_extproj_t| Array[1] aus vpoint_extproj         |




2. Ausführung auf Android
-------------------------

Für die Ausführung auf Android kann die NEON Implementierung verwendet werden, um von einen Geschwindigkeitsvorteil
durch die Nutzung von Single Instruction Multiple Data bei der Programmausführung zu erzielen.

Für die Ausführung des Code müssen folgende Schritte druchgeführt werden

1. Wechseln in das Verzeichnis FourQ_NEON
2. Anpassen des NDK Pfades in der build.sh
3. Ausführung von build.sh
    Dabei wird das Projekt gebaut, die ausführbare Datei nach /data/local/tmp kopiert und gestartet.
    Es werden die FourQ Funktionen getestet und ein Benchmark zu ihnen gestartet. Außerdem befindet sich in dem Programm
    der Stand zu der SchnorrQ Implementierung, den wir erreichen konnten.



3. Vergleich von SchnorrQ zu anderen Verfahren

https://www.cs.bris.ac.uk/Research/CryptographySecurity/RWC/2017/patrick.longa.pdf
Signing:      39k Cycles ( 61k cycles for ed25519)
Verification: 74k Cycles (185k cycles for ed25519)
Schnlüssel Generierung: ~0.5sec (~1.6sec for ed25519)