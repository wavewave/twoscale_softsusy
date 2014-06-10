SPHENO =
SOFTSUSY =
ISAJET =
CERNLIB =
#======================
SUSPECT=$(CURDIR)
MDIR = $(subst /lib*?,,$(CURDIR)*?)

#read compiler options ..

ifneq ($(MAKECMDGOALS),clean)
include ../../CalcHEP_src/FlagsForMake
endif 

.PHONY: all clean

VPATH = SuSpect:../../sources

SuSpectSRC = $(wildcard SuSpect/*.f)

special = isajetLesH.c

aLibOBJ =  $(subst .c,.o,  $(filter-out  $(special),$(wildcard *.c) )) 

all:  suspect.exe aLib.a 

suspect.exe: $(SuSpectSRC) 
	$(MAKE) -C SuSpect

aLib.a(suspect_call.o):suspect_path.h
aLib.a(isasugra_call.o):isajet_path.h
aLib.a(ssusy_call.o): ssusy_path.h
aLib.a(spheno_call.o):spheno_path.h

ssusy_path.h: Makefile
	echo \#define SOFTSUSY \"$(SOFTSUSY)\"  > ssusy_path.h
spheno_path.h: Makefile
	echo \#define SPHENO \"$(SPHENO)\"  > spheno_path.h
isajet_path.h:Makefile
	echo \#define ISAJET \"`pwd`\"  > isajet_path.h
suspect_path.h:Makefile
	echo \#define SUSPECT \"$(SUSPECT)\"  > suspect_path.h
aLib.a:aLib.a($(aLibOBJ))
	$(RANLIB) aLib.a
	rm -f $(aLibOBJ)

isajet_slha: isasugra_slha.f isajetLesH.c
	$(CC) $(CFLAGS) -c  isajetLesH.c
	$(FC) $(FFLAGS) -o isajet_slha isasugra_slha.f isajetLesH.o \
   -L$(ISAJET) -L$(CERNLIB) -lisajet -lmathlib

clean: 
	rm -f *.o *.a  *.so *.dll *.exe *_path.h isajet_slha so_locations 
	$(MAKE) -C SuSpect  clean
