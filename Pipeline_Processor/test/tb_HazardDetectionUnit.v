`timescale 1ns/1ps

module tb_HazardDetectionUnit;

  // Inputs
  reg ID_EX_Memread;
  reg [4:0] IF_ID_Rs1;
  reg [4:0] IF_ID_Rs2;
  reg [4:0] ID_EX_Rd;

  // Outputs
  wire control_unit_select;
  wire PC_Write;
  wire IF_ID_Write;

  // Instantiate the Unit Under Test (UUT)
  HazardDetectionUnit uut (
    .ID_EX_Memread(ID_EX_Memread),
    .IF_ID_Rs1(IF_ID_Rs1),
    .IF_ID_Rs2(IF_ID_Rs2),
    .ID_EX_Rd(ID_EX_Rd),
    .control_unit_select(control_unit_select),
    .PC_Write(PC_Write),
    .IF_ID_Write(IF_ID_Write)
  );

  // Task to display and check results
  task check_output;
    input expected_control_unit_select;
    input expected_PC_Write;
    input expected_IF_ID_Write;
    begin
      $display("Time %0t:", $time);
      $display("Inputs -> MemRead: %b, IF_ID_Rs1: %d, IF_ID_Rs2: %d, ID_EX_Rd: %d",
               ID_EX_Memread, IF_ID_Rs1, IF_ID_Rs2, ID_EX_Rd);
      $display("Outputs -> control_unit_select = %b (expected %b), PC_Write = %b (expected %b), IF_ID_Write = %b (expected %b)",
               control_unit_select, expected_control_unit_select,
               PC_Write, expected_PC_Write,
               IF_ID_Write, expected_IF_ID_Write);
      if ((control_unit_select !== expected_control_unit_select) ||
          (PC_Write !== expected_PC_Write) ||
          (IF_ID_Write !== expected_IF_ID_Write)) begin
        $display("❌ Test FAILED");
      end else begin
        $display("✅ Test PASSED");
      end
      $display("------------------------------------------------------");
    end
  endtask

  initial begin
    $dumpfile("obj/HazardDetectionUnit/wave.vcd");
    $dumpvars(0, tb_HazardDetectionUnit);
    $display("===== Hazard Detection Unit Testbench =====");

    // Test 1: No hazard (MemRead = 0)
    ID_EX_Memread = 0;
    IF_ID_Rs1 = 5'd1; IF_ID_Rs2 = 5'd2; ID_EX_Rd = 5'd3;
    #10 check_output(0, 1, 1);

    // Test 2: Hazard on Rs1
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd5; IF_ID_Rs2 = 5'd6; ID_EX_Rd = 5'd5;
    #10 check_output(1, 0, 0);

    // Test 3: Hazard on Rs2
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd4; IF_ID_Rs2 = 5'd7; ID_EX_Rd = 5'd7;
    #10 check_output(1, 0, 0);

    // Test 4: Hazard on both Rs1 and Rs2
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd10; IF_ID_Rs2 = 5'd10; ID_EX_Rd = 5'd10;
    #10 check_output(1, 0, 0);

    // Test 5: MemRead = 1, but no matching Rs1/Rs2
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd1; IF_ID_Rs2 = 5'd2; ID_EX_Rd = 5'd3;
    #10 check_output(0, 1, 1);

    // Test 6: Rd = 0 (x0) shouldn't trigger hazard even if Rs1/Rs2 match
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd0; IF_ID_Rs2 = 5'd0; ID_EX_Rd = 5'd0;
    #10 check_output(0, 1, 1);

    // Test 7: Rs1 == Rs2, but no match with ID_EX_Rd → no hazard
    ID_EX_Memread = 1;
    IF_ID_Rs1 = 5'd4;
    IF_ID_Rs2 = 5'd4;
    ID_EX_Rd = 5'd3;  // doesn't match Rs1/Rs2
    #10 check_output(0, 1, 1);

    $display("===== All tests completed =====");
    $finish;
  end

endmodule
