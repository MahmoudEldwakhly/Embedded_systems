/*
 * fifo.c
 *
 *  Created on: Aug 30, 2024
 *      Author: mahmoud eldawakhly
 */

#include "fifo.h"

// FIFO APIs
FIFO_Buffer_status FIFO_init(FIFO_Buffer_t* fifo, element_type* buffer, uint32_t length)
{
    if (buffer == NULL)
        return FIFO_null;

    fifo->base = buffer;
    fifo->head = buffer;
    fifo->tail = buffer;
    fifo->length = length;
    fifo->count = 0;

    return FIFO_no_error;
}

FIFO_Buffer_status FIFO_enqueue(FIFO_Buffer_t* fifo, element_type item)
{
    if (!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;

    // Check if FIFO is full
    if (FIFO_IS_FULL(fifo) == FIFO_full)
        return FIFO_full;

    // Enqueue the item
    *(fifo->head) = item;
    fifo->count++;

    // Move head pointer, wrap around if necessary
    if (fifo->head == (fifo->base + (fifo->length - 1)))
        fifo->head = fifo->base;
    else
        fifo->head++;

    return FIFO_no_error;
}

FIFO_Buffer_status FIFO_dequeue(FIFO_Buffer_t* fifo, element_type* item)
{
    if (!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;

    // Check if FIFO is empty
    if (fifo->count == 0)
        return FIFO_empty;

    // Dequeue the item
    *item = *(fifo->tail);
    fifo->count--;

    // Move tail pointer, wrap around if necessary
    if (fifo->tail == (fifo->base + (fifo->length - 1)))
        fifo->tail = fifo->base;
    else
        fifo->tail++;

    return FIFO_no_error;
}

FIFO_Buffer_status FIFO_IS_FULL(FIFO_Buffer_t* fifo)
{
    if (!fifo->base || !fifo->head || !fifo->tail)
        return FIFO_null;

    if (fifo->count == fifo->length)
        return FIFO_full;

    return FIFO_no_error;
}

void FIFO_print(FIFO_Buffer_t* fifo)
{
    element_type* temp;
    int i;

    if (fifo->count == 0)
    {
        printf("FIFO is empty\n");
    }
    else
    {
        temp = fifo->tail;
        printf("\n=============== FIFO Print ===============\n");
        for (i = 0; i < fifo->count; i++)
        {
            printf("\t%x\n", *temp);

            // Move temp pointer, wrap around if necessary
            if (temp == (fifo->base + (fifo->length - 1)))
                temp = fifo->base;
            else
                temp++;
        }
        printf("\n==========================================\n");
    }
}
