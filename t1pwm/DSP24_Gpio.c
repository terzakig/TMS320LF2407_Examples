#include "DSP24_Gpio.h"

// MCRA declarations
volatile union MCRA_REG *MCRAbits=(void*)0x7090;

// PADATDIR declarations
volatile union PADATDIR_REG *PADATDIRbits=(void*)0x7098;
