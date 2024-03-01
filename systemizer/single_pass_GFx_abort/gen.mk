sysGFxabort_mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

$(GEN_DIR)/comb_SA.v: $(sysGFxabort_mkfile_path)/gen_comb_SA.py
	python $(sysGFxabort_mkfile_path)/gen_comb_SA.py -n $N -m $(M) -b $(BLOCK) --name comb_SA > $(GEN_DIR)/comb_SA.v

$(GEN_DIR)/gf_mad.v: $(COMMON_DIR)/galois_field/gen_mad.sage
	sage $(COMMON_DIR)/galois_field/gen_mad.sage -gf $(M) > $(GEN_DIR)/gf_mad.v

$(GEN_DIR)/gf_inv.v: $(COMMON_DIR)/galois_field/gen_inv.sage
	sage $(COMMON_DIR)/galois_field/gen_inv.sage -gf $(M) > $(GEN_DIR)/gf_inv.v

