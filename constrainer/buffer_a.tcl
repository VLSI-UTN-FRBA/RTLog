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
##Constraints for a_i ##
#Constraints for a_i to itself#
set_max_delay 0.500 -from buffer/lca_i/C300R30442/A0 -to buffer/lca_i/C300R30442/B1
set_max_delay 0.500 -from buffer/lca_i/C300R30442/A0 -to buffer/lca_i/C300R30444/B
set_max_delay 0.500 -from buffer/lca_i/C300R30440/A0 -to buffer/lca_i/C300R30440/B1
set_max_delay 0.500 -from buffer/lca_i/C300R30440/A0 -to buffer/lca_i/C300R30444/A
set_max_delay 0.500 -from buffer/lca_i/C300R30444/A -to buffer/lca_i/C300R30440/A2
set_max_delay 0.500 -from buffer/lca_i/C300R30444/A -to buffer/lca_i/C300R30442/A2
set_max_delay 0.500 -from buffer/lca_i/C300R30444/B -to buffer/lca_i/C300R30440/A2
set_max_delay 0.500 -from buffer/lca_i/C300R30444/B -to buffer/lca_i/C300R30442/A2
set_min_delay 0.150 -from buffer/lca_i/C300R30444/A -to buffer/lca_i/C300R30440/A2
set_min_delay 0.150 -from buffer/lca_i/C300R30444/A -to buffer/lca_i/C300R30442/A2
set_min_delay 0.150 -from buffer/lca_i/C300R30444/B -to buffer/lca_i/C300R30440/A2
set_min_delay 0.150 -from buffer/lca_i/C300R30444/B -to buffer/lca_i/C300R30442/A2

#Constraints for a_i to their latchs#
set_max_delay 0.500 -from buffer/lca_i/C300R30440/A0 -to buffer/rega_i/LATCH*/G

#Constraints for a_i to  b_i#
set_max_delay 0.500 -from buffer/rega_i/LATCH*/Q -to buffer/reg b_i/LATCH*/D

set_max_delay 0.500 -from buffer/lca_i/C300R30442/A0 -to buffer/lc b_i/C300R30440/A0
set_max_delay 0.500 -from buffer/lca_i/C300R30442/A0 -to buffer/lc b_i/C300R30442/A0
set_min_delay 0.150 -from buffer/lca_i/C300R30442/A0 -to buffer/lc b_i/C300R30440/A0
set_min_delay 0.150 -from buffer/lca_i/C300R30442/A0 -to buffer/lc b_i/C300R30442/A0


##Constraints for  b_i ##
#Constraints for  b_i to itself#
set_max_delay 0.500 -from buffer/lc b_i/C300R30442/A0 -to buffer/lc b_i/C300R30442/B1
set_max_delay 0.500 -from buffer/lc b_i/C300R30442/A0 -to buffer/lc b_i/C300R30444/B
set_max_delay 0.500 -from buffer/lc b_i/C300R30440/A0 -to buffer/lc b_i/C300R30440/B1
set_max_delay 0.500 -from buffer/lc b_i/C300R30440/A0 -to buffer/lc b_i/C300R30444/A
set_max_delay 0.500 -from buffer/lc b_i/C300R30444/A -to buffer/lc b_i/C300R30440/A2
set_max_delay 0.500 -from buffer/lc b_i/C300R30444/A -to buffer/lc b_i/C300R30442/A2
set_max_delay 0.500 -from buffer/lc b_i/C300R30444/B -to buffer/lc b_i/C300R30440/A2
set_max_delay 0.500 -from buffer/lc b_i/C300R30444/B -to buffer/lc b_i/C300R30442/A2
set_min_delay 0.150 -from buffer/lc b_i/C300R30444/A -to buffer/lc b_i/C300R30440/A2
set_min_delay 0.150 -from buffer/lc b_i/C300R30444/A -to buffer/lc b_i/C300R30442/A2
set_min_delay 0.150 -from buffer/lc b_i/C300R30444/B -to buffer/lc b_i/C300R30440/A2
set_min_delay 0.150 -from buffer/lc b_i/C300R30444/B -to buffer/lc b_i/C300R30442/A2

#Constraints for  b_i to their latchs#
set_max_delay 0.500 -from buffer/lc b_i/C300R30440/A0 -to buffer/reg b_i/LATCH*/G

