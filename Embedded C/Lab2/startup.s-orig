/*startup_cortexM3.s 
Eng.Mahmoud Eldwakhly 
*/ 

/* SRAM 0x20000000 */ 
/* 32 bit , each word 4 bytes   */ 

.section .vectors   // Create a section named `.vectors` for the vector table

.word 0x20001000  // Initial stack pointer value (SP). The processor loads this value into the SP register on reset.
                  // In this case, it points to address 0x20001000, which is 4 KB into the SRAM (assuming 4 KB is the size of the stack).

.word _reset       // Reset vector: address of the reset handler (which is the entry point after reset)

.word Vector_handler  // NMI handler vector: points to the address of `Vector_handler`, 
                      // which is used here as a placeholder for the NMI handler.

.word Vector_handler  // Hard Fault handler vector: points to the address of `Vector_handler`,
                      // which is used here as a placeholder for the Hard Fault handler.

.section .text 
_reset: 
    bl main       // Branch and link to `main`. This will call the `main` function in your C code.
    b .           // Infinite loop to prevent the code from continuing after `main` returns.

.thumb_func  // Directive to indicate that the following function uses Thumb instruction set
Vector_handler: 
    b _reset      // Branch to the reset handler. This will effectively reset the processor.
