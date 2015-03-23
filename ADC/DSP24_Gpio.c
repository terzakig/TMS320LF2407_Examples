//###############################################################
//      TMS320 General pin IO registers 
//      George Terzakis 2009
//		
//        C file
//###########################################################################

#include "DSP24_Gpio.h"

// MCRA
volatile union IOMUXCTRLA_REG* IOMUXCTRLAbits=(void*)0x7090;
// MCRB
volatile union IOMUXCTRLB_REG* IOMUXCTRLBbits=(void*)0x7092;
// MSCRC
volatile union IOMUXCTRLC_REG* IOMUXCTRLCbits=(void*)0x7094;
// PADATDIR
volatile union IODIRDATA_REG* IODIRDATAbits=(void*)0x7098;
// PBDATDIR
volatile union IODIRDATB_REG* IODIRDATBbits=(void*)0x709A;
// PCDATDIR
volatile union IODIRDATC_REG* IODIRDATCbits=(void*)0x709C;
// PDDATDIR
volatile union IODIRDATD_REG* IODIRDATDbits=(void*)0x709E;
// PEDATDIR
volatile union IODIRDATE_REG* IODIRDATEbits=(void*)0x7095;
// PFDATDIR
volatile union IODIRDATF_REG* IODIRDATFbits=(void*)0x7096;
