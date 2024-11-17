# pico_pca9555

![Nix Flake](https://img.shields.io/badge/NIX%20FLAKE-5277C3.svg?logo=NixOS&logoColor=white) [![xc compatible](https://xcfile.dev/badge.svg)](https://xcfile.dev)

A C library for controlling the PCA9555/TCA9555 I2C IO expander with the Raspberry Pi Pico.

## Development

This library uses [nix](https://nixos.org).
To develop, run the nix shell using `nix develop`. This library can also be build using `nix build`.

## Tasks

### build
Directory: ./build

Build a static archive library (`.a`).

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

### build-dbg
Directory: ./build

Build the library with debug information.

```bash
cmake -DCMAKE_BUILD_TYPE=Debug .. 
make -j4
cp compile_commands.json ../ # Copies the autocomplete information for ccls.
```

### clean
Cleans the build directory for a fresh build.

```bash
rm -rf ./build
mkdir build
```
