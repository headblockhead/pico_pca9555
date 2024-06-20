cmake_minimum_required(VERSION 3.12)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(external/pico-sdk/pico_sdk_init.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico-pca9555 VERSION 0.0.1 DESCRIPTION "Library for the P/TCA9555 16-bit I2C-bus and SMBus I/O port with interrupt")

# Initialize the SDK
pico_sdk_init()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Debug/Development build enabled")
        # Create files for CCLS
        set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
        add_compile_options(-Og) # Enable debug optimizations
else()
       add_compile_options(-Os) # Enable size optimizations
endif()

# Generate a static library archive.
add_library(pico-pca9555 STATIC
        src/pico-pca9555.c
        )

target_include_directories(pico-pca9555 PRIVATE include)
target_link_libraries(pico-pca9555 pico_stdlib hardware_i2c)

set_target_properties(pico-pca9555 PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(pico-pca9555 PROPERTIES PUBLIC_HEADER include/pico-pca9555.h)
