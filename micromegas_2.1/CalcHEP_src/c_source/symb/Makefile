
include ../../FlagsForMake

Idir= chep_crt service2  polynom getmem  ..

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir)) $(SNUM)

special = s_calchep.c

VPATH = out diagram
OBJ= $(notdir $(subst .c,.o, $(filter-out $(special),$(wildcard *.c diagram/*.c out/*.c))))


../../bin/s_calchep: s_calchep.c ../../symb.a ../../serv.a
	$(CC) $(CFLAGS) -o $@ $^  $(LX11) -lm

../../symb.a:../../symb.a($(OBJ))
	$(RANLIB) $@
	@rm -f $(OBJ)
