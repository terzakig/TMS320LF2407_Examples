#ifndef DSP24_ADC_H
#define DSP24_ADC_H


//ADCTRL1
struct ADCTRL1_BITS {     // bits  description
	unsigned int  STESTENA:1;    // 0 Self TEST mode enabled
	unsigned int  HILO:1;        // 1  Test Voltage for Test Mode
	unsigned int  BRGENA:1;      // 2 Allows a refernce voltage in calibration
	unsigned int  CALENA:1;      // 3 Calibration enable - disabled the imput channel multiplxer in order to calibrate
	unsigned int  SEQCASC:1;     // 4 SEQuencer CASCaded operation
	unsigned int  INTPRI:1;      // 5 ADC interrupt request priority (HIGH/LOW)
	unsigned int  CONTRUN:1;     // 6 Continuous run
	unsigned int  CPS:1;         // 7 Conversion Clock Prescale
	unsigned int  ACQPS:4;		   // 8-11 acquisition windows prescale
	unsigned int  FREE:1;			// 12 used in Emulation
	unsigned int  SOFT:1;		    // 13 used in emulation mode
	unsigned int  RESET:1;		   // 14 ADC software reset
	unsigned int  rsvd1:1;		  // 15 reserved 
	
};

//ADCTRL1
union ADCTRL1_REG {
   unsigned int             all;
   struct ADCTRL1_BITS  bit; 
};
extern volatile union ADCTRL1_REG* ADCTRL1bits;
 
//ADCTRL2
struct ADCTRL2_BITS {        // bits  description
	unsigned int  EVBSOCSEQ2:1;   // 0 Allows SOC trigger by EVent manager B
	unsigned int  INTFLAGSEQ2:1;  // 1 INTerrupt flag for SEQ2
	unsigned int  INTENASEQ2:2;   // 3-2 INTerrupt mode ENAble for SEQ2
	unsigned int  SEQ2BSY:1;      // 4 SEQ2 BuSY flag
	unsigned int  SOCSEQ2:1;      // 5 SOC trigger for SEQ2
	unsigned int  RSTSEQ2:1;      // 6 ReSeT SEQ2
	unsigned int  EXTSOCSEQ1:1;    // 7 Allows SOC by the ADSOC pin (external)
	unsigned int  EVASOCSEQ1:1;    // 8 Allows SOC by Event Manager A
	unsigned int  INTFLAGSEQ1:1;   // 9 INTerrupt Flag for SEQ1
	unsigned int  INTENASEQ1:2;    // 10-11 Interrupt mode Enabled for SEQ1
	unsigned int  SEQ1BSY:1;       // 12 Sequencer1 busy
	unsigned int  SOCSEQ1:1;        // 13 SOC triogger for SEQ1
	unsigned int  RSTSEQ1STRTCAL:1; // 14 resets sequencer to CONV00 state
	unsigned int  EVBSOCSEQ:1;       // 15 SOC by Event ManagerB. Active only in Cascaded mode
	
};

union ADCTRL2_REG {
   unsigned int             all;
   struct ADCTRL2_BITS  bit;
};

extern volatile union ADCTRL2_REG *ADCTRL2bits;



// AUTO_SEQ_SR
struct AUTO_SEQ_SR_BITS {
	unsigned int  SEQ1STATE:3;  // 0-3 SEQ1 state (not relevant in cascaded mode)
	unsigned int  SEQ2STATE:2;  //4-6 SEQ2 state (not relevant in cascaded mode)
	unsigned int  rsvd2:1;   // 7 reserved
	unsigned int  SEQCNTR:4; // 8-11 Sequencing counter status bits
	unsigned int  rsvd1:4; //12-15 reserved
	
};

union AUTO_SEQ_SR_REG {
	unsigned int all;
	struct AUTO_SEQ_SR_BITS bit;
};
extern volatile union AUTO_SEQ_SR_REG *AUTO_SEQ_SRbits;


// CHSELSEQ1
struct CHSELSEQ1_BITS {
    unsigned int  CONV00:4;
    unsigned int  CONV01:4;
    unsigned int  CONV02:4;
    unsigned int  CONV03:4;
};

union  CHSELSEQ1_REG{
   unsigned int all;
   struct CHSELSEQ1_BITS bit;
};

extern volatile union CHSELSEQ1_REG *CHSELSEQ1bits;

//CHSELSEQ2
struct CHSELSEQ2_BITS {
    unsigned int  CONV04:4;
    unsigned int  CONV05:4;
    unsigned int  CONV06:4;
    unsigned int  CONV07:4;
};

union  CHSELSEQ2_REG{
   unsigned int all;
   struct CHSELSEQ2_BITS  bit;
};

extern volatile union CHSELSEQ2_REG *CHSELSEQ2bits;


//CHSELSEQ3
struct CHSELSEQ3_BITS {
    unsigned int  CONV08:4;
    unsigned int  CONV09:4;
    unsigned int  CONV10:4;
    unsigned int  CONV11:4;
};

union  CHSELSEQ3_REG{
   unsigned int all;
   struct CHSELSEQ3_BITS bit;
};
extern volatile union CHSELSEQ3_REG *CHSELSEQ3bits;


//CHSELSEQ4
struct CHSELSEQ4_BITS {
    unsigned int  CONV12:4;
    unsigned int  CONV13:4;
    unsigned int  CONV14:4;
    unsigned int  CONV15:4;
};

union  CHSELSEQ4_REG {
   unsigned int all;
   struct CHSELSEQ4_BITS bit;
};
extern volatile union CHSELSEQ4_REG *CHSELSEQ4bits;


// MAXCONV
extern volatile unsigned int *MAXCONV;

// RESULT REGISTERS (access i-th register as: *(RESULT+i), i=0,...,15)
extern volatile unsigned int *RESULT;

// CALIBRATION REGISTER
extern volatile unsigned int *ADCCAL;


#endif  