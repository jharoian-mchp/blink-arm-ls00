# Tool-chain file for arm-none-eabi-gcc
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)

set(CMAKE_C_FLAGS_INIT "-mcpu=cortex-m23 -ffunction-sections -fdata-sections --specs=nano.specs")

set(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--gc-sections -Wl,-T/home/c14029/Projects/blink-arm-ls00/dfp/PIC32CM-LS00/gcc/gcc/pic32cm5164ls00100_flash.ld")
