################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m.c \
../src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m_data.c 

COMPILER_OBJS += \
src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m.obj \
src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m_data.obj 

C_DEPS += \
src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m.d \
src/smc_gen/r_sci_rx/src/targets/rx71m/r_sci_rx71m_data.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/r_sci_rx/src/targets/rx71m/%.obj: ../src/smc_gen/r_sci_rx/src/targets/rx71m/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\r_sci_rx\src\targets\rx71m\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\r_sci_rx\src\targets\rx71m\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\r_sci_rx\src\targets\rx71m\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)"  -MT="$(@:%.d=%.obj)"  -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\r_sci_rx\src\targets\rx71m\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\r_sci_rx\src\targets\rx71m\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\r_sci_rx\src\targets\rx71m\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

