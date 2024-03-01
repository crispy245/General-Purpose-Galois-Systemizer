#
# Copyright (C) 2016
# Authors: Wen Wang <wen.wang.ww349@yale.edu>
#          Ruben Niederhagen <ruben@polycephaly.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

all: run

# L and K must be multiples of N for the test code
# N = 64
# L = 768
# K = 3488

N = 4
L = 16
K = 24

M ?= 2

BLOCK = $N

#SEED = 1
SEED = "random"
#SEED = 987017768506109152
#SEED = 6838570760048930442
#SEED = 9162491212290917210

SYS = --systemizable
#SYS = --not-systemizable


#SYSTEMIZER := single_pass_GFx
SYSTEMIZER := single_pass_GFp
#SYSTEMIZER := single_pass_GF2
#SYSTEMIZER := single_pass_GFx_abort
#SYSTEMIZER := single_pass_GF2_redo
#SYSTEMIZER := hybrid_early_abort
#SYSTEMIZER := single_pass_early_abort
#SYSTEMIZER := single_pass_early_abort_redo
#SYSTEMIZER := dual_pass_early_abort


GEN_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))/gen

COMMON_DIR := $(abspath $(dir $(abspath $(lastword $(MAKEFILE_LIST))))/../../)


include ../$(SYSTEMIZER)/gen.mk
include ../$(SYSTEMIZER)/sources.mk

#SOURCES += systemize_tb.v

.PHONY: only_tb
only_tb:
	iverilog -Wall -Wno-timescale -DN=$N -DL=$L -DK=$K -DM=$M -DBLOCK=$(BLOCK) $(SOURCES) systemize_tb.v -o systemize_tb

systemize_tb: $(SOURCES) systemize_tb.v
	iverilog -Wall -Wno-timescale -DN=$N -DL=$L -DK=$K -DM=$M -DBLOCK=$(BLOCK) $(SOURCES) systemize_tb.v -o systemize_tb


systemize_tb: $(SOURCES) systemize_tb.v
	iverilog -Wall -Wno-timescale -DN=$N -DL=$L -DK=$K -DM=$M -DBLOCK=$(BLOCK) $(SOURCES) systemize_tb.v -o systemize_tb

data.in:
	sage ./gen_test_general.sage -N $N -L $L -K $K --gf $M -s $(SEED) $(SYS) >> data.in

data.out: data.in systemize_tb
	./systemize_tb


run: data.out
	sage ./verify_test.sage -N $N -L $L -K $K --gf $M data.in data.out


clean:
	rm -rf gen/* systemize_tb data.in data.out gen_test.sage.py systemize_tb.vcd verify_test.sage.py *.vcd

