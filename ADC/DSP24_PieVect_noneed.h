//***************************************************************
//*																*
//* This header provie a convenient structure PieVectTable      *
//* containing entries for every GISR (1-6) and SSIR            *
//*																*
//* PieVectTable MUST bwe initialized with initPieVect()        *
//* in order to point to the right addresses                    *
//*															    *
//*					George Terzakis 2009					    *
//***************************************************************



#ifndef DSP24_PIE_VECT_H
#define DSP24_PIE_VECT_H


//---------------------------------------------------------------------------
// PIE Interrupt Vector Table Definition:
//
// Create a user type called PINT (pointer to interrupt):

typedef PINT(*PINT)(void);

// Define Vector Table:
struct PIE_VECT_TABLE {

// Reset is never fetched from this table.  
// Level 1 interrupt vector fields 
     PINT  INT1;
	 // 1) Power drvive Protection Interrupt pin A
	 PINT  PDPINTA;
// 2) Power Drive Protection interrupt pin B
     PINT  PDPINTB;
// 3) ADC interrupt in high priority
     PINT  ADCINT_HP;
// 4) External pin1 interrupt in high priority
     PINT XINT1_HP;
// 5) External pin2 interrupt in high priority
     PINT XINT2_HP;
// 6) SPI interrupt in high priority
     PINT SPIINT_HP;
// 7) SCI Receive (Rx) interrupt in high priority
     PINT RXINT_HP;
// 8) SCI Transmit (Tx) interrupt in high priority
     PINT TXINT_HP;
// 9) CAN mailbox interrupt in high priority
     PINT CANMBINT_HP;
// 10) CAN Error interrupt in high priority
     PINT CANERINT_HP;

// ***************LEVEL 2 interrupts **********************
// **********(including CPU INT2 interrupt)****************
     PINT INT2;// GISR for all INT2 level peripherals
// Now here comes all specific ISRs...

// 1) Compare 1 Interrupt
     PINT CMP1INT;
// 2) Compare 2 interrupt
     PINT CMP2INT;
// 3) Compare 3 Interrupt
	 PINT CMP3INT;
// 4) Timer 1 Period interrupt
	 PINT T1PINT;
// 5) Timer 1 Compare interrupt
	 PINT T1CINT;
// 6) Timer 1 Underflow interrupt
	 PINT T1UFINT;
// 7) Timer 1 Overflow interrupt
	 PINT T1OFINT;
// 8) Compare 4 interrupt
	 PINT CMP4INT;
// 9) Compare 5 interrupt
	 PINT CMP5INT;
// 10) Compare 6 interrupt
	 PINT CMP6INT;
// 11) Timer 3 Period interrupt
	 PINT T3PINT;
// 12) Timer 3 Compare interrupt
	 PINT T3CINT;
// 13) Timer 3 Underflow interrupt
	 PINT T3UFINT;
// 14) Timer 3 Overflow interrupt
	 PINT T3OFINT;

// ***************LEVEL 3 interrupts **********************
// **********(including CPU INT3 interrupt)****************
	 PINT INT3;// GISR for all INT3 level peripherals
// Now here comes all specific ISRs...

//1) Timer 2 Period interrupt
	 PINT T2PINT;
//2) Timer 2 Compare interrupt
	 PINT T2CINT;
//3) Timer 2 Underflow interrupt
	 PINT T2UFINT;
//4) Timer 2 Overflow interrupt
	 PINT T2OFINT;
//5) Timer 4 Period interrupt
	 PINT T4PINT;
//6) Timer 4 Compare interrupt
	 PINT T4CINT;
//7) Timer 4 Underflow interrupt
	 PINT T4UFINT;
//8) Timer 4 Overflow interruopt
     PINT T4OFINT;

// ***************LEVEL 4 interrupts **********************
// **********(including CPU INT4 interrupt)****************
	 PINT INT4;// GISR for all INT4 level peripherals
// Now here comes all specific ISRs...

//1) Capture 1 interrupt
	 PINT CAP1INT;
//2) Capture 2 interrupt
	 PINT CAP2INT;
//3) Capture 3 interrupt
	 PINT CAP3INT;
//4) Capture 2 interrupt
	 PINT CAP4INT;
//5) Capture 5 interrupt
	 PINT CAP5INT;
//6) Capture 6 interrupt
	 PINT CAP6INT;

// ***************LEVEL 5 interrupts **********************
// **********(including CPU INT5 interrupt)****************
	 PINT INT5;// GISR for all INT5 level peripherals
// Now here comes all specific ISRs...

//1) SPI interrupt in low priority
	 PINT SPIINT_LP;
//2) SCI receive (RX) interrupt in low priority
	 PINT RXINT_LP;
//3) SCI Transmit (Tx) interrupt in low priority
	 PINT TXINT_LP;
//4) CAN mailbox interrupt in low priority
	 PINT CANMBINT_LP;
//5) CAN Error interrupt in low priority
	 PINT CANERINT_LP;

// ***************LEVEL 6 interrupts **********************
// **********(including CPU INT6 interrupt)****************
	 PINT INT6;// General  INT6 level peripherals
// Now here comes all specific ISRs...

//1) ADC interrupt in low priority
	 PINT ADC_LP;
//2) External pin1 interrupt in low priority
	 PINT XINT1_LP;
//3) External pin 2 interrupt in low priority
	 PINT XINT2_LP;

 
};

//---------------------------------------------------------------------------
// PIE Interrupt Vector Table External References & Function Declarations:
//
extern struct PIE_VECT_TABLE PieVectTable;

// functions
extern void initPieVectTable(void);


#endif    // end 
