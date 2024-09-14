ENTRY(reset)

MEMORY 
{
    mem (rwx) : ORIGIN = 0x00000000, LENGTH = 64M 
}

SECTIONS 
{
    /* Set the location counter to 0x10000 for the .startup section */
    . = 0x10000;

    .startup . : 
    {
        startup.o(.text)
    } > mem

    /* The .text section will follow immediately after .startup */
    .text : 
    {
        *(.text)
        *(.rodata)
    } > mem

    .data : 
    {
        *(.data)
    } > mem

    .bss : 
    {
        *(.bss)
    } > mem

    /* Optionally, you can adjust the location counter if needed */
    . = . + 0x10000;

    /* Define the stack top, marking the end of the memory used */
    stack_top = .;
}
