
module barret_for_127(
    input wire [12:0] din_a,
    output wire [6:0] dout_r
);
      
    wire [12:0] mu_constant = 129;
    wire [12:0] q_val  = din_a >> 7;
    wire [12:0] q_hat  = q_val * mu_constant;
    wire [12:0] t_val  = q_hat >> 7;
    wire [12:0] mult   = t_val * 127;
    wire [12:0] result = din_a - mult;
      
    assign dout_r = result >= 127 ? result - 127 : result;

endmodule
