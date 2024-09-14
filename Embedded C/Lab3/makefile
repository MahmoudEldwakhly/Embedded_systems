# Define variables for the toolchain and flags
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2 -g 
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
project_name=mahmoud_cortex_m4_lab3

# Default target
all: $(project_name).bin
	@echo "Build is done"

# Rule to build .o files from .c files
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

# Rule to link object files into an ELF file
$(project_name).elf: $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@
	
	cp $(project_name).elf $(project_name).axf

# Rule to convert ELF file to binary
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

# Rule to clean all generated files
clean_all:
	rm -f *.o *.elf *.bin

# Rule to clean only ELF and binary files
clean:
	rm -f *.elf *.bin
