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
        // If button on PINC0 is pressed (low)
        if (ReadBit(PINC, 0) == 0)
        {
			while (ReadBit(PINC, 0) == 0)
			{
				ToggleBit(PORTA,0) ; 
				_delay_ms(250) ; 
			}
        }
    }

}
