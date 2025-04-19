# Variables
TOP_MODULE     = RegisterFile
TESTBENCH_MODULE = tb_RegisterFile
# CPP_TESTBENCH  = RegisterFile_tb.cpp
VSRCS          = $(TOP_MODULE).v
VTESTBENCH     = $(TESTBENCH_MODULE).v
OUT_VVD 	   = $(TESTBENCH_MODULE).vvd
# OBJ_DIR        = obj_dir
# EXECUTABLE     = $(OBJ_DIR)/V$(TOP_MODULE)
# TRACE_FLAG     = --trace
VCD_FILE       = wave.vcd

# Default target
all: build run

# Compile Verilog and C++ testbench
# build:
# 	# verilator -Wall $(TRACE_FLAG) --cc $(VSRCS) --exe $(CPP_TESTBENCH)
# 	# make -C $(OBJ_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

build:
	iverilog -o $(OUT_VVD) $(VTESTBENCH)
# Run the simulation
run:
	vvp $(OUT_VVD)

# Open waveform with GTKWave (optional)
wave:
	gtkwave $(VCD_FILE)

# Clean up generated files
clean:
	rm -rf $(OUT_VVD) $(VCD_FILE)

.PHONY: all build run clean wave
