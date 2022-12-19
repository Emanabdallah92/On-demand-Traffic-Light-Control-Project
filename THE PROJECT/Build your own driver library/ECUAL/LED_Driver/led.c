/*
 * led.c
 *
 * Created: 12/3/2022 12:01:20 AM
 *  Author: emana
 */ 
#include "led.h"


DRIVER_ERROR_T LED_init(uint8_t ledPin, uint8_t ledPort) // output
{
	//Initiate the lED which is always OUTPUT (OUT)
	DIO_init(ledPin, ledPort, OUT);
	DIO_write(ledPin,ledPort, LOW);
	
	//ERROR STATE
	return DRIVER_OK;
}


DRIVER_ERROR_T LED_on(uint8_t ledPin, uint8_t ledPort)
{
	// to turn on the led we write HIGH
	DIO_write(ledPin, ledPort, HIGH);
	
	//ERROR STATE
	return DRIVER_OK;
}

DRIVER_ERROR_T LED_off(uint8_t ledPin, uint8_t ledPort)
{
	// to turn off the led we write LOW
	DIO_write(ledPin,ledPort, LOW);
	
	//ERROR STATE
	return DRIVER_OK;
}
DRIVER_ERROR_T LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	// To toggle the led
	DIO_toggle(ledPin, ledPort);
	
	//ERROR STATE
	return DRIVER_OK;
}