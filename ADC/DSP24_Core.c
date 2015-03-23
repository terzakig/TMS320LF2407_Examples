/* ***************************************************************
 * A C file for the CPU core registers of TMS320LF2407A *
 *																 *
 *                     George Terzakis  2009                     *
 *****************************************************************
*/

#include "DSP24_Core.h"


volatile union IFR_REG *IFRbits=(void*)0x0006;

volatile union IMR_REG *IMRbits=(void*)0x0004;
// WDCR 
volatile union WDCTRL_REG *WDCTRLbits=(void*)0x7029;

