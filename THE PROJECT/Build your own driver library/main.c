/*
 * Build your own driver library.c
 *
 * Created: 12/2/2022 4:00:42 AM
 * Author : emana
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
/*#include "DIO Driver/dio.h"*/
#include "Application/application.h"

int main(void)
{
	APP_init();	

    while (1) 
    {
		APP_start();
    }
}


