/*
 ============================================================================
 Name        : lifo.c
 Author      : Mahmoud Eldwakhly
 Version     : first_data_structures_project (LIFO)
 ============================================================================
 */

#include "lifo.h"

// Function to add an item to the LIFO buffer
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buffer, unsigned int item) {
	// Check if LIFO buffer is valid
	if (!lifo_buffer->base || !lifo_buffer->head)
		return LIFO_Null;

	// Check if LIFO buffer is full
	if (lifo_buffer->count == lifo_buffer->length)
		return LIFO_full;

	// Add the item to the LIFO buffer
	*(lifo_buffer->head) = item;
	lifo_buffer->head++;
	lifo_buffer->count++;
	return LIFO_no_error;
}

// Function to retrieve an item from the LIFO buffer
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buffer, unsigned int* item) {
	// Check if LIFO buffer is valid
	if (!lifo_buffer->base || !lifo_buffer->head)
		return LIFO_Null;

	// Check if LIFO buffer is empty
	if (lifo_buffer->count == 0)
		return LIFO_empty;

	// Retrieve the item from the LIFO buffer
	lifo_buffer->head--;
	*item = *(lifo_buffer->head);
	lifo_buffer->count--;
	return LIFO_no_error;
}

// Function to initialize the LIFO buffer
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buffer, unsigned int* buffer, unsigned int length) {
	// Check if the provided buffer is valid
	if (buffer == NULL)
		return LIFO_Null;

	// Initialize LIFO buffer attributes
	lifo_buffer->base = buffer;
	lifo_buffer->head = buffer;
	lifo_buffer->length = length;
	lifo_buffer->count = 0;
	return LIFO_no_error;
}
