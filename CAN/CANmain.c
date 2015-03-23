// Using the CAN peripheral
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);
extern void initCAN(void);
extern sendCANMsg(unsigned int * msg);
extern initIO(void);


void main() {
  unsigned int msg[] = { 0x0101, 1, 2}, i, g;

  initSystem();
  initIO();
  initCAN();
  
  
  // enable interrupts
  asm("  CLRC INTM");
  
   sendCANMsg(msg);
   // main loop
   while (1);
      	
}