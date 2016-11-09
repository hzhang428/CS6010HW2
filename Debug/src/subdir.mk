################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EventHandler.c \
../src/main.c \
../src/priorityqueue.c \
../src/queue.c \
../src/randomNumber.c \
../src/simulationEngine.c 

OBJS += \
./src/EventHandler.o \
./src/main.o \
./src/priorityqueue.o \
./src/queue.o \
./src/randomNumber.o \
./src/simulationEngine.o 

C_DEPS += \
./src/EventHandler.d \
./src/main.d \
./src/priorityqueue.d \
./src/queue.d \
./src/randomNumber.d \
./src/simulationEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


