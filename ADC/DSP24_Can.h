//*************************************************************
//*															  *
//*         TMS320LF2407A Controller Area Network Registers   *
//*															  *
//*                  George Terzakis 2009                     *
//*************************************************************


#ifndef DSP24_CAN_H
#define DSP24_CAN_H

// Mailbox Direction/Enable Register
// MDER

struct  MDER_BITS {            // bit  description
   unsigned int      ME0:1;     // 0   Enable Mailbox 0
   unsigned int      ME1:1;     // 1   Enable Mailbox 1
   unsigned int      ME2:1;     // 2   Enable Mailbox 2
   unsigned int      ME3:1;     // 3   Enable Mailbox 3
   unsigned int      ME4:1;     // 4   Enable Mailbox 4
   unsigned int      ME5:1;     // 5   Enable Mailbox 5
   unsigned int      MD2:1;     // 6   Mailbox 2 Direction (1 Receive, 0 Transmit)
   unsigned int      MD3:1;     // 7   Mailbox 3 Direction (1 Receive, 0 Transmit)
   unsigned int      resvd:8;   // 8-15 reserved	
};

union MDER_REG {
   unsigned int  all;
   struct MDER_BITS  bit;
};
extern volatile union MDER_REG *MDERbits;

// Transmission Control Register
// TCR

struct TCR_BITS {
	unsigned int TRR2:1; //0 Transmission Request for Mailbox 2 (only se by CPU)
	unsigned int TRR3:1; //1 Transmission Request for Mailbox 3 (only se by CPU)
	unsigned int TRR4:1; //2 Transmission Request for Mailbox 4 (only se by CPU)
	unsigned int TRR5:1; //3 Transmission Request for Mailbox 4 (only se by CPU)
	unsigned int TRS2:1; //4 Transmission Request set for Mailbox 2 (user set to1 if want to "lock" transmission)
	unsigned int TRS3:1; //5 Transmission Request set for Mailbox 3 (user set to1 if want to "lock" transmission)
    unsigned int TRS4:1; //6 Transmission Request set for Mailbox 4 (user set to1 if want to "lock" transmission)
    unsigned int TRS5:1; //7 Transmission Request set for Mailbox 5 (user set to1 if want to "lock" transmission)
	unsigned int AA2:1;  //8 Abort Acknowledge bit for Mailbox 2
    unsigned int AA3:1;  //9 Abort Acknowledge bit for Mailbox 3
	unsigned int AA4:1;  //10 Abort Acknowledge bit for Mailbox 4
	unsigned int AA5:1;  //11 Abort Acknowledge bit for Mailbox 5
	unsigned int TA2:1;  // 12 Transmission Aknowledge for Mailbox 2 (Transmission successfull)
	unsigned int TA3:1;  // 13 Transmission Aknowledge for Mailbox 3 (Transmission successfull)
    unsigned int TA4:1;  // 14 Transmission Aknowledge for Mailbox 4 (Transmission successfull)
    unsigned int TA5:1;  // 15 Transmission Aknowledge for Mailbox 5 (Transmission successfull)
};

union TCR_REG {
	unsigned int all;
	struct TCR_BITS bit;
};
extern volatile union TCR_REG *TCRbits;

//CAN Receive Control Register
// RCR

struct RCR_BITS {
	unsigned int OPC0:1; // 0 Overright Protection Control for MB 0
	unsigned int OPC1:1; // 1 Overright Protection Control for MB 1
	unsigned int OPC2:1; // 2 Overright Protection Control for MB 2
	unsigned int OPC3:1; // 3 Overright Protection Control for MB 3
	unsigned int RMP0:1; // 4 Received Message Pending for MB 0 (logically must be cleared in following an Interrupt Rx service)
	unsigned int RMP1:1; // 5 Received Message Pending for MB 1 (logically must be cleared in following an Interrupt Rx service)
    unsigned int RMP2:1; // 6 Received Message Pending for MB 2 (logically must be cleared in following an Interrupt Rx service)
    unsigned int RMP3:1; // 7 Received Message Pending for MB 3 (logically must be cleared in following an Interrupt Rx service)
	unsigned int RML0:1; // 8 Received Message Lost for MB 0 (flag)
	unsigned int RML1:1; // 9 Received Message Lost for MB 1 (flag)
    unsigned int RML2:1; // 10 Received Message Lost for MB 2 (flag)
    unsigned int RML3:1; // 11 Received Message Lost for MB 3 (flag)
	unsigned int RFP0:1; // 12 Remote Frame Pending for MB 0
	unsigned int RFP1:1; // 13 Remote Frame Pending for MB 1
	unsigned int RFP2:1; // 14 Remote Frame Pending for MB 2
	unsigned int RFP3:1; // 12 Remote Frame Pending for MB 3
};

union RCR_REG {
	unsigned int all;
	struct RCR_BITS bit;
};
extern volatile union RCR_REG *RCRbits;

// CAN Master Control Register
// MCR

struct MCR_BITS {
	unsigned int MBNR:2; // 0-1 Mailbox number (CPU writes it for an access request)
	unsigned int rsvd1:4; // 2-5 reserved
	unsigned int STM:1; // 6 Self Test Mode
	unsigned int ABO:1; // 7 AutoBus ON
	unsigned int CDR:1; // 8 Change Data field request(MB 2 and 3 only)
	unsigned int WUBA:1; // 9 Wake Up on Bus Activity
	unsigned int DBO:1; // 10 Data Byte Order
	unsigned int PDR:1; // 11 Power Down Mode Request
	unsigned int CCR:1; // 12 Change Configuration Request
	unsigned int SUSP:1; // 13 Action on Emulation suspend (soft/free)
	unsigned int rsvd2:2; // 14-15 reserved
};

union MCR_REG {
	unsigned int all;
	struct MCR_BITS bit;
};
extern volatile union MCR_REG *MCRbits;

//Bit Configuration Registers
// Adjusting CAN to network specs
// BCR2
struct BCR2_BITS {
   unsigned int BAUDPSC:8; // 0-7 Baud Rate prescaler;
   unsigned int rsvd:8; // reserved
};

// CAN Time Quantum defined by the formula:
// 
//             TQ=(1/CLKOUT)*(BRP+1) (nanosecs)
//
union BCR2_REG {
	unsigned int all;
	struct BCR2_BITS bit;
};
extern volatile union BCR2_REG *BCR2bits;



// BCR1
struct BCR1_BITS {
   unsigned int TSEG2:2; // 0-2 Time segment 2. Phase segment2 lwength in TQ units
   unsigned int TSEG1:4; // 3-6 Time segment 1. Phase segment 1 length in TQ units
   unsigned int SAM:1;  // 7 sample point setting
   unsigned int SJW:2;   // 8-9 Synchronization Jump width
   unsigned int SBG:1;   // 10 Synchronization on botyh edges
   unsigned int rsvd:5; // 11-15 reserved
};

union BCR1_REG {
	unsigned int all;
    struct BCR1_BITS bit;
};
extern volatile union BCR1_REG *BCR1bits;




// CAN Error Status Register
// ESR
struct ESR_BITS {
	unsigned int WS:1; // 0 Warning Status
	unsigned int EP:1; // 1 Error Passive status (0 not in error passive mode, 1 in error passive mode)
	unsigned int BO:1; // 2 Buss Off status (0 normal, 1 abnormal rate of errors)
	unsigned int ACKE:1; // 3 ACKnowledge error (0 ACK received, 1 ACK did not received)
	unsigned int SER:1; // 4 Stuff error (0 no error, 1 stuff bit violated)
	unsigned int CRCE:1; //5 CRC Error (0 did not receive CRCERR, 1 wrong CRC)
	unsigned int SA1:1; // 6 Stuck at Dominant error (0 CAn detected a recessive bit, 1did not detect recessive bit)
	unsigned int BEF:1; // 7 Bit error Flag (0 correct, 1 was a bit error)
	unsigned int FER:1; // 8 Form error flag (0 tx/rx was correct, 1 form error occured)
	unsigned int rsvd:7; // 9-15 reserved
};

union ESR_REG {
	unsigned int all;
	struct ESR_BITS bit;
};
extern volatile union ESR_REG *ESRbits;

// CAN Global Status Register
// GSR

struct GSR_BITS {
	unsigned int TM:1; // 0 Transmit mode (0 not transmitting, 1 transmitting)
	unsigned int RM:1; // 1 Receive Mode (0 not receiving, 1 receiving)
	unsigned int rsvd1:1; // 2 reserved
	unsigned int PDA:1; // 3 Power Down mode Acknowledge (0 Normal, 1 Power Down)
	unsigned int CCE:1; // 4 Change Configuration Enable (0 access to configuration regs denied, 1 access allowed)
	unsigned int SMA:1;  // 5 Suspend Mode Acknowledge
	unsigned int rsvd2:9; // 6-15 reserved
};

union GSR_REG {
	unsigned int all;
	struct GSR_BITS bit;
};
extern volatile union GSR_REG *GSRbits;


// CAN Error Counter register
// CEC

struct CEC_BITS {
	unsigned int REC:8; // 0-7 Receive error counter
	unsigned int TEC:8; // 8-15 Transmit error Counter
};

union CEC_REG {
	unsigned int all;
	struct CEC_BITS bit;
};
extern volatile union CEC_REG *CECbits;

// CAN Interrupt Flag Register
// CAN_IFR
struct CAN_IFR_BITS {
	unsigned int WLIF:1; // 0 Warning Level Interrupt
	unsigned int EPIF:1; // 1 Error Passive Interrupt Flag
	unsigned int BOIF:1; // 2 Buss Off Interrupt Flag
	unsigned int WUIF:1; // 3 Wake up Interript Flag
	unsigned int WDIF:1; // 4 Write Denied Interrupt Flag
	unsigned int AAIF:1; // 5 Abort Acknowledge Interrupt Flag
	unsigned int RMLIF:1; // 6 Receive Message Lost interrupt flag
	unsigned int rsvd1:1; // 7 reserved
	unsigned int MIF0:1; // 8 Mailbox 0 interrupt
	unsigned int MIF1:1; // 9 Mailbox 1 interrupt flag
	unsigned int MIF2:1; // 10 Mailbox 2 interrupt flag
	unsigned int MIF3:1; // 11 Mailbox 3 interrupt flag
	unsigned int MIF4:1; // 12 Mailbox 4 interrupt flag
	unsigned int MIF5:1; // 13 Mailbox 5 interrupt flag
	unsigned int rsvd2:2; // 14-15 reserved
};

union CAN_IFR_REG {
	unsigned int all;
	struct CAN_IFR_BITS bit;
};
extern volatile union CAN_IF_REG *CAN_IFRbits;


// CAN Interrupt Mask Register
// CAN_IMR
struct CAN_IMR_BITS {
	unsigned int WLIM:1; // 0 Warning Level interrupt Mask
	unsigned int EPIM:1; // 1 Error Passive Interrupt Mask
	unsigned int BOIM:1; // 2 Buss off Interrupt Mask
	unsigned int WUIM:1; // 3 Wake up Interrupt Flag
	unsigned int WDIM:1; // 4 Write denied interrupt mask
	unsigned int AAIM:1; // 5 Abort Acknowledge interrupt mask
	unsigned int RMLIM:1; // 6 Receive Message Lost interrupt mask
	unsigned int rsvd1:1; // 7 reserved
	unsigned int MIM0:1; // 8 Mailbox 0 Interrupt Mask
	unsigned int MIM1:1; // 9 Mailbox 1 Interrupt Mask
	unsigned int MIM2:1; // 10 Mailbox 2 Interrupt Mask
	unsigned int MIM3:1; // 11 Mailbox 3 Interrupt Mask
	unsigned int MIM4:1; // 12 Mailbox 4 Interrupt Mask
	unsigned int MIM5:1; // 13 Mailbox 5 Interrupt Mask
	unsigned int rsvd2:2; // 14-15 reserved
};

union CAN_IMR_REG {
	unsigned int all;
	struct CAN_IMR_BITS bit;
};
extern volatile union CAN_IMR_REG *CAN_IMRbits;


#endif  // end        
