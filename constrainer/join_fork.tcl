####Constraints que van siempre####
set_size_only -all_instances [find -hier cell C300R30440]
set_size_only -all_instances [find -hier cell C300R30441]
set_size_only -all_instances [find -hier cell C300R30442]
set_size_only -all_instances [find -hier cell C300R30443]
set_size_only -all_instances [find -hier cell C300R30444]
set_size_only -all_instances [find -hier cell C300R30445]
set_size_only -all_instances [find -hier cell C300R30446]
set_size_only -all_instances [find -hier cell C300R30447]
set_disable_timing -from A2 -to Y [find -hier cell C300R30440]
set_disable_timing -from B1 -to Y [find -hier cell C300R30440]
set_disable_timing -from A1 -to Y [find -hier cell C300R30442]
set_disable_timing -from A2 -to Y [find -hier cell C300R30442]
set_disable_timing -from B0 -to Y [find -hier cell C300R30442]
set_disable_timing -from B1 -to Y [find -hier cell C300R30442]


####Constraints que dependen de R2R####
##Constraints for c ##
#Constraints for c to itself#
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcc/C300R30442/B1
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcc/C300R30444/B
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/lcc/C300R30440/B1
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/lcc/C300R30444/A
set_max_delay 0.500 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30442/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30442/A2

#Constraints for c to their latchs#
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/regc/LATCH*/G

#Constraints for c to a#
set_max_delay 0.500 -from join_fork/regc/LATCH*/Q -to join_fork/rega/LATCH*/D

set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lca/C300R30442/A0
set_min_delay 0.150 -from join_fork/lcc/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_min_delay 0.150 -from join_fork/lcc/C300R30442/A0 -to join_fork/lca/C300R30442/A0


##Constraints for c ##
#Constraints for c to itself#
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcc/C300R30442/B1
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcc/C300R30444/B
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/lcc/C300R30440/B1
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/lcc/C300R30444/A
set_max_delay 0.500 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30442/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/A -to join_fork/lcc/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcc/C300R30444/B -to join_fork/lcc/C300R30442/A2

#Constraints for c to their latchs#
set_max_delay 0.500 -from join_fork/lcc/C300R30440/A0 -to join_fork/regc/LATCH*/G

#Constraints for c to b#
set_max_delay 0.500 -from join_fork/regc/LATCH*/Q -to join_fork/regb/LATCH*/D

set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcb/C300R30440/A0
set_max_delay 0.500 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcb/C300R30442/A0
set_min_delay 0.150 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcb/C300R30440/A0
set_min_delay 0.150 -from join_fork/lcc/C300R30442/A0 -to join_fork/lcb/C300R30442/A0


##Constraints for d ##
#Constraints for d to itself#
set_max_delay 0.500 -from join_fork/lcd/C300R30442/A0 -to join_fork/lcd/C300R30442/B1
set_max_delay 0.500 -from join_fork/lcd/C300R30442/A0 -to join_fork/lcd/C300R30444/B
set_max_delay 0.500 -from join_fork/lcd/C300R30440/A0 -to join_fork/lcd/C300R30440/B1
set_max_delay 0.500 -from join_fork/lcd/C300R30440/A0 -to join_fork/lcd/C300R30444/A
set_max_delay 0.500 -from join_fork/lcd/C300R30444/A -to join_fork/lcd/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcd/C300R30444/A -to join_fork/lcd/C300R30442/A2
set_max_delay 0.500 -from join_fork/lcd/C300R30444/B -to join_fork/lcd/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcd/C300R30444/B -to join_fork/lcd/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcd/C300R30444/A -to join_fork/lcd/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcd/C300R30444/A -to join_fork/lcd/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcd/C300R30444/B -to join_fork/lcd/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcd/C300R30444/B -to join_fork/lcd/C300R30442/A2

#Constraints for d to their latchs#
set_max_delay 0.500 -from join_fork/lcd/C300R30440/A0 -to join_fork/regd/LATCH*/G

#Constraints for d to a#
set_max_delay 0.500 -from join_fork/regd/LATCH*/Q -to join_fork/rega/LATCH*/D

set_max_delay 0.500 -from join_fork/lcd/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_max_delay 0.500 -from join_fork/lcd/C300R30442/A0 -to join_fork/lca/C300R30442/A0
set_min_delay 0.150 -from join_fork/lcd/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_min_delay 0.150 -from join_fork/lcd/C300R30442/A0 -to join_fork/lca/C300R30442/A0


##Constraints for e ##
#Constraints for e to itself#
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lce/C300R30442/B1
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lce/C300R30444/B
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/lce/C300R30440/B1
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/lce/C300R30444/A
set_max_delay 0.500 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30440/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30442/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30440/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30442/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30440/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30442/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30440/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30442/A2

#Constraints for e to their latchs#
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/rege/LATCH*/G

#Constraints for e to a#
set_max_delay 0.500 -from join_fork/rege/LATCH*/Q -to join_fork/rega/LATCH*/D

set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lca/C300R30442/A0
set_min_delay 0.150 -from join_fork/lce/C300R30442/A0 -to join_fork/lca/C300R30440/A0
set_min_delay 0.150 -from join_fork/lce/C300R30442/A0 -to join_fork/lca/C300R30442/A0


##Constraints for e ##
#Constraints for e to itself#
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lce/C300R30442/B1
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lce/C300R30444/B
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/lce/C300R30440/B1
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/lce/C300R30444/A
set_max_delay 0.500 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30440/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30442/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30440/A2
set_max_delay 0.500 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30442/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30440/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/A -to join_fork/lce/C300R30442/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30440/A2
set_min_delay 0.150 -from join_fork/lce/C300R30444/B -to join_fork/lce/C300R30442/A2

#Constraints for e to their latchs#
set_max_delay 0.500 -from join_fork/lce/C300R30440/A0 -to join_fork/rege/LATCH*/G

#Constraints for e to b#
set_max_delay 0.500 -from join_fork/rege/LATCH*/Q -to join_fork/regb/LATCH*/D

set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lcb/C300R30440/A0
set_max_delay 0.500 -from join_fork/lce/C300R30442/A0 -to join_fork/lcb/C300R30442/A0
set_min_delay 0.150 -from join_fork/lce/C300R30442/A0 -to join_fork/lcb/C300R30440/A0
set_min_delay 0.150 -from join_fork/lce/C300R30442/A0 -to join_fork/lcb/C300R30442/A0


##Constraints for b ##
#Constraints for b to itself#
set_max_delay 0.500 -from join_fork/lcb/C300R30442/A0 -to join_fork/lcb/C300R30442/B1
set_max_delay 0.500 -from join_fork/lcb/C300R30442/A0 -to join_fork/lcb/C300R30444/B
set_max_delay 0.500 -from join_fork/lcb/C300R30440/A0 -to join_fork/lcb/C300R30440/B1
set_max_delay 0.500 -from join_fork/lcb/C300R30440/A0 -to join_fork/lcb/C300R30444/A
set_max_delay 0.500 -from join_fork/lcb/C300R30444/A -to join_fork/lcb/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcb/C300R30444/A -to join_fork/lcb/C300R30442/A2
set_max_delay 0.500 -from join_fork/lcb/C300R30444/B -to join_fork/lcb/C300R30440/A2
set_max_delay 0.500 -from join_fork/lcb/C300R30444/B -to join_fork/lcb/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcb/C300R30444/A -to join_fork/lcb/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcb/C300R30444/A -to join_fork/lcb/C300R30442/A2
set_min_delay 0.150 -from join_fork/lcb/C300R30444/B -to join_fork/lcb/C300R30440/A2
set_min_delay 0.150 -from join_fork/lcb/C300R30444/B -to join_fork/lcb/C300R30442/A2

#Constraints for b to their latchs#
set_max_delay 0.500 -from join_fork/lcb/C300R30440/A0 -to join_fork/regb/LATCH*/G

