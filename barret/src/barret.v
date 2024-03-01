//Made by: Aldo Balsamo

//Barret Reduction for prime finite fields
//k = 2
 /*

    Calculate q=⌊x/2k⌋.
    Calculate q′=q⋅μ.
    Calculate q′′=⌊q′/2k⌋.
    Compute r=x−q′′⋅m

*/

//Input: Positive integers x < 2^2k , 2^k−1 < q < 2^k
//<------------------------TEST: WORKING WITH GF(3)---------------------->
module barret(
    input clk,
    input wire [3:0] din_a,
    //the operation coming to din_a is a result of addition, substraction or multiplication
    //therefore it can be as large as log_2(a*b) = log_2(a) + log_2(b)
    input wire [3:0]din_m, //temporal, might set it on stone and just modify it
    //when generating the code
    output wire [1:0] dout_r//result must be at most 2 bit long
);

//μ value because depends only on m and not on x. 
//Since μ=⌊2^2k/m​⌋, it remains constant as long as 
//m does not change. important 
//This precalculation significantly speeds up the reduction process.

wire [3:0] mu_constant = 5; //⌊2^2k/m​⌋ where m is 3 and k is 2 
wire [3:0] q_val;
assign q_val = din_a >> 2; //⌊din_a/2^k​⌋ since our divisor is
                             //a power of two we can just shift right

wire[3:0] q_hat;
assign q_hat = q_val * mu_constant;

wire [3:0] t_val;
assign t_val = q_hat >> 2;//⌊q_hat/2^k​⌋

wire[3:0] mult;
assign mult = t_val * din_m;
wire[3:0] result;
assign result = din_a - mult;

wire[3:0] test; 

assign test = din_a - (((q_val*mu_constant) >> 2) * din_m);

assign dout_r = test >= din_m ? test - 3 : test;


endmodule