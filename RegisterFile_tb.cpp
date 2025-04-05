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
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    dut->clk = 1;
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
    write_reg(dut, 5, 0x12345678);
    write_reg(dut, 10, 0x87654321);
    write_reg(dut, 15, 0xA5A5A5A5);
    write_reg(dut, 31, 0xFFFFFFFF);

    tick(dut);

    std::cout << "Verifying reads...\n";
    auto [a, b] = read_regs(dut, 5, 10);
    std::cout << "R5:  0x" << std::hex << a << " (expected 0x12345678)\n";
    std::cout << "R10: 0x" << std::hex << b << " (expected 0x87654321)\n";
    assert(a == 0x12345678);
    assert(b == 0x87654321);

    tick(dut);

    auto [c, d] = read_regs(dut, 15, 31);
    std::cout << "R15: 0x" << std::hex << c << " (expected 0xA5A5A5A5)\n";
    std::cout << "R31: 0x" << std::hex << d << " (expected 0xFFFFFFFF)\n";
    assert(c == 0xA5A5A5A5);
    assert(d == 0xFFFFFFFF);

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

    std::cout << "Performing edge cases test (write to R0)...\n";
    write_reg(dut, 0, 0xDEADBEEF); // optional: R0 usually reserved
    auto [r0, _] = read_regs(dut, 0, 0);
    std::cout << "R0: 0x" << std::hex << r0 << " (expected 0xDEADBEEF)\n";
    assert(r0 == 0xDEADBEEF); // Unless R0 is hard-wired to 0, this should pass

    std::cout << "\n✅ All tests passed successfully.\n";

    // Cleanup
    tfp->close();
    delete tfp;
    delete dut;

    return 0;
}