
module barret_for_3967(
    input wire [22:0] din_a,
    output wire [11:0] dout_r
);
      
    wire [22:0] mu_constant = 4229;
    wire [22:0] q_val  = din_a >> 12;
    wire [22:0] q_hat  = q_val * mu_constant;
    wire [22:0] t_val  = q_hat >> 12;
    wire [22:0] mult   = t_val * 3967;
    wire [22:0] result = din_a - mult;
      
    assign dout_r = result >= 3967 ? result - 3967 : result;

endmodule
