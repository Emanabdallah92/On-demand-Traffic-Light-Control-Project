/*
 * application.c
 *
 * Created: 12/12/2022 5:37:27 PM
 *  Author: emana
 */ 
#include "application.h"

//Global variables
uint8_t *state;
int button = 0;

APP_ERROR_T APP_init(void)
{
	// Initiate the button - PORT D PIN 2
	BUTTON_init(2, PORT_D);
	
	// Initiate the LED - PORT A PIN 3
	LED_init(3, PORT_A);
	
	// Initiate timer0 - with prescalar 1
	 timer0_init(1);
	 
}

APP_ERROR_T APP_start(void)
{
	// Read the button state
	BUTTON_read(2, PORT_D, &state);
	
	// If button is pressed (HIGH) 
	if( *state == HIGH)
	{
		//Toggle the LED for 512ms
		LED_toggle(3, PORT_A);
		timer0_delay(512);
	} 

	
}
