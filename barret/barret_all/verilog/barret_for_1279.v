
module barret_for_1279(
    input wire [20:0] din_a,
    output wire [10:0] dout_r
);
      
    wire [20:0] mu_constant = 3279;
    wire [20:0] q_val  = din_a >> 11;
    wire [20:0] q_hat  = q_val * mu_constant;
    wire [20:0] t_val  = q_hat >> 11;
    wire [20:0] mult   = t_val * 1279;
    wire [20:0] result = din_a - mult;
      
    assign dout_r = result >= 1279 ? result - 1279 : result;

endmodule
