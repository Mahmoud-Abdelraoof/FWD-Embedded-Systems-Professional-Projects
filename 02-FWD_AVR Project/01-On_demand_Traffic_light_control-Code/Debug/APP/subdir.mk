################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/App.c \
../APP/main.c 

OBJS += \
./APP/App.o \
./APP/main.o 

C_DEPS += \
./APP/App.d \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\HAL" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\LIB" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL\01-DIO" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL\02-EXTI" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL\03-GIE" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL\04-ADC" -I"C:\Users\karim\OneDrive\Desktop\EgyptFWD-AVR Project\Project Code\On_demand_Traffic_light_control\MCAL\05-TIMERS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


