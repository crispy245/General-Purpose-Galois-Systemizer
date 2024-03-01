
module barret_for_1181(
    input wire [20:0] din_a,
    output wire [10:0] dout_r
);
      
    wire [20:0] mu_constant = 3551;
    wire [20:0] q_val  = din_a >> 11;
    wire [20:0] q_hat  = q_val * mu_constant;
    wire [20:0] t_val  = q_hat >> 11;
    wire [20:0] mult   = t_val * 1181;
    wire [20:0] result = din_a - mult;
      
    assign dout_r = result >= 1181 ? result - 1181 : result;

endmodule
