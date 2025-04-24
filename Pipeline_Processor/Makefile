RTL_DIR        = rtl
TEST_DIR  	   = test
OBJ_DIR        = obj

# Variables

# # RegisterFile
# TOP_MODULE     = RegisterFile
# TESTBENCH_MODULE = tb_RegisterFile

# # ForwardingUnit
# TOP_MODULE     = ForwardingUnit
# TESTBENCH_MODULE = tb_ForwardingUnit

# HazardDetectionUnit
TOP_MODULE     = HazardDetectionUnit
TESTBENCH_MODULE = tb_HazardDetectionUnit

# CPP_TESTBENCH  = RegisterFile_tb.cpp
VSRCS          = $(TOP_MODULE).v
VTESTBENCH     = $(TESTBENCH_MODULE).v
OUT_VVD 	   = $(TESTBENCH_MODULE).vvd

OBJ_STANDALONE = $(OBJ_DIR)/$(TOP_MODULE)

# EXECUTABLE     = $(OBJ_DIR)/V$(TOP_MODULE)
# TRACE_FLAG     = --trace
VCD_FILE       = wave.vcd

# Default target
all: build run

# Build the simulation
build:
	mkdir -p $(OBJ_STANDALONE)
	iverilog -o $(OBJ_STANDALONE)/$(OUT_VVD) $(TEST_DIR)/$(VTESTBENCH) $(RTL_DIR)/$(VSRCS)
# Run the simulation
run:
	vvp $(OBJ_STANDALONE)/$(OUT_VVD)

# Open waveform with GTKWave (optional)
wave:
	gtkwave $(OBJ_STANDALONE)/$(VCD_FILE)

# Clean up generated files
clean:
	rm -rf $(OBJ_STANDALONE)

.PHONY: all build run clean wave
