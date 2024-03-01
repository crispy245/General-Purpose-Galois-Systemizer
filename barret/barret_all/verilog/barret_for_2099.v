
module barret_for_2099(
    input wire [22:0] din_a,
    output wire [11:0] dout_r
);
      
    wire [22:0] mu_constant = 7992;
    wire [22:0] q_val  = din_a >> 12;
    wire [22:0] q_hat  = q_val * mu_constant;
    wire [22:0] t_val  = q_hat >> 12;
    wire [22:0] mult   = t_val * 2099;
    wire [22:0] result = din_a - mult;
      
    assign dout_r = result >= 2099 ? result - 2099 : result;

endmodule
