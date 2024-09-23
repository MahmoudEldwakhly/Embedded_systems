# AVR Interrupt Lab

## Project Overview

In this lab, I explored how to implement and handle interrupts on the AVR microcontroller. The project was built using **Atmel Studio** and simulated on **Proteus** to observe the behavior of the external interrupts in a controlled environment. The main goal was to configure and respond to three external interrupts (INT0, INT1, and INT2) which trigger the toggling of specific LEDs connected to port D.

The interrupts are configured with different edge triggers, and the LEDs are toggled using the corresponding interrupt service routines (ISRs). This allowed me to fully understand how external interrupts can be managed on an AVR system.

### What I Learned

1. **Setting up and using external interrupts:**
   - **INT0** is configured to be triggered by a logical change.
   - **INT1** is configured to be triggered by a rising edge.
   - **INT2** is configured to be triggered by a falling edge.
   - I used the `MCUCR` and `GICR` registers to set up these different edge triggers and enable the interrupts.

2. **ISR (Interrupt Service Routine):**
   - For each interrupt (INT0, INT1, and INT2), a corresponding ISR is defined using the `ISR()` macro.
   - Inside each ISR, the respective LED is turned on for 1 second using a delay (`_delay_ms(1000)`).

3. **Bit manipulation with macros:**
   - I used custom macros like `SET_BIT()`, `RESET_BIT()`, `TOGGLE_BIT()`, and `READ_BIT()` to manipulate specific bits in the registers. This simplified register-level coding and enhanced code readability.

4. **Global Interrupts:**
   - I used the `sei()` function to enable global interrupts, which allowed the microcontroller to respond to interrupt requests.

5. **Simulating the design in Proteus:**
   - The simulation in Proteus helped visualize how the microcontroller responds to external interrupts and how the LEDs toggle in response to the corresponding triggers.
   - This simulation allowed me to see the behavior of the external interrupts in action and ensured that the project worked as intended before testing it on real hardware.

### Registers Used

- **MCUCR**: To configure the interrupt sense control for INT0 and INT1.
- **GICR**: To enable INT0, INT1, and INT2.
- **MCUCSR**: To configure the interrupt sense control for INT2.
- **DDRD**: To configure pins 5, 6, and 7 of port D as output pins.
- **PORTD**: To toggle the LEDs connected to port D.

### Simulation Details

By using **Proteus**, I could simulate every detail, ensuring that the interrupts triggered as expected. The LEDs on pins 5, 6, and 7 of port D light up when the corresponding external interrupt is triggered. 

This lab gave me deeper insight into:
- How external interrupts work at the bit level.
- How to simulate real-world microcontroller behavior using Proteus.
- The importance of carefully managing interrupt sources to ensure the system responds correctly.

### Conclusion

This project provided hands-on experience in handling AVR microcontroller interrupts, configuring interrupt triggers, and simulating the entire process in Proteus to verify its functionality. The knowledge gained here will be essential in future interrupt-driven systems that I design.
