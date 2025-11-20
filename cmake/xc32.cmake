# Toolchain file for XC32
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER xc32-gcc)

set(CMAKE_C_FLAGS_INIT "-fno-common -MMD -MP" )

