// Using the ADC in cascaded sequencer mode
//
// George Terzakis 2009

extern void initSystem(void);
extern void initIO(void);
extern void initADC_CS(void);


void main(void) {

   initSystem();
   initIO();
   initADC_CS();

  // enable interrupts
  asm("  CLRC INTM");
  // main loop

  while (1) {
   }
}