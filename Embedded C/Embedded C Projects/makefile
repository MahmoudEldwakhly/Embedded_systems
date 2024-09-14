#@Copyright: Mahmoud Eldwakhly


# Define variables for the toolchain and flags
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=mahmoud

# Default target
all: $(project_name).bin
	@echo "Build is done"

# Rule to build .o files from .s files
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

# Rule to build .o files from .c files
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

# Rule to link object files into an ELF file
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@

# Rule to convert ELF file to binary
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

# Rule to clean all generated files
clean_all:
	rm -f *.o *.elf *.bin

# Rule to clean only ELF and binary files
clean:
	rm -f *.elf *.bin
