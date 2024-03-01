
module barret_for_7(
    input wire [4:0] din_a,
    output wire [2:0] dout_r
);
      
    wire [4:0] mu_constant = 9;
    wire [4:0] q_val  = din_a >> 3;
    wire [4:0] q_hat  = q_val * mu_constant;
    wire [4:0] t_val  = q_hat >> 3;
    wire [4:0] mult   = t_val * 7;
    wire [4:0] result = din_a - mult;
      
    assign dout_r = result >= 7 ? result - 7 : result;

endmodule
