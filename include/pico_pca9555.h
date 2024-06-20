#ifndef PCA9555_H
#define PCA9555_H

#include "hardware/i2c.h"

// Read the input values of the pca9555. The value is written to the object at
// the inputs pointer.
int pca9555_read_input(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                       uint16_t *inputs);

// Read the input values of the first 8 pins (port 0) of the pca9555. The value
// is written to the object at the inputs pointer.
int pca9555_read_input_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                         uint8_t *inputs);

// Read the input values of the last 8 pins (port 1) of the pca9555. The value
// is written to the object at the inputs pointer.
int pca9555_read_input_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                         uint8_t *inputs);

// Configure the inversion of the input read of the pca9555. A 0 bit is not
// inverted, 1 is inverted.
int pca9555_input_inversion(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                            uint16_t inverted_pins);

// Configure the inversion of the input read of the first 8 pins (port 0). A 0
// bit is not inverted, 1 is inverted.
int pca9555_input_inversion_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                              uint8_t inverted_pins);

// Configure the inversion of the input read of the last 8 pins (port 1). A 0
// bit is not inverted, 1 is inverted.
int pca9555_input_inversion_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                              uint8_t inverted_pins);

// Configure the pins for the pca9555. A 0 bit is output, 1 is input
int pca9555_configure(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                      uint16_t configuration);

// Configure the first 8 pins of the pca9555 (port 0). A 0 bit is output, 1 is
// input
int pca9555_configure_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                        uint8_t configuration);

// Configure the last 8 pins of the pca9555 (port 1). A 0 bit is output, 1 is
// input
int pca9555_configure_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                        uint8_t configuration);

// Set the output values of the pca9555
int pca9555_output(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                   uint16_t output_value);

// Set the output values of the first 8 pins (port 0)
int pca9555_output_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                     uint8_t output_value);

// Set the output values of the last 8 pins (port 1)
int pca9555_output_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                     uint8_t output_value);
#endif
