#include "uart.h"

unsigned char string_buffer[100] = "Mahmoud Eldwakhly" ;

void main (void)
{
    
uart_send_string (string_buffer) ;    // &string_buffer[0] 

}