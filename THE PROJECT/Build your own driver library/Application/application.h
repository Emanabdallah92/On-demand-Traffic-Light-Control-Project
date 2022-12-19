/*
 * application.h
 *
 * Created: 12/3/2022 12:51:37 AM
 *  Author: emana
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

// Include files.h (for lower drivers)
#include "../ECUAL/LED_Driver/led.h"
#include "../ECUAL/Button_Driver/button.h"



// APPLICATION ENUM - for error state
typedef enum{APP_OK, APP_ERROR} APP_ERROR_T;

// FUNCTIONS PROTOTYPE
APP_ERROR_T APP_init(void);
APP_ERROR_T APP_start(void);


#endif /* APPLICATION_H_ */