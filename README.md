# pico-pca9555
A C library for controlling the PCA9555/TCA9555 I2C IO expander with the Raspberry Pi Pico.

## Development

This library uses [nix](https://nixos.org).
To develop, run the nix shell using `nix develop`. This library can also be build using `nix build`.

## Tasks

### Build
Directory: ./build

Build a static archive library (`.a`).

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

### Build-debug
Directory: ./build

Builds the library with debug build type.

```bash
cmake -DCMAKE_BUILD_TYPE=Debug .. 
make -j4
cp compile_commands.json ../ # Copies the autocomplete information for ccls.
```

### Clean
Cleans the build directory for a fresh build.

```bash
rm -rf ./build
mkdir build
```

### Init-submodules

Fetches submodules for use in the project.
```bash
git submodule update --init --recursive
```
