// Using the Serial Peripheral Interface 
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);
extern void initIO(void);
extern void initSPI(void);
extern void sendCharSPI(unsigned int ch);

void main() {

  initSystem();
  initIO();
  initSPI();
  
  // enable global interrupt switch
  asm("  CLRC INTM");
  // main loop

   while (1) {

        sendCharSPI(0x007);
		

   }
}