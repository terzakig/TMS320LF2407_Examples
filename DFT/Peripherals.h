#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "DSP24_Core.h"
#include "DSP24_Ev.h"
#include "DSP24_ADC.h"
#include "DSP24_Spi.h"
#include "Globals.h"


void initADC(void);

void initTimer1(void);

void initSPI(void);

void sendWordSPI(unsigned int wrd);

#endif