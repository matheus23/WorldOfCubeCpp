################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/Game.cpp 

OBJS += \
./src/game/Game.o 

CPP_DEPS += \
./src/game/Game.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/%.o: ../src/game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


