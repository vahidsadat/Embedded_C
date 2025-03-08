################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o: ../thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

