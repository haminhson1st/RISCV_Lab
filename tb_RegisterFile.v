`timescale 1ns/1ps
`include "RegisterFile.v"


module tb_RegisterFile;

    // DUT signals
    reg clk = 1;
    reg reset = 1;
    reg reg_write = 0;
    reg [4:0] addrA = 0, addrB = 0, addrD = 0;
    reg [31:0] dataD = 0;
    wire [31:0] dataA, dataB;

    // Instantiate the DUT
    RegisterFile dut (
        .clk(clk),
        .reset(reset),
        .reg_write(reg_write),
        .addrA(addrA),
        .addrB(addrB),
        .addrD(addrD),
        .dataD(dataD),
        .dataA(dataA),
        .dataB(dataB)
    );

    // Clock generation
    always #5 clk = ~clk;

    // Task to write to a register
    task write_reg(input [4:0] addr, input [31:0] val);
    begin
        addrD = addr;
        dataD = val;
        reg_write = 1;
        @(posedge clk);
        reg_write = 0;
    end
    endtask

    // Task to read from two registers
    task read_regs(input [4:0] addr1, input [4:0] addr2, output [31:0] out1, output [31:0] out2);
    begin
        addrA = addr1;
        addrB = addr2;
        #1; // small delay for combinational logic to settle
        out1 = dataA;
        out2 = dataB;
    end
    endtask

    integer i;
    reg [31:0] outA, outB;

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_RegisterFile);

        $display("Applying reset...");
        reset = 0;
        @(posedge clk); @(posedge clk);
        reset = 1;
        @(posedge clk);

        $display("Testing register writes...");
        for (i = 1; i < 32; i = i + 1) begin
            write_reg(i, 32'h11111111 + i);
        end

        @(posedge clk);

        $display("Verifying reads...");
        for (i = 1; i < 32; i = i + 1) begin
            read_regs(i, ((i + 1) % 32), outA, outB);
            $display("R%0d: 0x%08x (expected 0x%08x)", i, outA, 32'h11111111 + i);
            if (outA !== (32'h11111111 + i)) begin
                $display("❌ Test failed at R%0d", i);
                $finish;
            end
            @(posedge clk);
        end

        $display("Re-applying reset...");
        reset = 0;
        @(posedge clk);
        reset = 1;
        @(posedge clk);

        read_regs(5, 10, outA, outB);
        $display("After reset - R5: 0x%08x, R10: 0x%08x", outA, outB);
        if (outA !== 32'h0 || outB !== 32'h0) begin
            $display("❌ Reset failed!");
            $finish;
        end

        $display("Performing edge cases test (write to R0)...");
        write_reg(0, 32'hDEADBEEF);
        @(posedge clk);
        read_regs(0, 0, outA, outB);
        @(posedge clk);
        $display("R0: 0x%08x (expected 0x00000000)", outA);
        if (outA !== 32'h0) begin
            $display("❌ R0 write protection failed!");
            $finish;
        end

        $display("\n✅ All tests passed successfully.");
        $finish;
    end

endmodule
// RegisterFile module for reference