################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/FreeRTOS/Source/portable/Renesas/RX600v2/port.c 

SRC_SRCS += \
../src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.src 

SRC_DEPS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.d 

ASSEMBLER_OBJS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port_asm.obj 

COMPILER_OBJS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port.obj 

C_DEPS += \
src/FreeRTOS/Source/portable/Renesas/RX600v2/port.d 

# Each subdirectory must supply rules for building sources it contributes
src/FreeRTOS/Source/portable/Renesas/RX600v2/%.obj: ../src/FreeRTOS/Source/portable/Renesas/RX600v2/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\FreeRTOS\Source\portable\Renesas\RX600v2\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\portable\Renesas\RX600v2\cDepSubCommand.tmp"
	ccrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\FreeRTOS\Source\portable\Renesas\RX600v2\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\portable\Renesas\RX600v2\cSubCommand.tmp"
	ccrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

src/FreeRTOS/Source/portable/Renesas/RX600v2/%.obj: ../src/FreeRTOS/Source/portable/Renesas/RX600v2/%.src 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	@echo src\FreeRTOS\Source\portable\Renesas\RX600v2\srcDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\portable\Renesas\RX600v2\srcDepSubCommand.tmp"
	asrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\srcDepSubCommand.tmp" -MF="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo src\FreeRTOS\Source\portable\Renesas\RX600v2\srcSubCommand.tmp=
	@sed -e "s/^/ /" "src\FreeRTOS\Source\portable\Renesas\RX600v2\srcSubCommand.tmp"
	asrx -subcommand="src\FreeRTOS\Source\portable\Renesas\RX600v2\srcSubCommand.tmp" -output="$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

