/*
 *
 * Public domain.
 *
 */
`timescale 1ns / 1ps

module mem_test;
  reg clk;

  reg  [3:0] data_in = 4'b0000;
  wire [3:0] data_out;

  reg  [3:0] rd_addr = 4'b0000;
  reg        rd_en   = 4'b0000;
  reg  [3:0] wr_addr = 4'b0000;
  reg        wr_en   = 4'b0000;
 
  mem DUT (
    .clock(clk),
    .data(data_in),
    .rdaddress(rd_addr),
    .rden(rd_en),
    .wraddress(wr_addr),
    .wren(wr_en),
    .q(data_out)
  );

  defparam DUT.WIDTH = 4;
  defparam DUT.DEPTH = 16;
  defparam DUT.FILE = "data.in";

  initial
   begin
      $dumpfile("mem_tb.vcd");
      $dumpvars(0,mem_test);
   end

  integer i;

  always
    begin
      # 100;

      wr_addr <= 4'b0001;

      data_in <= 4'b1111;

      wr_en <= 1'b1;

      #10;

      wr_en <= 1'b0;

      #20;

      rd_addr <= 4'b0010;
      rd_en <= 1'b1;

      #10;

      rd_en <= 1'b0;

      #10;

      $display("rd: %b", data_out);

      #50;

      for (i = 0; i < DUT.DEPTH; i = i + 1)
      begin
        $display("%b", DUT.mem[i]);
      end

      $finish;
    end

  always
    begin
      clk = 1'b1;
      #5;
      clk = 1'b0;
      #5;
    end
   
endmodule
