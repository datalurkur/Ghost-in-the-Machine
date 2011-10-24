################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ajean/Ghost-in-the-Machine/Resource/MaterialManager.cpp \
/home/ajean/Ghost-in-the-Machine/Resource/TTFManager.cpp \
/home/ajean/Ghost-in-the-Machine/Resource/TextureManager.cpp \
/home/ajean/Ghost-in-the-Machine/Resource/ThreadedResourceManager.cpp \
/home/ajean/Ghost-in-the-Machine/Resource/WorldManager.cpp 

OBJS += \
./Resource/MaterialManager.o \
./Resource/TTFManager.o \
./Resource/TextureManager.o \
./Resource/ThreadedResourceManager.o \
./Resource/WorldManager.o 

CPP_DEPS += \
./Resource/MaterialManager.d \
./Resource/TTFManager.d \
./Resource/TextureManager.d \
./Resource/ThreadedResourceManager.d \
./Resource/WorldManager.d 


# Each subdirectory must supply rules for building sources it contributes
Resource/MaterialManager.o: /home/ajean/Ghost-in-the-Machine/Resource/MaterialManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Resource/TTFManager.o: /home/ajean/Ghost-in-the-Machine/Resource/TTFManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Resource/TextureManager.o: /home/ajean/Ghost-in-the-Machine/Resource/TextureManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Resource/ThreadedResourceManager.o: /home/ajean/Ghost-in-the-Machine/Resource/ThreadedResourceManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Resource/WorldManager.o: /home/ajean/Ghost-in-the-Machine/Resource/WorldManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


