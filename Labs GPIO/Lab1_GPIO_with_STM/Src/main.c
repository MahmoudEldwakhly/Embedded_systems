
// @copyright :  Mahmoud Eldwakhly

// Lab 1 GPIO by STM

#include <stdint.h>  // Include standard integer types
#include <stdlib.h>  // For memory allocations functions
#include <stdio.h>


// Define base addresses for RCC and GPIO peripherals
//RCC
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18) // RCC APB2 peripheral clock enable register
#define RCC_IOPAEN (1 << 2)    // Bit mask for enabling GPIOA clock
#define RCC_IOPBEN (1 << 3)    // Bit mask for enabling GPIOB clock
#define RCC_AFIOEN (1 << 0)    // Bit mask for enabling Alternate function I/O clock
// GPIO
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)   // GPIO port configuration register high
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)   // GPIO port output data register
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_IDR *(volatile uint32_t *)(GPIOA_BASE + 0x08)

#define GPIOA13 (1UL << 13)    // Bit mask for GPIO pin 13

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + 0x04)   // GPIO port configuration register high
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_BASE + 0x0C)   // GPIO port output data register
#define GPIOB_IDR *(volatile uint32_t *)(GPIOB_BASE + 0x08)	// GPIO port Input data register
#define GPIOB_CRL *(volatile uint32_t *)(GPIOB_BASE + 0x00)

void clock_init()
{
	// Enable the clock for GPIOA by setting the IOPAEN bit in RCC_APB2ENR
	RCC_APB2ENR |= RCC_IOPAEN;
	// Enable the clock for GPIOB by setting the IOPBEN bit in RCC_APB2ENR
	RCC_APB2ENR |= RCC_IOPBEN;
}

void GPIO_init()
{
	GPIOA_CRL = 0x0 ;
	GPIOB_CRL = 0x0 ;
	// PA 1 input High Impedence (Z)
	GPIOA_CRL |= 1<<6 ;

	GPIOB_CRL &= ~(0b11<<6) ;
	// PB 1 output push pull mode , 01: Output mode, max speed 10 MHz
	GPIOB_CRL |= (0b01 << 4) ;
	// PA 13 input High Impedence (Z)
	GPIOA_CRH &= ~(0b11<<20) ;
	GPIOA_CRH |= ~(0b01<<22) ;
	// PB 13 output push pull mode
	GPIOB_CRH |= ~(0b01<<20) ;
	GPIOB_CRH |= (0b11 << 22) ;

}

void my_wait (int x)
{
	unsigned int i , j ;
	for (i=0 ; i<x ; i++)
		for(j=0 ; j<255 ; j++) ;

}
int main(void)
{
	clock_init() ;
	GPIO_init() ;


	while(1)
	{
	// PA1  >>>  connected with external pull up resistance
		if(((GPIOA_IDR & (1<<1)) >> 1 ) == 0 ) // Press
		{
			GPIOB_ODR ^= 1 << 1 ;
			while (((GPIOA_IDR & (1<<1)) >> 1 ) == 0 ) ; // Single press
		}
		// PA13  >>>  connected with external pull down resistance
		if(((GPIOA_IDR & (1<<1)) >> 13 ) == 1 ) // Multi Pressing
				{
					GPIOB_ODR ^= 1 << 13 ;

				}
		my_wait(1) ;
	}


}


