//*****************************************************************
//
// Serial Communications Interface registers of the TMSLF2407A
//					C-file
//			George Terzakis  2009
//
//*****************************************************************

// Baud Calculation Formulas! 
//
// BRR=(CLKOUT/(Baud*8))-1
//          or....
// Baud=CLKOUT/((BRR+1)*8)
//
// In the specific case of BRR=0: Baud=CLKOUT/16

#include "DSP24_Sci.h"

volatile union SCICCTRL_REG *SCICCTRLbits=(void*)0x7050;

volatile union SCICTRL1_REG *SCICTRL1bits=(void*)0x7051;

volatile union SCICTRL2_REG *SCISCTRL2bits=(void*)0x7054;

volatile union SCIRXST_REG *SCIRXSTbits=(void*)0x7055;

volatile union SCIPRI_REG *SCIPRIbits=(void*)0x705F;

