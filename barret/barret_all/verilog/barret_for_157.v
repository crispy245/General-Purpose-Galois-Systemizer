
module barret_for_157(
    input wire [14:0] din_a,
    output wire [7:0] dout_r
);
      
    wire [14:0] mu_constant = 417;
    wire [14:0] q_val  = din_a >> 8;
    wire [14:0] q_hat  = q_val * mu_constant;
    wire [14:0] t_val  = q_hat >> 8;
    wire [14:0] mult   = t_val * 157;
    wire [14:0] result = din_a - mult;
      
    assign dout_r = result >= 157 ? result - 157 : result;

endmodule
