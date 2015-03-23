// **********************************************************
// *			Header file for DSP24_SysFunc.c			    *
// *													    *
// *				George Terzakis 2009				    *
// *													    *
// **********************************************************

#ifndef DSP24_SYSFUNC_H
#define DSP24_SYSFUNC_H

#define noPWM 0
#define usePWM 1
#define noCAN 0
#define useCAN 1
#define noSPI 0
#define useSPI 1
#define noSCI 0
#define useSCI 1
#define noCAP 0
#define useCAP 1

                     // Acquisition time as x/60 (usecs)
#define ADCsample1 0 // 1/60 usec
#define ADCsample2 1 // 1/15 usec
#define ADCsample3 2 // 0.1 usec
#define ADCsampke4 3 // 2/15 usec
#define ADCsample5 4 // 1/6 usec
#define ADCsample6 5 // 0.2 usec
#define ADCsample7 6 // 0.25 usec
#define ADcsample8 7 // 4/15 usec
#define ADCsample9 8 // 0.3 usec
#define ADCsample10 9 // 0.33 usec
#define ADCsample11 10 // 22/60 usec
#define ADCsample12 11 // 2/5 usec
#define ADCsample13 12 // 13/30 usec
#define ADCsample14 13 // 28/60 usec
#define ADCsample15 14 // 0.5 usec
#define ADCsample16 15 // 8/15 usec 


extern void initSystem(int T1pwm, int T2pwm, int T3pwm, int T4pwm, 
				int CANfunc, int SPIfunc, int SCIfunc, 
				int CAP1func, int CAP2func, int CAP3func,
				int CAP4func, int CAP5func, int CAP6func,
				int pwm1, int pwm2);


extern void initPWMEVA(int prd, double duty1, double duty2, double duty3);


#endif