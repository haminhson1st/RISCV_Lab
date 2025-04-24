module ForwardingUnit
  (
    input [4:0] ID_EX_Rs1, //ID/EX.RegisterRs1
    input [4:0] ID_EX_Rs2, //ID/EX.RegisterRs2
    input [4:0] EX_MEM_Rd, //EX/MEM.Register Rd
    input [4:0] MEM_WB_Rd, //MEM/WB.RegisterRd
    
    input MEM_WB_regWrite, //MEM/WB.RegWrite
    input EX_MEM_regWrite, // EX/MEM.RegWrite
    output reg [1:0] Forward_A,
    output reg [1:0] Forward_B
 );
  
  always @(*)
    begin
        // Condition for EX hazard
    	if (EX_MEM_regWrite && (EX_MEM_Rd != 0) && (EX_MEM_Rd == ID_EX_Rs1))
        begin
          Forward_A = 2'b10;
        end
      else
        begin 
          //  Condition for MEM hazard 
          if (MEM_WB_regWrite && (MEM_WB_Rd != 0) && (MEM_WB_Rd == ID_EX_Rs1))
            begin
              Forward_A = 2'b01;
            end
          else
            begin
              Forward_A = 2'b00;
            end
        end
      
        // Condition for EX hazard
    	if (EX_MEM_regWrite && (EX_MEM_Rd != 0) && (EX_MEM_Rd == ID_EX_Rs2))
        begin
          Forward_B = 2'b10;
        end
      else
        begin 
          //  Condition for MEM hazard 
          if (MEM_WB_regWrite && (MEM_WB_Rd != 0) && (MEM_WB_Rd == ID_EX_Rs2))
            begin
              Forward_B = 2'b01;
            end
          else
            begin
              Forward_B = 2'b00;
            end
        end
    end
endmodule