################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Collision/b2BroadPhase.cpp \
../Collision/b2CollideCircle.cpp \
../Collision/b2CollideEdge.cpp \
../Collision/b2CollidePolygon.cpp \
../Collision/b2Collision.cpp \
../Collision/b2Distance.cpp \
../Collision/b2DynamicTree.cpp \
../Collision/b2TimeOfImpact.cpp 

OBJS += \
./Collision/b2BroadPhase.o \
./Collision/b2CollideCircle.o \
./Collision/b2CollideEdge.o \
./Collision/b2CollidePolygon.o \
./Collision/b2Collision.o \
./Collision/b2Distance.o \
./Collision/b2DynamicTree.o \
./Collision/b2TimeOfImpact.o 

CPP_DEPS += \
./Collision/b2BroadPhase.d \
./Collision/b2CollideCircle.d \
./Collision/b2CollideEdge.d \
./Collision/b2CollidePolygon.d \
./Collision/b2Collision.d \
./Collision/b2Distance.d \
./Collision/b2DynamicTree.d \
./Collision/b2TimeOfImpact.d 


# Each subdirectory must supply rules for building sources it contributes
Collision/%.o: ../Collision/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


