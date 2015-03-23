// *************************************************************
// *                                                           *
// *          TMS320LF2407A Serial Peripheral Interface        *
// *                                                           *
// *                  George Terzakis 2009                     *
// *                                                           *
// *************************************************************

#ifndef DSP24_SPI_H
#define DSP24_SPI_H

//SPI Configuration Control Register
//SPICCR

struct SPICCR_BITS {
	unsigned int CHARLEN:4; // 0-3 Containing Character length in bits (so that appropriate shifts are done)
	unsigned int rsvd:2;    // 4-5 reserved
	unsigned int CLKPOL:1;  // 6 clock polarity. (0 spi is output on rising edge)
	unsigned int SPIRST:1;  // 7 Reset. Set to 0 to reset, but must keep 1 afterwards during operation
};
union SPICCR_REG {
	unsigned int all;
	struct SPICCR_BITS bit;
};
extern volatile union SPICCR_REG *SPICCRbits;


// SPI Operation Control Register
// SPICTL
struct SPICTL_BITS {
	unsigned int INTENA:1; // 0 Enables Transmit/Receive interrupt
	unsigned int TALK:1;   // 1 Transmission enable. 
	unsigned int MST_SLV:1; // 2 if 0 SPI is slave, 1 for master
	unsigned int CLKPHSEL:1; // 3 set 0 for normal clocking, 1 for for 1.5 cycle delay
	unsigned int OVRNINTENA:1; // 4 Overrun Int enable
	unsigned int rsvd:3;      // 5-7 reserved
};
union SPICTL_REG {
	unsigned int all;
	struct SPICTL_BITS bit;
};
extern volatile union SPICTL_REG *SPICTLbits;

// SPI Status Register
// SPISTS
struct SPISTS_BITS {
	unsigned int rsvd:5; // 0-4 reserved
	unsigned int TxBUFFULL:1; // 5 Transmit buffer full flag
	unsigned int SPIINT:1; //6 SPI INT flag
	unsigned int RxOVRN:1; // 7 Receive ioverrun flag
};
union SPISTS_REG {
	unsigned int all;
	struct SPISTS_BITS bit;
};
extern volatile union SPISTS_REG *SPISTSbits;

// SPI Baud Register
// SPIBRR
struct SPIBRR_BITS {
	unsigned int BITRATE:7; // 0-6 SPI bit rate
	unsigned int rsvd:1; // 7 reserved
};

// ***********SPI Baudrate Formula**********************
//
//  for SPIBRR=3...127:         SPI Baud Rate=CLKOUT/(SPIBRR+1)
//
//  for SPIBRR=0,1,2:           SPI Baud Rate=CLKOUT/4
//
// *****************************************************
union SPIBRR_REG {
	unsigned int all;
	struct SPIBRR_BITS bit;
};
extern volatile union SPIBRR_REG *SPIBRRbits;

// DATA & BUFFER registers are used as straight values. 
// no bitwise structs define

// SPI Priority Control Register
// SPIPRI
struct SPIPRI_BITS {
	unsigned int rsvd1:4; //0-3 reserved
	unsigned int SPIFREE:1; // 4 SPI suspension free bit
	unsigned int SPISOFT:1; // 5 SPI suspension soft bit
	unsigned int SPIPRI:1;    // 6 SPI interrupt prioority (0 high, 1 low)
	unsigned int rsvd2:1;    // 7 reserved
};
union SPIPRI_REG {
	unsigned int all;
	struct SPIPRI_BITS bit;
};
extern volatile union SPIPRI_REG *SPIPRIbits;




#endif  // end of DSP24_SPI_H definition

