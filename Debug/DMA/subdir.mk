################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DMA/DMA.c 

OBJS += \
./DMA/DMA.o 

C_DEPS += \
./DMA/DMA.d 


# Each subdirectory must supply rules for building sources it contributes
DMA/%.o DMA/%.su DMA/%.cyclo: ../DMA/%.c DMA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"D:/STM32F407_Firmware/WS2811B_Driver/GPIO" -I"D:/STM32F407_Firmware/WS2811B_Driver/DMA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DMA

clean-DMA:
	-$(RM) ./DMA/DMA.cyclo ./DMA/DMA.d ./DMA/DMA.o ./DMA/DMA.su

.PHONY: clean-DMA

