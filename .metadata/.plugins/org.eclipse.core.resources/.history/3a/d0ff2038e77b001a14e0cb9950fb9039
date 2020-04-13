################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/FreeRTOS/Source/croutine.c \
../src/FreeRTOS/Source/event_groups.c \
../src/FreeRTOS/Source/list.c \
../src/FreeRTOS/Source/queue.c \
../src/FreeRTOS/Source/stream_buffer.c \
../src/FreeRTOS/Source/tasks.c \
../src/FreeRTOS/Source/timers.c 

COMPILER_OBJS += \
src/FreeRTOS/Source/croutine.obj \
src/FreeRTOS/Source/event_groups.obj \
src/FreeRTOS/Source/list.obj \
src/FreeRTOS/Source/queue.obj \
src/FreeRTOS/Source/stream_buffer.obj \
src/FreeRTOS/Source/tasks.obj \
src/FreeRTOS/Source/timers.obj 

C_DEPS += \
src/FreeRTOS/Source/croutine.d \
src/FreeRTOS/Source/event_groups.d \
src/FreeRTOS/Source/list.d \
src/FreeRTOS/Source/queue.d \
src/FreeRTOS/Source/stream_buffer.d \
src/FreeRTOS/Source/tasks.d \
src/FreeRTOS/Source/timers.d 

# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS/Source/%.obj: ../src/FreeRTOS/Source/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\FreeRTOS\Source\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\cDepSubCommand.tmp"
	ccrx -subcommand="src\FreeRTOS\Source\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\FreeRTOS\Source\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\cSubCommand.tmp"
	ccrx -subcommand="src\FreeRTOS\Source\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

