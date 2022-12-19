/*
 * application.c
 *
 * Created: 12/12/2022 6:28:15 PM
 *  Author: emana
 */ 

#include "application.h"

// GLobal variables
volatile uint8_t button = 0;

APP_ERROR_T APP_init(void)
{
	// Initiate the button - PORT D PIN 2 
	BUTTON_init(2, PORT_D);
	
	// Initiate the RED LED - PORT A PIN 0
	LED_init(0, PORT_A);
	
	//Initiate the YELLOW LED - PORT A PIN 7
	LED_init(7, PORT_A);
	
	// Enable timer0 NORMAL MODE and set Prescaler= 1
	timer0_init(1);
	
	// Enable global interrupt - set 1 in bit 7 in SREG
	enable_globalInterrupt();
		
	// Enable external interrupt 0 and choose external interrupt sense - rising mode
	extEnable_pin(INT_0, RISING);
	
	//STATE ERROR
	return APP_OK;
}

APP_ERROR_T APP_start(void)
{
	switch(button)
	{
		// When the button is not pressed or pressed for the third time
		case 0:
			// Turn off the RED LED
			LED_off(0, PORT_A);
			
			//Turn off the YELLOW LED
			LED_off(7, PORT_A);
		break;
		
		// When the button is pressed for the first time
		case 1:
			// Turn on the RED LED
			LED_on(0, PORT_A);
			
			//Turn off the YELLOW LED
			LED_off(7, PORT_A);
		break;
			
		// When the button is pressed for the second time 
		case 2:
			// Turn on the YELLOW LED
			LED_on(7, PORT_A);
			
			// Turn off the RED LED
			LED_off(0, PORT_A);
		break;
		
		//ERROR STATE
		return APP_OK;
	}
}

ISR (EXT_INT_0)
{
	if(button>1)
	{ 
		button = 0;
	}
	else
	{
		button ++;
	}
}