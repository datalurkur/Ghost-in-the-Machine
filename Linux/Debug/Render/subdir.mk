################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/datalurkur/GitM/Render/RenderContext.cpp \
/home/datalurkur/GitM/Render/Renderable.cpp \
/home/datalurkur/GitM/Render/Viewport.cpp 

OBJS += \
./Render/RenderContext.o \
./Render/Renderable.o \
./Render/Viewport.o 

CPP_DEPS += \
./Render/RenderContext.d \
./Render/Renderable.d \
./Render/Viewport.d 


# Each subdirectory must supply rules for building sources it contributes
Render/RenderContext.o: /home/datalurkur/GitM/Render/RenderContext.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/datalurkur/GitM -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Renderable.o: /home/datalurkur/GitM/Render/Renderable.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/datalurkur/GitM -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Viewport.o: /home/datalurkur/GitM/Render/Viewport.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/datalurkur/GitM -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


