
module barret_for_17(
    input wire [8:0] din_a,
    output wire [4:0] dout_r
);
      
    wire [8:0] mu_constant = 60;
    wire [8:0] q_val  = din_a >> 5;
    wire [8:0] q_hat  = q_val * mu_constant;
    wire [8:0] t_val  = q_hat >> 5;
    wire [8:0] mult   = t_val * 17;
    wire [8:0] result = din_a - mult;
      
    assign dout_r = result >= 17 ? result - 17 : result;

endmodule
