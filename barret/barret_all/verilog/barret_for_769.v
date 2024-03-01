
module barret_for_769(
    input wire [18:0] din_a,
    output wire [9:0] dout_r
);
      
    wire [18:0] mu_constant = 1363;
    wire [18:0] q_val  = din_a >> 10;
    wire [18:0] q_hat  = q_val * mu_constant;
    wire [18:0] t_val  = q_hat >> 10;
    wire [18:0] mult   = t_val * 769;
    wire [18:0] result = din_a - mult;
      
    assign dout_r = result >= 769 ? result - 769 : result;

endmodule
