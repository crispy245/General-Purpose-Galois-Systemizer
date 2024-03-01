
#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vbarret.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;



Vbarret *dut = new Vbarret;
VerilatedVcdC *m_trace = new VerilatedVcdC;
void full_clk(){
    dut->clk ^= 1;
    dut->eval();
    m_trace->dump(sim_time);
    sim_time++;
    dut->clk ^= 1;
    dut->eval();
    m_trace->dump(sim_time);
    sim_time++;
}

int main(int argc, char** argv, char** env) {

    Verilated::traceEverOn(true);
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");
    int mod = 3;
    dut->din_m = mod;
    for(int i = 0; i < 15; i++){
        dut->din_a = i;
        full_clk();
        if(i % mod == (int)dut->dout_r){
            std::cout<<"EQUAL : "<<i<<" % "<< mod << "|" << (int)dut->dout_r<<std::endl;
        }
        else{
            std::cout<<"ERROR : "<<i<<" % "<< mod << "|" << (int)dut->dout_r<<std::endl;
        }
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
