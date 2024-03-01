
module barret_for_53(
    input wire [10:0] din_a,
    output wire [5:0] dout_r
);
      
    wire [10:0] mu_constant = 77;
    wire [10:0] q_val  = din_a >> 6;
    wire [10:0] q_hat  = q_val * mu_constant;
    wire [10:0] t_val  = q_hat >> 6;
    wire [10:0] mult   = t_val * 53;
    wire [10:0] result = din_a - mult;
      
    assign dout_r = result >= 53 ? result - 53 : result;

endmodule
