################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
13_OutputCompare.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
13_OutputCompare.list \

OBJCOPY_BIN += \
13_OutputCompare.bin \


# All Target
all: 13_OutputCompare.elf secondary-outputs

# Tool invocations
13_OutputCompare.elf: $(OBJS) $(USER_OBJS) C:\Users\vahid\Desktop\STM32F401\13_OutputCompare\STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "13_OutputCompare.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\vahid\Desktop\STM32F401\13_OutputCompare\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="13_OutputCompare.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

13_OutputCompare.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "13_OutputCompare.list"
	@echo 'Finished building: $@'
	@echo ' '

13_OutputCompare.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "13_OutputCompare.bin"
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
