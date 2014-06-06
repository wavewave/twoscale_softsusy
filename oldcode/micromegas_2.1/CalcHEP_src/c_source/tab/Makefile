.PHONY: all

include ../../FlagsForMake

Idir = .. num chep_crt service2 getmem

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir))

LIBS = ../../num_c.a ../../serv.a ../../dummy.a  $(CALCHEP)/sqme_aux.$(SO)

all: ../../bin/events2tab ../../bin/show_distr ../../bin/sum_distr

../../bin/events2tab:events2tab.c e_tools.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LX11) -lm

../../bin/show_distr:show_distr.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LX11) -lm

../../bin/sum_distr:sum_distr.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LX11) -lm
