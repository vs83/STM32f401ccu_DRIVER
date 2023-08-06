################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32f401ccu6_gpio.c 

OBJS += \
./drivers/src/stm32f401ccu6_gpio.o 

C_DEPS += \
./drivers/src/stm32f401ccu6_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"C:/Embedded-_project/STM32f401ccu_DRIVER/Stm32F401CCU6/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32f401ccu6_gpio.cyclo ./drivers/src/stm32f401ccu6_gpio.d ./drivers/src/stm32f401ccu6_gpio.o ./drivers/src/stm32f401ccu6_gpio.su

.PHONY: clean-drivers-2f-src

