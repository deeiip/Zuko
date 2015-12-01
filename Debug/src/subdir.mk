################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Surrounding.c \
../src/interfaces.c \
../src/listening.c \
../src/log.c \
../src/serviceEP.c 

OBJS += \
./src/Surrounding.o \
./src/interfaces.o \
./src/listening.o \
./src/log.o \
./src/serviceEP.o 

C_DEPS += \
./src/Surrounding.d \
./src/interfaces.d \
./src/listening.d \
./src/log.d \
./src/serviceEP.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/dipanjan/workspace/Zuko/include" -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


