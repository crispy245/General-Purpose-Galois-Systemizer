sysGFx_mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

SOURCES += $(COMMON_DIR)/clog2.v \
           $(COMMON_DIR)/memory/mem_dual.v \
           $(COMMON_DIR)/memory/mem.v \
           $(sysGFx_mkfile_path)/systemizer.v \
           $(sysGFx_mkfile_path)/phase.v \
           $(sysGFx_mkfile_path)/pivot_cyc_mem.v \
           $(sysGFx_mkfile_path)/processor_AB.v \
           $(sysGFx_mkfile_path)/processor_B.v \
           $(sysGFx_mkfile_path)/mem_quad.v \
           $(GEN_DIR)/comb_SA.v

