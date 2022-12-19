/*
 * timer.h
 *
 * Created: 12/7/2022 8:25:22 PM
 *  Author: emana
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//include registers.h
#include "../../Utilities/registers.h"

//all driver macros
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM00 3
#define COM00 4
#define COM01 5
#define WGM01 6
#define FOC0 7
#define TOV0 0
#define TOIE0 0

#define Freq 1000000

//DRIVERS ENUM - FOR THE ERROR STATE
typedef enum {TIMER_OK, TIMER_ERROR}TIMER_ERROR_T;


//all driver function prototypes
// to initiate timer 0
TIMER_ERROR_T timer0_init(uint16_t prescaler);
// to enable timer 0 delay
TIMER_ERROR_T timer0_delay(uint16_t delay);
// to enable timer 0 overflow interrupt
TIMER_ERROR_T timer0_enableInterrupt(void);
// to stop timer 0
TIMER_ERROR_T timer0_stop(void);




#endif /* TIMER_H_ */