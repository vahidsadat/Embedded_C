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
0_led_toggle_addr.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
0_led_toggle_addr.list \

OBJCOPY_BIN += \
0_led_toggle_addr.bin \


# All Target
all: 0_led_toggle_addr.elf secondary-outputs

# Tool invocations
0_led_toggle_addr.elf: $(OBJS) $(USER_OBJS) C:\Users\vahid\Desktop\STM32F401\0_led_toggle_addr\STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "0_led_toggle_addr.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\vahid\Desktop\STM32F401\0_led_toggle_addr\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="0_led_toggle_addr.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

0_led_toggle_addr.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "0_led_toggle_addr.list"
	@echo 'Finished building: $@'
	@echo ' '

0_led_toggle_addr.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "0_led_toggle_addr.bin"
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
