
module barret_for_419(
    input wire [16:0] din_a,
    output wire [8:0] dout_r
);
      
    wire [16:0] mu_constant = 625;
    wire [16:0] q_val  = din_a >> 9;
    wire [16:0] q_hat  = q_val * mu_constant;
    wire [16:0] t_val  = q_hat >> 9;
    wire [16:0] mult   = t_val * 419;
    wire [16:0] result = din_a - mult;
      
    assign dout_r = result >= 419 ? result - 419 : result;

endmodule
