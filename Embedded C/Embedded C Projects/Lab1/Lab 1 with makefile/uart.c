#include "uart.h"

 // put the value in the Pointer to this address 

#define UART0DR   *((volatile unsigned int* const)(unsigned int*)(0x101f1000))   

// Function to send a string via UART
void uart_send_string(unsigned char* p_tx_string) 
{
    // Loop through each character in the string until the null terminator is reached
    while (*p_tx_string != '\0') 
    {
        // Write the current character to the UART data register
        UART0DR = (unsigned int)(*p_tx_string);

        // Move to the next character in the string
        p_tx_string++; 
    }
}
