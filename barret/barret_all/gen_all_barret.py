
from math import sqrt, ceil, log2, floor

def isPrime(n):
    for i in range(2, int(sqrt(n))+1):
        if (n % i == 0):
            return False
    return True

all_primes = []
for i in range (3,4094):
    if(isPrime(i)):
        all_primes.append(i)


#write module
for prime in all_primes:
    log2_field = ceil(log2(prime))
    k = log2_field
    mu_constant = floor(pow(2,2*k)/prime)
    file_name = "verilog/barret_for_{0}.v".format(prime)
    f = open(file_name,"x")
    f.write("""
module barret_for_{4}(
    input wire [{0}:0] din_a,
    output wire [{1}:0] dout_r
);
      
    wire [{0}:0] mu_constant = {2};
    wire [{0}:0] q_val  = din_a >> {3};
    wire [{0}:0] q_hat  = q_val * mu_constant;
    wire [{0}:0] t_val  = q_hat >> {3};
    wire [{0}:0] mult   = t_val * {4};
    wire [{0}:0] result = din_a - mult;
      
    assign dout_r = result >= {4} ? result - {4} : result;

endmodule
""".format((log2_field-1)*2,log2_field-1, mu_constant,k,prime))
    f.close()


#write testbench
for prime in all_primes:
    log2_field = ceil(log2(prime))
    k = log2_field
    mu_constant = floor(pow(2,2*k)/prime)
    file_name = "verilog/barret_for_{0}_tb.v".format(prime)
    f = open(file_name,"x") 
    f.write("""

`timescale 1ns / 1ps
module barret_for_{0}_tb;
    reg clk = 0; // Initialize clk
    reg[{1}:0] data_in;
    wire[{2}:0] data_out; // Changed from reg to wire since it's an output from the instantiated module
    
    // Corrected module instantiation with commas
    barret_for_{0} barret_inst (

        .din_a(data_in),
        .dout_r(data_out)
    );
    
    integer i;
    integer fd;
    
    initial begin
        fd = $fopen("result_prime_{0}.out", "w"); // Open file at the beginning of the simulation
        for(i = 0; i < {0}; i = i + 1) begin
            @(negedge clk); // Wait for negedge clk
            data_in = i;
            #10; // Wait for some time after updating input
            
            // Corrected $fwrite statements
            if(data_out == i % {0}) 
            begin
                $fwrite(fd, "EQUAL FOR %d mod {0}\\n", data_in);
            end 
            else 
            begin
                $fwrite(fd, "ERROR FOR %d mod {0}\\n", data_in);
            end
        end
        
        $fclose(fd); // Close the file
        $finish; // End the simulation
    end
    
    // Clock generation
    always #5 clk = !clk;
            
endmodule

""".format(prime, (log2_field-1)*2,log2_field-1))
    f.close()