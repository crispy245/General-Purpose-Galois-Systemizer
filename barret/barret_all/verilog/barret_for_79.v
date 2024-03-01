
module barret_for_79(
    input wire [12:0] din_a,
    output wire [6:0] dout_r
);
      
    wire [12:0] mu_constant = 207;
    wire [12:0] q_val  = din_a >> 7;
    wire [12:0] q_hat  = q_val * mu_constant;
    wire [12:0] t_val  = q_hat >> 7;
    wire [12:0] mult   = t_val * 79;
    wire [12:0] result = din_a - mult;
      
    assign dout_r = result >= 79 ? result - 79 : result;

endmodule
