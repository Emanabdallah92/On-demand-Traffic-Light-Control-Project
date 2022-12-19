/*
 * application.c
 *
 * Created: 12/12/2022 3:52:10 AM
 *  Author: emana
 */ 
#include "application.h"

//Global variables
uint8_t *state1;
uint8_t *state2;

APP_ERROR_T APP_init(void)
{
	// Initiate the first button - PORT C PIN 0 - INPUT
	BUTTON_init(0, PORT_C);
	
	// Initiate the second button - PORT D PIN 0 -INPUT
	BUTTON_init(0, PORT_D);
	
	// Initiate the GREEn LED - PORT A PIN 0 - OUTPUT
	LED_init(0, PORT_A); 
	
	// Initiate the GREEn LED - PORT A PIN 7 - OUTPUT
	LED_init(7, PORT_A);
}

APP_ERROR_T APP_start(void)
{
	
	// if button one is pressed the GREEN LED will be on 
	//  To read the button state 
	BUTTON_read(0, PORT_C, &state1);
	if(*state1 == HIGH)
	{
		// GREEN LED will be on
		LED_on(0, PORT_A);
		
		// YELLOW LED will be off
		LED_off(7, PORT_A);	
	}
	
	
	//if button two is pressed YELLOW LED will toggle and the GREEN LED will be off
	// To read the button state
	BUTTON_read(0, PORT_D, &state2);
	if(*state2 == HIGH)
	{	
		
		// YELLOW LED will toggle
		LED_toggle(7, PORT_A);
		
		// GREEN LED will be off
		LED_off(0, PORT_A);
	}
	else
	{
		// YELLOW LED will be off
		LED_off(7, PORT_A);
	}
	
	
	
	
}
