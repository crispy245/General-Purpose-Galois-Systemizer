
module barret_for_241(
    input wire [14:0] din_a,
    output wire [7:0] dout_r
);
      
    wire [14:0] mu_constant = 271;
    wire [14:0] q_val  = din_a >> 8;
    wire [14:0] q_hat  = q_val * mu_constant;
    wire [14:0] t_val  = q_hat >> 8;
    wire [14:0] mult   = t_val * 241;
    wire [14:0] result = din_a - mult;
      
    assign dout_r = result >= 241 ? result - 241 : result;

endmodule
