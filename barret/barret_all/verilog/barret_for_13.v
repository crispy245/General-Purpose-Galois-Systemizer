
module barret_for_13(
    input wire [6:0] din_a,
    output wire [3:0] dout_r
);
      
    wire [6:0] mu_constant = 19;
    wire [6:0] q_val  = din_a >> 4;
    wire [6:0] q_hat  = q_val * mu_constant;
    wire [6:0] t_val  = q_hat >> 4;
    wire [6:0] mult   = t_val * 13;
    wire [6:0] result = din_a - mult;
      
    assign dout_r = result >= 13 ? result - 13 : result;

endmodule
