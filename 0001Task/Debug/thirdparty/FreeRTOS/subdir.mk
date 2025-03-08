################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thirdparty/FreeRTOS/croutine.c \
../thirdparty/FreeRTOS/event_groups.c \
../thirdparty/FreeRTOS/list.c \
../thirdparty/FreeRTOS/queue.c \
../thirdparty/FreeRTOS/stream_buffer.c \
../thirdparty/FreeRTOS/tasks.c \
../thirdparty/FreeRTOS/timers.c 

OBJS += \
./thirdparty/FreeRTOS/croutine.o \
./thirdparty/FreeRTOS/event_groups.o \
./thirdparty/FreeRTOS/list.o \
./thirdparty/FreeRTOS/queue.o \
./thirdparty/FreeRTOS/stream_buffer.o \
./thirdparty/FreeRTOS/tasks.o \
./thirdparty/FreeRTOS/timers.o 

C_DEPS += \
./thirdparty/FreeRTOS/croutine.d \
./thirdparty/FreeRTOS/event_groups.d \
./thirdparty/FreeRTOS/list.d \
./thirdparty/FreeRTOS/queue.d \
./thirdparty/FreeRTOS/stream_buffer.d \
./thirdparty/FreeRTOS/tasks.d \
./thirdparty/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
thirdparty/FreeRTOS/croutine.o: ../thirdparty/FreeRTOS/croutine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/croutine.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/event_groups.o: ../thirdparty/FreeRTOS/event_groups.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/event_groups.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/list.o: ../thirdparty/FreeRTOS/list.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/list.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/queue.o: ../thirdparty/FreeRTOS/queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/queue.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/stream_buffer.o: ../thirdparty/FreeRTOS/stream_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/stream_buffer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/tasks.o: ../thirdparty/FreeRTOS/tasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/tasks.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
thirdparty/FreeRTOS/timers.o: ../thirdparty/FreeRTOS/timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401RETx -DSTM32F401xE -DDEBUG -c -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/Config" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/include" -I"C:/Users/vahid/Desktop/STM32F401/chip_headers/CMSIS/Include" -I../Drivers/CMSIS/Include -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/OS" -I../Core/Inc -I"C:/Users/vahid/Desktop/STM32F401/0001Task/thirdparty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"thirdparty/FreeRTOS/timers.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

