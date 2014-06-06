.PHONY: all

ifneq ($(MAKECMDGOALS),clean)
include ../../CalcHEP_src/FlagsForMake
endif

all:  CPsuperH2/cpsuperh.exe aLib.a mLib.$(SO)

ifeq ($(SONAME),) 
 target = $(CURDIR)/mLib.$(SO)
else 
ifeq ($(CC),gcc)
 target = $(CURDIR)/mLib.$(SO) -Wl,$(SONAME),$(CURDIR)/mLib.$(SO)
else
 target = $(CURDIR)/mLib.$(SO) $(SONAME) $(CURDIR)/mLib.$(SO)
endif
endif


cpsuperh_call.o:localpath.h cpsuperh_call.c
	$(CC) -c cpsuperh_call.c	

localpath.h:
	echo \#define lPath   \"$(CURDIR)\"  >  localpath.h

mLib.$(SO) : cpsuperh_call.c 
	$(CC) $(SHARED) -o $(target)  $^ -lm

aLib.a:  aLib.a(hMasses.o fort.o edm.o qbox.o  cpsuperh_call.o rdVarCPVMSSM.o)
	$(RANLIB) aLib.a
	rm -f hMasses.o fort.o cpsuperh_call.o
	
#edm.o : edm.c
#	 cc -c edm.c
        
CPsuperH2/cpsuperh.exe: CPsuperH2/*.f
	$(MAKE) -C CPsuperH2


clean: 
	rm -f *.o *.a *.so *.dll localpath.h
	$(MAKE) -C CPsuperH2 clean

  
