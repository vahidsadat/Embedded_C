################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include thirdparty/SEGGER/SEGGER/Syscalls/subdir.mk
-include thirdparty/SEGGER/SEGGER/subdir.mk
-include thirdparty/SEGGER/Rec/subdir.mk
-include thirdparty/SEGGER/OS/subdir.mk
-include thirdparty/SEGGER/Config/subdir.mk
-include thirdparty/FreeRTOS/portable/MemMang/subdir.mk
-include thirdparty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include thirdparty/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
0001Task.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
0001Task.list \

OBJCOPY_BIN += \
0001Task.bin \


# All Target
all: 0001Task.elf secondary-outputs

# Tool invocations
0001Task.elf: $(OBJS) $(USER_OBJS) C:\Users\vahid\Desktop\STM32F401\0001Task\STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "0001Task.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\vahid\Desktop\STM32F401\0001Task\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="0001Task.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

0001Task.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "0001Task.list"
	@echo 'Finished building: $@'
	@echo ' '

0001Task.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "0001Task.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
