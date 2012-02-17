################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graphics/image/SurfaceLoader.cpp \
../src/graphics/image/Texture.cpp 

OBJS += \
./src/graphics/image/SurfaceLoader.o \
./src/graphics/image/Texture.o 

CPP_DEPS += \
./src/graphics/image/SurfaceLoader.d \
./src/graphics/image/Texture.d 


# Each subdirectory must supply rules for building sources it contributes
src/graphics/image/%.o: ../src/graphics/image/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


