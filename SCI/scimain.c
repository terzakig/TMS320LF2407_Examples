// Using the Serial Communicatrons Interface (RS232)
//
// George Terzakis 2009
//
// From the book: "Introduction to C programming with the TMS320LF2407 DSP Controller"

extern void initSystem(void);
extern void initIO(void);
extern void initSCI(void);
extern void sendChar(char c);

void main(void) {
  int i;
  char ch;

  initSystem();
  initIO();
  initSCI();

  // enable global interrupts
  asm("  CLRC INTM");
  // main loop
  while(1) {

    for (i=0; i<15000; i++); // delay
	ch = 'A';
	for (i=0; i<10; i++)  
	          sendChar(ch+i);	
  }
}