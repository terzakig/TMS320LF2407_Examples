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
volatile union TCR_REG *TCRbits = (void*)0x7101;
// RCR
volatile union RCR_REG *RCRbits = (void*)0x7102;
// MCR
volatile union MCR_REG *MCRbits = (void*)0x7103;
// BCR2
volatile union BCR2_REG *BCR2bits = (void*)0x7104;
// BCR1
volatile union BCR1_REG *BCR1bits = (void*)0x7105;
// ESR
volatile union ESR_REG *ESRbits = (void*)0x7106;
// GSR
volatile union GSR_REG *GSRbits = (void*)0x7107;
// CEC
volatile union CEC_REG *CECbits = (void*)0x7108;
// CAN_IFR
volatile union CAN_IFR_REG *CAN_IFRbits = (void*)0x7109;
// CAN_IMR
volatile union CAN_IMR_REG *CAN_IMRbits = (void*)0x710A;

// Local Acceptance Mask Registers
// LAM0H
volatile union LAMn_H_REG *LAM0_Hbits = (void*)0x710B;
// LAM0L
volatile unsigned int *LAM0_L = (void*)0x710C;

// LAM1H
volatile union LAMn_H_REG *LAM1_Hbits = (void*)0x710D;
// LAM1L
volatile unsigned int *LAM1_L = (void*)0x710E;    

// ************ Mailbox ID Registers *********
//MSGID0L
volatile unsigned int *MSGID0L = (void*)0x7200;
// MSGID0H
volatile union MSGIDnH_REG *MSGID0Hbits = (void*)0x7201;
 
//MSGID1L
volatile unsigned int *MSGID1L = (void*)0x7208;
// MSGID1H
volatile union MSGIDnH_REG *MSGID1Hbits = (void*)0x7209;


//MSGID2L
volatile unsigned int *MSGID2L = (void*)0x7210;
// MSGID2H
volatile union MSGIDnH_REG *MSGID2Hbits = (void*)0x7211;

//MSGID3L
volatile unsigned int *MSGID3L = (void*)0x7218;
// MSGID3H
volatile union MSGIDnH_REG *MSGID3Hbits = (void*)0x7219;

//MSGID4L
volatile unsigned int *MSGID4L = (void*)0x7220;
// MSGID4H
volatile union MSGIDnH_REG *MSGID4Hbits = (void*)0x7221;

//MSGID5L
volatile unsigned int *MSGID5L = (void*)0x7228;
// MSGID5H
volatile union MSGIDnH_REG *MSGID5Hbits = (void*)0x7229;

// MSGCTRL0
volatile union MSGCTRLn_REG *MSGCTRL0bits = (void*)0x7202;

// MSGCTRL1
volatile union MSGCTRLn_REG *MSGCTRL1bits = (void*)0x720A;

// MSGCTRL2
volatile union MSGCTRLn_REG *MSGCTRL2bits = (void*)0x7212;

// MSGCTRL3
volatile union MSGCTRLn_REG *MSGCTRL3bits = (void*)0x721A;

// MSGCTRL4
volatile union MSGCTRLn_REG *MSGCTRL4bits = (void*)0x7222;

// MSGCTRL5
volatile union MSGCTRLn_REG *MSGCTRL5bits = (void*)0x722A;

// MB0A,B,C,D
volatile unsigned int *MBX0A = (void*)0x7204;
volatile unsigned int *MBX0B = (void*)0x7205;
volatile unsigned int *MBX0C = (void*)0x7206;
volatile unsigned int *MBX0D = (void*)0x7207;

// MB1A,B,C,D
volatile unsigned int *MBX1A = (void*)0x720C;
volatile unsigned int *MBX1B = (void*)0x720D;
volatile unsigned int *MBX1C = (void*)0x720E;
volatile unsigned int *MBX1D = (void*)0x720F;

// MB2A,B,C,D
volatile unsigned int *MBX2A = (void*)0x7214;
volatile unsigned int *MBX2B = (void*)0x7215;
volatile unsigned int *MBX2C = (void*)0x7216;
volatile unsigned int *MBX2D = (void*)0x7217;

// MB3 A,B,C,D
volatile unsigned int *MBX3A = (void*)0x721C;
volatile unsigned int *MBX3B = (void*)0x721D;
volatile unsigned int *MBX3C = (void*)0x721E;
volatile unsigned int *MBX3D = (void*)0x721F;

// MB4 A,B,C,D
volatile unsigned int *MBX4A = (void*)0x7224;
volatile unsigned int *MBX4B = (void*)0x7225;
volatile unsigned int *MBX4C = (void*)0x7226;
volatile unsigned int *MBX4D = (void*)0x7227;

// MB5 A,B,C,D
volatile unsigned int *MBX5A = (void*)0x722C;
volatile unsigned int *MBX5B = (void*)0x722D;
volatile unsigned int *MBX5C = (void*)0x722E;
volatile unsigned int *MBX5D = (void*)0x722F;




