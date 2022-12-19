/*
 * dio.c
 *
 * Created: 12/2/2022 4:39:35 AM
 *  Author: emana
 */ 

#include "dio.h"


// FUNCTION DEFINTIONS
DRIVER_ERROR_T DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber)
	{	
		// To initiate the PortA 
		case PORT_A:
			if(direction == IN) // if direction was input
			{
				//DDRA &=~ (1<<pinNumber); 
				clear_bit(DDRA, pinNumber);	//write 0
				//ERROR STATE
				return DRIVER_OK;
			}
			else if(direction == OUT) //if direction was output
			{
				//DDRA |= (1<<pinNumber); 
				set_bit(DDRA, pinNumber); //write 1
				//ERROR STATE
				return DRIVER_OK;
			}
			else
			{
				//ERROR STATE
				return DRIVER_ERROR;
			}
		break;
		
		// To initiate the PortB
		case PORT_B:
			if(direction == IN)  // if direction was input
			{
				//DDRB &=~ (1<<pinNumber); 
				clear_bit(DDRB, pinNumber); //write 0
				//ERROR STATE
				return DRIVER_OK;
			}
			else if(direction == OUT) //if direction was output
			{
				//DDRB |= (1<<pinNumber); 
				set_bit(DDRB, pinNumber); //write 1
				//ERROR STATE
				return DRIVER_OK;
			}
			else
			{
				//ERROR STATE
				return DRIVER_ERROR;
			}
		break;
		
		// To initiate the PortC
		case PORT_C:
			if(direction == IN) // if direction was input
			{
				//DDRC &=~ (1<<pinNumber); 
				clear_bit(DDRC, pinNumber); //write 0
				//ERROR STATE
				return DRIVER_OK;
			}
			else if(direction == OUT) //if direction was output
			{
				//DDRC |= (1<<pinNumber);
				set_bit(DDRC, pinNumber); //write 1
				//ERROR STATE
				return DRIVER_OK;
			}
			else
			{
				//ERROR STATE
				return DRIVER_ERROR;
			}
		break;
		
		// To initiate the PortD
		case PORT_D:
		if(direction == IN) // if direction was input
		{
			//DDRD &=~ (1<<pinNumber);
			clear_bit(DDRD, pinNumber); //write 0
			//ERROR STATE
			return DRIVER_OK;
		}
		else if(direction == OUT) //if direction was output
		{
			//DDRD |= (1<<pinNumber); 
			set_bit(DDRD, pinNumber); //write 1
			//ERROR STATE
			return DRIVER_OK;
		}
		else
		{
			//ERROR STATE
			return DRIVER_ERROR;
		}
		break;
			
	}
}

DRIVER_ERROR_T DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{   // To write data
		case PORT_A:
		if(value == LOW) //if it was low
		{
			//PORTA &=~ (1<<pinNumber); 
			clear_bit(PORTA, pinNumber); // write 0
			//ERROR STATE
			return DRIVER_OK;
		}
		else if(value == HIGH) //if it was high
		{
			//PORTA |= (1<<pinNumber);
			set_bit(PORTA, pinNumber); // write 1
			//ERROR STATE
			return DRIVER_OK;
		}
		else
		{
			//ERROR STATE
			return DRIVER_ERROR;
		}
		break;
		
		// To write data
		case PORT_B:
		if(value == LOW) //if it was low
		{
			//PORTB &=~ (1<<pinNumber);
			clear_bit(PORTB, pinNumber); // write 0
			//ERROR STATE
			return DRIVER_OK;
		}
		else if(value == HIGH) //if it was high
		{
			//PORTB |= (1<<pinNumber);
			set_bit(PORTB, pinNumber); // write 1
			//ERROR STATE
			return DRIVER_OK;
		}
		else
		{
			//ERROR STATE
			return DRIVER_ERROR;
		}
		break;
		
		// To write data
		case PORT_C:
		if(value == LOW) //if it was low
		{
			//PORTC &=~ (1<<pinNumber);
			clear_bit(PORTC, pinNumber); // write 0
			//ERROR STATE
			return DRIVER_OK;
		}
		else if(value == HIGH) //if it was high
		{
			//PORTC |= (1<<pinNumber);
			set_bit(PORTC, pinNumber); //write 1
			//ERROR STATE
			return DRIVER_OK;
		}
		else
		{
			//ERROR STATE
			return DRIVER_ERROR;
		}
		break;
		
		// To write data
		case PORT_D:
		if(value == LOW) //if it was low
		{
			//PORTD &=~ (1<<pinNumber);
			clear_bit(PORTD, pinNumber); // write 0
			//ERROR STATE
			return DRIVER_OK;
		}
		else if(value == HIGH) //if it was high
		{
			//PORTD |= (1<<pinNumber);
			set_bit(PORTD, pinNumber);// write 1
			//ERROR STATE
			return DRIVER_OK;
		}
		else
		{
			//ERROR STATE
			return DRIVER_ERROR;
		}
		break;
		
	}
}

DRIVER_ERROR_T DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch(portNumber)
	{
		case PORT_A:
			// to toggle PortA pinNumber
			toggle_bit(PORTA, pinNumber);
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_B:
			// to toggle PortB pinNumber
			toggle_bit(PORTB, pinNumber);
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_C:
			// to toggle PortC pinNumber
			toggle_bit(PORTC, pinNumber);
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_D:
			// to toggle PortD pinNumber
			toggle_bit(PORTD, pinNumber);
			//ERROR STATE
			return DRIVER_OK;
		break;
		default:
		//ERROR STATE
		return DRIVER_ERROR;
		break;
		
	}
}

DRIVER_ERROR_T DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		// to read the state of a specific pin on PortA
			//*value= (PINA & (1<<pinNumber))>>pinNumber; 
			*value= read_bit(PINA, pinNumber); // get state -> read bit
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_B:
		// to read the state of a specific pin on PortB
			//*value=(PINB & (1<<pinNumber))>>pinNumber;
			*value= read_bit(PINB, pinNumber); // get state -> read bit
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_C:
		// to read the state of a specific pin on PortC
			//*value=(PINC & (1<<pinNumber))>>pinNumber;
			*value= read_bit(PINC, pinNumber); // get state -> read bit
			//ERROR STATE
			return DRIVER_OK;
		break;
		case PORT_D:
		// to read the state of a specific pin on PortD
			//*value=(PIND & (1<<pinNumber))>>pinNumber;
			*value= read_bit(PIND, pinNumber); // get state -> read bit
			//ERROR STATE
			return DRIVER_OK;
			break;
		default:
			//ERROR STATE
			return DRIVER_ERROR;
		break;
		
	}
}
