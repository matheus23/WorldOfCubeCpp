################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/layers/player/Cursor.cpp 

OBJS += \
./src/game/layers/player/Cursor.o 

CPP_DEPS += \
./src/game/layers/player/Cursor.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/layers/player/%.o: ../src/game/layers/player/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


