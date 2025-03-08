################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/SEGGER/SEGGER/SEGGER_RTT.c \
../thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
../thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../thirdparty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./thirdparty/SEGGER/SEGGER/SEGGER_RTT.o \
./thirdparty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./thirdparty/SEGGER/SEGGER/SEGGER_RTT.d \
./thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/SEGGER/SEGGER/SEGGER_RTT.o: ../thirdparty/SEGGER/SEGGER/SEGGER_RTT.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/SEGGER/SEGGER/SEGGER_RTT.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/SEGGER/SEGGER/%.o: ../thirdparty/SEGGER/SEGGER/%.S
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.o: ../thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/SEGGER/SEGGER/SEGGER_RTT_printf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: ../thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/SEGGER/SEGGER/SEGGER_SYSVIEW.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

