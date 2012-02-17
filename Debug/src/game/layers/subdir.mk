################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/layers/LayerManager.cpp 

OBJS += \
./src/game/layers/LayerManager.o 

CPP_DEPS += \
./src/game/layers/LayerManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/layers/%.o: ../src/game/layers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


