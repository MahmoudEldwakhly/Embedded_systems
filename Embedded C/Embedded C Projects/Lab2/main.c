//@copyright :  Mahmoud Eldwakhly

// Toggle led  

#include "stdint.h"  // Include standard integer types

// Define volatile unsigned int type for hardware registers
typedef volatile unsigned int vuint32_t;

// Define base addresses for RCC and GPIO peripherals
#define RCC_BASE 0x40021000
#define GPIO_BASE 0x40010800

// Define offsets and addresses for specific registers
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18) // RCC APB2 peripheral clock enable register
#define GPIO_CRH *(volatile uint32_t *)(GPIO_BASE + 0x04)   // GPIO port configuration register high
#define GPIO_ODR *(volatile uint32_t *)(GPIO_BASE + 0x0C)   // GPIO port output data register

// Define bit masks for enabling GPIOA clock and controlling GPIO pin 13
#define RCC_IOPAEN (1 << 2)    // Bit mask for enabling GPIOA clock
#define GPIOA13 (1UL << 13)    // Bit mask for GPIO pin 13

// Define a union to access specific bits within the ODR register
typedef union {
    vuint32_t all_fields;  // Access all 32 bits of the register
    struct {
        vuint32_t reserved : 13; // Reserved bits (0-12)
        vuint32_t p_13 : 1;      // Pin 13 (bit 13)
    } pin;
} R_ODR_t;

// Define a pointer to the ODR register, casted to the union type
volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIO_BASE + 0x0C);

// Define some global variables for demonstration purposes
unsigned char g_variables[3] = {1, 2, 3};           // Global variable array
unsigned char const const_variables[3] = {1, 2, 3}; // Constant variable array
volatile int i;  // Volatile variable for the delay loop

int main(void) {
    // Enable the clock for GPIOA by setting the IOPAEN bit in RCC_APB2ENR
    RCC_APB2ENR |= RCC_IOPAEN;

    // Configure GPIO pin 13 as a general-purpose output
    // Clear the relevant bits in GPIO_CRH
    GPIO_CRH &= 0xFF0FFFFF;
    // Set the relevant bits in GPIO_CRH to configure pin 13 as output
    GPIO_CRH |= 0x00200000;

    // Main loop: toggle the LED connected to pin 13
    while (1) {
        R_ODR->pin.p_13 = 1; // Set pin 13 high (turn LED on)
        for (i = 0; i < 5000; i++); // Simple delay loop

        R_ODR->pin.p_13 = 0; // Set pin 13 low (turn LED off)
        for (i = 0; i < 5000; i++); // Simple delay loop
    }
}
