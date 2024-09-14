/*
 * fifo.h
 *
 *  Created on: Aug 30, 2024
 *      Author: mahmoud eldawakhly
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//User configuration
//Select the element type ( uint8_t , uint26_t , uint32_t , ...... )

#define element_type uint8_t
//Creat buffer
#define width1 5
element_type uart_buffer[width1] ;  // Global variable in data memory

// FIFO data types

typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_type* base ;
	element_type* tail ;
	element_type* head ;

}FIFO_Buffer_t;

typedef enum {
	FIFO_no_error ,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buffer_status;

//FIFO APIs

FIFO_Buffer_status FIFO_init (FIFO_Buffer_t* fifo ,element_type*  buffer , uint32_t length);
FIFO_Buffer_status FIFO_enqueue (FIFO_Buffer_t* fifo ,element_type item);
FIFO_Buffer_status FIFO_dequeue (FIFO_Buffer_t* fifo ,element_type item);
FIFO_Buffer_status FIFO_IS_FULL (FIFO_Buffer_t* fifo);
void FIFO_print (FIFO_Buffer_t* fifo);




#endif /* FIFO_H_ */
