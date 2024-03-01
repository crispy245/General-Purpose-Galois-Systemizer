
  module GFE_mad (
  input          clk,
  input  [1: 0] dinA,
  input  [1: 0] dinB,
  input  [1: 0] dinC,
  output [2: 0] dout
);

  assign dout = dinA * dinB + dinC; 
  
endmodule 
