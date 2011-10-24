################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dynamics/b2Body.cpp \
../Dynamics/b2ContactManager.cpp \
../Dynamics/b2Fixture.cpp \
../Dynamics/b2Island.cpp \
../Dynamics/b2World.cpp \
../Dynamics/b2WorldCallbacks.cpp 

OBJS += \
./Dynamics/b2Body.o \
./Dynamics/b2ContactManager.o \
./Dynamics/b2Fixture.o \
./Dynamics/b2Island.o \
./Dynamics/b2World.o \
./Dynamics/b2WorldCallbacks.o 

CPP_DEPS += \
./Dynamics/b2Body.d \
./Dynamics/b2ContactManager.d \
./Dynamics/b2Fixture.d \
./Dynamics/b2Island.d \
./Dynamics/b2World.d \
./Dynamics/b2WorldCallbacks.d 


# Each subdirectory must supply rules for building sources it contributes
Dynamics/%.o: ../Dynamics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


