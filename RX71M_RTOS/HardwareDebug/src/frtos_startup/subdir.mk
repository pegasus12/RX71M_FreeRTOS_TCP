################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/frtos_startup/freertos_object_init.c \
../src/frtos_startup/freertos_start.c 

COMPILER_OBJS += \
src/frtos_startup/freertos_object_init.obj \
src/frtos_startup/freertos_start.obj 

C_DEPS += \
src/frtos_startup/freertos_object_init.d \
src/frtos_startup/freertos_start.d 

# Each subdirectory must supply rules for building sources it contributes
src/frtos_startup/%.obj: ../src/frtos_startup/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\frtos_startup\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\frtos_startup\cDepSubCommand.tmp"
	ccrx -subcommand="src\frtos_startup\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\frtos_startup\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\frtos_startup\cSubCommand.tmp"
	ccrx -subcommand="src\frtos_startup\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

