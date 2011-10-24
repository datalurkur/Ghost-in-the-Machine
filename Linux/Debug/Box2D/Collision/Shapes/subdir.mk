################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2ChainShape.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2CircleShape.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2EdgeShape.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2PolygonShape.cpp 

OBJS += \
./Box2D/Collision/Shapes/b2ChainShape.o \
./Box2D/Collision/Shapes/b2CircleShape.o \
./Box2D/Collision/Shapes/b2EdgeShape.o \
./Box2D/Collision/Shapes/b2PolygonShape.o 

CPP_DEPS += \
./Box2D/Collision/Shapes/b2ChainShape.d \
./Box2D/Collision/Shapes/b2CircleShape.d \
./Box2D/Collision/Shapes/b2EdgeShape.d \
./Box2D/Collision/Shapes/b2PolygonShape.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Collision/Shapes/b2ChainShape.o: /home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2ChainShape.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Collision/Shapes/b2CircleShape.o: /home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2CircleShape.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Collision/Shapes/b2EdgeShape.o: /home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2EdgeShape.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Collision/Shapes/b2PolygonShape.o: /home/ajean/Ghost-in-the-Machine/Box2D/Collision/Shapes/b2PolygonShape.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


