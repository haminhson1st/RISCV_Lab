# RISCV_Lab_HUST
Design some components in a RISCV Processor in verilog, simulate using Verilator and GTKWave

## Project Structure

```bash
/RISCV_Lab_HUST
  ├── RegisterFile.v             # Verilog implementation of the RegisterFile module
  ├── RegisterFile_tb.cpp        # C++ testbench for RegisterFile using Verilator
  ├── Makefile                   # Makefile to automate build and simulation process
  ├── wave.vcd                   # (Generated) VCD waveform file
  ├── README.md
  └── obj_dir                    # Generated directory for Verilator C++ code

## Verify RegisterFile module
```bash
make all

## View wave
```bash
make wave