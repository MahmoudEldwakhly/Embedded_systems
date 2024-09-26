################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.c 

OBJS += \
./stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.o: ../stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/Embeded Systems Diploma ( KS )/Projects/Drivers/stm32_f103c6_drivers/KEYPAD_DRIVER" -I"D:/Embedded/Embeded Systems Diploma ( KS )/Projects/Drivers/stm32_f103c6_drivers/LCD_DRIVER" -I"D:/Embedded/Embeded Systems Diploma ( KS )/Projects/Drivers/stm32_f103c6_drivers/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

