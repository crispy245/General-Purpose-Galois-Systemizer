import argparse

parser = argparse.ArgumentParser(description='Generate Makefile and testbench for verilator.',
                                 formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument('-n', '--name', dest='n', type=str, required=True, help='name of top module')
args = parser.parse_args()

makefile_template = """
TOP = {0}
GTKWAVE = gtkwave

V_SRC += $(wildcard ./*.v)
INC = -I./include/clog2.v
TESTBENCH_SRC = ./testbench.cpp
VTOP = ./{0}.v 

WARN = 

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/V{0}

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	$(GTKWAVE) waveform.vcd

waveform.vcd: ./obj_dir/V$(TOP)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(TOP)

./obj_dir/V$(TOP): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(TOP).mk V$(TOP)

.stamp.verilate: ${{V_SRC}} ${{TESTBENCH_SRC}}
	@echo
	@echo "### VERILATING ###"
	verilator ${{WARN}} --cc --exe --build --trace ${{TESTBENCH_SRC}} ${{INC}} ${{V_SRC}} 
	@touch .stamp.verilate

.PHONY:lint
lint: ${{V_SRC}}
\tverilator --lint-only -Wno-WIDTH ${{V_SRC}} ${{INC}}

.PHONY: clean
clean:
\trm -rf .stamp.*;
\trm -rf ./obj_dir
\trm -rf waveform.vcd
"""

testbench_template = """
#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "V{0}.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {{
    V{0} *dut = new V{0};

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {{
        dut->clk ^= 1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }}

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}}
"""

makefile_content = makefile_template.format(args.n)
testbench_content = testbench_template.format(args.n)

# Write makefile and testbench to files
with open('Makefile', 'w') as f_makefile:
    f_makefile.write(makefile_content)

with open('testbench.cpp', 'w') as f_testbench:
    f_testbench.write(testbench_content)