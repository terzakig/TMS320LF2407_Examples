#ifndef DSP24_SCI_H
#define DSP24_SCI_H


// SCICCR communication control register (SCICCR)
struct  SCICCR_BITS {      
   unsigned int SCICHAR:3;         // 0-2 Character length (11 for 8 bits)        
   unsigned int ADDRIDLE_MODE:1;   // 3 ADDR/IDLE Mode (use IDLE-0 for normal RS-232 comms)
   unsigned int LOOPBKENA:1;       // 4 Loop Back enable
   unsigned int PARITYENA:1;       // 5 Parity enable   
   unsigned int PARITY:1;          // 6 Even-1 or Odd-0 Parity (if enabled)
   unsigned int STOPBITS:1;        // 7 Number of Stop Bits (0 for asb, 1 for 2sb)
}; 

union SCICCR_REG {
   unsigned int  all;
   struct SCICCR_BITS  bit;
};
extern volatile union SCICCR_REG *SCICCRbits;


// SCICTL1 control register 1 bit definitions:                       
struct  SCICTL1_BITS {     
   unsigned int RXENA:1; // 0 SCI receiver enable (if 1 characters are sent to SCIRXEMU and SCIRXBUF)
   unsigned int TXENA:1; // 1 SCI transmitter enable (if 1 data is sent out through SCITXD reg. 0 disables/resets transmit)
   unsigned int SLEEP:1; // 2 SCI sleep  
   unsigned int TXWAKE:1;// 3 Transmitter wakeup method (usually selecting one to enable the transmit feature in either IDLE or ADDRESS mode)
   unsigned int rsvd1:1; // 4 reserved
   unsigned int SWRESET:1; // 5 Software reset (0 resets without affecting configuration, 1 enables/reenables the SCI)   
   unsigned int RXERRINTENA:1; // 6 Receive Error interrupt enable
   unsigned int rsvd2:1; // 7 Reserved
	
}; 

union SCICTL1_REG {
   unsigned int    all;
   struct SCICTL1_BITS  bit;
};
extern volatile union SCICTL1_REG *SCICTL1bits;

// SCI control register 2 (SCICTL2) 
struct  SCICTL2_BITS {     
   unsigned int TXINTENA:1;   // 0 Transmit interrupt enable    
   unsigned int RXBKINTENA:1; // 1 Receiver-buffer break interrupt enable
   unsigned int rsvd:4;       // 5:2 reserved
   unsigned int TXEMPTY:1;  // 6 Transmitter empty flag (0 if loaded with data, 1 if empty)
   unsigned int TXRDY:1;   // 7 Transmitter ready flag  (if 1 TX register SCITXBUF is ready to receive another character)
}; 

union SCICTL2_REG {
   unsigned int     all;
   struct SCICTL2_BITS  bit;
};
extern volatile union SCICTL2_REG *SCICTL2bits;


// SCIRXST Receiver status register (SCIRXST)
struct  SCIRXST_BITS {  
   unsigned int rsvd:1;    // 0 reserved
   unsigned int RXWAKE:1;  // 1 Receiver wakeup detect flag
   unsigned int PE:1;      // 2 Parity error flag
   unsigned int OE:1;      // 3 Overrun error flag
   unsigned int FE:1;      // 4 Framing error flag
   unsigned int BRKDT:1;   // 5 Break-detect flag   
   unsigned int RXRDY:1;   // 6 Receiver ready flag (1 if receiver ready to receive)
   unsigned int RXERR:1;   // 7 Receiver error flag

}; 

union SCIRXST_REG {
   unsigned int                 all;
   struct SCIRXST_BITS  bit;
};
extern volatile union SCIRXST_REG *SCIRXSTbits;

// Priority control register (SCIPRI)                                                    
struct  SCIPRI_BITS {      
   unsigned int rsvd:3;  // 0-2 reserved
   unsigned int FREE:1;  // 3 Free emulation suspend mode (determine behaviour of sci in suspensions)
   unsigned int SOFT:1;  // 4 Soft emulation suspend mode  (i.e. breakpoints, etc.)
   unsigned int SCIRXPRI:1;// 5 (0-high priority request, 1-low priority request)
   unsigned int SCITXPRI:1;// 6 (0-high priority request, 1-low priority request)	
   unsigned int rsvd1:1;  // 6 (0-high priority request, 1-low priority request)	

}; 

union SCIPRI_REG {
   unsigned int                all;
   struct SCIPRI_BITS  bit;
};
extern volatile union SCIPRI_REG *SCIPRIbits;


extern volatile unsigned int* SCIHBAUD;   // SCI baud-select reg, high byte
extern volatile unsigned int* SCILBAUD;   // SCI baud-select reg, low byte 
extern volatile unsigned int* SCIRXEMU;   // SCI emulation data buffer register
extern volatile unsigned int* SCIRXBUF;   // SCI receiver data buffer register
extern volatile unsigned int* SCITXBUF;   // SCI transmit data buffer register

#endif  