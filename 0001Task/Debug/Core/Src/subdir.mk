################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_hal_msp.o: ../Core/Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_hal_timebase_tim.o: ../Core/Src/stm32f4xx_hal_timebase_tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_hal_timebase_tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f4xx_it.o: ../Core/Src/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32f4xx.o: ../Core/Src/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

