
module barret_for_463(
    input wire [16:0] din_a,
    output wire [8:0] dout_r
);
      
    wire [16:0] mu_constant = 566;
    wire [16:0] q_val  = din_a >> 9;
    wire [16:0] q_hat  = q_val * mu_constant;
    wire [16:0] t_val  = q_hat >> 9;
    wire [16:0] mult   = t_val * 463;
    wire [16:0] result = din_a - mult;
      
    assign dout_r = result >= 463 ? result - 463 : result;

endmodule
