set parameters {
    {N.arg "4"    ""}
    {L.arg "16"   ""}
    {K.arg "20"   ""}
    {SRC.arg ""   ""}
    {SYS.arg ""   ""}
}
puts $argv
if {[catch {array set options [cmdline::getoptions ::argv $parameters]}]} {
    puts [cmdline::usage $parameters $usage]
} else {
    parray options
}
puts [array get options]

set N $options(N)
set L $options(L)
set K $options(K)
set systemizer $options(SYS)

# STEP#0: define output directory area.
#
#set outputDir ./$systemizer-$N-$L-$K-mem_quad
#set outputDir ./$systemizer-$N-$L-$K-pivot_cyc_mem
set outputDir ./$systemizer-$N-$L-$K
file mkdir $outputDir

#
# STEP#1: setup design sources and constraints
#

foreach fname [split $options(SRC)] {
  puts $fname
  read_verilog $fname
}

read_xdc systemizer.xdc

#
# STEP#2: run synthesis, report utilization and timing estimates, write checkpoint design
#
#synth_design -top mem_quad -mode out_of_context -generic N=$N -generic L=$L -generic K=$K -part xc7a100tcsg324-1
#synth_design -top pivot_cyc_mem -mode out_of_context -generic N=$N -generic L=$L -generic K=$K -part xc7a100tcsg324-1
synth_design -top systemizer -flatten_hierarchy none -generic N=$N -generic L=$L -generic K=$K -part xc7a100tcsg324-1
#synth_design -top systemizer -generic N=$N -generic L=$L -generic K=$K -part xc7a100tcsg324-1
write_checkpoint -force $outputDir/post_synth
report_timing_summary -file $outputDir/post_synth_timing_summary.rpt
report_power -file $outputDir/post_synth_power.rpt

#
# STEP#3: run placement and logic optimzation, report utilization and timing estimates, write checkpoint design
#
opt_design
place_design
phys_opt_design
write_checkpoint -force $outputDir/post_place
report_timing_summary -file $outputDir/post_place_timing_summary.rpt

#
# STEP#4: run router, report actual utilization and timing, write checkpoint design, run drc, write verilog and xdc out
#
route_design
write_checkpoint -force $outputDir/post_route
report_timing_summary -file $outputDir/post_route_timing_summary.rpt
report_timing -sort_by group -max_paths 100 -path_type summary -file $outputDir/post_route_timing.rpt
report_clock_utilization -file $outputDir/clock_util.rpt
report_utilization -file $outputDir/post_route_util.rpt
report_utilization -hierarchical -file $outputDir/post_route_util_hierarch.rpt
report_power -file $outputDir/post_route_power.rpt
report_drc -file $outputDir/post_imp_drc.rpt
write_verilog -force $outputDir/systemizer_impl_netlist.v
write_xdc -no_fixed_only -force $outputDir/systemizer_impl.xdc

#
# STEP#5: generate a bitstream
# 
# write_bitstream -force $outputDir/systemizer.bit

quit

