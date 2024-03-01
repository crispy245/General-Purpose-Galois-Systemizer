
module barret_for_1399(
    input wire [20:0] din_a,
    output wire [10:0] dout_r
);
      
    wire [20:0] mu_constant = 2998;
    wire [20:0] q_val  = din_a >> 11;
    wire [20:0] q_hat  = q_val * mu_constant;
    wire [20:0] t_val  = q_hat >> 11;
    wire [20:0] mult   = t_val * 1399;
    wire [20:0] result = din_a - mult;
      
    assign dout_r = result >= 1399 ? result - 1399 : result;

endmodule
