//***************************************************************
//      
//      Peripheral Interrupt Expansion & System Configuration 
//							Registers
//						George Terzakis 2009
//
//****************************************************************

#ifndef DSP24_PIESYS_H
#define DSP24_PIESYS_H



//---------------------------------------------------------------------------
// PIE Control Register Bit Definitions:
//
// PIVR (read only)- contains the interrupt vector after acknowledment
struct PIVR_BITS {    // bits description
   unsigned int  V0:1;        // 0    
   unsigned int  V1:1;     // 1 
   unsigned int  V2:1;     // 2
   unsigned int  V3:1;     // 3
   unsigned int  V4:1;     // 4
   unsigned int  V5:1;     // 5
   unsigned int  V6:1;     // 6 
   unsigned int  V7:1;     // 7
   unsigned int  V8:1;     // 8
   unsigned int  V9:1;     // 9
   unsigned int  V10:1;     // 10
   unsigned int  V11:1;     // 11
   unsigned int  V12:1;     // 12
   unsigned int  V13:1;     // 13
   unsigned int  V14:1;     // 14
   unsigned int  V15:1;     // 15 
};

union PIVR_REG {
   unsigned int   all;
   struct PIVR_BITS  bit;
};  

extern volatile union PIVR_REG *PIVRbits;

// ****************************************************
// Peripheral Interrupt Request registers
//
// PIRQR0

struct PIRQR0_BITS {     // bits description PIRQR0
   unsigned int  PDPINTA_IRQ0:1; // 0    Power device protection interrupt pin
   unsigned int  ADC_IRQ1:1; // 1 ADC interrupt request (high priority)
   unsigned int  XINT1_IRQ2:1; // 2 External Interrupt pin 1 (high priority)
   unsigned int  XINT2_IRQ3:1; // 3 External Interrupt pin 1 (high priority)
   unsigned int  SPI_IRQ4:1;   // 4 SPI Interrupt (high priority)
   unsigned int  RX_IRQ5:1;     // 5 SCI Receive interrupt (high priority)
   unsigned int  TX_IRQ6:1;     // 6 SCI Transmit interrupt (high priority)
   unsigned int  CANMB_IRQ7:1; // 7 CAN mailbox interrupt (high priority)
   unsigned int  CANER_IRQ8:1;  // 8 CAN error interrupt (high priority)
   unsigned int  CMP1_IRQ9:1;   // 9 Compare 1 interrupt
   unsigned int  CMP2_IRQ10:1;   // 10 Compare 2 interrupt
   unsigned int  CMP3_IRQ11:1;   // 11 Compare 3 interrupt
   unsigned int  T1P_IRQ12:1;   // 12 Timer 1 Period interrupt
   unsigned int  T1C_IRQ13:1;   // 13 Timer 1 Compare interrupt
   unsigned int  T1UF_IRQ14:1;  // 14 T1 Underflow interrupt
   unsigned int  T1OF_IRQ15:1; // 15 Timer 1 OverFlow interrupt

};

union PIRQR0_REG {
   unsigned int                all;
   struct PIRQR0_BITS  bit;
}; 
extern volatile union PIRQR0_REG *PIRQR0bits;


// ****************************************************
// Peripheral Interrupt Request registers
//
// PIRQR1

struct PIRQR1_BITS {     // bits description PIRQR1
   unsigned int  T2P_IRQ0:1; // 0 Timer 2 Period Interrupt
   unsigned int  T2C_IRQ1:1; // 1 Timer 2 Compare interrupt
   unsigned int  T2UF_IRQ2:1; // 2 Timer 2 UnderFlow interrupt
   unsigned int  T2OF_IRQ3:1; // 3 Timer 2 OverFlow interrupt
   unsigned int  CAP1_IRQ4:1;   // 4 Capture 1 interrupt
   unsigned int  CAP2_IRQ5:1;     // 5 Capture 2 interrupt
   unsigned int  CAP3_IRQ6:1;     // 6 Capture 3 interrupt
   unsigned int  SPI_IRQ7:1; // 7 SPI interrupt (low priority)
   unsigned int  RX_IRQ8:1;  // 8 SCI Receive (Low priority)
   unsigned int  TX_IRQ9:1;   // 9 SCI transmit (Low priority)
   unsigned int  CANMB_IRQ10:1;   // 10 CAN MailBox (low priority)
   unsigned int  CANER_IRQ11:1;   // 11 CAN ERror (low priority)
   unsigned int  ADC_IRQ12:1;   // 12 ADC interrupt (Low priority)
   unsigned int  XINT1_IRQ13:1;   // 13 External interrupt pin 1 (low priority)
   unsigned int  XINT2_IRQ14:1;  // 14 External interrupt pin 2 (low priority)
   unsigned int  rsvd:1; // 15 reserved

};

union PIRQR1_REG {
   unsigned int     all;
   struct PIRQR1_BITS  bit;
}; 
extern volatile union PIRQR1_REG *PIRQR1bits;


// ****************************************************
// Peripheral Interrupt Request registers
//
// PIRQR2

struct PIRQR2_BITS {     // bits description PIRQR2
   unsigned int  PDPINTB_IRQ0:1; // 0 Power Drive Protection interrupt pin
   unsigned int  CMP4_IRQ1:1; // 1 Compare 4 interrupt
   unsigned int  CMP5_IRQ2:1; // 2 Compare 5 interrupt
   unsigned int  CMP6_IRQ3:1; // 3 Compare 6 interrupt
   unsigned int  T3P_IRQ4:1;   // 4 Timer 3 Period interrupt
   unsigned int  T3C_IRQ5:1;     // 5 Timer 3 Compare interrupt
   unsigned int  T3UF_IRQ6:1;     // 6 Timer 3 UnderFlow interrupt
   unsigned int  T3OF_IRQ7:1; // 7 T3 OverFlow interrupt 
   unsigned int  T4P_IRQ8:1;  // 8 T4 Period interrupt
   unsigned int  T4C_IRQ9:1;   // 9  T4 Compare Interrupt
   unsigned int  T4UF_IRQ10:1;   // 10  T4 UnderFlow Interrupt
   unsigned int  T4OF_IRQ11:1;   // 11  T4 OverFlow Interrupt
   unsigned int  CAP4_IRQ12:1;   // 12 Capture 4 interrupt
   unsigned int  CAP5_IRQ13:1;   // 13 Capture 5 interrupt
   unsigned int  CAP6_IRQ14:1;   // 14 Capture 6 interrupt
   unsigned int  rsvd:1; // 15 reserved

};

union PIRQR2_REG {
   unsigned int     all;
   struct PIRQR2_BITS  bit;
}; 
extern volatile union PIRQR2_REG *PIRQR2bits;



//************************************************************
// Peripheral Interrupt Acknowledge Registers
// 
// PIACKR0

struct PIACKR0_BITS {     // bits description PIACKR0
   unsigned int  PDPINTB_IAK0:1; // 0 Power Device Protection interrupt pin
   unsigned int  ADC_IAK1:1; // 1 ADC interrupt (high priority)
   unsigned int  XINT1_IAK2:1; // 2 External pin1 interrupt (high priority)
   unsigned int  XINT2_IAK3:1; // 3 External pin2 interrupt (high priority)
   unsigned int  SPI_IAK4:1;   // 4 SPI interrupt (high priority)
   unsigned int  RX_IAK5:1;     // 5 SCI Receive interrupt (high priority)
   unsigned int  TX_IAK6:1;     // 6 SCI Transmit interrupt (high priority)
   unsigned int  CANMB_IAK7:1; // 7 CAN Mailbox interrupt (high priority)
   unsigned int  CANER_IAK8:1;  // 8 CAN ERror interrupt (high priority)
   unsigned int  CMP1_IAK9:1;   // 9  Compare 1 Interrupt
   unsigned int  CMP2_IAK10:1;   // 10  Compare 2 Interrupt
   unsigned int  CMP3_IAK11:1;   // 11  Compare 3 Interrupt
   unsigned int  T1P_IAK12:1;   // 12 Timer 1 Period interrupt
   unsigned int  T1C_IAK13:1;   // 13 Timer 1 Compare interrupt
   unsigned int  T1UF_IAK14:1;   // 14 Timer 1 UnderFlow interrupt
   unsigned int  T1OV_IAK15:1; // 15 Timer 1 OverFlow Interrupt

};

union PIACKR0_REG {
   unsigned int     all;
   struct PIACKR0_BITS  bit;
}; 
extern volatile union PIACKR0_REG *PIACKR0bits;


//************************************************************
// Peripheral Interrupt Acknowledge Registers
// 
// PIACKR1

struct PIACKR1_BITS {     // bits description PIACKR1
   unsigned int  T2P_IAK0:1; // 0 Timer 2 Period Interrupt
   unsigned int  T2C_IAK1:1; // 1 Timer 2 Compare interrupt
   unsigned int  T2UF_IAK2:1; // 2 Timer 2 UnderFlow interrupt
   unsigned int  T2OF_IAK3:1; // 3 Timer 2 OverFlow interrupt
   unsigned int  CAP1_IAK4:1;   // 4 Capture 1 interrupt
   unsigned int  CAP2_IAK5:1;     // 5 Capture 2 interrupt
   unsigned int  CAP3_IAK6:1;     // 6 Capture 3 interrupt
   unsigned int  SPI_IAK7:1; // 7 SPI interrupt (low priority)
   unsigned int  RX_IAK8:1;  // 8 SCI Receive (Low priority)
   unsigned int  TX_IAK9:1;   // 9 SCI transmit (Low priority)
   unsigned int  CANMB_IAK10:1;   // 10 CAN MailBox (low priority)
   unsigned int  CANER_IAK11:1;   // 11 CAN ERror (low priority)
   unsigned int  ADC_IAK12:1;   // 12 ADC interrupt (Low priority)
   unsigned int  XINT1_IAK13:1;   // 13 External interrupt pin 1 (low priority)
   unsigned int  XINT2_IAK14:1;  // 14 External interrupt pin 2 (low priority)
   unsigned int  rsvd:1; // 15 reserved

};

union PIACKR1_REG {
   unsigned int     all;
   struct PIACKR1_BITS  bit;
}; 
extern volatile union PIACKR1_REG *PIACKR1bits;



struct PIACKR2_BITS {     // bits description PIACKR2
   unsigned int  PDPINTB_IAK0:1; // 0 Power Drive Protection interrupt pin
   unsigned int  CMP4_IAK1:1; // 1 Compare 4 interrupt
   unsigned int  CMP5_IAK2:1; // 2 Compare 5 interrupt
   unsigned int  CMP6_IAK3:1; // 3 Compare 6 interrupt
   unsigned int  T3P_IAK4:1;   // 4 Timer 3 Period interrupt
   unsigned int  T3C_IAK5:1;     // 5 Timer 3 Compare interrupt
   unsigned int  T3UF_IAK6:1;     // 6 Timer 3 UnderFlow interrupt
   unsigned int  T3OF_IAK7:1; // 7 T3 OverFlow interrupt 
   unsigned int  T4P_IAK8:1;  // 8 T4 Period interrupt
   unsigned int  T4C_IAK9:1;   // 9  T4 Compare Interrupt
   unsigned int  T4UF_IAK10:1;   // 10  T4 UnderFlow Interrupt
   unsigned int  T4OF_IAK11:1;   // 11  T4 OverFlow Interrupt
   unsigned int  CAP4_IAK12:1;   // 12 Capture 4 interrupt
   unsigned int  CAP5_IAK13:1;   // 13 Capture 5 interrupt
   unsigned int  CAP6_IAK14:1;   // 14 Capture 6 interrupt
   unsigned int  rsvd:1; // 15 reserved

};

union PIACKR2_REG {
   unsigned int     all;
   struct PIACKR2_BITS  bit;
}; 
extern volatile union PIACKR2_REG *PIACKR2bits;


//****************************************************************
// System Configuration Registers
// 
// SCSR1

struct SCSR1_BITS {     // bits description SCSR1
   unsigned int  ILLADR:1;      // 0 Illegal address detect (must be cleared manually!)
   unsigned int  rsvd1:1;      // 1 reserved
   unsigned int  EVA_CLKEN:1; // 2 EVA Clock enable bit
   unsigned int  EVB_CLKEN:1; // 3 EVB Clock enable bit
   unsigned int  CAN_CLKEN:1; // 4 CAN Clock Enable bit
   unsigned int  SPI_CLKEN:1; // 5 SPI Clock enable bit
   unsigned int  SCI_CLKEN:1; // 6 SCI Clock Enable bit
   unsigned int  ADC_CLKEN:1; // 7 ADC clock enable bit
   unsigned int  rsvd2:1;     // 8 reserved
   unsigned int  PLL_PSC:3;    // 9-11 Phase Lock Loop Prescaling
   unsigned int  LPM_SEL:2;     // 12-13 Low Power Mode Select
   unsigned int  CLKOUT:1;    // 14 if 0, CLKOUT pin has CPU clock - if 1 CLKOUT pin has Watchdog Clock
   unsigned int  rsvd3:1;      // 15 reserved
};

union SCSR1_REG {
   unsigned int     all;
   struct SCSR1_BITS  bit;
}; 
extern volatile union SCSR1_REG *SCSR1bits;


//****************************************************************
// System Configuration Registers
// 
// SCSR2

struct SCSR2_BITS {     // bits description SCSR2
   unsigned int  DONPON:2;      // 0-1 Defines Internal SARAM memory mapping (11 is default - both program and data space)
   unsigned int  MPMC:1;      // 2 MicroProcessor/MicroController mode (1 for for MP, 0 for MC)
   unsigned int  BOOTEN:1; // 3 BOOT ROM ENable bit. 0 for enabling mapping initial address space to on-chip boot ROM, 1 address 0000-7fff is mapped to flash rom
   unsigned int  XMIFZ:1; // 4 Controls state of external memory (0 normal signals, 1 high impedance)
   unsigned int  WD_OVRD:1; // 5 WatchDOG Override (by setting to 1 , software may disable the watchdog, if 0 we cannot disable the watchdog)
   unsigned int  INPQLFY:1; // 6 Input Qualifier Clocks. 
   unsigned int  rsvd:9; // 7-15 reserved
   
};

union SCSR2_REG {
   unsigned int     all;
   struct SCSR2_BITS  bit;
}; 
extern volatile union SCSR2_REG *SCSR2bits;



#endif  

