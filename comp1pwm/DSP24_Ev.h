#ifndef DSP24_EV_H
#define DSP24_EV_H

// General Purpose Timer Control Register A (GPTCONA)
struct GPTCONA_BITS  {
   unsigned int T1PIN:2;         // 0-1   Polarity of GP timer 1 compare
   unsigned int T2PIN:2;         // 2-3   Polarity of GP timer 2 compare
   unsigned int rsvd1:2;         // 4-5 Reserved
   unsigned int TCOMPOE:1;       // 6 CoMPare Output Enable (if PDPINT is 0 (active low) TCMPOE is forced low)
   unsigned int T1TOADC:2;       // 7-8 Start ADC with Timer 3
   unsigned int T2TOADC:2;       // 9-10 Start ADC with Timer 4
   unsigned int rsvd2:2;         // 11-12 Reserved
   unsigned int T1STAT:1;        // 13 Timer 3 STATus
   unsigned int T2STAT:1;        // 14 Timer 3 STATus
   unsigned int rsvd3:1;         // 15 reserved

};

/* Allow access to the bit fields or entire register */
union GPTCONA_REG {
   unsigned int        all;
   struct  GPTCONA_BITS bit;
};

extern volatile union GPTCONA_REG *GPTCONAbits;

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
   
union EVAIFRA_REG {
   unsigned int         all;
   struct  EVAIFRA_BITS bit;
};
extern volatile union EVAIFRA_REG *EVAIFRAbits;


// COMpare Control Register A (COMCONA)
struct COMCONA_BITS {
	unsigned int  rsvd1:8; // 0-7 Reserved
	unsigned int  PDPINTASTAT:1; // 8 PDPINTA pin status
	unsigned int  FCOMPOE:1; // 9 COMPare Output Enable. if 1 (PWM pins are normal, if 09 they are High Impedance)
	unsigned int  ACTRLD:2; // 10-11 Action Control Register Reload Condition
	unsigned int  SVENABLE:1; // 12 Space Vector PWM mode enable
	unsigned int  CLD:2;     // 13-14 Compare register reloaD condition
	unsigned int  CENABLE:1; // 15 Compare Enable
};

union COMCONA_REG {
   unsigned int        all;
   struct  COMCONA_BITS bit;
};
extern volatile union COMCONA_REG *COMCONAbits;

// Compare Action Control Registers ACTRA (ACTRA)

struct ACTRA_BITS {
	unsigned int  CMP1ACT:2; // 0-1 Action on Compare Output Pin 1
	unsigned int  CMP2ACT:2; // 2-3 Action on Compare Output Pin 2
	unsigned int  CMP3ACT:2; // 4-5 Action on Compare Output Pin 3
	unsigned int  CMP4ACT:2; // 5-7 Action on Compare Output Pin 4
	unsigned int  CMP5ACT:2; // 8-9 Action on Compare Output Pin 5
	unsigned int  CMP6ACT:2; // 10-11 Action on Compare Output Pin 6
	unsigned int  D0:1;       // 12 Basic Space Vector bit D0
	unsigned int  D1:1;       // 13 Basic Space Vector bit D1
	unsigned int  D2:1;       // 14 Basic Space Vector bit D2
	unsigned int  SVRDIR:1;   // Space Vector PWM rotation direction (used only in space vector PWM)
};

/* Allow access to the bit fields or entire register */
union ACTRA_REG {
   unsigned int        all;
   struct  ACTRA_BITS bit;
};
extern volatile union ACTRA_REG *ACTRAbits;

/* Dead-Band Timer Control register bit definitions */
// DBTCONA
struct DBTCONA_BITS {
   unsigned int   rsvd1:2;       // 0-1    reserved
   unsigned int   DBTPS:3;       // 2-4    Dead-Band timer prescaler
   unsigned int   EDBT1:1;       // 5      Dead-Band timer 1 enable (for pins PWM1-PWM2 of Compare unit 1) 
   unsigned int   EDBT2:1;       // 6      Dead-Band timer 2 enable (for pins PWM3-PWM4 of Compare unit 2)
   unsigned int   EDBT3:1;       // 7      Dead-Band timer 3 enable (for pins PWM5-PWM6 of Compare unit 3)
   unsigned int   DBT:4;         // 8-11   Dead-Band timer period
   unsigned int   rsvd2:4;       // 12-15  reserved   
};

union DBTCONA_REG {
   unsigned int        all;
   struct  DBTCONA_BITS bit;
};
extern volatile union DBTCONA_REG *DBTCONAbits;

extern volatile unsigned int *T1CNT;   /* GP timer 1 counter reg */
extern volatile unsigned int *T1CMPR;   /* GP timer 1 compare reg */
extern volatile unsigned int *T1PR;   /* GP timer 1 period reg  */
extern volatile unsigned int *CMPR1; // CoMPare Register for Compare unit1

#endif