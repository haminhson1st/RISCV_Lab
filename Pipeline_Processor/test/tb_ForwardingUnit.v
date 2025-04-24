`timescale 1ns/1ps

module tb_ForwardingUnit;

  // Inputs
  reg [4:0] ID_EX_Rs1;
  reg [4:0] ID_EX_Rs2;
  reg [4:0] EX_MEM_Rd;
  reg [4:0] MEM_WB_Rd;
  reg EX_MEM_regWrite;
  reg MEM_WB_regWrite;

  // Outputs
  wire [1:0] Forward_A;
  wire [1:0] Forward_B;

  // Instantiate the Unit Under Test (UUT)
  ForwardingUnit uut (
    .ID_EX_Rs1(ID_EX_Rs1),
    .ID_EX_Rs2(ID_EX_Rs2),
    .EX_MEM_Rd(EX_MEM_Rd),
    .MEM_WB_Rd(MEM_WB_Rd),
    .EX_MEM_regWrite(EX_MEM_regWrite),
    .MEM_WB_regWrite(MEM_WB_regWrite),
    .Forward_A(Forward_A),
    .Forward_B(Forward_B)
  );

  // Task to display result
  task display_result;
    input [1:0] expected_A;
    input [1:0] expected_B;
    begin
      $display("Time: %0t | Forward_A = %b (expected %b), Forward_B = %b (expected %b)",
               $time, Forward_A, expected_A, Forward_B, expected_B);
      if (Forward_A !== expected_A || Forward_B !== expected_B) begin
        $display("❌ Test FAILED");
      end else begin
        $display("✅ Test PASSED");
      end
      $display("-------------------------------------------------");
    end
  endtask

  initial begin
    $dumpfile("obj/ForwardingUnit/wave.vcd");
    $dumpvars(0, tb_ForwardingUnit);
    $display("===== Forwarding Unit Testbench =====");

    // Test 1: No hazard
    ID_EX_Rs1 = 5'd1; ID_EX_Rs2 = 5'd2;
    EX_MEM_Rd = 5'd3; MEM_WB_Rd = 5'd4;
    EX_MEM_regWrite = 1'b1; MEM_WB_regWrite = 1'b1;
    #10 display_result(2'b00, 2'b00);

    // Test 2: EX hazard on Rs1
    ID_EX_Rs1 = 5'd5; ID_EX_Rs2 = 5'd6;
    EX_MEM_Rd = 5'd5; MEM_WB_Rd = 5'd0;
    EX_MEM_regWrite = 1'b1; MEM_WB_regWrite = 1'b0;
    #10 display_result(2'b10, 2'b00);

    // Test 3: MEM hazard on Rs2
    ID_EX_Rs1 = 5'd0; ID_EX_Rs2 = 5'd8;
    EX_MEM_Rd = 5'd7; MEM_WB_Rd = 5'd8;
    EX_MEM_regWrite = 1'b0; MEM_WB_regWrite = 1'b1;
    #10 display_result(2'b00, 2'b01);

    // Test 4: EX hazards on both Rs1 and Rs2
    ID_EX_Rs1 = 5'd9; ID_EX_Rs2 = 5'd9;
    EX_MEM_Rd = 5'd9; MEM_WB_Rd = 5'd10; 
    EX_MEM_regWrite = 1'b1; MEM_WB_regWrite = 1'b1;
    #10 display_result(2'b10, 2'b10);

    // Test 5: MEM hazard on Rs1, EX hazard on Rs2
    ID_EX_Rs1 = 5'd11; ID_EX_Rs2 = 5'd12;
    EX_MEM_Rd = 5'd12; MEM_WB_Rd = 5'd11;
    EX_MEM_regWrite = 1'b1; MEM_WB_regWrite = 1'b1;
    #10 display_result(2'b01, 2'b10);

    // Test 6: MEM hazard on both Rs1 and Rs2
    ID_EX_Rs1 = 5'd11; ID_EX_Rs2 = 5'd11;
    EX_MEM_Rd = 5'd12; MEM_WB_Rd = 5'd11;
    EX_MEM_regWrite = 1'b1; MEM_WB_regWrite = 1'b1;
    #10 display_result(2'b01, 2'b01);

    $display("===== All tests completed =====");
    $finish;
  end

endmodule
