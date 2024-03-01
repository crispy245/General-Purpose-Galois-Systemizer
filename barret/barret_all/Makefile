VERILOG_DIR := ./verilog
VVP_DIR := ./vvp
OUT_DIR := ./out
IVFLAGS := -Wall

VERILOG_FILES := $(filter-out $(wildcard $(VERILOG_DIR)/*_tb.v), $(wildcard $(VERILOG_DIR)/*.v))

TESTBENCH_FILES := $(wildcard $(VERILOG_DIR)/*_tb.v)

VERILOG_MODULES := $(notdir $(VERILOG_FILES))
TESTBENCH_MODULES := $(notdir $(TESTBENCH_FILES))

VERILOG_VVP_FILES := $(addprefix $(VVP_DIR)/, $(VERILOG_MODULES:%.v=%.vvp))
VERILOG_OUT_FILES := $(addprefix $(OUT_DIR)/, $(VERILOG_MODULES:%.v=%.out))

TESTBENCH_VVP_FILES := $(addprefix $(VVP_DIR)/, $(TESTBENCH_MODULES:%.v=%.vvp))
TESTBENCH_OUT_FILES := $(addprefix $(OUT_DIR)/, $(TESTBENCH_MODULES:%.v=%.out))

$(VVP_DIR)/%.vvp: $(VERILOG_DIR)/%.v
	iverilog $(IVFLAGS) -o $@ $^

$(VVP_DIR)/%_tb.vvp: $(VERILOG_DIR)/%_tb.v $(VERILOG_DIR)/%.v
	iverilog $(IVFLAGS) -o $@ $^

.PHONY: sim
sim: $(VERILOG_OUT_FILES) $(TESTBENCH_OUT_FILES)

$(OUT_DIR)/%.out: $(VVP_DIR)/%.vvp
	vvp $< > $@

$(OUT_DIR)/%_tb.out: $(VVP_DIR)/%_tb.vvp
	vvp $< > $@

all: make_dirs verilog sim

make_dirs: 
	@mkdir -p $(VERILOG_DIR) $(VVP_DIR) $(OUT_DIR)

verilog: 
	python python_gen_all_barret.py

clean:
	rm -rf $(VVP_DIR) $(OUT_DIR) *.out 
