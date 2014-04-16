
.PHONY: all libs clean

# read compiler flags
ifneq ($(MAKECMDGOALS),clean)
AllFlags = ../CalcHEP_src/FlagsForMake
ifeq (,$(wildcard $(AllFlags) )) 
$(error File $(AllFlags) is absent. Presumably you forgot to compile main code)
endif 
include ../CalcHEP_src/FlagsForMake 
endif 

# files to compile
SSS = $(main) $(wildcard lib/aLib.a) ../sources/micromegas.a  $(wildcard lib/mLib.$(SO)) work/work_aux.a $(CALCHEP)/sqme_aux.$(SO) $(CALCHEP)/alpha_s.$(SO) 

all: $(main) libs
ifeq (,$(main)) 
	@echo Main program is not specified. Use gmake main='<code of main program>'
else
ifeq (.cpp,$(suffix $(main)))
	$(CXX) $(CFLAGS) -o $(main:.cpp=) $(SSS) $(lDL)  -lm
else
ifeq (.c,$(suffix $(main)))
	$(CC) $(CFLAGS) -o $(main:.c=) $(SSS) $(lDL)  -lm
else 
ifeq (.F,$(suffix $(main)))
	$(FC) $(FFLAGS) -o $(main:.F=)  $(SSS)  $(lDL)  -lm
else 
	 @echo Only .c, .cpp, and .F  main programs  are expected.
endif
endif
endif
endif

libs:
	$(MAKE) -C work
	$(MAKE) -C lib

clean: 
	$(MAKE) -C lib  clean
	$(MAKE) -C work clean 
	rm -f calchep/tmp/* calchep/results/*
	../sources/cleanexe
	rm -f LesHin LesHout suspect2_lha.in suspect2_lha.out suspect2.out tab
	rm -f Control.in LesHouches.in Messages.out SPheno.out slha.in slha.out
