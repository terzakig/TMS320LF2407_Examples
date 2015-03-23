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


// GPTCONB
struct GPTCONB_BITS  {
   unsigned int T3PIN:2;  // 0-1   Polarity of GP timer 3 compare
   unsigned int T4PIN:2;  // 2-3   Polarity of GP timer 4 compare
   unsigned int rsvd1:2;   // 4-5 Reserved
   unsigned int TCOMPOE:1;  // 6 CoMPare Output Enable (if PDPINT is 0 (active low) TCMPOE is forced low)
   unsigned int T3TOADC:2;  // 7-8 start of ADC with T3
   unsigned int T4TOADC:2;  // 9-10 start of ADC with Timer4
   unsigned int rsvd2:2;    // 11-12 reserved
   unsigned int T3STAT:1;   // 13 Timer 3 Status
   unsigned int T4STAT:1;   // 14 Timer 4 Status
   unsigned int rsvd3:1;    // 15 reserved
};

/* Allow access to the bit fields or entire register */
union GPTCONB_REG {
   unsigned int        all;
   struct  GPTCONB_BITS bit;
};

extern volatile union GPTCONB_REG *GPTCONBbits;


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

//T2CON
struct T2CON_BITS  {
	unsigned int T1PERSEL:1; // 0 Select Period register (1 for T1PR, 0 for own)
	unsigned int TCMPREN:1; // 1 Timer Compare Enables
	unsigned int TCLD:2;    // 2-3 Compare register reload condition
	unsigned int TCLKS:2;   // 4-5 Clock Source Select
	unsigned int TENABLE:1; // 6 Timer Enable
	unsigned int T2SWT1:1;  // 7 if 1, Timer2 starts with Timer1
	unsigned int TPS:3;    // 8-10 Input Clock Prescaling
	unsigned int TMODE:2;  // 11-12  Count mode selection
	unsigned int rsvd3:1;  // 13 reserved
	unsigned int SOFT:1;   // 14 EMUlation control bit 0 (soft)
	unsigned int FREE:1;   // 15 EMUlation control bit 1 (free)

};
union T2CON_REG {
   unsigned int        all;
   struct  T2CON_BITS bit;
};
extern volatile union T2CON_REG *T2CONbits;

//T3CON
struct T3CON_BITS  {
	unsigned int rsvd1:1; // 0 Select Period register (1 for T1PR, 0 for own)
	unsigned int TCMPREN:1; // 1 Timer Compare Enabled
	unsigned int TCLD:2;    // 2-3 Compare register reload condition
	unsigned int TCLKS:2;   // 4-5 Clock Source Select
	unsigned int TENABLE:1; // 6 Timer Enable
	unsigned int rsvd2:1;  // 7 reserved
	unsigned int TPS:3;    // 8-10 Input Clock Prescaling
	unsigned int TMODE:2;  // 11-12  Count mode selection
	unsigned int rsvd3:1;  // 13 reserved
	unsigned int SOFT:1;   // 14 EMUlation control bit 0 (soft)
	unsigned int FREE:1;   // 15 EMUlation control bit 1 (free)

};
/* Allow access to the bit fields or entire register */
union T3CON_REG {
   unsigned int        all;
   struct  T3CON_BITS bit;
};
extern volatile union T3CON_REG *T3CONbits;


//T4CON
struct T4CON_BITS  {
	unsigned int T3PERSEL:1; // 0 Select Period register (1 for T3 PERiod register, 0 for own)
	unsigned int TCMPREN:1; // 1 Timer Compare Enabled
	unsigned int TCLD:2;    // 2-3 Compare register reload condition
	unsigned int TCLKS:2;   // 4-5 Clock Source Select
	unsigned int TENABLE:1; // 6 Timer Enable
	unsigned int T4SWT3:1;  // 7 if 1, Timer4 starts with Timer3
	unsigned int TPS:3;    // 8-10 Input Clock Prescaling
	unsigned int TMODE:2;  // 11-12  Count mode selection
	unsigned int rsvd3:1;  // 13 reserved
	unsigned int SOFT:1;   // 14 EMUlation control bit 0 (soft)
	unsigned int FREE:1;   // 15 EMUlation control bit 1 (free)

};
/* Allow access to the bit fields or entire register */
union T4CON_REG {
   unsigned int        all;
   struct  T4CON_BITS bit;
};

extern volatile union T4CON_REG *T4CONbits;


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
   
union EVAIMRA_REG {
   unsigned int         all;
   struct  EVAIMRA_BITS bit;
};
extern volatile union EVAIMRA_REG *EVAIMRAbits;

//EVAIMRB
struct EVAIMRB_BITS {
   unsigned int   T2PINT:1;       // 0       Enable
   unsigned int   T2CINT:1;       // 1       Enable
   unsigned int   T2UFINT:1;      // 2       Enable
   unsigned int   T2OFINT:1;      // 3       Enable
   unsigned int   rsvd1:12;       // 4-15    reserved
};

union EVAIMRB_REG {
   unsigned int         all;
   struct  EVAIMRB_BITS bit;
};
extern volatile union EVAIMRB_REG *EVAIMRBbits;


// EVAIMRC (Capture 1,2,3 interrupt masks)
struct EVAIMRC_BITS {
    unsigned int   CAP1INT:1;     // 0  Enable/Disable CAP1 interrupt
    unsigned int   CAP2INT:1;     // 1  Enable/Disable CAP2 interrupt
    unsigned int   CAP3INT:1;     // 2  Enable/Disable CAP3 interrupt
    unsigned int   rsvd1:13;      // 3-15     reserved
};

union EVAIMRC_REG {
   unsigned int         all;
   struct  EVAIMRC_BITS bit;
};
extern volatile union EVAIMRC_REG *EVAIMRCbits;

// EVBIMRA
struct EVBIMRA_BITS {
    unsigned int  PDPINTB:1;      // 0       Enable PDPINTB
    unsigned int  CMP4INT:1;      // 1       Enable
    unsigned int  CMP5INT:1;      // 2       Enable
    unsigned int  CMP6INT:1;      // 3       Enable
    unsigned int  rsvd1:3;        // 6:4     reserved
    unsigned int  T3PINT:1;       // 7       Enable
    unsigned int  T3CINT:1;       // 8       Enable
    unsigned int  T3UFINT:1;      // 9       Enable
    unsigned int  T3OFINT:1;      // 10      Enable
    unsigned int  rsvd2:5;        // 15:11   reserved
};

   
/* Allow access to the bit fields or entire register */
union EVBIMRA_REG {
   unsigned int         all;
   struct  EVBIMRA_BITS bit;
};
extern volatile union EVBIMRA_REG *EVBIMRAbits;

struct EVBIMRB_BITS {
   unsigned int   T4PINT:1;       // 0       Enable
   unsigned int   T4CINT:1;       // 1       Enable
   unsigned int   T4UFINT:1;      // 2       Enable
   unsigned int   T4OFINT:1;      // 3       Enable
   unsigned int   rsvd1:12;       // 15:4    reserved
};

/* Allow access to the bit fields or entire register */
union EVBIMRB_REG {
   unsigned int         all;
   struct  EVBIMRB_BITS bit;
};
extern volatile union EVBIMRB_REG *EVBIMRBbits;

struct EVBIMRC_BITS {
    unsigned int   CAP4INT:1;     // 0        Enable
    unsigned int   CAP5INT:1;     // 1        Enable
    unsigned int   CAP6INT:1;     // 2        Enable
    unsigned int   rsvd1:13;      // 3-15     reserved
};

/* Allow access to the bit fields or entire register */
union EVBIMRC_REG {
   unsigned int         all;
   struct  EVBIMRC_BITS bit;
};
extern volatile union EVBIMRC_REG *EVBIMRCbits;


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

//EVAIFRB
struct EVAIFRB_BITS {
   unsigned int   T2PINT:1;       // 0       Flag
   unsigned int   T2CINT:1;       // 1       Flag
   unsigned int   T2UFINT:1;      // 2       Flag
   unsigned int   T2OFINT:1;      // 3       Flag
   unsigned int   rsvd1:12;       // 4-15    reserved
};

union EVAIFRB_REG {
   unsigned int         all;
   struct  EVAIFRB_BITS bit;
};
extern volatile union EVAIFRB_REG *EVAIFRBbits;

//EVAIFRC (CAPture 1,2,3 Interrupt Flags)
struct EVAIFRC_BITS {
    unsigned int   CAP1INT:1;     // 0  CAP1 interrupt Flag
    unsigned int   CAP2INT:1;     // 1  CAP2 interrupt Flag
    unsigned int   CAP3INT:1;     // 2  CAP3 interrupt flag
    unsigned int   rsvd1:13;      // 3-15     reserved
};


union EVAIFRC_REG {
   unsigned int         all;
   struct  EVAIFRC_BITS bit;
};
extern volatile union EVAIFRC_REG *EVAIFRCbits;

/* Interrupt Mask Register bit definitions */
struct EVBIFRA_BITS {
    unsigned int  PDPINTB:1;      // 0       Flag PDPINTB
    unsigned int  CMP4INT:1;      // 1       Flag
    unsigned int  CMP5INT:1;      // 2       Flag
    unsigned int  CMP6INT:1;      // 3       Flag
    unsigned int  rsvd1:3;        // 4-6     reserved
    unsigned int  T3PINT:1;       // 7       Flag
    unsigned int  T3CINT:1;       // 8       Flag
    unsigned int  T3UFINT:1;      // 9       Flag
    unsigned int  T3OFINT:1;      // 10      Flag
    unsigned int  rsvd2:5;        // 11-15   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVBIFRA_REG {
   unsigned int         all;
   struct  EVBIFRA_BITS bit;
};
extern volatile union EVBIFRA_REG *EVBIFRAbits;

struct EVBIFRB_BITS {
   unsigned int   T4PINT:1;       // 0       Flag
   unsigned int   T4CINT:1;       // 1       Flag
   unsigned int   T4UFINT:1;      // 2       Flag
   unsigned int   T4OFINT:1;      // 3       Flag
   unsigned int   rsvd1:12;       // 15:4    reserved
};


union EVBIFRB_REG {
   unsigned int         all;
   struct  EVBIFRB_BITS bit;
};
extern volatile union EVBIFRB_REG *EVBIFRBbits;

struct EVBIFRC_BITS {
	unsigned int CAP4INT:1; // 0 CAP4 int flag
	unsigned int CAP5INT:1; // 1 CAP5 int flag
	unsigned int CAP6INT:1; // 2 CAP6 int flag
	unsigned int rsvd:13;   // 3-15 reserved
};

union EVBIFRC_REG {
	unsigned int all;
	struct EVBIFRC_BITS bit;
};
extern volatile union EVBIFRC_REG *EVBIFRCbits;


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

// COMCONB
struct COMCONB_BITS {
	unsigned int  rsvd1:8; // 0-7 Reserved
	unsigned int  PDPINTBSTAT:1; // 8 PDPINTA pin status
	unsigned int  FCOMPOE:1; // 9 COMPare Output Enable. if 1 (PWM pins are normal, if 09 they are High Impedance)
	unsigned int  ACTRLD:2; // 10-11 Action Control Register Reload Condition
	unsigned int  SVENABLE:1; // 12 Space Vector PWM mode enable
	unsigned int  CLD:2;     // 13-14 Compare register reloaD condition
	unsigned int  CENABLE:1; // 15 Compare Enable
};

/* Allow access to the bit fields or entire register */
union COMCONB_REG {
   unsigned int        all;
   struct  COMCONB_BITS bit;
};
extern volatile union COMCONB_REG *COMCONBbits;


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

// ACTRB
struct ACTRB_BITS {
	unsigned int  CMP7ACT1:2; // 0-1 Action on Compare Output Pin 1
	unsigned int  CMP8ACT1:2; // 2-3 Action on Compare Output Pin 2
	unsigned int  CMP9ACT1:2; // 4-5 Action on Compare Output Pin 3
	unsigned int  CMP10ACT1:2; // 5-7 Action on Compare Output Pin 4
	unsigned int  CMP11ACT1:2; // 8-9 Action on Compare Output Pin 5
	unsigned int  CMP12ACT1:2; // 10-11 Action on Compare Output Pin 6
	unsigned int  D0:1;       // 12 Basic Space Vector bit D0
	unsigned int  D1:1;       // 13 Basic Space Vector bit D1
	unsigned int  D2:1;       // 14 Basic Space Vector bit D2
	unsigned int  SVRDIR:1;   // Space Vector PWM rotation direction (used only in space vector PWM)
};

/* Allow access to the bit fields or entire register */
union ACTRB_REG {
   unsigned int        all;
   struct  ACTRB_BITS bit;
};
extern volatile union ACTRB_REG *ACTRBbits;

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

// DBTCONB
struct DBTCONB_BITS {
   unsigned int   rsvd1:2;       // 0-1    reserved
   unsigned int   DBTPS:3;       // 2-4    Dead-Band timer prescaler
   unsigned int   EDBT1:1;       // 5      Dead-Band timer 1 enable (for pins PWM7-PWM8 of Compare unit4)
   unsigned int   EDBT2:1;       // 6      Dead-Band timer 2 enable (for pins PWM9-PWM10 of Compare unit5)
   unsigned int   EDBT3:1;       // 7      Dead-Band timer 3 enable (for pins PWM11-PWM12 of Compare Unit 6)
   unsigned int   DBT:4;         // 8-11   Dead-Band timer period
   unsigned int   rsvd2:4;       // 12-15  reserved   
};

/* Allow access to the bit fields or entire register */
union DBTCONB_REG {
   unsigned int        all;
   struct  DBTCONB_BITS bit;
};
extern volatile union DBTCONB_REG *DBTCONBbits;


// Capture Control register A (CAPCONA)
struct CAPCONA_BITS {
   unsigned int  rsvd1:2;         // 0-1   reserved
   unsigned int  CAP3EDGE:2;      // 2-3   Edge Detection for Unit 3
   unsigned int  CAP2EDGE:2;      // 4-5   Edge Detection for Unit 2
   unsigned int  CAP1EDGE:2;      // 6-7   Edge Detection for Unit 1
   unsigned int  CAP3TOADC:1;     // 8     Unit 3 starts the ADC
   unsigned int  CAP12TSEL:1;     // 9     GP Timer selection for Units 1 and 2 (0 for Timer 2, 1 for Timer 1)
   unsigned int  CAP3TSEL:1;      // 10    GP Timer selection for Unit 3 (0 for timer2, 1 for timer 1)
   unsigned int  rsvd2:1;         // 11    reserved
   unsigned int  CAP3EN:1;        // 12    Capture Unit 3 control
   unsigned int  CAP12EN:2;       // 13-14 Capture Unit 1 and 2 enabling control
   unsigned int  CAPRES:1;        // 15    Capture reset (always reads 0). Writing 0 clears the capture registers, 1 no action
};

union CAPCONA_REG {
   unsigned int        all;
   struct  CAPCONA_BITS bit;
};  
extern volatile union CAPCONA_REG *CAPCONAbits;

// CAPCONB
struct CAPCONB_BITS {
   unsigned int  rsvd1:2;         // 0-1   reserved
   unsigned int  CAP6EDGE:2;      // 2-3   Edge Detection for Unit 6
   unsigned int  CAP5EDGE:2;      // 4-5   Edge Detection for Unit 5
   unsigned int  CAP4EDGE:2;      // 6-7   Edge Detection for Unit 4
   unsigned int  CAP6TOADC:1;     // 8     Unit 6 starts the ADC
   unsigned int  CAP45TSEL:1;     // 9     GP Timer selection for Units 4 and 5
   unsigned int  CAP6TSEL:1;      // 10    GP Timer selection for Unit 6
   unsigned int  rsvd2:1;         // 11    reserved
   unsigned int  CAP6EN:1;        // 12    Capture Unit 6 control
   unsigned int  CAP45EN:2;       // 13-14 Capture Unit 4 and 5 control
   unsigned int  CAPRES:1;        // 15    Capture reset (always reads 0). 0 clears the capture registers, 1 no action
};

/* Allow access to the bit fields or entire register */
union CAPCONB_REG {
   unsigned int        all;
   struct  CAPCONB_BITS bit;
}; 
extern volatile union CAPCONB_REG *CAPCONBbits;

// Capture FIFO status register A (CAPFIFOA)
struct CAPFIFOA_BITS {
	unsigned int rsvd1:8; // 0-7 reserved
	unsigned int CAP1FIFOSTAT:2; // 8-9 CAP1 FIFO status
	unsigned int CAP2FIFOSTAT:2; // 10-11 CAP2 FIFO status
	unsigned int CAP3FIFOSTAT:2; // 12-13 CAP3 FIFO status
	unsigned int rsvd2:2;        // 14-15 reserved
};

union CAPFIFOA_REG {
	unsigned int all;
	struct CAPFIFOA_BITS bit;
};

extern volatile union CAPFIFOA_REG *CAPFIFOAbits;

//CAPFIFOB
struct CAPFIFOB_BITS {
	unsigned int rsvd1:8;   //0-7 reserved
	unsigned int CAP4FIFOSTAT:2;  // 8-9 CAP4 FIFO status
	unsigned int CAP5FIFOSTAT:2;  // 10-11 CAP5 FIFO status
	unsigned int CAP6FIFOSTAT:2;  // 12-13 CAP6 FIFO status
	unsigned int rsvd2:2;         // 14-15 reserved
};

union CAPFIFOB_REG {
	unsigned int all;
	struct CAPFIFOB_BITS bit;
};
extern volatile union CAPFIFOB_REG *CAPFIFOBbits; 



extern volatile unsigned int *T1CNT;   /* GP timer 1 counter reg */
extern volatile unsigned int *T1CMPR;   /* GP timer 1 compare reg */
extern volatile unsigned int *T1PR;   /* GP timer 1 period */


extern volatile unsigned int *T2CNT; /* GP timer 2 counter reg */
extern volatile unsigned int *T2CMPR; /* GP timer 2 compare reg */
extern volatile unsigned int *T2PR; /* GP timer 2 period reg */

extern volatile unsigned int *CMPR1; /* Compare register for Compare unit1 */
extern volatile unsigned int *CMPR2; /* Compare register for Compare unit2 */
extern volatile unsigned int *CMPR3; /* Compare register for Compare unit3 */


extern volatile unsigned int *T3CNT;   /* GP timer 3 counter  */
extern volatile unsigned int *T3CMPR;   /* GP timer 3 compare */
extern volatile unsigned int *T3PR;   /* GP timer 3 period */

extern volatile unsigned int *T4CNT;  /* GP timer 4 counter reg */
extern volatile unsigned int *T4CMPR; /* GP timer 4 compare reg */
extern volatile unsigned int *T4PR;   /* GP timer 4 period reg */


extern volatile unsigned int *CMPR4; /* Compare register for Compare unit4 */
extern volatile unsigned int *CMPR5; /* Compare register for Compare unit5 */
extern volatile unsigned int *CMPR6; /* Compare register for Compare unit6 */


extern volatile unsigned int *CAP1FIFO; /* Capture Channel 1 FIFO top */
extern volatile unsigned int *CAP2FIFO; /* Capture channel 2 FIIFO top */
extern volatile unsigned int *CAP3FIFO; /* Capture channel 3 FIFO top */
extern volatile unsigned int *CAP1FBOT; /* Capture channel 1 FIFO BOTtom */
extern volatile unsigned int *CAP2FBOT; /* Capture channel 2 FIFO BOTtom */
extern volatile unsigned int *CAP3FBOT; /* Capture channel 3 FIFO BOTtom */

extern volatile unsigned int *CAP4FIFO; /* Capture Channel 4 FIFO top */
extern volatile unsigned int *CAP5FIFO; /* Capture channel 5 FIIFO top */
extern volatile unsigned int *CAP6FIFO; /* Capture channel 6 FIFO top */
extern volatile unsigned int *CAP4FBOT; /* Capture channel 4 FIFO BOTtom */
extern volatile unsigned int *CAP5FBOT; /* Capture channel 5 FIFO BOTtom */
extern volatile unsigned int *CAP6FBOT; /* Capture channel 6 FIFO BOTtom */


#endif