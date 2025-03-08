################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/SEGGER/Rec/segger_uart.c 

OBJS += \
./thirdparty/SEGGER/Rec/segger_uart.o 

C_DEPS += \
./thirdparty/SEGGER/Rec/segger_uart.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/SEGGER/Rec/%.o thirdparty/SEGGER/Rec/%.su thirdparty/SEGGER/Rec/%.cyclo: ../thirdparty/SEGGER/Rec/%.c thirdparty/SEGGER/Rec/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DSTM32F401RETx -c -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/FreeRTOS" -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/SEGGER/OS" -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/SEGGER/SEGGER" -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/FreeRTOS/include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/002LEDproject/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-thirdparty-2f-SEGGER-2f-Rec

clean-thirdparty-2f-SEGGER-2f-Rec:
	-$(RM) ./thirdparty/SEGGER/Rec/segger_uart.cyclo ./thirdparty/SEGGER/Rec/segger_uart.d ./thirdparty/SEGGER/Rec/segger_uart.o ./thirdparty/SEGGER/Rec/segger_uart.su

.PHONY: clean-thirdparty-2f-SEGGER-2f-Rec

