//****************************************************************
//
//          TMS320LF2407A external interrupt registers 
//			            C file
//					George Terzakis 2009
//
//****************************************************************

#include "DSP24_XIntrupt.h"

//   XINT1CR
volatile union XINT1CTRL_REG *XINT1CTRLbits=(void*)0x7070;
//   XINT2CR
volatile union XINT2CTRL_REG *XINT2CTRLbits=(void*)0x7071;

