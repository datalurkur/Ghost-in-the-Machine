################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ajean/Ghost-in-the-Machine/Render/Font.cpp \
/home/ajean/Ghost-in-the-Machine/Render/Material.cpp \
/home/ajean/Ghost-in-the-Machine/Render/RenderContext.cpp \
/home/ajean/Ghost-in-the-Machine/Render/Renderable.cpp \
/home/ajean/Ghost-in-the-Machine/Render/Texture.cpp \
/home/ajean/Ghost-in-the-Machine/Render/Viewport.cpp 

OBJS += \
./Render/Font.o \
./Render/Material.o \
./Render/RenderContext.o \
./Render/Renderable.o \
./Render/Texture.o \
./Render/Viewport.o 

CPP_DEPS += \
./Render/Font.d \
./Render/Material.d \
./Render/RenderContext.d \
./Render/Renderable.d \
./Render/Texture.d \
./Render/Viewport.d 


# Each subdirectory must supply rules for building sources it contributes
Render/Font.o: /home/ajean/Ghost-in-the-Machine/Render/Font.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Material.o: /home/ajean/Ghost-in-the-Machine/Render/Material.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/RenderContext.o: /home/ajean/Ghost-in-the-Machine/Render/RenderContext.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Renderable.o: /home/ajean/Ghost-in-the-Machine/Render/Renderable.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Texture.o: /home/ajean/Ghost-in-the-Machine/Render/Texture.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Render/Viewport.o: /home/ajean/Ghost-in-the-Machine/Render/Viewport.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


