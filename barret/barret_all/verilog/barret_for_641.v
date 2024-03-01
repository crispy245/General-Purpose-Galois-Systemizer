
module barret_for_641(
    input wire [18:0] din_a,
    output wire [9:0] dout_r
);
      
    wire [18:0] mu_constant = 1635;
    wire [18:0] q_val  = din_a >> 10;
    wire [18:0] q_hat  = q_val * mu_constant;
    wire [18:0] t_val  = q_hat >> 10;
    wire [18:0] mult   = t_val * 641;
    wire [18:0] result = din_a - mult;
      
    assign dout_r = result >= 641 ? result - 641 : result;

endmodule
