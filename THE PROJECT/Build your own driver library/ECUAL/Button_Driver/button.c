/*
 * button.c
 *
 * Created: 12/3/2022 2:33:26 AM
 *  Author: emana
 */ 
#include "button.h"


DRIVER_ERROR_T BUTTON_init(uint8_t buttonPin, uint8_t buttonPort)
{
	// To initialize the button - always input(IN)
	DIO_init(buttonPin, buttonPort, IN);
	
	//ERROR STATE
	return DRIVER_OK;
}

DRIVER_ERROR_T BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value)
{
	// to read the button state
	DIO_read(buttonPin, buttonPort, *value);
	
	//ERROR STATE
	return DRIVER_OK;
}