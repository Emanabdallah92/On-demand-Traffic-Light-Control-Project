/*
 * interrupt.c
 *
 * Created: 12/9/2022 12:45:20 AM
 *  Author: emana
 */ 
#include "interrupt.h"


INTERRUPT_ERROR_T enable_globalInterrupt(void)
{
	// Enable interrupt by writing 1 in bit I
	set_bit(SREG, I);
	//ERROR STATE
	return INTERRUPT_OK;
}

INTERRUPT_ERROR_T disable_globalInterrupt(void)
{
	// Disable interrupt by writing 0 in bit I
	clear_bit(SREG, I);
	//ERROR STATE
	return INTERRUPT_OK;
}

INTERRUPT_ERROR_T extEnable_pin(EXT_t interruptNumber, MODE_t interruptMode)
{
	switch(interruptNumber)
	{
		// TO choose Interrupt mode
		case INT_0:
		if(interruptMode == LOW_LEVEL) // choose level mode
		{
			// Write 0 in MCUCR in bit ISC00
			clear_bit(MCUCR, ISC00);
			// Write 0 in MCUCR in bit ISC01
			clear_bit(MCUCR, ISC01);
		}
		if(interruptMode == PIN_CHANGE) // choose level mode
		{
			// Write 1 in MCUCR in bit ISC00
			set_bit(MCUCR, ISC00);
			// Write 0 in MCUCR in bit ISC01
			clear_bit(MCUCR, ISC01);
		}
		if(interruptMode == FALLING) // choose level mode
		{
			// Write 0 in MCUCR in bit ISC00
			clear_bit(MCUCR, ISC00);
			// Write 1 in MCUCR in bit ISC01
			set_bit(MCUCR, ISC01);
		}
		if(interruptMode == RISING) // choose level mode
		{
			// Write 1 in MCUCR in bit ISC00
			set_bit(MCUCR, ISC00);
			// Write 1 in MCUCR in bit ISC01
			set_bit(MCUCR, ISC01);
		}
		
		// to enable INT0
		set_bit(GICR, INT0);
		
		//ERROR STATE
		return INTERRUPT_OK;
		break;
		
		// TO choose Interrupt mode
		case INT_1:
		if(interruptMode == LOW_LEVEL) // to choose level mode
		{
			// Write 0 in MCUCR in bit ISC10
			clear_bit(MCUCR, ISC10);
			// Write 0 in MCUCR in bit ISC11
			clear_bit(MCUCR, ISC11);
		}
		if(interruptMode == PIN_CHANGE) // to choose level mode
		{
			// Write 1 in MCUCR in bit ISC10
			set_bit(MCUCR, ISC10);
			// Write 0 in MCUCR in bit ISC11
			clear_bit(MCUCR, ISC11);
		}
		if(interruptMode == FALLING) // to choose level mode
		{
			// Write 0 in MCUCR in bit ISC10
			clear_bit(MCUCR, ISC10);
			// Write 0 in MCUCR in bit ISC11
			set_bit(MCUCR, ISC11);
		}
		if(interruptMode == RISING) // to choose level mode
		{
			// Write 1 in MCUCR in bit ISC10
			set_bit(MCUCR, ISC10);
			// Write 1 in MCUCR in bit ISC11
			set_bit(MCUCR, ISC11);
		}
		
		// To enable INT1
		set_bit(GICR, INT1);
		
		//ERROR STATE
		return INTERRUPT_OK;
		break;
		
		// To choose interrupt level
		case INT_2:
		if(interruptMode == FALLING) // to choose level mode
		{
			// Write 0 in MCUCR in bit ISC2
			clear_bit(MCUCSR, ISC2);
		}
		if(interruptMode == RISING) // to choose level mode
		{
			// Write 1 in MCUCR in bit ISC2
			set_bit(MCUCSR, ISC2);
		}
		
		// TO enable INT2
		set_bit(GICR, INT2);
		
		//ERROR STATE
		return INTERRUPT_OK;
		break;
		default:
		//ERROR STATE
		return INTERRUPT_ERROR;
		break;
	}
}