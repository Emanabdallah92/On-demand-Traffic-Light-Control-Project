/*
 * button.h
 *
 * Created: 12/3/2022 2:33:53 AM
 *  Author: emana
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// Include files.h (lower Drivers)
#include "../../MCAL/DIO_Driver/dio.h"
#include "../../MCAL/Timer_Driver/timer.h"
#include "../../MCAL/Interrupt_Driver/interrupt.h"

// Button state macros
#define LOW 0
#define HIGH 1

// function prototype
// initialize
DRIVER_ERROR_T BUTTON_init(uint8_t buttonPin, uint8_t buttonPort);

// button read
DRIVER_ERROR_T BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value);




#endif /* BUTTON_H_ */