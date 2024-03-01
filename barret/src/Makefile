
TOP = barret
GTKWAVE = gtkwave

V_SRC += $(wildcard ./*.v)
INC = -I./include/clog2.v
TESTBENCH_SRC = ./testbench.cpp
VTOP = ./barret.v 

WARN = -Wno-WIDTH

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Vbarret

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

.stamp.verilate: ${V_SRC} ${TESTBENCH_SRC}
	@echo
	@echo "### VERILATING ###"
	verilator ${WARN} --cc --exe --build --trace ${TESTBENCH_SRC} ${INC} ${V_SRC} 
	@touch .stamp.verilate

.PHONY:lint
lint: ${V_SRC}
	verilator --lint-only -Wno-WIDTH ${V_SRC} ${INC}

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
