cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH /home/tristan/Repos/pico-sdk)
set(PICO_BOARD pico_w)

include (${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(fido_pico)
pico_sdk_init()

message(WARNING "Building ${PROJECT_NAME}")
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(${PROJECT_NAME})
