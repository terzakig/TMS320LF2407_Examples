#ifndef DSP24_EV_H
#define DSP24_EV_H



//Timer 1 CONtrol register (T1CON)
struct T1CON_BITS  {
	unsigned int rsvd1:1;    // 0 Reserved
	unsigned int TCMPREN:1; // 1 Timer Compare Enabled
	unsigned int TCLD:2;    // 2-3 Compare register reload condition
	unsigned int TCLKS:2;   // 4-5 Clock Source Select
	unsigned int TENABLE:1; // 6 Timer Enable
	unsigned int rsvd2:1;  // 7 Reserved
	unsigned int TPS:3;    // 8-10 Input Clock Prescaling
	unsigned int TMODE:2;  // 11-12 Count mode selection
	unsigned int rsvd3:1;  // 13 reserved
	unsigned int SOFT:1;   // 14 EMUlation control bit 0 (soft)
	unsigned int FREE:1;   // 15 EMUlation control bit 1 (free)

};

union T1CON_REG {
   unsigned int        all;
   struct  T1CON_BITS bit;
};

extern volatile union T1CON_REG *T1CONbits;

/* Interrupt Mask Register bit definitions */
struct EVAIMRA_BITS {
    unsigned int  PDPINTA:1;      // 0       Enable PDPINTA
    unsigned int  CMP1INT:1;      // 1       Enable
    unsigned int  CMP2INT:1;      // 2       Enable
    unsigned int  CMP3INT:1;      // 3       Enable
    unsigned int  rsvd1:3;        // 4-6     reserved
    unsigned int  T1PINT:1;       // 7       Enable
    unsigned int  T1CINT:1;       // 8       Enable
    unsigned int  T1UFINT:1;      // 9       Enable
    unsigned int  T1OFINT:1;      // 10      Enable
    unsigned int  rsvd2:5;        // 11-15   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVAIMRA_REG {
   unsigned int         all;
   struct  EVAIMRA_BITS bit;
};
extern volatile union EVAIMRA_REG *EVAIMRAbits;

/* Interrupt Flag Registers bit definitions */
//EVAIFRA
struct EVAIFRA_BITS {
    unsigned int  PDPINTA:1;      // 0       Flag PDPINTA
    unsigned int  CMP1INT:1;      // 1       Flag
    unsigned int  CMP2INT:1;      // 2       Flag
    unsigned int  CMP3INT:1;      // 3       Flag
    unsigned int  rsvd1:3;        // 4-6     reserved
    unsigned int  T1PINT:1;       // 7       Flag
    unsigned int  T1CINT:1;       // 8       Flag
    unsigned int  T1UFINT:1;      // 9       Flag
    unsigned int  T1OFINT:1;      // 10      Flag
    unsigned int  rsvd2:5;        // 11-15   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVAIFRA_REG {
   unsigned int         all;
   struct  EVAIFRA_BITS bit;
};
extern volatile union EVAIFRA_REG *EVAIFRAbits;

extern volatile unsigned int *T1CNT;   /* GP timer 1 counter reg */
extern volatile unsigned int *T1CMPR;   /* GP timer 1 compare reg */
extern volatile unsigned int *T1PR;   /* GP timer 1 period reg  */

#endif