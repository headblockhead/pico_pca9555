#include "pico_pca9555.h"

// Constants for I2C communication
const uint8_t PCA9555_CMD_SET_INPUTS_0 = _u(0x00);
const uint8_t PCA9555_CMD_SET_INPUTS_1 = _u(0x01);
const uint8_t PCA9555_CMD_SET_OUTPUTS_0 = _u(0x02);
const uint8_t PCA9555_CMD_SET_OUTPUTS_1 = _u(0x03);
const uint8_t PCA9555_CMD_POLARITY_INVERT_0 = _u(0x04);
const uint8_t PCA9555_CMD_POLARITY_INVERT_1 = _u(0x05);
const uint8_t PCA9555_CMD_CONFIGURE_0 = _u(0x06);
const uint8_t PCA9555_CMD_CONFIGURE_1 = _u(0x07);

int pca9555_read_input(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                       uint16_t *inputs) {
  // Two sets of 8-bit inputs
  uint8_t inputs_0;
  uint8_t inputs_1;
  // Read the 8-bit input values
  int err = pca9555_read_input_0(i2c_instance, i2c_address, &inputs_0);
  if (err < 0) {
    return err;
  }
  err = pca9555_read_input_1(i2c_instance, i2c_address, &inputs_1);
  if (err < 0) {
    return err;
  }
  // Combine the 8-bit inputs into a 16-bit value
  *inputs = (inputs_1 << 8) | inputs_0;
  return 0;
}

int pca9555_read_input_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                         uint8_t *inputs) {
  // Read the 8-bit input value
  return i2c_read_blocking(i2c_instance, i2c_address, inputs, 1, false);
}

int pca9555_read_input_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                         uint8_t *inputs) {
  // Read the 8-bit input value
  return i2c_read_blocking(i2c_instance, i2c_address, inputs, 1, false);
}

int pca9555_configure_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                        uint8_t configuration) {
  // Set the 8-bit configuration
  uint8_t config_0[2] = {PCA9555_CMD_CONFIGURE_0, configuration};
  // Write the configuration
  return i2c_write_blocking(i2c_instance, i2c_address, config_0, 2, false);
}

int pca9555_configure_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                        uint8_t configuration) {
  // Set the 8-bit configuration
  uint8_t config_1[2] = {PCA9555_CMD_CONFIGURE_1, configuration};
  // Write the configuration
  return i2c_write_blocking(i2c_instance, i2c_address, config_1, 2, false);
}

int pca9555_input_inversion(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                            uint16_t inverted_pins) {
  // Two sets of 8-bit input inversion
  uint8_t inversion_0[2] = {PCA9555_CMD_POLARITY_INVERT_0,
                            inverted_pins & 0xFF};
  uint8_t inversion_1[2] = {PCA9555_CMD_POLARITY_INVERT_1,
                            (inverted_pins >> 8) & 0xFF};
  int err =
      pca9555_input_inversion_0(i2c_instance, i2c_address, inversion_0[1]);
  if (err < 0) {
    return err;
  }
  return pca9555_input_inversion_1(i2c_instance, i2c_address, inversion_1[1]);
}

int pca9555_input_inversion_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                              uint8_t inverted_pins) {
  // Set the 8-bit input inversion
  uint8_t inversion_0[2] = {PCA9555_CMD_POLARITY_INVERT_0, inverted_pins};
  // Write the inversion
  return i2c_write_blocking(i2c_instance, i2c_address, inversion_0, 2, false);
}

int pca9555_input_inversion_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                              uint8_t inverted_pins) {
  // Set the 8-bit input inversion
  uint8_t inversion_1[2] = {PCA9555_CMD_POLARITY_INVERT_1, inverted_pins};
  // Write the inversion
  return i2c_write_blocking(i2c_instance, i2c_address, inversion_1, 2, false);
}

int pca9555_output(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                   uint16_t output_value) {
  // Two sets of 8-bit outputs
  uint8_t outputs_0[2] = {PCA9555_CMD_SET_OUTPUTS_0, output_value & 0xFF};
  uint8_t outputs_1[2] = {PCA9555_CMD_SET_OUTPUTS_1,
                          (output_value >> 8) & 0xFF};
  int err = pca9555_output_0(i2c_instance, i2c_address, outputs_0[1]);
  if (err < 0) {
    return err;
  }
  return pca9555_output_1(i2c_instance, i2c_address, outputs_1[1]);
}

int pca9555_output_0(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                     uint8_t output_value) {
  // Set the 8-bit outputs
  uint8_t outputs_0[2] = {PCA9555_CMD_SET_OUTPUTS_0, output_value};
  // Write the outputs
  return i2c_write_blocking(i2c_instance, i2c_address, outputs_0, 2, false);
}

int pca9555_output_1(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                     uint8_t output_value) {
  // Set the 8-bit outputs
  uint8_t outputs_1[2] = {PCA9555_CMD_SET_OUTPUTS_1, output_value};
  // Write the outputs
  return i2c_write_blocking(i2c_instance, i2c_address, outputs_1, 2, false);
}

// Configure the PCA9555 for inputs or outputs
int pca9555_configure(i2c_inst_t *i2c_instance, uint8_t i2c_address,
                      uint16_t configuration) {
  // Two sets of 8-bit configurations
  uint8_t config_0[2] = {PCA9555_CMD_CONFIGURE_0, configuration & 0xFF};
  uint8_t config_1[2] = {PCA9555_CMD_CONFIGURE_1, (configuration >> 8) & 0xFF};
  // Write the configurations
  int err = i2c_write_blocking(i2c_instance, i2c_address, config_0, 2, true);
  if (err < 0) {
    return err;
  }
  err = i2c_write_blocking(i2c_instance, i2c_address, config_1, 2, false);
  return err;
}
