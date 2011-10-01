################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/datalurkur/GitM/Base/Log.cpp \
/home/datalurkur/GitM/Base/Matrix4.cpp 

OBJS += \
./Base/Log.o \
./Base/Matrix4.o 

CPP_DEPS += \
./Base/Log.d \
./Base/Matrix4.d 


# Each subdirectory must supply rules for building sources it contributes
Base/Log.o: /home/datalurkur/GitM/Base/Log.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Base/Matrix4.o: /home/datalurkur/GitM/Base/Matrix4.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


