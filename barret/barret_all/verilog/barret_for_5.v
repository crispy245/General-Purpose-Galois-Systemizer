
module barret_for_5(
    input wire [4:0] din_a,
    output wire [2:0] dout_r
);
      
    wire [4:0] mu_constant = 12;
    wire [4:0] q_val  = din_a >> 3;
    wire [4:0] q_hat  = q_val * mu_constant;
    wire [4:0] t_val  = q_hat >> 3;
    wire [4:0] mult   = t_val * 5;
    wire [4:0] result = din_a - mult;
      
    assign dout_r = result >= 5 ? result - 5 : result;

endmodule
