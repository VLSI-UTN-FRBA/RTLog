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
##Constraints for r1[0] ##
#Constraints for r1[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lcr1[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lcr1[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30440/A0 -to fifo_8b_8d/lcr1[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30440/A0 -to fifo_8b_8d/lcr1[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30444/A -to fifo_8b_8d/lcr1[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30444/A -to fifo_8b_8d/lcr1[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30444/B -to fifo_8b_8d/lcr1[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30444/B -to fifo_8b_8d/lcr1[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30444/A -to fifo_8b_8d/lcr1[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30444/A -to fifo_8b_8d/lcr1[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30444/B -to fifo_8b_8d/lcr1[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30444/B -to fifo_8b_8d/lcr1[0]/C300R30442/A2

#Constraints for r1[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30440/A0 -to fifo_8b_8d/regr1[0]/LATCH*/G

#Constraints for r1[0] to  r2[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[0]/LATCH*/Q -to fifo_8b_8d/reg r2[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lc r2[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lc r2[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lc r2[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[0]/C300R30442/A0 -to fifo_8b_8d/lc r2[0]/C300R30442/A0


##Constraints for r1[1] ##
#Constraints for r1[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lcr1[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lcr1[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30440/A0 -to fifo_8b_8d/lcr1[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30440/A0 -to fifo_8b_8d/lcr1[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30444/A -to fifo_8b_8d/lcr1[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30444/A -to fifo_8b_8d/lcr1[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30444/B -to fifo_8b_8d/lcr1[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30444/B -to fifo_8b_8d/lcr1[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30444/A -to fifo_8b_8d/lcr1[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30444/A -to fifo_8b_8d/lcr1[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30444/B -to fifo_8b_8d/lcr1[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30444/B -to fifo_8b_8d/lcr1[1]/C300R30442/A2

#Constraints for r1[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30440/A0 -to fifo_8b_8d/regr1[1]/LATCH*/G

#Constraints for r1[1] to  r2[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[1]/LATCH*/Q -to fifo_8b_8d/reg r2[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lc r2[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lc r2[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lc r2[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[1]/C300R30442/A0 -to fifo_8b_8d/lc r2[1]/C300R30442/A0


##Constraints for r1[2] ##
#Constraints for r1[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lcr1[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lcr1[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30440/A0 -to fifo_8b_8d/lcr1[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30440/A0 -to fifo_8b_8d/lcr1[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30444/A -to fifo_8b_8d/lcr1[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30444/A -to fifo_8b_8d/lcr1[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30444/B -to fifo_8b_8d/lcr1[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30444/B -to fifo_8b_8d/lcr1[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30444/A -to fifo_8b_8d/lcr1[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30444/A -to fifo_8b_8d/lcr1[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30444/B -to fifo_8b_8d/lcr1[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30444/B -to fifo_8b_8d/lcr1[2]/C300R30442/A2

#Constraints for r1[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30440/A0 -to fifo_8b_8d/regr1[2]/LATCH*/G

#Constraints for r1[2] to  r2[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[2]/LATCH*/Q -to fifo_8b_8d/reg r2[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lc r2[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lc r2[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lc r2[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[2]/C300R30442/A0 -to fifo_8b_8d/lc r2[2]/C300R30442/A0


##Constraints for r1[3] ##
#Constraints for r1[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lcr1[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lcr1[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30440/A0 -to fifo_8b_8d/lcr1[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30440/A0 -to fifo_8b_8d/lcr1[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30444/A -to fifo_8b_8d/lcr1[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30444/A -to fifo_8b_8d/lcr1[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30444/B -to fifo_8b_8d/lcr1[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30444/B -to fifo_8b_8d/lcr1[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30444/A -to fifo_8b_8d/lcr1[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30444/A -to fifo_8b_8d/lcr1[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30444/B -to fifo_8b_8d/lcr1[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30444/B -to fifo_8b_8d/lcr1[3]/C300R30442/A2

#Constraints for r1[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30440/A0 -to fifo_8b_8d/regr1[3]/LATCH*/G

#Constraints for r1[3] to  r2[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[3]/LATCH*/Q -to fifo_8b_8d/reg r2[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lc r2[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lc r2[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lc r2[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[3]/C300R30442/A0 -to fifo_8b_8d/lc r2[3]/C300R30442/A0


##Constraints for r1[4] ##
#Constraints for r1[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lcr1[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lcr1[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30440/A0 -to fifo_8b_8d/lcr1[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30440/A0 -to fifo_8b_8d/lcr1[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30444/A -to fifo_8b_8d/lcr1[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30444/A -to fifo_8b_8d/lcr1[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30444/B -to fifo_8b_8d/lcr1[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30444/B -to fifo_8b_8d/lcr1[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30444/A -to fifo_8b_8d/lcr1[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30444/A -to fifo_8b_8d/lcr1[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30444/B -to fifo_8b_8d/lcr1[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30444/B -to fifo_8b_8d/lcr1[4]/C300R30442/A2

#Constraints for r1[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30440/A0 -to fifo_8b_8d/regr1[4]/LATCH*/G

#Constraints for r1[4] to  r2[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[4]/LATCH*/Q -to fifo_8b_8d/reg r2[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lc r2[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lc r2[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lc r2[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[4]/C300R30442/A0 -to fifo_8b_8d/lc r2[4]/C300R30442/A0


##Constraints for r1[5] ##
#Constraints for r1[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lcr1[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lcr1[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30440/A0 -to fifo_8b_8d/lcr1[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30440/A0 -to fifo_8b_8d/lcr1[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30444/A -to fifo_8b_8d/lcr1[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30444/A -to fifo_8b_8d/lcr1[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30444/B -to fifo_8b_8d/lcr1[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30444/B -to fifo_8b_8d/lcr1[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30444/A -to fifo_8b_8d/lcr1[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30444/A -to fifo_8b_8d/lcr1[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30444/B -to fifo_8b_8d/lcr1[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30444/B -to fifo_8b_8d/lcr1[5]/C300R30442/A2

#Constraints for r1[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30440/A0 -to fifo_8b_8d/regr1[5]/LATCH*/G

#Constraints for r1[5] to  r2[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[5]/LATCH*/Q -to fifo_8b_8d/reg r2[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lc r2[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lc r2[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lc r2[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[5]/C300R30442/A0 -to fifo_8b_8d/lc r2[5]/C300R30442/A0


##Constraints for r1[6] ##
#Constraints for r1[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lcr1[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lcr1[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30440/A0 -to fifo_8b_8d/lcr1[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30440/A0 -to fifo_8b_8d/lcr1[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30444/A -to fifo_8b_8d/lcr1[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30444/A -to fifo_8b_8d/lcr1[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30444/B -to fifo_8b_8d/lcr1[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30444/B -to fifo_8b_8d/lcr1[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30444/A -to fifo_8b_8d/lcr1[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30444/A -to fifo_8b_8d/lcr1[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30444/B -to fifo_8b_8d/lcr1[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30444/B -to fifo_8b_8d/lcr1[6]/C300R30442/A2

#Constraints for r1[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30440/A0 -to fifo_8b_8d/regr1[6]/LATCH*/G

#Constraints for r1[6] to  r2[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[6]/LATCH*/Q -to fifo_8b_8d/reg r2[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lc r2[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lc r2[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lc r2[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[6]/C300R30442/A0 -to fifo_8b_8d/lc r2[6]/C300R30442/A0


##Constraints for r1[7] ##
#Constraints for r1[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lcr1[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lcr1[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30440/A0 -to fifo_8b_8d/lcr1[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30440/A0 -to fifo_8b_8d/lcr1[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30444/A -to fifo_8b_8d/lcr1[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30444/A -to fifo_8b_8d/lcr1[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30444/B -to fifo_8b_8d/lcr1[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30444/B -to fifo_8b_8d/lcr1[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30444/A -to fifo_8b_8d/lcr1[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30444/A -to fifo_8b_8d/lcr1[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30444/B -to fifo_8b_8d/lcr1[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30444/B -to fifo_8b_8d/lcr1[7]/C300R30442/A2

#Constraints for r1[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30440/A0 -to fifo_8b_8d/regr1[7]/LATCH*/G

#Constraints for r1[7] to  r2[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr1[7]/LATCH*/Q -to fifo_8b_8d/reg r2[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lc r2[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lc r2[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lc r2[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr1[7]/C300R30442/A0 -to fifo_8b_8d/lc r2[7]/C300R30442/A0


##Constraints for r2[0] ##
#Constraints for r2[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lcr2[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lcr2[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30440/A0 -to fifo_8b_8d/lcr2[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30440/A0 -to fifo_8b_8d/lcr2[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30444/A -to fifo_8b_8d/lcr2[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30444/A -to fifo_8b_8d/lcr2[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30444/B -to fifo_8b_8d/lcr2[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30444/B -to fifo_8b_8d/lcr2[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30444/A -to fifo_8b_8d/lcr2[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30444/A -to fifo_8b_8d/lcr2[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30444/B -to fifo_8b_8d/lcr2[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30444/B -to fifo_8b_8d/lcr2[0]/C300R30442/A2

#Constraints for r2[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30440/A0 -to fifo_8b_8d/regr2[0]/LATCH*/G

#Constraints for r2[0] to  r3[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[0]/LATCH*/Q -to fifo_8b_8d/reg r3[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lc r3[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lc r3[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lc r3[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[0]/C300R30442/A0 -to fifo_8b_8d/lc r3[0]/C300R30442/A0


##Constraints for r2[1] ##
#Constraints for r2[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lcr2[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lcr2[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30440/A0 -to fifo_8b_8d/lcr2[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30440/A0 -to fifo_8b_8d/lcr2[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30444/A -to fifo_8b_8d/lcr2[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30444/A -to fifo_8b_8d/lcr2[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30444/B -to fifo_8b_8d/lcr2[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30444/B -to fifo_8b_8d/lcr2[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30444/A -to fifo_8b_8d/lcr2[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30444/A -to fifo_8b_8d/lcr2[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30444/B -to fifo_8b_8d/lcr2[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30444/B -to fifo_8b_8d/lcr2[1]/C300R30442/A2

#Constraints for r2[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30440/A0 -to fifo_8b_8d/regr2[1]/LATCH*/G

#Constraints for r2[1] to  r3[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[1]/LATCH*/Q -to fifo_8b_8d/reg r3[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lc r3[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lc r3[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lc r3[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[1]/C300R30442/A0 -to fifo_8b_8d/lc r3[1]/C300R30442/A0


##Constraints for r2[2] ##
#Constraints for r2[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lcr2[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lcr2[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30440/A0 -to fifo_8b_8d/lcr2[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30440/A0 -to fifo_8b_8d/lcr2[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30444/A -to fifo_8b_8d/lcr2[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30444/A -to fifo_8b_8d/lcr2[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30444/B -to fifo_8b_8d/lcr2[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30444/B -to fifo_8b_8d/lcr2[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30444/A -to fifo_8b_8d/lcr2[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30444/A -to fifo_8b_8d/lcr2[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30444/B -to fifo_8b_8d/lcr2[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30444/B -to fifo_8b_8d/lcr2[2]/C300R30442/A2

#Constraints for r2[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30440/A0 -to fifo_8b_8d/regr2[2]/LATCH*/G

#Constraints for r2[2] to  r3[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[2]/LATCH*/Q -to fifo_8b_8d/reg r3[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lc r3[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lc r3[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lc r3[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[2]/C300R30442/A0 -to fifo_8b_8d/lc r3[2]/C300R30442/A0


##Constraints for r2[3] ##
#Constraints for r2[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lcr2[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lcr2[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30440/A0 -to fifo_8b_8d/lcr2[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30440/A0 -to fifo_8b_8d/lcr2[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30444/A -to fifo_8b_8d/lcr2[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30444/A -to fifo_8b_8d/lcr2[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30444/B -to fifo_8b_8d/lcr2[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30444/B -to fifo_8b_8d/lcr2[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30444/A -to fifo_8b_8d/lcr2[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30444/A -to fifo_8b_8d/lcr2[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30444/B -to fifo_8b_8d/lcr2[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30444/B -to fifo_8b_8d/lcr2[3]/C300R30442/A2

#Constraints for r2[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30440/A0 -to fifo_8b_8d/regr2[3]/LATCH*/G

#Constraints for r2[3] to  r3[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[3]/LATCH*/Q -to fifo_8b_8d/reg r3[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lc r3[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lc r3[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lc r3[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[3]/C300R30442/A0 -to fifo_8b_8d/lc r3[3]/C300R30442/A0


##Constraints for r2[4] ##
#Constraints for r2[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lcr2[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lcr2[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30440/A0 -to fifo_8b_8d/lcr2[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30440/A0 -to fifo_8b_8d/lcr2[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30444/A -to fifo_8b_8d/lcr2[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30444/A -to fifo_8b_8d/lcr2[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30444/B -to fifo_8b_8d/lcr2[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30444/B -to fifo_8b_8d/lcr2[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30444/A -to fifo_8b_8d/lcr2[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30444/A -to fifo_8b_8d/lcr2[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30444/B -to fifo_8b_8d/lcr2[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30444/B -to fifo_8b_8d/lcr2[4]/C300R30442/A2

#Constraints for r2[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30440/A0 -to fifo_8b_8d/regr2[4]/LATCH*/G

#Constraints for r2[4] to  r3[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[4]/LATCH*/Q -to fifo_8b_8d/reg r3[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lc r3[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lc r3[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lc r3[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[4]/C300R30442/A0 -to fifo_8b_8d/lc r3[4]/C300R30442/A0


##Constraints for r2[5] ##
#Constraints for r2[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lcr2[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lcr2[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30440/A0 -to fifo_8b_8d/lcr2[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30440/A0 -to fifo_8b_8d/lcr2[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30444/A -to fifo_8b_8d/lcr2[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30444/A -to fifo_8b_8d/lcr2[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30444/B -to fifo_8b_8d/lcr2[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30444/B -to fifo_8b_8d/lcr2[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30444/A -to fifo_8b_8d/lcr2[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30444/A -to fifo_8b_8d/lcr2[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30444/B -to fifo_8b_8d/lcr2[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30444/B -to fifo_8b_8d/lcr2[5]/C300R30442/A2

#Constraints for r2[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30440/A0 -to fifo_8b_8d/regr2[5]/LATCH*/G

#Constraints for r2[5] to  r3[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[5]/LATCH*/Q -to fifo_8b_8d/reg r3[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lc r3[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lc r3[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lc r3[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[5]/C300R30442/A0 -to fifo_8b_8d/lc r3[5]/C300R30442/A0


##Constraints for r2[6] ##
#Constraints for r2[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lcr2[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lcr2[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30440/A0 -to fifo_8b_8d/lcr2[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30440/A0 -to fifo_8b_8d/lcr2[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30444/A -to fifo_8b_8d/lcr2[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30444/A -to fifo_8b_8d/lcr2[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30444/B -to fifo_8b_8d/lcr2[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30444/B -to fifo_8b_8d/lcr2[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30444/A -to fifo_8b_8d/lcr2[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30444/A -to fifo_8b_8d/lcr2[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30444/B -to fifo_8b_8d/lcr2[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30444/B -to fifo_8b_8d/lcr2[6]/C300R30442/A2

#Constraints for r2[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30440/A0 -to fifo_8b_8d/regr2[6]/LATCH*/G

#Constraints for r2[6] to  r3[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[6]/LATCH*/Q -to fifo_8b_8d/reg r3[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lc r3[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lc r3[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lc r3[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[6]/C300R30442/A0 -to fifo_8b_8d/lc r3[6]/C300R30442/A0


##Constraints for r2[7] ##
#Constraints for r2[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lcr2[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lcr2[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30440/A0 -to fifo_8b_8d/lcr2[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30440/A0 -to fifo_8b_8d/lcr2[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30444/A -to fifo_8b_8d/lcr2[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30444/A -to fifo_8b_8d/lcr2[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30444/B -to fifo_8b_8d/lcr2[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30444/B -to fifo_8b_8d/lcr2[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30444/A -to fifo_8b_8d/lcr2[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30444/A -to fifo_8b_8d/lcr2[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30444/B -to fifo_8b_8d/lcr2[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30444/B -to fifo_8b_8d/lcr2[7]/C300R30442/A2

#Constraints for r2[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30440/A0 -to fifo_8b_8d/regr2[7]/LATCH*/G

#Constraints for r2[7] to  r3[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr2[7]/LATCH*/Q -to fifo_8b_8d/reg r3[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lc r3[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lc r3[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lc r3[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr2[7]/C300R30442/A0 -to fifo_8b_8d/lc r3[7]/C300R30442/A0


##Constraints for r3[0] ##
#Constraints for r3[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lcr3[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lcr3[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30440/A0 -to fifo_8b_8d/lcr3[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30440/A0 -to fifo_8b_8d/lcr3[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30444/A -to fifo_8b_8d/lcr3[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30444/A -to fifo_8b_8d/lcr3[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30444/B -to fifo_8b_8d/lcr3[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30444/B -to fifo_8b_8d/lcr3[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30444/A -to fifo_8b_8d/lcr3[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30444/A -to fifo_8b_8d/lcr3[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30444/B -to fifo_8b_8d/lcr3[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30444/B -to fifo_8b_8d/lcr3[0]/C300R30442/A2

#Constraints for r3[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30440/A0 -to fifo_8b_8d/regr3[0]/LATCH*/G

#Constraints for r3[0] to  r4[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[0]/LATCH*/Q -to fifo_8b_8d/reg r4[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lc r4[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lc r4[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lc r4[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[0]/C300R30442/A0 -to fifo_8b_8d/lc r4[0]/C300R30442/A0


##Constraints for r3[1] ##
#Constraints for r3[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lcr3[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lcr3[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30440/A0 -to fifo_8b_8d/lcr3[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30440/A0 -to fifo_8b_8d/lcr3[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30444/A -to fifo_8b_8d/lcr3[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30444/A -to fifo_8b_8d/lcr3[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30444/B -to fifo_8b_8d/lcr3[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30444/B -to fifo_8b_8d/lcr3[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30444/A -to fifo_8b_8d/lcr3[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30444/A -to fifo_8b_8d/lcr3[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30444/B -to fifo_8b_8d/lcr3[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30444/B -to fifo_8b_8d/lcr3[1]/C300R30442/A2

#Constraints for r3[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30440/A0 -to fifo_8b_8d/regr3[1]/LATCH*/G

#Constraints for r3[1] to  r4[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[1]/LATCH*/Q -to fifo_8b_8d/reg r4[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lc r4[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lc r4[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lc r4[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[1]/C300R30442/A0 -to fifo_8b_8d/lc r4[1]/C300R30442/A0


##Constraints for r3[2] ##
#Constraints for r3[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lcr3[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lcr3[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30440/A0 -to fifo_8b_8d/lcr3[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30440/A0 -to fifo_8b_8d/lcr3[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30444/A -to fifo_8b_8d/lcr3[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30444/A -to fifo_8b_8d/lcr3[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30444/B -to fifo_8b_8d/lcr3[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30444/B -to fifo_8b_8d/lcr3[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30444/A -to fifo_8b_8d/lcr3[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30444/A -to fifo_8b_8d/lcr3[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30444/B -to fifo_8b_8d/lcr3[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30444/B -to fifo_8b_8d/lcr3[2]/C300R30442/A2

#Constraints for r3[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30440/A0 -to fifo_8b_8d/regr3[2]/LATCH*/G

#Constraints for r3[2] to  r4[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[2]/LATCH*/Q -to fifo_8b_8d/reg r4[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lc r4[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lc r4[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lc r4[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[2]/C300R30442/A0 -to fifo_8b_8d/lc r4[2]/C300R30442/A0


##Constraints for r3[3] ##
#Constraints for r3[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lcr3[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lcr3[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30440/A0 -to fifo_8b_8d/lcr3[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30440/A0 -to fifo_8b_8d/lcr3[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30444/A -to fifo_8b_8d/lcr3[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30444/A -to fifo_8b_8d/lcr3[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30444/B -to fifo_8b_8d/lcr3[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30444/B -to fifo_8b_8d/lcr3[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30444/A -to fifo_8b_8d/lcr3[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30444/A -to fifo_8b_8d/lcr3[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30444/B -to fifo_8b_8d/lcr3[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30444/B -to fifo_8b_8d/lcr3[3]/C300R30442/A2

#Constraints for r3[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30440/A0 -to fifo_8b_8d/regr3[3]/LATCH*/G

#Constraints for r3[3] to  r4[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[3]/LATCH*/Q -to fifo_8b_8d/reg r4[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lc r4[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lc r4[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lc r4[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[3]/C300R30442/A0 -to fifo_8b_8d/lc r4[3]/C300R30442/A0


##Constraints for r3[4] ##
#Constraints for r3[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lcr3[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lcr3[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30440/A0 -to fifo_8b_8d/lcr3[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30440/A0 -to fifo_8b_8d/lcr3[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30444/A -to fifo_8b_8d/lcr3[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30444/A -to fifo_8b_8d/lcr3[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30444/B -to fifo_8b_8d/lcr3[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30444/B -to fifo_8b_8d/lcr3[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30444/A -to fifo_8b_8d/lcr3[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30444/A -to fifo_8b_8d/lcr3[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30444/B -to fifo_8b_8d/lcr3[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30444/B -to fifo_8b_8d/lcr3[4]/C300R30442/A2

#Constraints for r3[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30440/A0 -to fifo_8b_8d/regr3[4]/LATCH*/G

#Constraints for r3[4] to  r4[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[4]/LATCH*/Q -to fifo_8b_8d/reg r4[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lc r4[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lc r4[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lc r4[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[4]/C300R30442/A0 -to fifo_8b_8d/lc r4[4]/C300R30442/A0


##Constraints for r3[5] ##
#Constraints for r3[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lcr3[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lcr3[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30440/A0 -to fifo_8b_8d/lcr3[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30440/A0 -to fifo_8b_8d/lcr3[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30444/A -to fifo_8b_8d/lcr3[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30444/A -to fifo_8b_8d/lcr3[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30444/B -to fifo_8b_8d/lcr3[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30444/B -to fifo_8b_8d/lcr3[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30444/A -to fifo_8b_8d/lcr3[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30444/A -to fifo_8b_8d/lcr3[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30444/B -to fifo_8b_8d/lcr3[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30444/B -to fifo_8b_8d/lcr3[5]/C300R30442/A2

#Constraints for r3[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30440/A0 -to fifo_8b_8d/regr3[5]/LATCH*/G

#Constraints for r3[5] to  r4[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[5]/LATCH*/Q -to fifo_8b_8d/reg r4[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lc r4[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lc r4[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lc r4[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[5]/C300R30442/A0 -to fifo_8b_8d/lc r4[5]/C300R30442/A0


##Constraints for r3[6] ##
#Constraints for r3[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lcr3[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lcr3[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30440/A0 -to fifo_8b_8d/lcr3[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30440/A0 -to fifo_8b_8d/lcr3[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30444/A -to fifo_8b_8d/lcr3[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30444/A -to fifo_8b_8d/lcr3[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30444/B -to fifo_8b_8d/lcr3[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30444/B -to fifo_8b_8d/lcr3[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30444/A -to fifo_8b_8d/lcr3[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30444/A -to fifo_8b_8d/lcr3[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30444/B -to fifo_8b_8d/lcr3[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30444/B -to fifo_8b_8d/lcr3[6]/C300R30442/A2

#Constraints for r3[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30440/A0 -to fifo_8b_8d/regr3[6]/LATCH*/G

#Constraints for r3[6] to  r4[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[6]/LATCH*/Q -to fifo_8b_8d/reg r4[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lc r4[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lc r4[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lc r4[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[6]/C300R30442/A0 -to fifo_8b_8d/lc r4[6]/C300R30442/A0


##Constraints for r3[7] ##
#Constraints for r3[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lcr3[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lcr3[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30440/A0 -to fifo_8b_8d/lcr3[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30440/A0 -to fifo_8b_8d/lcr3[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30444/A -to fifo_8b_8d/lcr3[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30444/A -to fifo_8b_8d/lcr3[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30444/B -to fifo_8b_8d/lcr3[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30444/B -to fifo_8b_8d/lcr3[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30444/A -to fifo_8b_8d/lcr3[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30444/A -to fifo_8b_8d/lcr3[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30444/B -to fifo_8b_8d/lcr3[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30444/B -to fifo_8b_8d/lcr3[7]/C300R30442/A2

#Constraints for r3[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30440/A0 -to fifo_8b_8d/regr3[7]/LATCH*/G

#Constraints for r3[7] to  r4[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr3[7]/LATCH*/Q -to fifo_8b_8d/reg r4[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lc r4[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lc r4[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lc r4[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr3[7]/C300R30442/A0 -to fifo_8b_8d/lc r4[7]/C300R30442/A0


##Constraints for r4[0] ##
#Constraints for r4[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lcr4[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lcr4[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30440/A0 -to fifo_8b_8d/lcr4[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30440/A0 -to fifo_8b_8d/lcr4[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30444/A -to fifo_8b_8d/lcr4[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30444/A -to fifo_8b_8d/lcr4[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30444/B -to fifo_8b_8d/lcr4[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30444/B -to fifo_8b_8d/lcr4[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30444/A -to fifo_8b_8d/lcr4[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30444/A -to fifo_8b_8d/lcr4[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30444/B -to fifo_8b_8d/lcr4[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30444/B -to fifo_8b_8d/lcr4[0]/C300R30442/A2

#Constraints for r4[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30440/A0 -to fifo_8b_8d/regr4[0]/LATCH*/G

#Constraints for r4[0] to  r5[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[0]/LATCH*/Q -to fifo_8b_8d/reg r5[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lc r5[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lc r5[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lc r5[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[0]/C300R30442/A0 -to fifo_8b_8d/lc r5[0]/C300R30442/A0


##Constraints for r4[1] ##
#Constraints for r4[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lcr4[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lcr4[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30440/A0 -to fifo_8b_8d/lcr4[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30440/A0 -to fifo_8b_8d/lcr4[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30444/A -to fifo_8b_8d/lcr4[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30444/A -to fifo_8b_8d/lcr4[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30444/B -to fifo_8b_8d/lcr4[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30444/B -to fifo_8b_8d/lcr4[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30444/A -to fifo_8b_8d/lcr4[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30444/A -to fifo_8b_8d/lcr4[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30444/B -to fifo_8b_8d/lcr4[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30444/B -to fifo_8b_8d/lcr4[1]/C300R30442/A2

#Constraints for r4[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30440/A0 -to fifo_8b_8d/regr4[1]/LATCH*/G

#Constraints for r4[1] to  r5[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[1]/LATCH*/Q -to fifo_8b_8d/reg r5[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lc r5[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lc r5[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lc r5[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[1]/C300R30442/A0 -to fifo_8b_8d/lc r5[1]/C300R30442/A0


##Constraints for r4[2] ##
#Constraints for r4[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lcr4[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lcr4[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30440/A0 -to fifo_8b_8d/lcr4[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30440/A0 -to fifo_8b_8d/lcr4[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30444/A -to fifo_8b_8d/lcr4[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30444/A -to fifo_8b_8d/lcr4[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30444/B -to fifo_8b_8d/lcr4[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30444/B -to fifo_8b_8d/lcr4[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30444/A -to fifo_8b_8d/lcr4[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30444/A -to fifo_8b_8d/lcr4[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30444/B -to fifo_8b_8d/lcr4[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30444/B -to fifo_8b_8d/lcr4[2]/C300R30442/A2

#Constraints for r4[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30440/A0 -to fifo_8b_8d/regr4[2]/LATCH*/G

#Constraints for r4[2] to  r5[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[2]/LATCH*/Q -to fifo_8b_8d/reg r5[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lc r5[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lc r5[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lc r5[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[2]/C300R30442/A0 -to fifo_8b_8d/lc r5[2]/C300R30442/A0


##Constraints for r4[3] ##
#Constraints for r4[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lcr4[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lcr4[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30440/A0 -to fifo_8b_8d/lcr4[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30440/A0 -to fifo_8b_8d/lcr4[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30444/A -to fifo_8b_8d/lcr4[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30444/A -to fifo_8b_8d/lcr4[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30444/B -to fifo_8b_8d/lcr4[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30444/B -to fifo_8b_8d/lcr4[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30444/A -to fifo_8b_8d/lcr4[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30444/A -to fifo_8b_8d/lcr4[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30444/B -to fifo_8b_8d/lcr4[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30444/B -to fifo_8b_8d/lcr4[3]/C300R30442/A2

#Constraints for r4[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30440/A0 -to fifo_8b_8d/regr4[3]/LATCH*/G

#Constraints for r4[3] to  r5[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[3]/LATCH*/Q -to fifo_8b_8d/reg r5[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lc r5[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lc r5[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lc r5[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[3]/C300R30442/A0 -to fifo_8b_8d/lc r5[3]/C300R30442/A0


##Constraints for r4[4] ##
#Constraints for r4[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lcr4[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lcr4[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30440/A0 -to fifo_8b_8d/lcr4[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30440/A0 -to fifo_8b_8d/lcr4[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30444/A -to fifo_8b_8d/lcr4[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30444/A -to fifo_8b_8d/lcr4[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30444/B -to fifo_8b_8d/lcr4[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30444/B -to fifo_8b_8d/lcr4[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30444/A -to fifo_8b_8d/lcr4[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30444/A -to fifo_8b_8d/lcr4[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30444/B -to fifo_8b_8d/lcr4[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30444/B -to fifo_8b_8d/lcr4[4]/C300R30442/A2

#Constraints for r4[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30440/A0 -to fifo_8b_8d/regr4[4]/LATCH*/G

#Constraints for r4[4] to  r5[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[4]/LATCH*/Q -to fifo_8b_8d/reg r5[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lc r5[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lc r5[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lc r5[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[4]/C300R30442/A0 -to fifo_8b_8d/lc r5[4]/C300R30442/A0


##Constraints for r4[5] ##
#Constraints for r4[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lcr4[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lcr4[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30440/A0 -to fifo_8b_8d/lcr4[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30440/A0 -to fifo_8b_8d/lcr4[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30444/A -to fifo_8b_8d/lcr4[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30444/A -to fifo_8b_8d/lcr4[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30444/B -to fifo_8b_8d/lcr4[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30444/B -to fifo_8b_8d/lcr4[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30444/A -to fifo_8b_8d/lcr4[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30444/A -to fifo_8b_8d/lcr4[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30444/B -to fifo_8b_8d/lcr4[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30444/B -to fifo_8b_8d/lcr4[5]/C300R30442/A2

#Constraints for r4[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30440/A0 -to fifo_8b_8d/regr4[5]/LATCH*/G

#Constraints for r4[5] to  r5[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[5]/LATCH*/Q -to fifo_8b_8d/reg r5[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lc r5[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lc r5[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lc r5[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[5]/C300R30442/A0 -to fifo_8b_8d/lc r5[5]/C300R30442/A0


##Constraints for r4[6] ##
#Constraints for r4[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lcr4[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lcr4[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30440/A0 -to fifo_8b_8d/lcr4[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30440/A0 -to fifo_8b_8d/lcr4[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30444/A -to fifo_8b_8d/lcr4[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30444/A -to fifo_8b_8d/lcr4[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30444/B -to fifo_8b_8d/lcr4[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30444/B -to fifo_8b_8d/lcr4[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30444/A -to fifo_8b_8d/lcr4[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30444/A -to fifo_8b_8d/lcr4[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30444/B -to fifo_8b_8d/lcr4[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30444/B -to fifo_8b_8d/lcr4[6]/C300R30442/A2

#Constraints for r4[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30440/A0 -to fifo_8b_8d/regr4[6]/LATCH*/G

#Constraints for r4[6] to  r5[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[6]/LATCH*/Q -to fifo_8b_8d/reg r5[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lc r5[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lc r5[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lc r5[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[6]/C300R30442/A0 -to fifo_8b_8d/lc r5[6]/C300R30442/A0


##Constraints for r4[7] ##
#Constraints for r4[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lcr4[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lcr4[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30440/A0 -to fifo_8b_8d/lcr4[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30440/A0 -to fifo_8b_8d/lcr4[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30444/A -to fifo_8b_8d/lcr4[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30444/A -to fifo_8b_8d/lcr4[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30444/B -to fifo_8b_8d/lcr4[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30444/B -to fifo_8b_8d/lcr4[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30444/A -to fifo_8b_8d/lcr4[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30444/A -to fifo_8b_8d/lcr4[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30444/B -to fifo_8b_8d/lcr4[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30444/B -to fifo_8b_8d/lcr4[7]/C300R30442/A2

#Constraints for r4[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30440/A0 -to fifo_8b_8d/regr4[7]/LATCH*/G

#Constraints for r4[7] to  r5[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr4[7]/LATCH*/Q -to fifo_8b_8d/reg r5[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lc r5[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lc r5[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lc r5[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr4[7]/C300R30442/A0 -to fifo_8b_8d/lc r5[7]/C300R30442/A0


##Constraints for r5[0] ##
#Constraints for r5[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lcr5[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lcr5[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30440/A0 -to fifo_8b_8d/lcr5[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30440/A0 -to fifo_8b_8d/lcr5[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30444/A -to fifo_8b_8d/lcr5[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30444/A -to fifo_8b_8d/lcr5[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30444/B -to fifo_8b_8d/lcr5[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30444/B -to fifo_8b_8d/lcr5[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30444/A -to fifo_8b_8d/lcr5[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30444/A -to fifo_8b_8d/lcr5[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30444/B -to fifo_8b_8d/lcr5[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30444/B -to fifo_8b_8d/lcr5[0]/C300R30442/A2

#Constraints for r5[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30440/A0 -to fifo_8b_8d/regr5[0]/LATCH*/G

#Constraints for r5[0] to  r6[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[0]/LATCH*/Q -to fifo_8b_8d/reg r6[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lc r6[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lc r6[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lc r6[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[0]/C300R30442/A0 -to fifo_8b_8d/lc r6[0]/C300R30442/A0


##Constraints for r5[1] ##
#Constraints for r5[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lcr5[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lcr5[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30440/A0 -to fifo_8b_8d/lcr5[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30440/A0 -to fifo_8b_8d/lcr5[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30444/A -to fifo_8b_8d/lcr5[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30444/A -to fifo_8b_8d/lcr5[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30444/B -to fifo_8b_8d/lcr5[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30444/B -to fifo_8b_8d/lcr5[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30444/A -to fifo_8b_8d/lcr5[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30444/A -to fifo_8b_8d/lcr5[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30444/B -to fifo_8b_8d/lcr5[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30444/B -to fifo_8b_8d/lcr5[1]/C300R30442/A2

#Constraints for r5[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30440/A0 -to fifo_8b_8d/regr5[1]/LATCH*/G

#Constraints for r5[1] to  r6[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[1]/LATCH*/Q -to fifo_8b_8d/reg r6[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lc r6[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lc r6[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lc r6[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[1]/C300R30442/A0 -to fifo_8b_8d/lc r6[1]/C300R30442/A0


##Constraints for r5[2] ##
#Constraints for r5[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lcr5[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lcr5[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30440/A0 -to fifo_8b_8d/lcr5[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30440/A0 -to fifo_8b_8d/lcr5[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30444/A -to fifo_8b_8d/lcr5[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30444/A -to fifo_8b_8d/lcr5[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30444/B -to fifo_8b_8d/lcr5[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30444/B -to fifo_8b_8d/lcr5[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30444/A -to fifo_8b_8d/lcr5[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30444/A -to fifo_8b_8d/lcr5[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30444/B -to fifo_8b_8d/lcr5[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30444/B -to fifo_8b_8d/lcr5[2]/C300R30442/A2

#Constraints for r5[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30440/A0 -to fifo_8b_8d/regr5[2]/LATCH*/G

#Constraints for r5[2] to  r6[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[2]/LATCH*/Q -to fifo_8b_8d/reg r6[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lc r6[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lc r6[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lc r6[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[2]/C300R30442/A0 -to fifo_8b_8d/lc r6[2]/C300R30442/A0


##Constraints for r5[3] ##
#Constraints for r5[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lcr5[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lcr5[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30440/A0 -to fifo_8b_8d/lcr5[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30440/A0 -to fifo_8b_8d/lcr5[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30444/A -to fifo_8b_8d/lcr5[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30444/A -to fifo_8b_8d/lcr5[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30444/B -to fifo_8b_8d/lcr5[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30444/B -to fifo_8b_8d/lcr5[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30444/A -to fifo_8b_8d/lcr5[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30444/A -to fifo_8b_8d/lcr5[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30444/B -to fifo_8b_8d/lcr5[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30444/B -to fifo_8b_8d/lcr5[3]/C300R30442/A2

#Constraints for r5[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30440/A0 -to fifo_8b_8d/regr5[3]/LATCH*/G

#Constraints for r5[3] to  r6[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[3]/LATCH*/Q -to fifo_8b_8d/reg r6[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lc r6[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lc r6[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lc r6[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[3]/C300R30442/A0 -to fifo_8b_8d/lc r6[3]/C300R30442/A0


##Constraints for r5[4] ##
#Constraints for r5[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lcr5[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lcr5[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30440/A0 -to fifo_8b_8d/lcr5[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30440/A0 -to fifo_8b_8d/lcr5[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30444/A -to fifo_8b_8d/lcr5[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30444/A -to fifo_8b_8d/lcr5[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30444/B -to fifo_8b_8d/lcr5[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30444/B -to fifo_8b_8d/lcr5[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30444/A -to fifo_8b_8d/lcr5[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30444/A -to fifo_8b_8d/lcr5[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30444/B -to fifo_8b_8d/lcr5[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30444/B -to fifo_8b_8d/lcr5[4]/C300R30442/A2

#Constraints for r5[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30440/A0 -to fifo_8b_8d/regr5[4]/LATCH*/G

#Constraints for r5[4] to  r6[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[4]/LATCH*/Q -to fifo_8b_8d/reg r6[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lc r6[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lc r6[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lc r6[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[4]/C300R30442/A0 -to fifo_8b_8d/lc r6[4]/C300R30442/A0


##Constraints for r5[5] ##
#Constraints for r5[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lcr5[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lcr5[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30440/A0 -to fifo_8b_8d/lcr5[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30440/A0 -to fifo_8b_8d/lcr5[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30444/A -to fifo_8b_8d/lcr5[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30444/A -to fifo_8b_8d/lcr5[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30444/B -to fifo_8b_8d/lcr5[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30444/B -to fifo_8b_8d/lcr5[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30444/A -to fifo_8b_8d/lcr5[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30444/A -to fifo_8b_8d/lcr5[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30444/B -to fifo_8b_8d/lcr5[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30444/B -to fifo_8b_8d/lcr5[5]/C300R30442/A2

#Constraints for r5[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30440/A0 -to fifo_8b_8d/regr5[5]/LATCH*/G

#Constraints for r5[5] to  r6[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[5]/LATCH*/Q -to fifo_8b_8d/reg r6[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lc r6[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lc r6[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lc r6[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[5]/C300R30442/A0 -to fifo_8b_8d/lc r6[5]/C300R30442/A0


##Constraints for r5[6] ##
#Constraints for r5[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lcr5[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lcr5[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30440/A0 -to fifo_8b_8d/lcr5[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30440/A0 -to fifo_8b_8d/lcr5[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30444/A -to fifo_8b_8d/lcr5[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30444/A -to fifo_8b_8d/lcr5[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30444/B -to fifo_8b_8d/lcr5[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30444/B -to fifo_8b_8d/lcr5[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30444/A -to fifo_8b_8d/lcr5[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30444/A -to fifo_8b_8d/lcr5[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30444/B -to fifo_8b_8d/lcr5[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30444/B -to fifo_8b_8d/lcr5[6]/C300R30442/A2

#Constraints for r5[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30440/A0 -to fifo_8b_8d/regr5[6]/LATCH*/G

#Constraints for r5[6] to  r6[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[6]/LATCH*/Q -to fifo_8b_8d/reg r6[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lc r6[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lc r6[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lc r6[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[6]/C300R30442/A0 -to fifo_8b_8d/lc r6[6]/C300R30442/A0


##Constraints for r5[7] ##
#Constraints for r5[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lcr5[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lcr5[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30440/A0 -to fifo_8b_8d/lcr5[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30440/A0 -to fifo_8b_8d/lcr5[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30444/A -to fifo_8b_8d/lcr5[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30444/A -to fifo_8b_8d/lcr5[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30444/B -to fifo_8b_8d/lcr5[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30444/B -to fifo_8b_8d/lcr5[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30444/A -to fifo_8b_8d/lcr5[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30444/A -to fifo_8b_8d/lcr5[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30444/B -to fifo_8b_8d/lcr5[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30444/B -to fifo_8b_8d/lcr5[7]/C300R30442/A2

#Constraints for r5[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30440/A0 -to fifo_8b_8d/regr5[7]/LATCH*/G

#Constraints for r5[7] to  r6[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr5[7]/LATCH*/Q -to fifo_8b_8d/reg r6[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lc r6[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lc r6[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lc r6[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr5[7]/C300R30442/A0 -to fifo_8b_8d/lc r6[7]/C300R30442/A0


##Constraints for r6[0] ##
#Constraints for r6[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lcr6[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lcr6[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30440/A0 -to fifo_8b_8d/lcr6[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30440/A0 -to fifo_8b_8d/lcr6[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30444/A -to fifo_8b_8d/lcr6[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30444/A -to fifo_8b_8d/lcr6[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30444/B -to fifo_8b_8d/lcr6[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30444/B -to fifo_8b_8d/lcr6[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30444/A -to fifo_8b_8d/lcr6[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30444/A -to fifo_8b_8d/lcr6[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30444/B -to fifo_8b_8d/lcr6[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30444/B -to fifo_8b_8d/lcr6[0]/C300R30442/A2

#Constraints for r6[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30440/A0 -to fifo_8b_8d/regr6[0]/LATCH*/G

#Constraints for r6[0] to  r7[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[0]/LATCH*/Q -to fifo_8b_8d/reg r7[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lc r7[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lc r7[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lc r7[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[0]/C300R30442/A0 -to fifo_8b_8d/lc r7[0]/C300R30442/A0


##Constraints for r6[1] ##
#Constraints for r6[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lcr6[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lcr6[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30440/A0 -to fifo_8b_8d/lcr6[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30440/A0 -to fifo_8b_8d/lcr6[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30444/A -to fifo_8b_8d/lcr6[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30444/A -to fifo_8b_8d/lcr6[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30444/B -to fifo_8b_8d/lcr6[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30444/B -to fifo_8b_8d/lcr6[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30444/A -to fifo_8b_8d/lcr6[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30444/A -to fifo_8b_8d/lcr6[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30444/B -to fifo_8b_8d/lcr6[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30444/B -to fifo_8b_8d/lcr6[1]/C300R30442/A2

#Constraints for r6[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30440/A0 -to fifo_8b_8d/regr6[1]/LATCH*/G

#Constraints for r6[1] to  r7[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[1]/LATCH*/Q -to fifo_8b_8d/reg r7[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lc r7[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lc r7[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lc r7[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[1]/C300R30442/A0 -to fifo_8b_8d/lc r7[1]/C300R30442/A0


##Constraints for r6[2] ##
#Constraints for r6[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lcr6[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lcr6[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30440/A0 -to fifo_8b_8d/lcr6[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30440/A0 -to fifo_8b_8d/lcr6[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30444/A -to fifo_8b_8d/lcr6[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30444/A -to fifo_8b_8d/lcr6[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30444/B -to fifo_8b_8d/lcr6[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30444/B -to fifo_8b_8d/lcr6[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30444/A -to fifo_8b_8d/lcr6[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30444/A -to fifo_8b_8d/lcr6[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30444/B -to fifo_8b_8d/lcr6[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30444/B -to fifo_8b_8d/lcr6[2]/C300R30442/A2

#Constraints for r6[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30440/A0 -to fifo_8b_8d/regr6[2]/LATCH*/G

#Constraints for r6[2] to  r7[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[2]/LATCH*/Q -to fifo_8b_8d/reg r7[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lc r7[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lc r7[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lc r7[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[2]/C300R30442/A0 -to fifo_8b_8d/lc r7[2]/C300R30442/A0


##Constraints for r6[3] ##
#Constraints for r6[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lcr6[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lcr6[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30440/A0 -to fifo_8b_8d/lcr6[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30440/A0 -to fifo_8b_8d/lcr6[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30444/A -to fifo_8b_8d/lcr6[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30444/A -to fifo_8b_8d/lcr6[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30444/B -to fifo_8b_8d/lcr6[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30444/B -to fifo_8b_8d/lcr6[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30444/A -to fifo_8b_8d/lcr6[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30444/A -to fifo_8b_8d/lcr6[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30444/B -to fifo_8b_8d/lcr6[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30444/B -to fifo_8b_8d/lcr6[3]/C300R30442/A2

#Constraints for r6[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30440/A0 -to fifo_8b_8d/regr6[3]/LATCH*/G

#Constraints for r6[3] to  r7[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[3]/LATCH*/Q -to fifo_8b_8d/reg r7[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lc r7[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lc r7[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lc r7[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[3]/C300R30442/A0 -to fifo_8b_8d/lc r7[3]/C300R30442/A0


##Constraints for r6[4] ##
#Constraints for r6[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lcr6[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lcr6[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30440/A0 -to fifo_8b_8d/lcr6[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30440/A0 -to fifo_8b_8d/lcr6[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30444/A -to fifo_8b_8d/lcr6[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30444/A -to fifo_8b_8d/lcr6[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30444/B -to fifo_8b_8d/lcr6[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30444/B -to fifo_8b_8d/lcr6[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30444/A -to fifo_8b_8d/lcr6[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30444/A -to fifo_8b_8d/lcr6[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30444/B -to fifo_8b_8d/lcr6[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30444/B -to fifo_8b_8d/lcr6[4]/C300R30442/A2

#Constraints for r6[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30440/A0 -to fifo_8b_8d/regr6[4]/LATCH*/G

#Constraints for r6[4] to  r7[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[4]/LATCH*/Q -to fifo_8b_8d/reg r7[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lc r7[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lc r7[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lc r7[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[4]/C300R30442/A0 -to fifo_8b_8d/lc r7[4]/C300R30442/A0


##Constraints for r6[5] ##
#Constraints for r6[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lcr6[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lcr6[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30440/A0 -to fifo_8b_8d/lcr6[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30440/A0 -to fifo_8b_8d/lcr6[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30444/A -to fifo_8b_8d/lcr6[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30444/A -to fifo_8b_8d/lcr6[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30444/B -to fifo_8b_8d/lcr6[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30444/B -to fifo_8b_8d/lcr6[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30444/A -to fifo_8b_8d/lcr6[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30444/A -to fifo_8b_8d/lcr6[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30444/B -to fifo_8b_8d/lcr6[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30444/B -to fifo_8b_8d/lcr6[5]/C300R30442/A2

#Constraints for r6[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30440/A0 -to fifo_8b_8d/regr6[5]/LATCH*/G

#Constraints for r6[5] to  r7[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[5]/LATCH*/Q -to fifo_8b_8d/reg r7[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lc r7[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lc r7[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lc r7[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[5]/C300R30442/A0 -to fifo_8b_8d/lc r7[5]/C300R30442/A0


##Constraints for r6[6] ##
#Constraints for r6[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lcr6[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lcr6[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30440/A0 -to fifo_8b_8d/lcr6[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30440/A0 -to fifo_8b_8d/lcr6[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30444/A -to fifo_8b_8d/lcr6[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30444/A -to fifo_8b_8d/lcr6[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30444/B -to fifo_8b_8d/lcr6[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30444/B -to fifo_8b_8d/lcr6[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30444/A -to fifo_8b_8d/lcr6[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30444/A -to fifo_8b_8d/lcr6[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30444/B -to fifo_8b_8d/lcr6[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30444/B -to fifo_8b_8d/lcr6[6]/C300R30442/A2

#Constraints for r6[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30440/A0 -to fifo_8b_8d/regr6[6]/LATCH*/G

#Constraints for r6[6] to  r7[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[6]/LATCH*/Q -to fifo_8b_8d/reg r7[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lc r7[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lc r7[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lc r7[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[6]/C300R30442/A0 -to fifo_8b_8d/lc r7[6]/C300R30442/A0


##Constraints for r6[7] ##
#Constraints for r6[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lcr6[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lcr6[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30440/A0 -to fifo_8b_8d/lcr6[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30440/A0 -to fifo_8b_8d/lcr6[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30444/A -to fifo_8b_8d/lcr6[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30444/A -to fifo_8b_8d/lcr6[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30444/B -to fifo_8b_8d/lcr6[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30444/B -to fifo_8b_8d/lcr6[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30444/A -to fifo_8b_8d/lcr6[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30444/A -to fifo_8b_8d/lcr6[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30444/B -to fifo_8b_8d/lcr6[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30444/B -to fifo_8b_8d/lcr6[7]/C300R30442/A2

#Constraints for r6[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30440/A0 -to fifo_8b_8d/regr6[7]/LATCH*/G

#Constraints for r6[7] to  r7[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr6[7]/LATCH*/Q -to fifo_8b_8d/reg r7[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lc r7[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lc r7[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lc r7[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr6[7]/C300R30442/A0 -to fifo_8b_8d/lc r7[7]/C300R30442/A0


##Constraints for r7[0] ##
#Constraints for r7[0] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lcr7[0]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lcr7[0]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30440/A0 -to fifo_8b_8d/lcr7[0]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30440/A0 -to fifo_8b_8d/lcr7[0]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30444/A -to fifo_8b_8d/lcr7[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30444/A -to fifo_8b_8d/lcr7[0]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30444/B -to fifo_8b_8d/lcr7[0]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30444/B -to fifo_8b_8d/lcr7[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30444/A -to fifo_8b_8d/lcr7[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30444/A -to fifo_8b_8d/lcr7[0]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30444/B -to fifo_8b_8d/lcr7[0]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30444/B -to fifo_8b_8d/lcr7[0]/C300R30442/A2

#Constraints for r7[0] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30440/A0 -to fifo_8b_8d/regr7[0]/LATCH*/G

#Constraints for r7[0] to  r8[0]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[0]/LATCH*/Q -to fifo_8b_8d/reg r8[0]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lc r8[0]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lc r8[0]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lc r8[0]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[0]/C300R30442/A0 -to fifo_8b_8d/lc r8[0]/C300R30442/A0


##Constraints for r7[1] ##
#Constraints for r7[1] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lcr7[1]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lcr7[1]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30440/A0 -to fifo_8b_8d/lcr7[1]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30440/A0 -to fifo_8b_8d/lcr7[1]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30444/A -to fifo_8b_8d/lcr7[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30444/A -to fifo_8b_8d/lcr7[1]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30444/B -to fifo_8b_8d/lcr7[1]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30444/B -to fifo_8b_8d/lcr7[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30444/A -to fifo_8b_8d/lcr7[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30444/A -to fifo_8b_8d/lcr7[1]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30444/B -to fifo_8b_8d/lcr7[1]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30444/B -to fifo_8b_8d/lcr7[1]/C300R30442/A2

#Constraints for r7[1] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30440/A0 -to fifo_8b_8d/regr7[1]/LATCH*/G

#Constraints for r7[1] to  r8[1]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[1]/LATCH*/Q -to fifo_8b_8d/reg r8[1]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lc r8[1]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lc r8[1]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lc r8[1]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[1]/C300R30442/A0 -to fifo_8b_8d/lc r8[1]/C300R30442/A0


##Constraints for r7[2] ##
#Constraints for r7[2] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lcr7[2]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lcr7[2]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30440/A0 -to fifo_8b_8d/lcr7[2]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30440/A0 -to fifo_8b_8d/lcr7[2]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30444/A -to fifo_8b_8d/lcr7[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30444/A -to fifo_8b_8d/lcr7[2]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30444/B -to fifo_8b_8d/lcr7[2]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30444/B -to fifo_8b_8d/lcr7[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30444/A -to fifo_8b_8d/lcr7[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30444/A -to fifo_8b_8d/lcr7[2]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30444/B -to fifo_8b_8d/lcr7[2]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30444/B -to fifo_8b_8d/lcr7[2]/C300R30442/A2

#Constraints for r7[2] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30440/A0 -to fifo_8b_8d/regr7[2]/LATCH*/G

#Constraints for r7[2] to  r8[2]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[2]/LATCH*/Q -to fifo_8b_8d/reg r8[2]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lc r8[2]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lc r8[2]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lc r8[2]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[2]/C300R30442/A0 -to fifo_8b_8d/lc r8[2]/C300R30442/A0


##Constraints for r7[3] ##
#Constraints for r7[3] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lcr7[3]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lcr7[3]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30440/A0 -to fifo_8b_8d/lcr7[3]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30440/A0 -to fifo_8b_8d/lcr7[3]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30444/A -to fifo_8b_8d/lcr7[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30444/A -to fifo_8b_8d/lcr7[3]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30444/B -to fifo_8b_8d/lcr7[3]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30444/B -to fifo_8b_8d/lcr7[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30444/A -to fifo_8b_8d/lcr7[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30444/A -to fifo_8b_8d/lcr7[3]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30444/B -to fifo_8b_8d/lcr7[3]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30444/B -to fifo_8b_8d/lcr7[3]/C300R30442/A2

#Constraints for r7[3] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30440/A0 -to fifo_8b_8d/regr7[3]/LATCH*/G

#Constraints for r7[3] to  r8[3]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[3]/LATCH*/Q -to fifo_8b_8d/reg r8[3]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lc r8[3]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lc r8[3]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lc r8[3]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[3]/C300R30442/A0 -to fifo_8b_8d/lc r8[3]/C300R30442/A0


##Constraints for r7[4] ##
#Constraints for r7[4] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lcr7[4]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lcr7[4]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30440/A0 -to fifo_8b_8d/lcr7[4]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30440/A0 -to fifo_8b_8d/lcr7[4]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30444/A -to fifo_8b_8d/lcr7[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30444/A -to fifo_8b_8d/lcr7[4]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30444/B -to fifo_8b_8d/lcr7[4]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30444/B -to fifo_8b_8d/lcr7[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30444/A -to fifo_8b_8d/lcr7[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30444/A -to fifo_8b_8d/lcr7[4]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30444/B -to fifo_8b_8d/lcr7[4]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30444/B -to fifo_8b_8d/lcr7[4]/C300R30442/A2

#Constraints for r7[4] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30440/A0 -to fifo_8b_8d/regr7[4]/LATCH*/G

#Constraints for r7[4] to  r8[4]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[4]/LATCH*/Q -to fifo_8b_8d/reg r8[4]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lc r8[4]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lc r8[4]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lc r8[4]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[4]/C300R30442/A0 -to fifo_8b_8d/lc r8[4]/C300R30442/A0


##Constraints for r7[5] ##
#Constraints for r7[5] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lcr7[5]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lcr7[5]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30440/A0 -to fifo_8b_8d/lcr7[5]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30440/A0 -to fifo_8b_8d/lcr7[5]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30444/A -to fifo_8b_8d/lcr7[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30444/A -to fifo_8b_8d/lcr7[5]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30444/B -to fifo_8b_8d/lcr7[5]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30444/B -to fifo_8b_8d/lcr7[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30444/A -to fifo_8b_8d/lcr7[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30444/A -to fifo_8b_8d/lcr7[5]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30444/B -to fifo_8b_8d/lcr7[5]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30444/B -to fifo_8b_8d/lcr7[5]/C300R30442/A2

#Constraints for r7[5] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30440/A0 -to fifo_8b_8d/regr7[5]/LATCH*/G

#Constraints for r7[5] to  r8[5]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[5]/LATCH*/Q -to fifo_8b_8d/reg r8[5]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lc r8[5]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lc r8[5]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lc r8[5]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[5]/C300R30442/A0 -to fifo_8b_8d/lc r8[5]/C300R30442/A0


##Constraints for r7[6] ##
#Constraints for r7[6] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lcr7[6]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lcr7[6]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30440/A0 -to fifo_8b_8d/lcr7[6]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30440/A0 -to fifo_8b_8d/lcr7[6]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30444/A -to fifo_8b_8d/lcr7[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30444/A -to fifo_8b_8d/lcr7[6]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30444/B -to fifo_8b_8d/lcr7[6]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30444/B -to fifo_8b_8d/lcr7[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30444/A -to fifo_8b_8d/lcr7[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30444/A -to fifo_8b_8d/lcr7[6]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30444/B -to fifo_8b_8d/lcr7[6]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30444/B -to fifo_8b_8d/lcr7[6]/C300R30442/A2

#Constraints for r7[6] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30440/A0 -to fifo_8b_8d/regr7[6]/LATCH*/G

#Constraints for r7[6] to  r8[6]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[6]/LATCH*/Q -to fifo_8b_8d/reg r8[6]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lc r8[6]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lc r8[6]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lc r8[6]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[6]/C300R30442/A0 -to fifo_8b_8d/lc r8[6]/C300R30442/A0


##Constraints for r7[7] ##
#Constraints for r7[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lcr7[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lcr7[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30440/A0 -to fifo_8b_8d/lcr7[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30440/A0 -to fifo_8b_8d/lcr7[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30444/A -to fifo_8b_8d/lcr7[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30444/A -to fifo_8b_8d/lcr7[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30444/B -to fifo_8b_8d/lcr7[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30444/B -to fifo_8b_8d/lcr7[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30444/A -to fifo_8b_8d/lcr7[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30444/A -to fifo_8b_8d/lcr7[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30444/B -to fifo_8b_8d/lcr7[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30444/B -to fifo_8b_8d/lcr7[7]/C300R30442/A2

#Constraints for r7[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30440/A0 -to fifo_8b_8d/regr7[7]/LATCH*/G

#Constraints for r7[7] to  r8[7]#
set_max_delay 0.500 -from fifo_8b_8d/regr7[7]/LATCH*/Q -to fifo_8b_8d/reg r8[7]/LATCH*/D

set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30440/A0
set_max_delay 0.500 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30442/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30440/A0
set_min_delay 0.150 -from fifo_8b_8d/lcr7[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30442/A0


##Constraints for  r8[7] ##
#Constraints for  r8[7] to itself#
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30442/B1
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30442/A0 -to fifo_8b_8d/lc r8[7]/C300R30444/B
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30440/A0 -to fifo_8b_8d/lc r8[7]/C300R30440/B1
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30440/A0 -to fifo_8b_8d/lc r8[7]/C300R30444/A
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30444/A -to fifo_8b_8d/lc r8[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30444/A -to fifo_8b_8d/lc r8[7]/C300R30442/A2
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30444/B -to fifo_8b_8d/lc r8[7]/C300R30440/A2
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30444/B -to fifo_8b_8d/lc r8[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lc r8[7]/C300R30444/A -to fifo_8b_8d/lc r8[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lc r8[7]/C300R30444/A -to fifo_8b_8d/lc r8[7]/C300R30442/A2
set_min_delay 0.150 -from fifo_8b_8d/lc r8[7]/C300R30444/B -to fifo_8b_8d/lc r8[7]/C300R30440/A2
set_min_delay 0.150 -from fifo_8b_8d/lc r8[7]/C300R30444/B -to fifo_8b_8d/lc r8[7]/C300R30442/A2

#Constraints for  r8[7] to their latchs#
set_max_delay 0.500 -from fifo_8b_8d/lc r8[7]/C300R30440/A0 -to fifo_8b_8d/reg r8[7]/LATCH*/G

