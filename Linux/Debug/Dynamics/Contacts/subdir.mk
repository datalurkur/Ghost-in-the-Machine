################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dynamics/Contacts/b2ChainAndCircleContact.cpp \
../Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
../Dynamics/Contacts/b2CircleContact.cpp \
../Dynamics/Contacts/b2Contact.cpp \
../Dynamics/Contacts/b2ContactSolver.cpp \
../Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
../Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
../Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
../Dynamics/Contacts/b2PolygonContact.cpp 

OBJS += \
./Dynamics/Contacts/b2ChainAndCircleContact.o \
./Dynamics/Contacts/b2ChainAndPolygonContact.o \
./Dynamics/Contacts/b2CircleContact.o \
./Dynamics/Contacts/b2Contact.o \
./Dynamics/Contacts/b2ContactSolver.o \
./Dynamics/Contacts/b2EdgeAndCircleContact.o \
./Dynamics/Contacts/b2EdgeAndPolygonContact.o \
./Dynamics/Contacts/b2PolygonAndCircleContact.o \
./Dynamics/Contacts/b2PolygonContact.o 

CPP_DEPS += \
./Dynamics/Contacts/b2ChainAndCircleContact.d \
./Dynamics/Contacts/b2ChainAndPolygonContact.d \
./Dynamics/Contacts/b2CircleContact.d \
./Dynamics/Contacts/b2Contact.d \
./Dynamics/Contacts/b2ContactSolver.d \
./Dynamics/Contacts/b2EdgeAndCircleContact.d \
./Dynamics/Contacts/b2EdgeAndPolygonContact.d \
./Dynamics/Contacts/b2PolygonAndCircleContact.d \
./Dynamics/Contacts/b2PolygonContact.d 


# Each subdirectory must supply rules for building sources it contributes
Dynamics/Contacts/%.o: ../Dynamics/Contacts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


