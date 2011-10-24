################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dynamics/Joints/b2DistanceJoint.cpp \
../Dynamics/Joints/b2FrictionJoint.cpp \
../Dynamics/Joints/b2GearJoint.cpp \
../Dynamics/Joints/b2Joint.cpp \
../Dynamics/Joints/b2MouseJoint.cpp \
../Dynamics/Joints/b2PrismaticJoint.cpp \
../Dynamics/Joints/b2PulleyJoint.cpp \
../Dynamics/Joints/b2RevoluteJoint.cpp \
../Dynamics/Joints/b2RopeJoint.cpp \
../Dynamics/Joints/b2WeldJoint.cpp \
../Dynamics/Joints/b2WheelJoint.cpp 

OBJS += \
./Dynamics/Joints/b2DistanceJoint.o \
./Dynamics/Joints/b2FrictionJoint.o \
./Dynamics/Joints/b2GearJoint.o \
./Dynamics/Joints/b2Joint.o \
./Dynamics/Joints/b2MouseJoint.o \
./Dynamics/Joints/b2PrismaticJoint.o \
./Dynamics/Joints/b2PulleyJoint.o \
./Dynamics/Joints/b2RevoluteJoint.o \
./Dynamics/Joints/b2RopeJoint.o \
./Dynamics/Joints/b2WeldJoint.o \
./Dynamics/Joints/b2WheelJoint.o 

CPP_DEPS += \
./Dynamics/Joints/b2DistanceJoint.d \
./Dynamics/Joints/b2FrictionJoint.d \
./Dynamics/Joints/b2GearJoint.d \
./Dynamics/Joints/b2Joint.d \
./Dynamics/Joints/b2MouseJoint.d \
./Dynamics/Joints/b2PrismaticJoint.d \
./Dynamics/Joints/b2PulleyJoint.d \
./Dynamics/Joints/b2RevoluteJoint.d \
./Dynamics/Joints/b2RopeJoint.d \
./Dynamics/Joints/b2WeldJoint.d \
./Dynamics/Joints/b2WheelJoint.d 


# Each subdirectory must supply rules for building sources it contributes
Dynamics/Joints/%.o: ../Dynamics/Joints/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


