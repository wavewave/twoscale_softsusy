.PHONY: all

include ../../FlagsForMake

Idir = .. chep_crt plot  service2 getmem

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir))

special = n_calchep.c usrfun.c pdf_dummy.c  alpha_s.c userInt.c

OBJ= $(notdir $(subst .c,.o, $(filter-out $(special),$(wildcard *.c strfun/*.c))))
VPATH = strfun
all: ../../num_c.a ../../dummy.a ../../n_calchep.o $(CALCHEP)/alpha_s.$(SO) $(CALCHEP)/sqme_aux.$(SO)  ../../bin/Int

../../num_c.a:../../num_c.a($(OBJ))
	$(RANLIB) ../../num_c.a
	@rm -f $(OBJ)

../../dummy.a:../../dummy.a(usrfun.o pdf_dummy.o)
	$(RANLIB) $@
	@rm -f usrfun.o pdf_dummy.o

 ../../n_calchep.o: n_calchep.c
	$(CC) $(CFLAGS) -c -o $@  $<

../../bin/Int:  userInt.c ../../serv.a ../../num_c.a
	$(CC) -o ../../bin/Int  $(CFLAGS) userInt.c ../../serv.a ../../num_c.a  -lm

alpha_s_so = $(CALCHEP)/alpha_s.$(SO)
sqme_aux_so =$(CALCHEP)/sqme_aux.$(SO)

ifneq ($(SONAME),)  
ifeq ($(CC),gcc)
 alpha_s_so  := $(alpha_s_so) -Wl,$(SONAME),$(alpha_s_so)
 sqme_aux_so := $(sqme_aux_so) -Wl,$(SONAME),$(sqme_aux_so)
else
 alpha_s_so  := $(alpha_s_so)  $(SONAME) $(alpha_s_so)
 sqme_aux_so := $(sqme_aux_so) $(SONAME) $(sqme_aux_so)
endif
endif

$(CALCHEP)/alpha_s.$(SO): alpha_s.c
	$(CC) $(CFLAGS) $(SHARED) -o $(alpha_s_so)  $<

$(CALCHEP)/sqme_aux.$(SO): sqme_aux.c 
	$(CC) $(CFLAGS) -DforMICROMEGAS $(SHARED) -o $(sqme_aux_so)  $<

