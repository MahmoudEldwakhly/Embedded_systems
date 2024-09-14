/*
 ============================================================================
 Name        : lifo.h
 Author      : Mahmoud Eldwakhly
 Version     : first_data_structures_project (LIFO)
 ============================================================================
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

// Typedef for LIFO buffer structure
typedef struct {
	unsigned int length;  // Maximum number of elements in the buffer
	unsigned int count;   // Current number of elements in the buffer
	unsigned int* base;   // Pointer to the base of the buffer
	unsigned int* head;   // Pointer to the top of the buffer (next position to add)
} LIFO_Buf_t;

// Enumeration for LIFO status codes
typedef enum {
	LIFO_no_error, // No error
	LIFO_full,     // Buffer is full
	LIFO_empty,    // Buffer is empty
	LIFO_Null      // Buffer is null (invalid)
} LIFO_status;

// Function prototypes (APIs)
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buffer, unsigned int item);
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buffer, unsigned int* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buffer, unsigned int* buffer, unsigned int length);

#endif /* LIFO_H_ */
