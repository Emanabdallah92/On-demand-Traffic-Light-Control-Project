/*
 * led.h
 *
 * Created: 12/3/2022 12:01:31 AM
 *  Author: emana
 */ 


#ifndef LED_H_
#define LED_H_

// Include files.h (lower drivers)
#include "../../MCAL/DIO_Driver/dio.h"
#include "../../MCAL/Timer_Driver/timer.h"
#include "../../MCAL/Interrupt_Driver/interrupt.h"

//all driver function prototypes
// to initialize the LED
DRIVER_ERROR_T LED_init(uint8_t ledPin, uint8_t ledPort);
// To turn on the LED
DRIVER_ERROR_T LED_on(uint8_t ledPin, uint8_t ledPort);

//To turn off the LED
DRIVER_ERROR_T LED_off(uint8_t ledPin, uint8_t ledPort);

//To toggle the LED
DRIVER_ERROR_T LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */