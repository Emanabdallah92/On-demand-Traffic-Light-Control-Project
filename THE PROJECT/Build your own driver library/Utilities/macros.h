/*
 * macros.h
 *
 * Created: 12/3/2022 2:24:42 PM
 *  Author: emana
 */ 


#ifndef MACROS_H_
#define MACROS_H_
#include <stdint.h>

// Macro Functions
#define set_bit(byte, bit) ((byte) |= (1<<(bit)))
#define clear_bit(byte, bit) ((byte) &=~ (1<< (bit)))
#define read_bit(byte, bit) ((byte) >> (bit) & 1)
#define toggle_bit(byte, bit) ((byte) ^= (1<<(bit)))


#endif /* MACROS_H_ */