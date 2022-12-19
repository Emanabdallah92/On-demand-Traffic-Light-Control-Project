/*
 * timer.c
 *
 * Created: 12/7/2022 8:25:05 PM
 *  Author: emana
 */ 
#include "timer.h"
#include "math.h"

// global variable
uint16_t Pre_Scaler=0;

TIMER_ERROR_T timer0_init(uint16_t prescaler)
{
	// to write 0 in WMG00 and WGM01
	//TTCR0 = 0x00;
	clear_bit(TTCR0, WGM00);
	clear_bit(TTCR0, WGM01);
	
	Pre_Scaler= prescaler;
	
	switch (prescaler)
	{
		// if prescalar = 1
		case 1:
		// write 1 in CS00
		set_bit(TTCR0, CS00);
		// write 0 in CS01
		clear_bit(TTCR0, CS01);
		// write 0 in CS01
		clear_bit(TTCR0, CS02);
		//ERROR STATE
		return TIMER_OK;
		break;
		
		// if prescaler = 8
		case 8:
		// write 0 in CS00
		clear_bit(TTCR0, CS00);
		// write 1 in CS01
		set_bit(TTCR0, CS01);
		// write 0 in CS02
		clear_bit(TTCR0, CS02);
		//ERROR STATE
		return TIMER_OK;
		break;
		
		// if prescaler = 64
		case 64:
		// write 1 in CS00
		set_bit(TTCR0, CS00);
		// write 1 in CS01
		set_bit(TTCR0, CS01);
		// write 0 in CS02
		clear_bit(TTCR0, CS02);
		//ERROR STATE
		return TIMER_OK;
		break;
		
		// if prescaler = 256
		case 256:
		// write 0 in CS00
		clear_bit(TTCR0, CS00);
		// write 0 in CS01
		clear_bit(TTCR0, CS01);
		// write 1 in CS02
		set_bit(TTCR0, CS02);
		//ERROR STATE
		return TIMER_OK;
		break;
		
		// if prescaler = 1024
		case 1024:
		// write 1 in CS00
		set_bit(TTCR0, CS00);
		// write 0 in CS01
		clear_bit(TTCR0, CS01);
		// write 1 in CS02
		set_bit(TTCR0, CS02);
		//ERROR STATE
		return TIMER_OK;
		break;
		
		default:
		//ERROR STATE
		return TIMER_ERROR;
		break;
	}
}
TIMER_ERROR_T timer0_delay(uint16_t delay)
{
	// start time value
	TCNT0 = 0x00;
	
	// to calculate the over flow
	double NumberOfoverFlow = ceil(((double)(delay*(Freq/1000)))/ ((double)(Pre_Scaler *256.0)));
	
	unsigned long overFlowCounter =0;
	while(overFlowCounter < NumberOfoverFlow)
	{
		// busy while
		while((TIFR &(1<<TOV0))==0);
		// clear the overflow flag
		TIFR |= (1<<0);
		overFlowCounter++;
	}
	
	overFlowCounter=0;
	//ERROR STATE
	return TIMER_OK;
}
TIMER_ERROR_T timer0_enableInterrupt(void)
{
	// to enable overflow interrupt
	TIMSK |= (1<<TOIE0);
	
	//ERROR STATE
	return TIMER_OK;
}

TIMER_ERROR_T timer0_stop()
{
	//TTCR0 = 0x00;
	
	clear_bit(TTCR0, CS00);
	clear_bit(TTCR0, CS01);
	clear_bit(TTCR0, CS02);
	clear_bit(TTCR0, WGM01);
	clear_bit(TTCR0, COM00);
	clear_bit(TTCR0, COM01);
	clear_bit(TTCR0, WGM00);
	clear_bit(TTCR0, FOC0);
	
	//ERROR STATE
	return TIMER_OK;
}