/**
 * \file
 *
 * \brief Empty user application template
 *
 */

// By Mahmoud Eldwakhly
// Lab2_GPIO 
#include <MemoryMap.h>
#include <util/delay.h>
#include <utilis.h>

#define F_CPU 8000000UL  // Define CPU frequency before including util/delay.h

// For 7 segment numbers display
static unsigned char SegmentNumber[] = {0x3f,0x06 ,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ; 

int main (void)
{
    // Set DDRA pins 0, 2, and 4 as output (0x15 = 0b00010101)
    DDRA = 0X15;    // 0b00010101
    
    // Set pin 0 of DDRC as input
    ClearBit(DDRC, 0);
    
    // Enable internal pull-up resistor on pin 0 of PORTC
    SetBit(PORTC, 0);
	unsigned char flag = 0 ; 
    while(1)
    {
		for (flag = 0 ; flag<= 10 ; flag ++)
		{
			PORTA = SegmentNumber[flag] ; 
			_delay_ms(500) ; 
			
		}
    }

}
