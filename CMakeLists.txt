cmake_minimum_required(VERSION 3.19)

set(executable_name blink)         # Name used for target and .elf and .hex files in build folder
set(microcontroller 32CM5164LS00100)       # Target microcontroller - needed for xc32

# Project name is independent of the target name
# Semantic version number updated here
project(    blink
            VERSION 0.1.0
            LANGUAGES C
)

# List of .c files
add_executable( ${executable_name}.elf
                blink.c
                dfp/PIC32CM-LS00/gcc/gcc/startup_pic32cm5164ls00100.c
)

# Modify the paths below for DFP and CMSIS include
# Pack updates appear in home_directory and original files appear in MPLAB X install directory
set(microchip_dfp_path "dfp/PIC32CM-LS00/include" )
set(cmsis_include_path "CMSIS_6/CMSIS/Core/Include" )

# Include directories - need at least DFP and CMSIS directories
target_include_directories(	${executable_name}.elf
				PRIVATE ${microchip_dfp_path}
				PRIVATE ${cmsis_include_path}
				PRIVATE "/home/c14029/.local/share/arm-gcc/v14.3.1/lib/gcc/arm-none-eabi/14.3.1/include"
)

# Set processor and other options for build
target_compile_options(	${executable_name}.elf
			PUBLIC "-O0"
			PUBLIC "-ggdb"
)

target_link_options(	${executable_name}.elf
			PUBLIC "-Wl,-Map=${executable_name}.map"
			PUBLIC "-ggdb"
)

# Set configuration
target_compile_definitions(	${executable_name}.elf
				PUBLIC "__PIC32CM5164LS00100__"
)

# Create hex file from target
add_custom_command(	TARGET ${executable_name}.elf
			POST_BUILD COMMAND arm-none-eabi-objcopy ${executable_name}.elf -O ihex ${executable_name}.hex
)

