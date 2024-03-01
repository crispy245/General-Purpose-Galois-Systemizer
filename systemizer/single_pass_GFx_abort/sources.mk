sysGFxabort_mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

SOURCES += $(COMMON_DIR)/clog2.v \
           $(COMMON_DIR)/memory/mem.v \
           $(COMMON_DIR)/delay.v \
           $(sysGFxabort_mkfile_path)/systemizer.v \
           $(sysGFxabort_mkfile_path)/phase.v \
           $(sysGFxabort_mkfile_path)/step.v \
           $(sysGFxabort_mkfile_path)/processor_AB.v \
           $(sysGFxabort_mkfile_path)/processor_B.v \
           $(GEN_DIR)/comb_SA.v \
           $(GEN_DIR)/gf_mad.v \
           $(GEN_DIR)/gf_inv.v
