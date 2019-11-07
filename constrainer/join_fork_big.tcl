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
##Constraints for w ##
#Constraints for w to itself#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2

#Constraints for w to their latchs#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/regw/LATCH*/G

#Constraints for w to a#
set_max_delay 0.500 -from join_fork_big/regw/LATCH*/Q -to join_fork_big/rega/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lca/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lca/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lca/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lca/C300R30442/A0


##Constraints for w ##
#Constraints for w to itself#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2

#Constraints for w to their latchs#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/regw/LATCH*/G

#Constraints for w to b#
set_max_delay 0.500 -from join_fork_big/regw/LATCH*/Q -to join_fork_big/regb/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcb/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcb/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcb/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcb/C300R30442/A0


##Constraints for w ##
#Constraints for w to itself#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2

#Constraints for w to their latchs#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/regw/LATCH*/G

#Constraints for w to c#
set_max_delay 0.500 -from join_fork_big/regw/LATCH*/Q -to join_fork_big/regc/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0


##Constraints for w ##
#Constraints for w to itself#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcw/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/lcw/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/A -to join_fork_big/lcw/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcw/C300R30444/B -to join_fork_big/lcw/C300R30442/A2

#Constraints for w to their latchs#
set_max_delay 0.500 -from join_fork_big/lcw/C300R30440/A0 -to join_fork_big/regw/LATCH*/G

#Constraints for w to d#
set_max_delay 0.500 -from join_fork_big/regw/LATCH*/Q -to join_fork_big/regd/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcw/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0


##Constraints for x ##
#Constraints for x to itself#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2

#Constraints for x to their latchs#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/regx/LATCH*/G

#Constraints for x to b#
set_max_delay 0.500 -from join_fork_big/regx/LATCH*/Q -to join_fork_big/regb/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcb/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcb/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcb/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcb/C300R30442/A0


##Constraints for x ##
#Constraints for x to itself#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2

#Constraints for x to their latchs#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/regx/LATCH*/G

#Constraints for x to c#
set_max_delay 0.500 -from join_fork_big/regx/LATCH*/Q -to join_fork_big/regc/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0


##Constraints for x ##
#Constraints for x to itself#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcx/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/lcx/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/A -to join_fork_big/lcx/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcx/C300R30444/B -to join_fork_big/lcx/C300R30442/A2

#Constraints for x to their latchs#
set_max_delay 0.500 -from join_fork_big/lcx/C300R30440/A0 -to join_fork_big/regx/LATCH*/G

#Constraints for x to d#
set_max_delay 0.500 -from join_fork_big/regx/LATCH*/Q -to join_fork_big/regd/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcx/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0


##Constraints for y ##
#Constraints for y to itself#
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcy/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcy/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/lcy/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/lcy/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30442/A2

#Constraints for y to their latchs#
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/regy/LATCH*/G

#Constraints for y to c#
set_max_delay 0.500 -from join_fork_big/regy/LATCH*/Q -to join_fork_big/regc/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcc/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcc/C300R30442/A0


##Constraints for y ##
#Constraints for y to itself#
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcy/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcy/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/lcy/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/lcy/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/A -to join_fork_big/lcy/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcy/C300R30444/B -to join_fork_big/lcy/C300R30442/A2

#Constraints for y to their latchs#
set_max_delay 0.500 -from join_fork_big/lcy/C300R30440/A0 -to join_fork_big/regy/LATCH*/G

#Constraints for y to d#
set_max_delay 0.500 -from join_fork_big/regy/LATCH*/Q -to join_fork_big/regd/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcy/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0


##Constraints for z ##
#Constraints for z to itself#
set_max_delay 0.500 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcz/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcz/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcz/C300R30440/A0 -to join_fork_big/lcz/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcz/C300R30440/A0 -to join_fork_big/lcz/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcz/C300R30444/A -to join_fork_big/lcz/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcz/C300R30444/A -to join_fork_big/lcz/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcz/C300R30444/B -to join_fork_big/lcz/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcz/C300R30444/B -to join_fork_big/lcz/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcz/C300R30444/A -to join_fork_big/lcz/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcz/C300R30444/A -to join_fork_big/lcz/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcz/C300R30444/B -to join_fork_big/lcz/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcz/C300R30444/B -to join_fork_big/lcz/C300R30442/A2

#Constraints for z to their latchs#
set_max_delay 0.500 -from join_fork_big/lcz/C300R30440/A0 -to join_fork_big/regz/LATCH*/G

#Constraints for z to d#
set_max_delay 0.500 -from join_fork_big/regz/LATCH*/Q -to join_fork_big/regd/LATCH*/D

set_max_delay 0.500 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_max_delay 0.500 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0
set_min_delay 0.150 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcd/C300R30440/A0
set_min_delay 0.150 -from join_fork_big/lcz/C300R30442/A0 -to join_fork_big/lcd/C300R30442/A0


##Constraints for d ##
#Constraints for d to itself#
set_max_delay 0.500 -from join_fork_big/lcd/C300R30442/A0 -to join_fork_big/lcd/C300R30442/B1
set_max_delay 0.500 -from join_fork_big/lcd/C300R30442/A0 -to join_fork_big/lcd/C300R30444/B
set_max_delay 0.500 -from join_fork_big/lcd/C300R30440/A0 -to join_fork_big/lcd/C300R30440/B1
set_max_delay 0.500 -from join_fork_big/lcd/C300R30440/A0 -to join_fork_big/lcd/C300R30444/A
set_max_delay 0.500 -from join_fork_big/lcd/C300R30444/A -to join_fork_big/lcd/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcd/C300R30444/A -to join_fork_big/lcd/C300R30442/A2
set_max_delay 0.500 -from join_fork_big/lcd/C300R30444/B -to join_fork_big/lcd/C300R30440/A2
set_max_delay 0.500 -from join_fork_big/lcd/C300R30444/B -to join_fork_big/lcd/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcd/C300R30444/A -to join_fork_big/lcd/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcd/C300R30444/A -to join_fork_big/lcd/C300R30442/A2
set_min_delay 0.150 -from join_fork_big/lcd/C300R30444/B -to join_fork_big/lcd/C300R30440/A2
set_min_delay 0.150 -from join_fork_big/lcd/C300R30444/B -to join_fork_big/lcd/C300R30442/A2

#Constraints for d to their latchs#
set_max_delay 0.500 -from join_fork_big/lcd/C300R30440/A0 -to join_fork_big/regd/LATCH*/G

