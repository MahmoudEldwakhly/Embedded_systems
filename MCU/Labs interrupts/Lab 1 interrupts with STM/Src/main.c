//@copyright :  Mahmoud Eldwakhly

// Lab 1 interrupt 

#include <stdint.h>  // Include standard integer types
#include <stdlib.h>  // For memory allocations functions
#include <stdio.h>


// Define base addresses for RCC and GPIO peripherals
//RCC
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18) // RCC APB2 peripheral clock enable register
#define RCC_IOPAEN (1 << 2)    // Bit mask for enabling GPIOA clock
#define RCC_AFIOEN (1 << 0)    // Bit mask for enabling Alternate function I/O clock
// GPIO
#define GPIO_BASE 0x40010800
#define GPIO_CRH *(volatile uint32_t *)(GPIO_BASE + 0x04)   // GPIO port configuration register high
#define GPIO_ODR *(volatile uint32_t *)(GPIO_BASE + 0x0C)   // GPIO port output data register
#define GPIO_CRH *(volatile uint32_t *)(GPIO_BASE + 0x04)
#define GPIO_CRL *(volatile uint32_t *)(GPIO_BASE + 0x00)
#define GPIOA13 (1UL << 13)    // Bit mask for GPIO pin 13

// External Interrupt
#define EXTI_BASE  0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_BASE + 0x00)  // Interrupt mask register
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08) // Rising trigger selection register
#define EXTI_PR *(volatile uint32_t *)(EXTI_BASE + 0x14)   /* Pending register , This bit is set when the selected edge event arrives on the external interrupt line. This bit is
cleared by writing a ‘1’ into the bit.*/

// Alternative function in out (AFIO) by External interrupt configuration register 1 (AFIO_EXTICR1)
#define AFIO_BASE  0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

// NVIC
#define NVIC_EXTIE0 *(volatile uint32_t *)(0xE000E100)

void clock_init()
{
	// Enable the clock for GPIOA by setting the IOPAEN bit in RCC_APB2ENR
	RCC_APB2ENR |= RCC_IOPAEN;
	// Bit 0 AFIOEN: Alternate function I/O clock enable
	RCC_APB2ENR |= RCC_AFIOEN ;

}

void GPIO_init()
{
	// Pin 13 port A Output pin
	// Clear the relevant bits in GPIO_CRH
	GPIO_CRH &= 0xFF0FFFFF;
	// Set the relevant bits in GPIO_CRH to configure pin 13 as output
	GPIO_CRH |= 0x00200000;
	// PinA0 : 01 (Floating input (reset state))
	GPIO_CRL |= (1<<2) ;

}

int main(void) 
{
	clock_init() ;
	GPIO_init() ;


	//  EXTI0 configuration for portA0
	AFIO_EXTICR1 = 0 ;
	// Enable EXTI Line 0 by making mask 1
	EXTI_IMR |= (1<<0) ;
	// Enable Rising trigger
	EXTI_RTSR |= (1<<0) ;
	// Enable NVIC Irq6 <<>> EXTI0
	NVIC_EXTIE0 |= (1<<6) ;



	while(1);


}

void EXTI0_IRQHandler(void)
{
	// IRQ is happened EXTI0  >>> PORTA pin 0 _| rising edge
	// Toggle led pin A 13
	GPIO_ODR ^= (1<<13) ;
	// Clear pending request for line zero using Pending register
	EXTI_PR |= (1<<0) ;


}


