
.PHONY:  clean all

ifneq ($(MAKECMDGOALS),clean)
include ../../CalcHEP_src/FlagsForMake
endif

all: work_aux.a newProcess

workOBJ = variables.o  odd_particles.o path.o

work_aux.a: work_aux.a($(workOBJ))
	$(RANLIB) work_aux.a 
	rm -f $(workOBJ)

variables.c: models/vars1.mdl
	../../sources/getVAR 

odd_particles.c: models/prtcls1.mdl
	../../sources/getOdd

path.c:
	echo char \* WORK=\"`pwd`\"\; >  path.c

newProcess: ../../sources/newProcess
	cp  ../../sources/newProcess .

clean:
	rm -f *.a *.o  lock_ LOCK  results/* tmp/* models/*2.mdl so_generated/* lock_
	rm -f  path.c variables.c  odd_particles.c  newProcess
