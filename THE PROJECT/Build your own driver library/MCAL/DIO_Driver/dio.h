/*
 * dio.h
 *
 * Created: 12/2/2022 4:40:29 AM
 *  Author: emana
 */ 


#ifndef DIO_H_
#define DIO_H_
//include registers.h
#include "../../Utilities/registers.h"

//all internal driver typedefs
//all driver macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//DIRECTION DEFINES
#define IN 0
#define OUT 1

//VALUE DEFINES
#define LOW 0
#define HIGH 1

//DRIVERS ENUM - FOR THE ERROR STATE
typedef enum {DRIVER_OK, DRIVER_ERROR}DRIVER_ERROR_T;

//all driver function prototypes

DRIVER_ERROR_T DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // initialize DIO direction

DRIVER_ERROR_T DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // write data to DIO

DRIVER_ERROR_T DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle DIO

DRIVER_ERROR_T DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // read DIO

#endif /* DIO_H_ */