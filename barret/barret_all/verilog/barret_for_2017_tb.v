

`timescale 1ns / 1ps
module barret_for_2017_tb;
    reg clk = 0; // Initialize clk
    reg[20:0] data_in;
    wire[10:0] data_out; // Changed from reg to wire since it's an output from the instantiated module
    
    // Corrected module instantiation with commas
    barret_for_2017 barret_inst (

        .din_a(data_in),
        .dout_r(data_out)
    );
    
    integer i;
    integer fd;
    
    initial begin
        fd = $fopen("result_prime_2017.out", "w"); // Open file at the beginning of the simulation
        for(i = 0; i < 2017; i = i + 1) begin
            @(negedge clk); // Wait for negedge clk
            data_in = i;
            #10; // Wait for some time after updating input
            
            // Corrected $fwrite statements
            if(data_out == i % 2017) 
            begin
                $fwrite(fd, "EQUAL FOR %d mod 2017\n", data_in);
            end 
            else 
            begin
                $fwrite(fd, "ERROR FOR %d mod 2017\n", data_in);
            end
        end
        
        $fclose(fd); // Close the file
        $finish; // End the simulation
    end
    
    // Clock generation
    always #5 clk = !clk;
            
endmodule

