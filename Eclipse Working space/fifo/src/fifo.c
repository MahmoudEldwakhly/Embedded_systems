/*
 * fifo.c
 *
 *  Created on: Aug 30, 2024
 *      Author: mahmoud eldawakhly
 */


#include "fifo.h"


//FIFO APIs
FIFO_Buffer_status FIFO_init (FIFO_Buffer_t* fifo,element_type* buffer , uint32_t length)
{
	if(buffer == NULL)
		return FIFO_null ;
	fifo->base = buffer ;
	fifo->head = buffer ;
	fifo->tail = buffer ;
	fifo->length = length ;
	fifo->count = 0 ;
	return FIFO_no_error ;
}
FIFO_Buffer_status FIFO_enqueue (FIFO_Buffer_t* fifo ,element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null ;
	// fifo is full ?

	if(FIFO_IS_FULL (fifo)== FIFO_full)
		return FIFO_full ;
	*(fifo->head) = item ;
	fifo->count ++ ;
	// circular fifo
	if ((fifo->head) == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base ;
	else
		fifo->base ++ ;

return FIFO_no_error ;

}
FIFO_Buffer_status FIFO_dequeue (FIFO_Buffer_t* fifo ,element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null ;
	//check fifo is empty or not ?
	if(fifo->count == 0)
		return FIFO_empty ;
	*item = fifo->tail ;
	fifo->count -- ;
	// circular fifo
	if ((fifo->tail) == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail ++ ;
	return FIFO_no_error ;


}
FIFO_Buffer_status FIFO_IS_FULL (FIFO_Buffer_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null ;
	if(fifo->count == fifo->length)
		return FIFO_null ;

	return FIFO_no_error ;


}
void FIFO_print (FIFO_Buffer_t* fifo)
{
	element_type* temp ;
	int i ;
	if(fifo->count == 0)
	{
		printf("fifo is empty \n") ;

	}
	else
	{
		temp = fifo->tail ;
		printf("\n  ================ fifo_print ================ \n") ;
		for(i=0 ; i < fifo->count ; i++ )
		{
			printf("\t %x \n " ,*temp) ;
			temp ++ ;

		}
		printf("\n  ================================ \n") ;

	}





}
