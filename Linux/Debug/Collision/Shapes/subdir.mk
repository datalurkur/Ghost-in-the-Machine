################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Collision/Shapes/b2ChainShape.cpp \
../Collision/Shapes/b2CircleShape.cpp \
../Collision/Shapes/b2EdgeShape.cpp \
../Collision/Shapes/b2PolygonShape.cpp 

OBJS += \
./Collision/Shapes/b2ChainShape.o \
./Collision/Shapes/b2CircleShape.o \
./Collision/Shapes/b2EdgeShape.o \
./Collision/Shapes/b2PolygonShape.o 

CPP_DEPS += \
./Collision/Shapes/b2ChainShape.d \
./Collision/Shapes/b2CircleShape.d \
./Collision/Shapes/b2EdgeShape.d \
./Collision/Shapes/b2PolygonShape.d 


# Each subdirectory must supply rules for building sources it contributes
Collision/Shapes/%.o: ../Collision/Shapes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


