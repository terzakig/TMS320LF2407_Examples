//###############################################################
//      TMS320 General pin IO registers 
//      George Terzakis 2009
//		
//
//###########################################################################

#ifndef DSP24_GPIO_H
#define DSP24_GPIO_H

//----------------------------------------------------
// General purpose I/O (GPIO) Register Bit Definitions                                               

// MCRA

struct IOMUXCTRLA_BITS  {      // bits   description (MCRA)
   unsigned int SCITXD_GPIOA0:1;     // 0  PORTA0 if 0
   unsigned int SCIRXD_GPIOA1:1;     // 1 PORTA1  if 0
   unsigned int XINT1_GPIOA2:1;     // 2  PORTA2 if 0
   unsigned int CAP1QEP1_GPIOA3:1;     // 3 PORTA3 if 0
   unsigned int CAP2QEP2_GPIOA4:1;     // 4 PORTA4  if 0
   unsigned int CAP3_GPIOA5:1;     // 5 PORTA5 if 0
   unsigned int PWM1_GPIOA6:1;    // 6  PORTA6  if 0
   unsigned int PWM2_GPIOA7:1;    // 7 PORTA7  if 0     
   unsigned int PWM3_GPIOB0:1;   // 8 PORTB0   if 0
   unsigned int PWM4_GPIOB1:1;   // 9 PORTB1  if 0
   unsigned int PWM5_GPIOB2:1; // 10 PORTB2  if 0
   unsigned int PWM6_GPIOB3:1;   // 11 PORTB3 if 0
   unsigned int T1PWMT1CMP_GPIOB4:1; // 12 PORTB4 if 0
   unsigned int T1PWMT2CMP_GPIOAB5:1;  // 13  PORTB5 if 0
   unsigned int TDIRA_GPIOAB6:1;  // 14  PORTB6 if 0
   unsigned int TCLKINA_GPIOAB7:1;  // 15 PORTB7 if 0
         
};

union IOMUXCTRLA_REG {
   unsigned int        all;
   struct IOMUXCTRLA_BITS bit;
};
extern volatile union IOMUXCTRLA_REG *IOMUXCTRLAbits;



// MCRB

struct IOMUXCTRLB_BITS  {      // bits   description (MCRB)
   unsigned int WR_GPIOC0:1;     // 0  PORTC0 if 0
   unsigned int BIO_GPIOC1:1;     // 1 PORTC1 if 0
   unsigned int SPISIMO_GPIOC2:1;     // 2  PORTC2 if 0
   unsigned int SPISOMI_GPIOC3:1;     // 3 PORTC3 if 0
   unsigned int SPICLK_GPIOC4:1;     // 4 PORTC4  if 0
   unsigned int SPISTE_GPIOC5:1;     // 5 PORTC5 if 0
   unsigned int CANTX_GPIOC6:1;    // 6  PORTC6 if 0
   unsigned int CANRX_GPIOC7:1;    // 7 PORTC7  if 0     
   unsigned int XINTADCSOC_GPIOD0:1;   // 8 PORTD0 if 0/XINT or ADC SOC
   unsigned int EMU0_rsvd:1;   // 9 reserved if 0/EMU0
   unsigned int EMU1_rsvd:1; // 10 reserved if 0/ EMU1
   unsigned int TCK_rsvd:1;   // 11 reserved if 0/ TCK
   unsigned int TDI_rsvd:1; // 12 reserved if 0/TDI 
   unsigned int TDO_rsvd:1;  // 13  reserved if 0/TDO
   unsigned int TMS_rsvd:1;  // 14  reserved if 0 / TMS
   unsigned int TMS2_rsvd:1;  // 15 reserved if 0 / TMS2
         
};

union IOMUXCTRLB_REG {
   unsigned int        all;
   struct IOMUXCTRLB_BITS bit;
};
extern volatile union IOMUXCTRLB_REG *IOMUXCTRLBbits;



// MSCRC
struct IOMUXCTRLC_BITS  {      // bits   description (MCRC)
   unsigned int CLKOUT_GPIOE0:1;     // 0  PORTC0 if 0
   unsigned int PWM7_GPIOE1:1;     // 1 PORTC1 if 0
   unsigned int PWM8_GPIOE2:1;     // 2  PORTC2 if 0
   unsigned int PWM9_GPIOE3:1;     // 3 PORTC3 if 0
   unsigned int PWM10_GPIOE4:1;     // 4 PORTC4  if 0
   unsigned int PWM11_GPIOE5:1;     // 5 PORTC5 if 0
   unsigned int PWM12_GPIOE6:1;    // 6  PORTC6 if 0
   unsigned int CAP4QEP3_GPIOE7:1;    // 7 PORTC7  if 0     
   unsigned int CAP5QEP4_GPIOF0:1;   // 8 PORTD0 if 0/XINT or ADC SOC
   unsigned int CAP6_GPIOF1:1;   // 9 reserved if 0/EMU0
   unsigned int T3PWMT3CMP_GPIOF2:1; // 10 reserved if 0/ EMU1
   unsigned int T4PWMT4CMP_GPIOF3:1;   // 11 reserved if 0/ TCK
   unsigned int TDIRB_GPIOF4:1; // 12 reserved if 0/TDI 
   unsigned int TCLKINB_GPIOF5:1;  // 13  reserved if 0/TDO
   unsigned int rsvd1:1;  // 14  reserved
   unsigned int rsvd2:1;  // 15 reserved
         
};

union IOMUXCTRLC_REG {
   unsigned int        all;
   struct IOMUXCTRLC_BITS bit;
};
extern volatile union IOMUXCTRLC_REG *IOMUXCTRLCbits;


//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register A bit definitions                                    
// 
// PADATDIR
struct IODIRDATA_BITS  {      // bits   description (PADATDIR)
   unsigned int IOPA0:1;     // 0  A0 data
   unsigned int IOPA1:1;          // 1 A1 data
   unsigned int IOPA2:1;          // 2 A2 data
   unsigned int IOPA3:1;          // 3  A3 data
   unsigned int IOPA4:1;          // 4  A4 data
   unsigned int IOPA5:1;          // 5  A5 data
   unsigned int IOPA6:1;          // 6  A6 data
   unsigned int IOPA7:1;          // 7  A7 data      
   unsigned int A0DIR:1;          // 8  A0 direction (0 input/1 output)
   unsigned int A1DIR:1;          // 9  A1 direction (0 input/1 output)
   unsigned int A2DIR:1;         // 10  A2 direction (0 input/1 output)
   unsigned int A3DIR:1;         // 11 A3 direction (0 input/1 output)
   unsigned int A4DIR:1;         // 12 A4 direction (0 input/1 output)
   unsigned int A5DIR:1;         // 13  A5 direction (0 input/1 output)
   unsigned int A6DIR:1;         // 14  A6 direction (0 input/1 output) 
   unsigned int A7DIR:1;         // 15  A7 direction (0 input/1 output)
         
};

union IODIRDATA_REG {
   unsigned int               all;
   struct IODIRDATA_BITS bit;
};
extern volatile union IODIRDATA_REG *IODIRDATAbits;


//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register B bit definitions                                    
// 
// PBDATDIR
struct IODIRDATB_BITS  {      // bits   description (PBDATDIR)
   unsigned int IOPB0:1;     // 0  B0 data
   unsigned int IOPB1:1;          // 1 B1 data
   unsigned int IOPB2:1;          // 2 B2 data
   unsigned int IOPB3:1;          // 3  B3 data
   unsigned int IOPB4:1;          // 4  B4 data
   unsigned int IOPB5:1;          // 5  B5 data
   unsigned int IOPB6:1;          // 6  B6 data
   unsigned int IOPB7:1;          // 7  B7 data      
   unsigned int B0DIR:1;          // 8  B0 direction (0 input/1 output)
   unsigned int B1DIR:1;          // 9  B1 direction (0 input/1 output)
   unsigned int B2DIR:1;         // 10  B2 direction (0 input/1 output)
   unsigned int B3DIR:1;         // 11 B3 direction (0 input/1 output)
   unsigned int B4DIR:1;         // 12 B4 direction (0 input/1 output)
   unsigned int B5DIR:1;         // 13  B5 direction (0 input/1 output)
   unsigned int B6DIR:1;         // 14  B6 direction (0 input/1 output) 
   unsigned int B7DIR:1;         // 15  B7 direction (0 input/1 output)
         
};

union IODIRDATB_REG {
   unsigned int               all;
   struct IODIRDATB_BITS bit;
};
extern volatile union IODIRDATB_REG *IODIRDATBbits;


//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register C bit definitions                                    
// 
// PCDATDIR
struct IODIRDATC_BITS  {      // bits   description (PCDATDIR)
   unsigned int IOPC0:1;     // 0  C0 data
   unsigned int IOPC1:1;          // 1 C1 data
   unsigned int IOPC2:1;          // 2 C2 data
   unsigned int IOPC3:1;          // 3  C3 data
   unsigned int IOPC4:1;          // 4  C4 data
   unsigned int IOPC5:1;          // 5  C5 data
   unsigned int IOPC6:1;          // 6  C6 data
   unsigned int IOPC7:1;          // 7  C7 data      
   unsigned int C0DIR:1;          // 8  C0 direction (0 input/1 output)
   unsigned int C1DIR:1;          // 9  C1 direction (0 input/1 output)
   unsigned int C2DIR:1;         // 10  C2 direction (0 input/1 output)
   unsigned int C3DIR:1;         // 11 C3 direction (0 input/1 output)
   unsigned int C4DIR:1;         // 12 C4 direction (0 input/1 output)
   unsigned int C5DIR:1;         // 13  C5 direction (0 input/1 output)
   unsigned int C6DIR:1;         // 14  C6 direction (0 input/1 output) 
   unsigned int C7DIR:1;         // 15  C7 direction (0 input/1 output)
         
};

union IODIRDATC_REG {
   unsigned int               all;
   struct IODIRDATC_BITS bit;
};
extern volatile union IODIRDATC_REG *IODIRDATCbits;



//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register D bit definitions                                    
// 
// PDDATDIR
struct IODIRDATD_BITS  {      // bits   description (PDDATDIR)
   unsigned int IOPD0:1;     // 0  D0 data
   unsigned int rsvd1:7;          // reserved
   unsigned int D0DIR:1;          // 8 D0 direction (0 input/1 output)
   unsigned int rsvd2:7;          // 3  reserved
         
};

union IODIRDATD_REG {
   unsigned int               all;
   struct IODIRDATD_BITS bit;
};
extern volatile union IODIRDATD_REG *IODIRDATDbits;


//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register E bit definitions                                    
// 
// PEDATDIR
struct IODIRDATE_BITS  {      // bits   description (PEDATDIR)
   unsigned int IOPE0:1;     // 0  E0 data
   unsigned int IOPE1:1;          // 1 E1 data
   unsigned int IOPE2:1;          // 2 E2 data
   unsigned int IOPE3:1;          // 3  E3 data
   unsigned int IOPE4:1;          // 4  E4 data
   unsigned int IOPE5:1;          // 5  E5 data
   unsigned int IOPE6:1;          // 6  E6 data
   unsigned int IOPE7:1;          // 7  E7 data      
   unsigned int E0DIR:1;          // 8  E0 direction (0 input/1 output)
   unsigned int E1DIR:1;          // 9  E1 direction (0 input/1 output)
   unsigned int E2DIR:1;         // 10  E2 direction (0 input/1 output)
   unsigned int E3DIR:1;         // 11 E3 direction (0 input/1 output)
   unsigned int E4DIR:1;         // 12 E4 direction (0 input/1 output)
   unsigned int E5DIR:1;         // 13  E5 direction (0 input/1 output)
   unsigned int E6DIR:1;         // 14  E6 direction (0 input/1 output) 
   unsigned int E7DIR:1;         // 15  E7 direction (0 input/1 output)
         
};

union IODIRDATE_REG {
   unsigned int               all;
   struct IODIRDATE_BITS bit;
};
extern volatile union IODIRDATE_REG *IODIRDATEbits;


//---------------------------------------------------------------------------------------
// GPIO  Direction and Data control register F bit definitions                                    
// 
// PFDATDIR
struct IODIRDATF_BITS  {      // bits   description (PFDATDIR)
   unsigned int IOPF0:1;     // 0  F0 data
   unsigned int IOPF1:1;          // 1 F1 data
   unsigned int IOPF2:1;          // 2 F2 data
   unsigned int IOPF3:1;          // 3  F3 data
   unsigned int IOPF4:1;          // 4  F4 data
   unsigned int IOPF5:1;          // 5  F5 data
   unsigned int IOPF6:1;          // 6  F6 data
   unsigned int rsvd1:1;          // 7  reserved      
   unsigned int F0DIR:1;          // 8  F0 direction (0 input/1 output)
   unsigned int F1DIR:1;          // 9  F1 direction (0 input/1 output)
   unsigned int F2DIR:1;         // 10  F2 direction (0 input/1 output)
   unsigned int F3DIR:1;         // 11 F3 direction (0 input/1 output)
   unsigned int F4DIR:1;         // 12 F4 direction (0 input/1 output)
   unsigned int F5DIR:1;         // 13  F5 direction (0 input/1 output)
   unsigned int F6DIR:1;         // 14  F6 direction (0 input/1 output) 
   unsigned int rsvd2:1;         // 15  reserved
         
};

union IODIRDATF_REG {
   unsigned int               all;
   struct IODIRDATF_BITS bit;
};
extern volatile union IODIRDATF_REG *IODIRDATFbits;




#endif  // end of DSP24_GPIO_H definition

//===========================================================================
// ouf! No more.
//===========================================================================
