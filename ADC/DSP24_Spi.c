// *************************************************************
// *                                                           *
// *          TMS320LF2407A Serial Peripheral Interface        *
// *					C file                                                        *
// *                  George Terzakis 2009                     *
// *                                                           *
// *************************************************************

#include "DSP24_Spi.h"

volatile union SPICCR_REG *SPICCRbits=(void*)0x7040;

volatile union SPICTL_REG *SPICTLbits=(void*)0x7041;

volatile union SPISTS_REG *SPISTSbits=(void*)0x7042;

volatile union SPIBRR_REG *SPIBRRbits=(void*)0x7044;

volatile union SPIPRI_REG *SPIPRIbits=(void*)0x704F;
