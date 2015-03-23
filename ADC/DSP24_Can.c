//*************************************************************
//*															  *
//*         TMS320LF2407A Controller Area Network Registers   *
//*						C file    							  *
//*                  George Terzakis 2009                     *
//*************************************************************

#include "DSP24_Can.h"

// MDER
volatile union MDER_REG *MDERbits = (void*)0x7100;
// TCR
volatile union TCR_REG *TCRbits=(void*)0x7101;
// RCR
volatile union RCR_REG *RCRbits=(void*)0x7102;
// MCR
volatile union MCR_REG *MCRbits=(void*)0x7103;
// BCR2
volatile union BCR2_REG *BCR2bits=(void*)0x7104;
// BCR1
volatile union BCR1_REG *BCR1bits=(void*)0x7105;
// ESR
volatile union ESR_REG *ESRbits=(void*)0x7106;
// GSR
volatile union GSR_REG *GSRbits=(void*)0x7107;
// CEC
volatile union CEC_REG *CECbits=(void*)0x7108;
// CAN_IFR
volatile union CAN_IF_REG *CAN_IFRbits=(void*)0x7109;
// CAN_IMR
volatile union CAN_IMR_REG *CAN_IMRbits=(void*)0x710A;


       
