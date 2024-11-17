cmake_minimum_required(VERSION 3.12)

# Find SDK using PICO_SDK_PATH
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico_pca9555)

# Initialize the SDK
pico_sdk_init()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
        add_compile_options(-Og)
else()
       add_compile_options(-Os)
endif()

# Generate a static library archive.
add_library(pico_pca9555 STATIC
        src/pico_pca9555.c
        )

target_link_libraries(pico_pca9555 pico_stdlib hardware_i2c)
target_include_directories(pico_pca9555 PUBLIC include)
set_target_properties(pico_pca9555 PROPERTIES PUBLIC_HEADER include/pico_pca9555.h)
