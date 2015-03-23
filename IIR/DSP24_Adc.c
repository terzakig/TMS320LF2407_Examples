
#include "DSP24_Adc.h"


volatile union ADCTRL1_REG *ADCTRL1bits=(void*)0x70A0;

volatile union ADCTRL2_REG *ADCTRL2bits=(void*)0x70A1;

volatile union AUTO_SEQ_SR_REG *AUTO_SEQ_SRbits=(void*)0x70A7;

volatile union CHSELSEQ1_REG *CHSELSEQ1bits=(void*)0x70A3;

volatile union CHSELSEQ2_REG *CHSELSEQ2bits=(void*)0x70A4;

volatile union CHSELSEQ3_REG *CHSELSEQ3bits=(void*)0x70A5;

volatile union CHSELSEQ4_REG *CHSELSEQ4bits=(void*)0x70A6;


// Single word pointers
volatile unsigned int *MAXCONV = (void*)0x70A2;

volatile unsigned int *RESULT = (void*)0x70A8;

volatile unsigned int *ADCCAL = (void*)0x70B8;