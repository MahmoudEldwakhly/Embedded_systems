/*
 * main.c
 *
 *  Created on: Aug 30, 2024
 *      Author: mahmoud eldawakhly
 */

#include "fifo.h"

int main() // Changed to `int` return type
{
    FIFO_Buffer_t FIFO_UART;
    element_type i, temp;

    if (FIFO_init(&FIFO_UART, uart_buffer, 5) == FIFO_no_error)
        printf("FIFO init -------- Done\n");

    for (i = 0; i < 7; i++)
    {
        printf("FIFO Enqueue (%x)\n", i);
        if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
            printf("\tFIFO enqueue -------- Done\n");
        else
            printf("\tFIFO enqueue -------- failed\n");
    }

    FIFO_print(&FIFO_UART);

    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
        printf("\tFIFO dequeue %x -------- Done\n", temp);

    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
        printf("\tFIFO dequeue %x -------- Done\n", temp);

    FIFO_print(&FIFO_UART);

    return 0;
}
