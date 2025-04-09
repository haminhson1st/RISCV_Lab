# RISCV_Lab
Design some components in a RISCV Processor in verilog, simulate using Icarus Verilog and GTKWave

## Project Structure

```bash
/RISCV_Lab
  ├── RegisterFile.v             # Verilog implementation of the RegisterFile module
  ├── RegisterFile_tb.cpp        # C++ testbench for RegisterFile using Verilator
  ├── tb_RegisterFile.v          # Verilog testbench for RegisterFile using Icarus Verilog
  ├── Makefile                   # Makefile to automate build and simulation process
  ├── wave.vcd                   # (Generated) VCD waveform file
  ├── README.md
  └── tb_RegisterFile.vvd        # Generated file for Icarus Verilog code
```

## Verify RegisterFile module
```bash
make all
```

## View wave
```bash
make wave
```