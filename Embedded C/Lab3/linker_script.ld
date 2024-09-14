/* Linker script for Cortex-M4
   Eng. Mahmoud Eldwakhly  
*/

MEMORY
{
    flash (RX) : ORIGIN = 0x00000000, LENGTH = 512M
    sram  (RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS 
{
    /* Code and Read-Only Data */
    .text : {
        *(.vectors)         /* Vector table */
        *(.text*)           /* Code */
        *(.rodata*)         /* Read-only data */
        _E_text = .;        /* End of the .text section */
    } > flash

    /* Initialized Data */
    .data : {
        _S_DATA = .;        /* Start of .data section */
        *(.data)            /* Initialized data */
        . = ALIGN(4);       /* Align to 4 bytes */
        _E_DATA = .;        /* End of the .data section */
    } > sram AT > flash

    /* Uninitialized Data */
    .bss : {
        _S_bss = . ;        /* Start of .bss section */
        *(.bss)             /* Uninitialized data */
        _E_bss = . ; 
  
    } > sram
}
