################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Employee.c \
../LinkedList.c \
../main.c \
../parser.c \
../punteros.c \
../utn.c 

OBJS += \
./Controller.o \
./Employee.o \
./LinkedList.o \
./main.o \
./parser.o \
./punteros.o \
./utn.o 

C_DEPS += \
./Controller.d \
./Employee.d \
./LinkedList.d \
./main.d \
./parser.d \
./punteros.d \
./utn.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


