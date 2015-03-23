#include "DSP24_Sci.h"

// Communcation Control Register
volatile union SCICCR_REG *SCICCRbits=(void*)0x7050;
// SCI Control Register 1
volatile union SCICTL1_REG *SCICTL1bits=(void*)0x7051;
//SCI Control Register 2
volatile union SCICTL2_REG *SCICTL2bits=(void*)0x7054;
//SCI Receiver Status Register
volatile union SCIRXST_REG *SCIRXSTbits=(void*)0x7055;
//SCI Priority Register
volatile union SCIPRI_REG *SCIPRIbits=(void*)0x705F;

// SCI baud-select register, high byte
volatile unsigned int* SCIHBAUD=(void*)0x7052;
// SCI baud-select register, low byte   
volatile unsigned int* SCILBAUD=(void*)0x7053;
// SCI emulation data buffer register
volatile unsigned int* SCIRXEMU=(void*)0x7056;  
// SCI receiver data buffer register 
volatile unsigned int* SCIRXBUF=(void*)0x7057;   
// SCI transmit data buffer register
volatile unsigned int* SCITXBUF=(void*)0x7059;      