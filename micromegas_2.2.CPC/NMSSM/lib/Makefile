.PHONY: clean all

Tools = NMSSMTools_2.1.0

ifneq ($(MAKECMDGOALS),clean)
include ../../CalcHEP_src/FlagsForMake
endif

aLibOBJ = fort.o hMasses.o nmssm.o  calchep_func.o  rdVarNMSSM.o \
  lesHouches.o

MDIR = $(subst /lib*?,,$(CURDIR)*?)

ifeq ($(SONAME),) 
  target = $(CURDIR)/mLib.$(SO)
else
  target = $(CURDIR)/mLib.$(SO) $(SONAME) $(CURDIR)/mLib.$(SO)
endif

all:  aLib.a  nmhdecay nmspec 

aLib.a:aLib.a($(aLibOBJ))
	$(RANLIB) aLib.a
	rm -f $(aLibOBJ)

aLib.a(nmssm.o): lpath.h

lpath.h:
	echo \#define LPATH \"`pwd`\" > lpath.h

nmhdecay: $(Tools)/nmhdecay.F $(Tools)/sources/*.f
	echo $(MAKE) -C  $(Tools) ../nmhdecay
	$(MAKE) -C  $(Tools) ../nmhdecay
 
nmspec: $(Tools)/nmspec.F $(Tools)/sources/*.f
	$(MAKE) -C  $(Tools) ../nmspec



clean: 
	rm -f lpath.h *.o *.a *.so *.dll *.exe  so_locations 
	$(MAKE) -C $(Tools) clean
