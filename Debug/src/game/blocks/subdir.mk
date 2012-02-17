################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/blocks/Block.cpp \
../src/game/blocks/BlockEarth.cpp \
../src/game/blocks/BlockGrass.cpp 

OBJS += \
./src/game/blocks/Block.o \
./src/game/blocks/BlockEarth.o \
./src/game/blocks/BlockGrass.o 

CPP_DEPS += \
./src/game/blocks/Block.d \
./src/game/blocks/BlockEarth.d \
./src/game/blocks/BlockGrass.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/blocks/%.o: ../src/game/blocks/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/philipp/program/workspace/WorldOfCube/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


