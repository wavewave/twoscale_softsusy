.PHONY: all

include ../../FlagsForMake

Idir= .. num chep_crt service2 getmem

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir))

special = view_tab.c

OBJ= $(subst .c,.o, $(filter-out $(special),$(wildcard *.c)))

../../bin/plot_view:  view_tab.c ../../num_c.a ../../serv.a
	$(CC) $(CFLAGS) -o $@ $^  $(LX11) -lm

../../num_c.a:../../num_c.a($(OBJ))
	$(RANLIB) $@
	@rm -f $(OBJ)
