#include "DSP24_Gpio.h"

// MCRA declarations
volatile union MCRA_REG *MCRAbits=(void*)0x7090;

// PADATDIR declarations
volatile union PADATDIR_REG *PADATDIRbits=(void*)0x7098;
// MCRB declarations
volatile union MCRB_REG *MCRBbits=(void*)0x7092;

