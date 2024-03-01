
module barret_for_3607(
    input wire [22:0] din_a,
    output wire [11:0] dout_r
);
      
    wire [22:0] mu_constant = 4651;
    wire [22:0] q_val  = din_a >> 12;
    wire [22:0] q_hat  = q_val * mu_constant;
    wire [22:0] t_val  = q_hat >> 12;
    wire [22:0] mult   = t_val * 3607;
    wire [22:0] result = din_a - mult;
      
    assign dout_r = result >= 3607 ? result - 3607 : result;

endmodule
