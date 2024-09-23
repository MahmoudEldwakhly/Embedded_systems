
# Lab 1 - STM32 Interrupts and GPIO Control

In this lab, I worked on understanding and implementing interrupts on an STM32 microcontroller. Specifically, I programmed an external interrupt to toggle an LED connected to Pin 13 of GPIOA when a button connected to Pin 0 was pressed. The code involved configuring the RCC, GPIO, and EXTI registers to manage the clock, GPIO pin modes, and external interrupt behavior.

## What I Learned
### 1. Interrupt Handling
- I learned how to configure an interrupt on a specific pin (in this case, PA0) and trigger an action (toggling an LED) when the button is pressed.
- I explored how to enable and configure EXTI (External Interrupt) lines, including setting up the interrupt mask register (IMR), rising trigger selection register (RTSR), and clearing pending interrupts.

### 2. GPIO Configuration
- I practiced configuring GPIO pin 13 as an output pin and GPIO pin 0 as an input pin.
- I learned how to set and reset bits in GPIO configuration registers (GPIO_CRH and GPIO_CRL) to control the behavior of the pins.

### 3. RCC (Clock Control)
- I enabled the clock for GPIOA and the Alternate Function IO (AFIO) to ensure proper peripheral communication.

## Microvision Simulator
To observe and verify the functionality of the project, I used the Microvision simulator. The simulator allowed me to:
- Visualize my work at the bit level and see exactly what was happening in each register as I debugged the code.
- Monitor changes in registers and values when interrupts were triggered and the LED was toggled.
- Set breakpoints in the code to pause execution and examine the state of the microcontroller at different stages.
- This debugging and monitoring process helped me understand the importance of correct register configuration and how external interrupts work in real-time.

### Debugging and Breakpoints
During the simulation, I was able to place breakpoints to halt the execution at specific lines of code. This allowed me to inspect:
- The state of the EXTI_PR register when an interrupt occurred.
- The state of the GPIO_ODR register when toggling the LED.
- The overall program flow to ensure everything was functioning as expected.

## Conclusion
By completing this lab, I gained hands-on experience with configuring and handling interrupts in STM32, setting GPIO modes, and using the Microvision simulator for detailed debugging. This deepened my understanding of microcontroller operations, especially at the register level, and how to troubleshoot code by visualizing real-time changes.
