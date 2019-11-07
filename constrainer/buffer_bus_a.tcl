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
##Constraints for a_i[0] ##
#Constraints for a_i[0] to itself#
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lca_i[0]/C300R30442/B1
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lca_i[0]/C300R30444/B
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30440/A0 -to buffer_bus/lca_i[0]/C300R30440/B1
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30440/A0 -to buffer_bus/lca_i[0]/C300R30444/A
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30444/A -to buffer_bus/lca_i[0]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30444/A -to buffer_bus/lca_i[0]/C300R30442/A2
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30444/B -to buffer_bus/lca_i[0]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30444/B -to buffer_bus/lca_i[0]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30444/A -to buffer_bus/lca_i[0]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30444/A -to buffer_bus/lca_i[0]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30444/B -to buffer_bus/lca_i[0]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30444/B -to buffer_bus/lca_i[0]/C300R30442/A2

#Constraints for a_i[0] to their latchs#
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30440/A0 -to buffer_bus/rega_i[0]/LATCH*/G

#Constraints for a_i[0] to  b_i[0]#
set_max_delay 0.500 -from buffer_bus/rega_i[0]/LATCH*/Q -to buffer_bus/reg b_i[0]/LATCH*/D

set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lc b_i[0]/C300R30440/A0
set_max_delay 0.500 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lc b_i[0]/C300R30442/A0
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lc b_i[0]/C300R30440/A0
set_min_delay 0.150 -from buffer_bus/lca_i[0]/C300R30442/A0 -to buffer_bus/lc b_i[0]/C300R30442/A0


##Constraints for a_i[1] ##
#Constraints for a_i[1] to itself#
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lca_i[1]/C300R30442/B1
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lca_i[1]/C300R30444/B
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30440/A0 -to buffer_bus/lca_i[1]/C300R30440/B1
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30440/A0 -to buffer_bus/lca_i[1]/C300R30444/A
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30444/A -to buffer_bus/lca_i[1]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30444/A -to buffer_bus/lca_i[1]/C300R30442/A2
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30444/B -to buffer_bus/lca_i[1]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30444/B -to buffer_bus/lca_i[1]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30444/A -to buffer_bus/lca_i[1]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30444/A -to buffer_bus/lca_i[1]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30444/B -to buffer_bus/lca_i[1]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30444/B -to buffer_bus/lca_i[1]/C300R30442/A2

#Constraints for a_i[1] to their latchs#
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30440/A0 -to buffer_bus/rega_i[1]/LATCH*/G

#Constraints for a_i[1] to  b_i[1]#
set_max_delay 0.500 -from buffer_bus/rega_i[1]/LATCH*/Q -to buffer_bus/reg b_i[1]/LATCH*/D

set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lc b_i[1]/C300R30440/A0
set_max_delay 0.500 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lc b_i[1]/C300R30442/A0
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lc b_i[1]/C300R30440/A0
set_min_delay 0.150 -from buffer_bus/lca_i[1]/C300R30442/A0 -to buffer_bus/lc b_i[1]/C300R30442/A0


##Constraints for a_i[2] ##
#Constraints for a_i[2] to itself#
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lca_i[2]/C300R30442/B1
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lca_i[2]/C300R30444/B
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30440/A0 -to buffer_bus/lca_i[2]/C300R30440/B1
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30440/A0 -to buffer_bus/lca_i[2]/C300R30444/A
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30444/A -to buffer_bus/lca_i[2]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30444/A -to buffer_bus/lca_i[2]/C300R30442/A2
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30444/B -to buffer_bus/lca_i[2]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30444/B -to buffer_bus/lca_i[2]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30444/A -to buffer_bus/lca_i[2]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30444/A -to buffer_bus/lca_i[2]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30444/B -to buffer_bus/lca_i[2]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30444/B -to buffer_bus/lca_i[2]/C300R30442/A2

#Constraints for a_i[2] to their latchs#
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30440/A0 -to buffer_bus/rega_i[2]/LATCH*/G

#Constraints for a_i[2] to  b_i[2]#
set_max_delay 0.500 -from buffer_bus/rega_i[2]/LATCH*/Q -to buffer_bus/reg b_i[2]/LATCH*/D

set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lc b_i[2]/C300R30440/A0
set_max_delay 0.500 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lc b_i[2]/C300R30442/A0
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lc b_i[2]/C300R30440/A0
set_min_delay 0.150 -from buffer_bus/lca_i[2]/C300R30442/A0 -to buffer_bus/lc b_i[2]/C300R30442/A0


##Constraints for a_i[3] ##
#Constraints for a_i[3] to itself#
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lca_i[3]/C300R30442/B1
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lca_i[3]/C300R30444/B
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30440/A0 -to buffer_bus/lca_i[3]/C300R30440/B1
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30440/A0 -to buffer_bus/lca_i[3]/C300R30444/A
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30444/A -to buffer_bus/lca_i[3]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30444/A -to buffer_bus/lca_i[3]/C300R30442/A2
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30444/B -to buffer_bus/lca_i[3]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30444/B -to buffer_bus/lca_i[3]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30444/A -to buffer_bus/lca_i[3]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30444/A -to buffer_bus/lca_i[3]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30444/B -to buffer_bus/lca_i[3]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30444/B -to buffer_bus/lca_i[3]/C300R30442/A2

#Constraints for a_i[3] to their latchs#
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30440/A0 -to buffer_bus/rega_i[3]/LATCH*/G

#Constraints for a_i[3] to  b_i[3]#
set_max_delay 0.500 -from buffer_bus/rega_i[3]/LATCH*/Q -to buffer_bus/reg b_i[3]/LATCH*/D

set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30440/A0
set_max_delay 0.500 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30442/A0
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30440/A0
set_min_delay 0.150 -from buffer_bus/lca_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30442/A0


##Constraints for  b_i[3] ##
#Constraints for  b_i[3] to itself#
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30442/B1
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30442/A0 -to buffer_bus/lc b_i[3]/C300R30444/B
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30440/A0 -to buffer_bus/lc b_i[3]/C300R30440/B1
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30440/A0 -to buffer_bus/lc b_i[3]/C300R30444/A
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30444/A -to buffer_bus/lc b_i[3]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30444/A -to buffer_bus/lc b_i[3]/C300R30442/A2
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30444/B -to buffer_bus/lc b_i[3]/C300R30440/A2
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30444/B -to buffer_bus/lc b_i[3]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lc b_i[3]/C300R30444/A -to buffer_bus/lc b_i[3]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lc b_i[3]/C300R30444/A -to buffer_bus/lc b_i[3]/C300R30442/A2
set_min_delay 0.150 -from buffer_bus/lc b_i[3]/C300R30444/B -to buffer_bus/lc b_i[3]/C300R30440/A2
set_min_delay 0.150 -from buffer_bus/lc b_i[3]/C300R30444/B -to buffer_bus/lc b_i[3]/C300R30442/A2

#Constraints for  b_i[3] to their latchs#
set_max_delay 0.500 -from buffer_bus/lc b_i[3]/C300R30440/A0 -to buffer_bus/reg b_i[3]/LATCH*/G

