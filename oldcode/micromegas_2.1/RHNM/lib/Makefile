.PHONY: all clean

ifneq ($(MAKECMDGOALS),clean)
include ../../CalcHEP_src/FlagsForMake 
endif

ifeq ($(SONAME),) 
 target = $(CURDIR)/mLib.$(SO)
else 
ifeq ($(CC),gcc)
 target = $(CURDIR)/mLib.$(SO) -Wl,$(SONAME),$(CURDIR)/mLib.$(SO)
else
 target = $(CURDIR)/mLib.$(SO) $(SONAME) $(CURDIR)/mLib.$(SO)
endif
endif


all: mLib.$(SO) aLib.a

mLib.$(SO):lzp.c bessj0.c bessj1.c bessy0.c bessy1.c bessjy.c chebev.c nrutil.c simp.c couplings.c dd.c
	$(CC)  $(SHARED) -o $(target) $^ -lm

aLib.a:aLib.a(rdVarRHNM.o)
	$(RANLIB) aLib.a
	rm -f rdVarRHNM.o

clean: 
	rm -f *.o *.a *.so *.dll
