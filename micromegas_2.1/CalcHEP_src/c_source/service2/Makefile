.PHONY: all

include ../../FlagsForMake

Idir= .. chep_crt getmem

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir))

special = main_calc.c

OBJ= $(subst .c,.o, $(filter-out $(special),$(wildcard *.c)))

all: ../../serv.a  ../../bin/calc

../../serv.a:../../serv.a($(OBJ))
	$(RANLIB) ../../serv.a
	@rm -f $(OBJ)


 ../../bin/calc: main_calc.c ../../serv.a
	$(CC) $(CFLAGS)  -o $@    $^ -lm
