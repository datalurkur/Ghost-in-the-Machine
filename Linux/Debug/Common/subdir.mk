################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Common/b2BlockAllocator.cpp \
../Common/b2Draw.cpp \
../Common/b2Math.cpp \
../Common/b2Settings.cpp \
../Common/b2StackAllocator.cpp \
../Common/b2Timer.cpp 

OBJS += \
./Common/b2BlockAllocator.o \
./Common/b2Draw.o \
./Common/b2Math.o \
./Common/b2Settings.o \
./Common/b2StackAllocator.o \
./Common/b2Timer.o 

CPP_DEPS += \
./Common/b2BlockAllocator.d \
./Common/b2Draw.d \
./Common/b2Math.d \
./Common/b2Settings.d \
./Common/b2StackAllocator.d \
./Common/b2Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Common/%.o: ../Common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


