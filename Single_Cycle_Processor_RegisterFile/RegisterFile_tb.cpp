#include "VRegisterFile.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <utility>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

VerilatedVcdC* tfp = nullptr;

// Clock tick function with optional waveform dump
void tick(VRegisterFile* dut) {
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;
}

// Helper to write to a register
void write_reg(VRegisterFile* dut, uint8_t addr, uint32_t value) {
    dut->addrD = addr;
    dut->dataD = value;
    dut->reg_write = 1;
    tick(dut);
    dut->reg_write = 0; // disable write immediately
}

// Helper to read from registers A and B
std::pair<uint32_t, uint32_t> read_regs(VRegisterFile* dut, uint8_t addrA, uint8_t addrB) {
    dut->addrA = addrA;
    dut->addrB = addrB;
    dut->eval(); // read logic is combinational
    return {dut->dataA, dut->dataB};
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    VRegisterFile* dut = new VRegisterFile;

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    std::cout << "Applying reset...\n";
    dut->reset = 0;
    tick(dut);
    tick(dut);
    dut->reset = 1;

    std::cout << "Testing register writes...\n";
    for (int i = 1; i < 32; i++) {
        write_reg(dut, i, 0x11111111 + i);
    }

    tick(dut);

    std::cout << "Verifying reads...\n";
    for (int i = 1; i < 32; i++) {
        auto [dataA, dataB] = read_regs(dut, i, (i + 1) % 32);
        std::cout << "R" << i << ": 0x" << std::hex << dataA << " (expected 0x" << std::hex << (i + 0x11111111) << ")\n";
        assert(dataA == (i + 0x11111111));
        tick(dut);

    }


    tick(dut);


    std::cout << "Re-applying reset...\n";
    dut->reset = 0;
    tick(dut);
    dut->reset = 1;
    tick(dut);

    auto [rafterReset1, rafterReset2] = read_regs(dut, 5, 10);
    std::cout << "After reset - R5: 0x" << std::hex << rafterReset1 << ", R10: 0x" << rafterReset2 << "\n";
    assert(rafterReset1 == 0x0);
    assert(rafterReset2 == 0x0);
    tick(dut);
    std::cout << "Performing edge cases test (write to R0)...\n";
    write_reg(dut, 0, 0xDEADBEEF); // optional: R0 usually reserved
    tick(dut);
    auto [r0, _] = read_regs(dut, 0, 0);
    tick(dut);
    std::cout << "R0: 0x" << std::hex << r0 << " (expected 0xDEADBEEF)\n";
    assert(r0 == 0); // R0 should always read 0

    std::cout << "\n✅ All tests passed successfully.\n";

    // Cleanup
    tfp->close();
    delete tfp;
    delete dut;

    return 0;
}