/*
 ============================================================================
 Name        : main.c
 Author      : Mahmoud Eldwakhly
 Version     : first_data_structures_project (LIFO)
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "lifo.h"

// Define a buffer with 5 elements, each 4 bytes (unsigned int).
unsigned int buffer1[5]; // 5 * 4 = 20 Bytes in Data memory

void main()
{
	int i, temp = 0;
	LIFO_Buf_t uart_lifo, I2C_lifo;

	// Static allocation of LIFO buffer
	LIFO_init(&uart_lifo, buffer1, 5);

	// Dynamic allocation of LIFO buffer
	unsigned int* buffer2 = (unsigned int*) malloc(5 * sizeof(unsigned int)); // 5 * 4 = 20 Bytes in Heap memory

	// Ensure malloc was successful before using buffer2
	if (buffer2 == NULL) {
		printf("Memory allocation failed\n");
		return;
	}

	LIFO_init(&I2C_lifo, buffer2, 5);

	// Adding items to UART LIFO buffer
	for (i = 0; i < 5; i++) {
		if (LIFO_Add_item(&uart_lifo, i) == LIFO_no_error)
			printf("UART_LIFO add: %d\n", i);
	}

	// Retrieving items from UART LIFO buffer
	for (i = 0; i < 5; i++) {
		if (LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
			printf("UART_LIFO get: %d\n", temp);
	}

	// Free dynamically allocated memory
	free(buffer2);
}
