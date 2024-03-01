

`timescale 1ns / 1ps
module barret_for_3221_tb;
    reg clk = 0; // Initialize clk
    reg[22:0] data_in;
    wire[11:0] data_out; // Changed from reg to wire since it's an output from the instantiated module
    
    // Corrected module instantiation with commas
    barret_for_3221 barret_inst (

        .din_a(data_in),
        .dout_r(data_out)
    );
    
    integer i;
    integer fd;
    
    initial begin
        fd = $fopen("result_prime_3221.out", "w"); // Open file at the beginning of the simulation
        for(i = 0; i < 3221; i = i + 1) begin
            @(negedge clk); // Wait for negedge clk
            data_in = i;
            #10; // Wait for some time after updating input
            
            // Corrected $fwrite statements
            if(data_out == i % 3221) 
            begin
                $fwrite(fd, "EQUAL FOR %d mod 3221\n", data_in);
            end 
            else 
            begin
                $fwrite(fd, "ERROR FOR %d mod 3221\n", data_in);
            end
        end
        
        $fclose(fd); // Close the file
        $finish; // End the simulation
    end
    
    // Clock generation
    always #5 clk = !clk;
            
endmodule

