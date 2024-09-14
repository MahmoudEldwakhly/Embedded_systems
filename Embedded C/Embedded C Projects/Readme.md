# Embedded C Projects and Labs Experience

## Overview

This repository showcases my journey in Embedded C programming, specifically targeting ARM Cortex-M microcontrollers. Through various lab projects and practical tasks, I have gained extensive hands-on experience in developing, debugging, and optimizing embedded applications.

## Key Learnings

### 1. Setting Up and Using Toolchains
- **Toolchain Setup**: I have installed and configured toolchains for ARM Cortex-M microcontrollers, particularly using the arm-none-eabi tools.
- **Makefile Usage**: I’ve worked with Makefile to automate the build process, including compiling C code, linking object files, and generating executable binaries.
- **Troubleshooting Compilation Errors**: I encountered and resolved various compilation and linking errors, deepening my understanding of how to properly link standard libraries and handle multiple definitions.

### 2. Embedded C Programming
- **Basic C Syntax and Structure**: I have practiced writing and compiling basic C programs targeted for embedded systems, reinforcing my understanding of C syntax, data types, and control structures.
- **Memory Management**: I’ve learned about dynamic memory allocation (`malloc`, `free`) and the importance of proper memory management in embedded systems to ensure efficient use of limited resources.
- **Working with Pointers**: I’ve used pointers for direct memory manipulation, which is crucial in embedded programming where working with hardware registers and memory-mapped I/O is common.

### 3. ARM Cortex-M Microcontroller Specifics
- **Startup Code and Linker Scripts**: I explored the role of startup code in initializing the microcontroller and setting up the vector table, as well as writing and using custom linker scripts to control how memory is allocated in embedded applications.
- **Interrupt Handling**: Through startup code, I learned how interrupt vectors are set up and how to define Interrupt Service Routines (ISRs) that respond to specific hardware events.

### 4. Debugging and Optimization
- **Debugging Techniques**: I’ve practiced debugging techniques using various tools and methods, such as analyzing map files to understand how memory is being used and using `objdump` and `objcopy` to examine and manipulate binaries.
- **Optimization Considerations**: I’ve started considering optimization strategies, such as minimizing memory usage and reducing code size, which are critical in resource-constrained embedded systems.

### 5. Hands-on Practice with Embedded Systems
- **Project Development**: I’ve engaged in multiple projects where I applied what I’ve learned in a practical context. This included setting up development environments, writing Embedded C code, compiling, linking, and debugging applications.
- **Real-World Problem Solving**: I faced real-world issues, such as dealing with multiple definitions, circular dependencies, and understanding the intricacies of how embedded applications are built and executed on a microcontroller.

### 6. Learning from Errors
- **Error Resolution**: Each lab and task introduced new challenges, from compilation errors to linking issues. By solving these, I’ve built a strong foundation in problem-solving and debugging, which is crucial for any embedded systems developer.

## Detailed Lab Projects

### Lab 1: ARM VersatilePB
- **Booting Sequence & Modes**: Explored booting sequences, bootloaders, and different running modes.
- **Bare Metal Software Development**: Developed bare-metal software from scratch, including startup code and linker script commands.
- **Executable File Analysis**: Worked with `.obj` files, explored executable sections like `.data`, `.bss`, and `.rodata`.
- **Tool Proficiency**: Used `gdb` for debugging and mastered Makefile creation for efficient project management.

### Lab 2: ARM Cortex-M3 STM32
- **Complex Startup and Linker**: Developed a complex C startup routine and linker script, enhancing my understanding of memory alignment and thumb instructions.
- **Executable Sections Analysis**: Analyzed relocatable object files and explored linker and locator functionality in embedded systems.
- **Advanced Embedded C**: Implemented functional attributes, including weak and alias, in Embedded C, and handled data copying for `.bss` sections.

### Lab 3: TM4C123 ARM Cortex-M4
- **Comprehensive Debugging**: Gained proficiency in debugging using Keil-µVision, OpenOCD gdbserver, and Eclipse IDE.
- **Mapfile Review**: Analyzed and reviewed map files to understand memory allocation and optimize code.
- **Embedded Application Development**: Successfully developed and debugged embedded applications on the TM4C123 microcontroller.

## Summary

The labs and projects I’ve completed have significantly contributed to my understanding of Embedded C programming and ARM Cortex-M microcontrollers. From developing complex startup routines to optimizing embedded applications, I’ve built a solid foundation in both the software and hardware aspects of embedded systems. My hands-on experience with debugging, optimization, and real-world problem-solving has equipped me with the skills necessary to excel in the field of embedded systems engineering.
