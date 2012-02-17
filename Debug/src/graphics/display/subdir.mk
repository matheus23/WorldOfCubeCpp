################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/display/SDLDisplay.cpp 

OBJS += \
./src/graphics/display/SDLDisplay.o 

CPP_DEPS += \
./src/graphics/display/SDLDisplay.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/display/%.o: ../src/graphics/display/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


