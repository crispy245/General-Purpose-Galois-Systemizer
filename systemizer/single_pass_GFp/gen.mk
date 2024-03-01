sysGFx_mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

$(GEN_DIR)/comb_SA.v: $(sysGFx_mkfile_path)/gen_comb_SA.py
	python $(sysGFx_mkfile_path)/gen_comb_SA.py -n $N -m $(M) -b $(BLOCK) --name comb_SA > $(GEN_DIR)/comb_SA.v

$(GEN_DIR)/gf_mad.v: $(COMMON_DIR)/galois_field/gen_mad_general.py
	python $(COMMON_DIR)/galois_field/gen_mad_general.py -gf $(M) > $(GEN_DIR)/gf_mad.v

$(GEN_DIR)/gf_inv.v: $(COMMON_DIR)/galois_field/gen_inv_general.sage
	sage $(COMMON_DIR)/galois_field/gen_inv_general.sage -gf $(M) > $(GEN_DIR)/gf_inv.v

$(GEN_DIR)/gf_barret.v: $(COMMON_DIR)/galois_field/gen_barret.py
	python $(COMMON_DIR)/galois_field/gen_barret.py -gf $(M) > $(GEN_DIR)/gf_barret.v