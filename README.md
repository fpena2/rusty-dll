# Example Project 

Letting a shared library (in Rust) handle C++'s workload...

## Build

Build the shared library

```cmd
cargo build --release
```

Build the C++ frontend

```cmd
cmake --build .
```

## Run

Execute `./build/main`