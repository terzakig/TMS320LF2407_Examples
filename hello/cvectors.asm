
        .ref _c_int0
        .ref _INT1_GISR
        .ref _INT2_GISR
        .ref _INT3_GISR
        .ref _INT4_GISR
        .ref _INT5_GISR
        .ref _INT6_GISR

        .sect    "vectors"
rset:   B       _c_int0         ;00h reset
int1:   B       _INT1_GISR            ;02h INT1
int2:   B       _INT2_GISR      ;04h INT2
int3:   B       _INT3_GISR     ;06h INT3
int4:   B       _INT4_GISR      ;08h INT4
int5:   B       _INT5_GISR      ;0Ah INT5
int6:   B       _INT6_GISR      ;0Ch INT6
int7:   B       int7            ;0Eh reserved
int8:   B       int8            ;10h INT8  (software)
int9:   B       int9            ;12h INT9  (software)
int10:  B       int10           ;14h INT10 (software)
int11:  B       int11           ;16h INT11 (software)
int12:  B       int12           ;18h INT12 (software)
int13:  B       int13           ;1Ah INT13 (software)
int14:  B       int14           ;1Ch INT14 (software)
int15:  B       int15           ;1Eh INT15 (software)
int16:  B       int16           ;20h INT16 (software)
int17:  B       int17           ;22h TRAP
int18:  B       int18           ;24h NMI
int19:  B       int19           ;26h reserved
int20:  B       int20           ;28h INT20 (software)
int21:  B       int21           ;2Ah INT21 (software)
int22:  B       int22           ;2Ch INT22 (software)
int23:  B       int23           ;2Eh INT23 (software)
int24:  B       int24           ;30h INT24 (software)
int25:  B       int25           ;32h INT25 (software)
int26:  B       int26           ;34h INT26 (software)
int27:  B       int27           ;36h INT27 (software)
int28:  B       int28           ;38h INT28 (software)
int29:  B       int29           ;3Ah INT29 (software)
int30:  B       int30           ;3Ch INT30 (software)
int31:  B       int31           ;3Eh INT31 (software)
