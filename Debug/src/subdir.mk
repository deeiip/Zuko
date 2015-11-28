################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Surrounding.c \
../src/interfaces.c \
../src/log.c 

OBJS += \
./src/Surrounding.o \
./src/interfaces.o \
./src/log.o 

C_DEPS += \
./src/Surrounding.d \
./src/interfaces.d \
./src/log.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/dipanjan/workspace/Zuko/include" -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


