################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/RX71M_RTOS.c \
../src/TCPEchoClient_NcTestTasks.c \
../src/toei_protocol.c 

COMPILER_OBJS += \
src/RX71M_RTOS.obj \
src/TCPEchoClient_NcTestTasks.obj \
src/toei_protocol.obj 

C_DEPS += \
src/RX71M_RTOS.d \
src/TCPEchoClient_NcTestTasks.d \
src/toei_protocol.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\cDepSubCommand.tmp"
	ccrx -subcommand="src\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\cSubCommand.tmp"
	ccrx -subcommand="src\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

