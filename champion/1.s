#
# ex.s for corewar
#
# Alexandre David
#
#Sat Nov 10 22:24:30 2201
#
.name "zork"
.comment "just a basic living prog"

l2:
	sti r1,%:live,%1
	and r1,%0,r1
live:	 live %1
	zjmp %:live
