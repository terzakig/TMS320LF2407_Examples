// Using the ADC in Dual Sequencer mode
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);

extern void initADC_DS(void);


void main(void) {

   initSystem();
   initADC_DS();

  // enable interrupts
  asm("  CLRC INTM");
  // main loop

  while (1) {
   }
}