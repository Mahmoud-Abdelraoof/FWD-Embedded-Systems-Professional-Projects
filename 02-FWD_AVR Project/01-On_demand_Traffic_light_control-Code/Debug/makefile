################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/05-TIMERS/subdir.mk
-include MCAL/03-GIE/subdir.mk
-include MCAL/02-EXTI/subdir.mk
-include MCAL/01-DIO/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
On_demand_Traffic_light_control.lss \

FLASH_IMAGE += \
On_demand_Traffic_light_control.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: On_demand_Traffic_light_control.elf secondary-outputs

# Tool invocations
On_demand_Traffic_light_control.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,On_demand_Traffic_light_control.map -mmcu=atmega16 -o "On_demand_Traffic_light_control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

On_demand_Traffic_light_control.lss: On_demand_Traffic_light_control.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S On_demand_Traffic_light_control.elf  >"On_demand_Traffic_light_control.lss"
	@echo 'Finished building: $@'
	@echo ' '

On_demand_Traffic_light_control.hex: On_demand_Traffic_light_control.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex On_demand_Traffic_light_control.elf  "On_demand_Traffic_light_control.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: On_demand_Traffic_light_control.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 On_demand_Traffic_light_control.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) On_demand_Traffic_light_control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
