################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Body.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2ContactManager.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Fixture.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Island.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2World.cpp \
/home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2WorldCallbacks.cpp 

OBJS += \
./Box2D/Dynamics/b2Body.o \
./Box2D/Dynamics/b2ContactManager.o \
./Box2D/Dynamics/b2Fixture.o \
./Box2D/Dynamics/b2Island.o \
./Box2D/Dynamics/b2World.o \
./Box2D/Dynamics/b2WorldCallbacks.o 

CPP_DEPS += \
./Box2D/Dynamics/b2Body.d \
./Box2D/Dynamics/b2ContactManager.d \
./Box2D/Dynamics/b2Fixture.d \
./Box2D/Dynamics/b2Island.d \
./Box2D/Dynamics/b2World.d \
./Box2D/Dynamics/b2WorldCallbacks.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Dynamics/b2Body.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Body.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Dynamics/b2ContactManager.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2ContactManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Dynamics/b2Fixture.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Fixture.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Dynamics/b2Island.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2Island.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Dynamics/b2World.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2World.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Box2D/Dynamics/b2WorldCallbacks.o: /home/ajean/Ghost-in-the-Machine/Box2D/Dynamics/b2WorldCallbacks.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


