module GFE_inv (
  input wire        clk,
  input wire [1:0] din_A,
  output wire [1:0] dout_A,
  output wire dout_en_A,
  input wire [1:0] din_B,
  output wire [1:0] dout_B,
  output wire dout_en_B
);

parameter DELAY = -1;

generate
if (DELAY != 1) begin
    ERROR_module_parameter_DELAY_not_set_correctly_in_GF_INV ASSERT_ERROR();
end
endgenerate

reg [2:0] mem [0:2];

initial begin
  mem[0] = 3'b000;
  mem[1] = 3'b101;
  mem[2] = 3'b110;
end

reg [2:0] dout_A_tmp;

always @(posedge clk) 
begin
  dout_A_tmp <= mem[din_A];
end

assign dout_A = dout_A_tmp[1:0];
assign dout_en_A = dout_A_tmp[2];

reg [2:0] dout_B_tmp;

always @(posedge clk) 
begin
  dout_B_tmp <= mem[din_B];
end

assign dout_B = dout_B_tmp[1:0];
assign dout_en_B = dout_B_tmp[2];

endmodule

