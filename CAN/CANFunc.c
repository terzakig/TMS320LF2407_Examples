#include "DSP24_Can.h"
#include "DSP24_Core.h"


void initCAN(void) {

// 1. Configuring Master Control Register (MCR)

MCRbits->bit.STM = 0; // Self-test mode disabled
MCRbits->bit.ABO = 0; // Auto-bus ON 
MCRbits->bit.CDR = 0; // no write action (mboxes 2 and 3)
MCRbits->bit.WUBA = 0; // wake up on bus activity disabled
MCRbits->bit.DBO = 1;  // Data Byte Order = 0, 1, ..., 7
MCRbits->bit.PDR = 0;  // no action

MCRbits->bit.SUSP = 0;  // Stop on suspend (after completing transmission)


// Requesting configuration change for BCR1 and BCR2
MCRbits->bit.CCR = 1;  
// wait until access is granted
while (GSRbits->bit.CCE == 0); 

// 2. Configuring the Time Quantum (TQ) and bit period

// BCR2
BCR2bits->bit.BAUDPSC = 255; // maximum tq (255/40,000,000=6.375 usec)

// BCR1
BCR1bits->bit.TSEG2 = 6;   // 7 tq for PHASE_SEG2 (must be SJW+1 - 8)
BCR1bits->bit.TSEG1 = 10;  // 11 tq for PHASE_SEQ2 (must be>=TSEG2 and 3-16) 
BCR1bits->bit.SAM = 1;     // Sample 3 times on sample point
BCR1bits->bit.SJW = 3;     // 4 tq bit synchronization jump width
BCR1bits->bit.SBG = 0;     // synchronization on falling edge

// Clearing configuration access to BCR1 and BCR2
MCRbits->bit.CCR = 0;
// wait until access restricted
while (GSRbits->bit.CCE == 1); 

// 3. Disabling mailboxes 0 and 2 for ID configuration

MDERbits->bit.ME0 = 0; // disable mailbox0
MDERbits->bit.ME2 = 0; // diable mailbox2

// 4. Setting up Local Acceptance Masks

// Local Acceptance mask 0 (mboxes 0 and 1)
LAM0_Hbits->bit.LAM = 0;
LAM0_Hbits->bit.LAMI = 0; // Acceptable ID type is defied by IDE

*LAM0_L = 0;              // Will be using exact ID match


// Local Acceptance mask 1 (mboxes 2 and 3)
LAM1_Hbits->bit.LAM = 0;
LAM1_Hbits->bit.LAMI = 0; // Acceptable ID type is defied by IDE)

*LAM1_L = 0;              // Will be using exact ID match


// 5. Configuring mailbox identifiers

// Configuring ID for Mailbox 2 (transmit)
MSGID2Hbits->bit.IDE = 0; //Standard 11-bit ID
MSGID2Hbits->bit.AME = 0; // IDs must be EXACT match
MSGID2Hbits->bit.AAM = 0; // Automatic answer disabled
MSGID0Hbits->bit.IDH = 0x14; // Bits 2-12 store matching ID = 5

*MSGID2L = 0;             // using standard ID

// configuring ID for Mbox 0 (receive)
MSGID0Hbits->bit.IDE = 0;
MSGID0Hbits->bit.AME = 0;
MSGID0Hbits->bit.AAM = 0;
MSGID2Hbits->bit.IDH = 0x14; // Bits 2-12 store matching ID = 5

*MSGID0L = 0;		  // using standard ID

// 6. Configuring mailbox overwrite protection

RCRbits->bit.OPC0 = 0;// mailbox0 overwrite protection disabled 

// 7. Configuring Interrupts

// clearing appropriate mailbox flags
TCRbits->bit.TA2 = 1;
RCRbits->bit.RMP0 = 1;

// clearing all interrupt flags (CAN_IFR)
CAN_IFRbits->all = 0xffff;

// Enabling interrupts (CAN_IMR)
CAN_IMRbits->bit.WLIM = 0; // disable warning level interrupt
CAN_IMRbits->bit.EPIM = 0; // disable error passive interrupt
CAN_IMRbits->bit.BOIM = 1; // enable bus off interrupt
CAN_IMRbits->bit.WUIM = 0; // disable bus wake-up interrupt
CAN_IMRbits->bit.WDIM = 0; // disable write denied interrupt
CAN_IMRbits->bit.AAIM = 0; // disable abort acknowledge interrupt
CAN_IMRbits->bit.RMLIM = 0; // disable received message lost interrupt
CAN_IMRbits->bit.MIM0 = 0; // disable mailbox 0 interrupt
CAN_IMRbits->bit.MIM1 = 0; // disable mailbox 1 interrupt
CAN_IMRbits->bit.MIM2 = 1; // enable mailbox 2 interrupt
CAN_IMRbits->bit.MIM3 = 0; // disable mailbox 3 interrupt
CAN_IMRbits->bit.MIM4 = 0; // disable mailbox 4 interrupt
CAN_IMRbits->bit.MIM5 = 0; // disable mailbox 5 interrupt

CAN_IMRbits->bit.EIL = 0; // High error interrupt priority (ignored)
CAN_IMRbits->bit.MIL = 0; // High Mailbox interrupt priority


// 8. Configuring direction and enabling mailboxes (MDER)
MDERbits->bit.ME0 = 1; // enable mailbox0

MDERbits->bit.MD2 = 0; // mailbox2 is transmit Mbox
MDERbits->bit.ME2 = 1; // enable mailbox2


// 9. Enabling core interrupt INT1 (CAN high priority interrupts)
*IMR |= 1;

}



void sendCANMsg(unsigned int * msg) {
 // waiting until until mailbox is not transmitting 
 while (TCRbits->bit.TRR2 != 0);

 // writing data to the mailbox
 MCRbits->bit.CDR = 1;

 *MBX2A = 1;
 *MBX2B = 0;
 *MBX2C = 0;
 *MBX2D = 0;

 MCRbits->bit.CDR = 0;
 // Configuring frame as Data
 MSGCTRL2bits->bit.RTR = 0; // RTR = 0, 
 // Data Length is 1 byte
 MSGCTRL2bits->bit.DLC = 1; 
 // Now requesting transmission
 while (TCRbits->bit.TRS2 != 0);

 TCRbits->bit.TRS2 = 1;
 
 }

