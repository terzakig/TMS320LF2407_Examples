#include        "f2407_c.h" 


#define PI 		3.1415926
 	/*PWM modulate frequency*/




void pwm_init(void)
{

/*** Setup timers 1 and 2, and the PWM configuration ***/
    *T1CON = 0x0000;                    /* disable timer 1 */
    *T2CON = 0x0000;                    /* disable timer 2 */

    *GPTCONA = 0x0000;                  /* configure GPTCONA */
/*     
 bit 15        0:      reserved
 bit 14        0:      T2STAT, read-only
 bit 13        0:      T1STAT, read-only
 bit 12-11     00:     reserved
 bit 10-9      00:     T2TOADC, 00 = no timer2 event starts ADC
 bit 8-7       00:     T1TOADC, 00 = no timer1 event starts ADC
 bit 6         0:      TCOMPOE, 0 = Hi-z all timer compare outputs
 bit 5-4       00:     reserved
 bit 3-2       00:     T2PIN, 00 = forced low
 bit 1-0       00:     T1PIN, 00 = forced low
*/


/* Timer 1: configure to clock the PWM on PWM1 pin */
/* Symmetric PWM, 20KHz carrier frequency, 25% duty cycle */
    *T1CNT = 0x0000;                    /* clear timer counter */
    *T1PR = 3000;               /* set timer period */
    *DBTCONA = 0x0000;                  /* deadband units off */
    *CMPR1 = 3000*0.25;         /* set PWM1 duty cycle */

    *ACTRA = 0x0666;                    /* PWM1 pin set active high */     
/*
 bit 15        0:      space vector dir is CCW (don't care)
 bit 14-12     000:    basic space vector is 000 (dont' care)
 bit 11-10     01:     PWM6/IOPB3 pin active low
 bit 9-8       10:     PWM5/IOPB2 pin active high
 bit 7-6       01:     PWM4/IOPB1 pin active low
 bit 5-4       10:     PWM3/IOPB0 pin active high
 bit 3-2       01:     PWM2/IOPA7 pin active low
 bit 1-0       10:     PWM1/IOPA6 pin active high
*/

     *COMCONA = 0x8200;                 /* configure COMCON register */
/*
 bit 15        1:      1 = enable compare operation
 bit 14-13     00:     00 = reload CMPRx regs on timer 1 underflow
 bit 12        0:      0 = space vector disabled
 bit 11-10     00:     00 = reload ACTR on timer 1 underflow
 bit 9         1:      1 = enable PWM pins
 bit 8-0       0's:    reserved
*/


     *T1CON = 0x0840;                   /* configure T1CON register */
/*     
 bit 15-14     00:     stop immediately on emulator suspend
 bit 13        0:      reserved
 bit 12-11     01:     01 = continous-up/down count mode
 bit 10-8      000:    000 = x/1 prescaler
 bit 7         0:      reserved in T1CON
 bit 6         1:      TENABLE, 1 = enable timer
 bit 5-4       00:     00 = CPUCLK is clock source
 bit 3-2       00:     00 = reload compare reg on underflow
 bit 1         0:      0 = disable timer compare
 bit 0         0:      reserved in T1CON
*/



    *IMR |= 0x0002;                      /* enable desired core interrupts (in2)*/

/*** Setup the event manager interrupts ***/
    
    *EVAIMRA |= 0x0200;                  /* enable desired EVA group A interrupts */
    *EVAIMRB = 0x0000;                  /* enable desired EVA group B interrupts */
    *EVAIMRC = 0x0000;                  /* enable desired EVA group C interrupts */
    
}    

                                 

 
