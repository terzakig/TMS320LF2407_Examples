/* ***************************************************************
 * The C file for the Analog rto Digital Converter of 320LF2407A *
 *																 *
 *                     George Terzakis  2009                     *
 *****************************************************************
*/
#include "DSP24_Adc.h"


volatile union ADCTRL1_REG *ADCTRL1bits=(void*)0x70A0;

volatile union ADCTRL2_REG *ADCTRL2bits=(void*)0x70A1;

volatile union ADCMAX_CONV_REG *ADCMAXCONVbits=(void*)0x70A2;

volatile union AUTO_SEQ_SR_REG *AUTO_SEQ_SRbits=(void*)0x70A7;

volatile union ADCCHSELSEQ1 *ADCCHSELSEQ1bits=(void*)0x70A3;

volatile union ADCCHSELSEQ2 *ADCCHSELSEQ2bits=(void*)0x70A4;

volatile union ADCCHSELSEQ3 *ADCCHSELSEQ3bits=(void*)0x70A5;

volatile union ADCCHSELSEQ4 *ADCCHSELSEQ4bits=(void*)0x70A6;

