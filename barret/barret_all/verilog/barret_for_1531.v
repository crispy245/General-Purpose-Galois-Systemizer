
module barret_for_1531(
    input wire [20:0] din_a,
    output wire [10:0] dout_r
);
      
    wire [20:0] mu_constant = 2739;
    wire [20:0] q_val  = din_a >> 11;
    wire [20:0] q_hat  = q_val * mu_constant;
    wire [20:0] t_val  = q_hat >> 11;
    wire [20:0] mult   = t_val * 1531;
    wire [20:0] result = din_a - mult;
      
    assign dout_r = result >= 1531 ? result - 1531 : result;

endmodule
