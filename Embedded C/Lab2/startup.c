#include <stdint.h>
extern int main(void);

// Forward declaration of the default handler
void Default_Handler(void);

// Forward declaration of the exception handlers
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

extern unsigned int _stack_top;

// Vector table
uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &_stack_top,            // Initial stack pointer
    (uint32_t) &Reset_Handler,        // Reset handler
    (uint32_t) &NMI_Handler,          // NMI handler
    (uint32_t) &H_fault_Handler,      // Hard fault handler
    (uint32_t) &MM_Fault_Handler,     // Memory management fault handler
    (uint32_t) &Bus_Fault,            // Bus fault handler
    (uint32_t) &Usage_Fault_Handler   // Usage fault handler
};

// Default handler implementation (used for unhandled exceptions)
void Default_Handler(void)
{
    while(1);  // Infinite loop to halt the system
}

/* Symbols not variables (Address) */
extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

// Reset handler implementation
void Reset_Handler(void)
{
    // Copy data section from flash to RAM
    unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
    unsigned char* p_src = (unsigned char*)&_E_text;
    unsigned char* p_dst = (unsigned char*)&_S_DATA;
    int i;  // Declare loop variable here

    for (i = 0; i < DATA_size; i++)
    {
        *((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
    }

    // Initialize .bss section in SRAM to 0
    unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
    p_dst = (unsigned char*)&_S_bss;

    for (i = 0; i < bss_size; i++)
    {
        *((unsigned char*)p_dst++) = (unsigned char)0;
    }

    // Jump to main
    main();
}
