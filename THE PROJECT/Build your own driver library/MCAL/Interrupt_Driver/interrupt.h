/*
 * interrupt.h
 *
 * Created: 12/9/2022 12:45:33 AM
 *  Author: emana
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// INclude register.h
#include "../../Utilities/registers.h"

//DRIVER MACROS
#define I 7
#define INT0 6
#define INT1 7
#define INT2 5
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6

//DRIVER ENUM
typedef enum { INT_0, INT_1, INT_2}EXT_t;
typedef enum {LOW_LEVEL, PIN_CHANGE, FALLING, RISING }MODE_t;

/*EXTERNAL INTERRUPT VECTORS*/
//EXTERNAL INTERRUPT REQUEST 0
#define EXT_INT_0 __vector_1
//EXTERNAL INTERRUPT REQUEST 1
#define EXT_INT_1 __vector_2
//EXTERNAL INTERRUPT REQUEST 2
#define EXT_INT_2 __vector_3

//TIMER/COUNTER 0 OVERFLOW
#define TIM0_OVF __vector_11

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//DRIVERS ENUM - FOR THE ERROR STATE
typedef enum {INTERRUPT_OK, INTERRUPT_ERROR}INTERRUPT_ERROR_T;

// FUNCTION PROTOTYPE
// to enable global interrupt
INTERRUPT_ERROR_T enable_globalInterrupt(void);

// to disable global interrupt
INTERRUPT_ERROR_T disable_globalInterrupt(void);

// to enable the interrupt pin and choose the mode
INTERRUPT_ERROR_T extEnable_pin(EXT_t interruptNumber, MODE_t interruptMode);




#endif /* INTERRUPT_H_ */