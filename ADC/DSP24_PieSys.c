//***************************************************************
//      
//      Peripheral Interrupt Expansion & System Configuration 
//							Registers, C file
//						George Terzakis 2009
//
//****************************************************************

#include "DSP24_PieSys.h"

// PIVR (read only)- contains the interrupt vector after acknowledment
volatile union PIVR_REG *PIVRbits=(void*)0x701E;

// PIRQR0
volatile union PIRQR0_REG *PIRQR0bits=(void*)0x7010;
// PIRQR1
volatile union PIRQR1_REG *PIRQR1bits=(void*)0x7011;

// PIRQR2
volatile union PIRQR2_REG *PIRQR2bits=(void*)0x7012;

// PIACKR0
volatile union PIACKR0_REG *PIACKR0bits=(void*)0x7014;
// PIACKR1
volatile union PIACKR1_REG *PIACKR1bits=(void*)0x7015;

volatile union PIACKR2_REG *PIACKR2bits=(void*)0x7016;
// SCSR1
volatile union SCSR1_REG *SCSR1bits=(void*)0x7018;
// SCSR2
volatile union SCSR2_REG *SCSR2bits=(void*)0x7019;

