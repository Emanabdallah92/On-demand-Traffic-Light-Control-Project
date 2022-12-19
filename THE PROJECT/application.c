/*
 * application.c
 *
 * Created: 12/3/2022 12:51:23 AM
 *  Author: emana
 */ 
#include "application.h"
#include <stdbool.h>

#define delay_time 5000

//GLOBAL VARIABLES
volatile double time_passed;
volatile double time_external;
volatile double current_time;


bool Green=0, Red=0, Yellow=0, Check=0;

uint8_t button = 0;

void APP_init(void)
{	
	current_time = time_passed;
	
	//initiate the pedestrian push button
	BUTTON_init(2, PORT_D);
	
	//Enable timer0 NORMAL MODE and set Prescaler= 1
	timer0_init(1);
	
	//Enable overflow interrupt
	timer0_enableInterrupt();
	
	//initiate the three  CAR's LEDs
	//initiate the Green LED on port A pin 0
	LED_init(0, PORT_A);
	//initiate the Yellow LED on port A pin 1
	LED_init(1, PORT_A);
	//initiate the Red LED on port A pin 2
	LED_init(2, PORT_A);
	
	//initiate the three PEDESTRIAN's LEDs
	//initiate the Green LED on port B pin 0
	LED_init(0, PORT_B);
	//initiate the Yellow LED on port B pin 1
	LED_init(1, PORT_B);
	//initiate the Red LED on port B pin 2
	LED_init(2, PORT_B);
	
	//enable global interrupt - set 1 in bit 7 in SREG
	enable_globalInterrupt();
	
	//Enable external interrupt 0 and choose external interrupt sense - rising mode
	extEnable_pin(INT_0, PIN_CHANGE);

	
}

void APP_start(void)
{	int i=0;
	switch(button)
	{	//CAR's MODE
		case 0:
			if (time_passed < delay_time)
			{
				//Turn on LED Green for 5s
				LED_on(0, PORT_A);
				Green = true;
				//Turn off LED RED and Yellow
				LED_off(1, PORT_A);
				LED_off(2, PORT_A);
				Yellow = false;
				Red = false;
			}
			
			else if ((time_passed > delay_time) && (time_passed < 10000))
			{	
				//Turn off LED RED and Green
				LED_off(0, PORT_A);
				LED_off(2, PORT_A);
				Red = false;
				Green = false;
				// Yellow Led is blinking
				if ((int)(time_passed/1000) % 2 == 0)
				{
					//Turn on LED Yellow
					LED_on(1, PORT_A); 
				}
				else
				{
					//Turn off LED Yellow 
					LED_off(1, PORT_A); 
				}
				Yellow = true;
			}
			
			else if ((time_passed > 10000) && (time_passed < 15000))
			{
				//Turn on LED Red for 5s
				LED_on(2, PORT_A);
				Red = true;
				//Turn off LED Green and Yellow
				LED_off(0, PORT_A);
				LED_off(1, PORT_A);
				Green = false;
				Yellow = false;
			}
			
			else if ((time_passed > 15000) && (time_passed < 20000))
			{	
				//Turn off LED RED and Green
				LED_off(0, PORT_A);
				LED_off(2, PORT_A);
				Red = false;
				Green = false;
				
				//Blinking Yellow LED
				if ((int)(time_passed/1000) % 2 == 0)
				{
					//Turn on LED Yellow
					LED_on(1, PORT_A);
				}
				else
				{
					//Turn off LED Yellow
					LED_off(1, PORT_A);
				}
				Yellow = true;
			}
			
			if(time_passed>20000)
			{
				time_passed=0;
			}
		break;
		//Pedestrian's mode
		case 1:
			//WHEN THE BUTTON IS PRESSED WHEN THE CAR'S RED LED IS ON
			if(Red == true)
			{	
				if(time_passed <delay_time)
				{
					//Turn on Car's Red LED for 5s
					LED_on(2, PORT_A);
					
					//Turn on Pedestrian's Green LED for 5s
					LED_on(0, PORT_B);
					LED_off(1, PORT_B);
					LED_off(2, PORT_B);
				}
				else if((time_passed>delay_time) && (time_passed<10000))
				{
					//Turn off Car's Red LED
					LED_off(2, PORT_A);
					
					//  Both Yellow LEDs start blinking for 5 seconds
					if ((int)(time_passed/1000) % 2 == 0)
					{
						//Turn on Car's Yellow LED
						LED_on(1, PORT_A);
						
						//Turn on Pedestrian's Yellow LED
						LED_on(1, PORT_B);
					}
					else
					{
						//Turn off Car's Yellow LED
						LED_off(1, PORT_A);
						
						//Turn off Pedestrian's Yellow LED
						LED_off(1, PORT_B);
					}
				}
				else if((time_passed>10000) && (time_passed<15000))
				{	
					//Turn off Car's Yellow LED
					LED_off(1, PORT_A);
					//Turn off Pedestrian's Yellow LED
					LED_off(1, PORT_B);
					//Turn off Pedestrian's Green LED
					LED_off(0, PORT_B);
					//Turn on Pedestrian's Red LED
					LED_on(2, PORT_B);
					//Turn on Car's Green LED
					LED_on(0, PORT_A);
				}
				else if(time_passed>15000)
				{
					//Turn off Pedestrian's Red LED
					LED_off(2, PORT_B);
					//Turn off Car's Green LED
					LED_off(0, PORT_A);
					button = 0;
					time_passed=0;
				}
			}
			
			//WHEN THE BUTTON IS PRESSED WHEN THE CAR'S GREEN LED IS ON
			if((Green == true) || (Yellow == true))
			{	
				if((time_passed<delay_time))
				{	
					//Turn off Car's Green LED
					LED_off(0, PORT_A);
					//Turn on Pedestrian's Red LED
					LED_on(2, PORT_B);
					if ((int)(time_passed/1000) % 2 == 0)
					{
						//Turn on Car's Yellow LED
						LED_on(1, PORT_A);
						//Turn on Pedestrian's Yellow LED 
						LED_on(1, PORT_B);
					}
					else
					{
						//Turn off Car's Yellow LED
						LED_off(1, PORT_A);
						//Turn off Pedestrian's Yellow LED
						LED_off(1, PORT_B);
					}
				}
				else if((time_passed> delay_time) && (time_passed<10000))
				{	
					//Turn off Car's Yellow LED
					LED_off(1, PORT_A);
					//Turn off Pedestrian's Yellow LED
					LED_off(1, PORT_B);
					//Turn off Pedestrian's Red LED
					LED_off(2, PORT_B);
					//Turn on Pedestrian's Green LED
					LED_on(0, PORT_B);
					//Turn on Car's Red LED
					LED_on(2, PORT_A);
				}
				else if((time_passed>10000) && (time_passed<15000))
				{		
						//Turn off Car's Red LED
						LED_off(2, PORT_A);
						
						//  Both Yellow LEDs start blinking for 5 seconds
						if ((int)(time_passed/1000) % 2 == 0)
						{
							//Turn on Car's Yellow LED
							LED_on(1, PORT_A);
							
							//Turn on Pedestrian's Yellow LED
							LED_on(1, PORT_B);
						}
						else
						{
							//Turn off Car's Yellow LED
							LED_off(1, PORT_A);
							
							//Turn off Pedestrian's Yellow LED
							LED_off(1, PORT_B);
						}
				}
				else if((time_passed>15000) && (time_passed<20000))
				{	
					//Turn off Car's Yellow LED
					LED_off(1, PORT_A);
					//Turn off Pedestrian's Yellow LED
					LED_off(1, PORT_B);
					//Turn off Pedestrian's Green LED
					LED_off(0, PORT_B);
					//Turn on Pedestrian's Red LED
					LED_on(2, PORT_B);
					//Turn on Car's Green LED
					LED_on(0, PORT_A);
				}
				else if(time_passed>20000)
				{
					
					//Turn off Pedestrian's Red LED
					LED_off(2, PORT_B);
					//Turn off Car's Green LED
					LED_off(0, PORT_A);
					button = 0;
					time_passed=0;
				}
				
			}
			
		
		break;	
	}
}




