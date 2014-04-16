
include ../../FlagsForMake

Idir= chep_crt getmem service2 symb

override CFLAGS += -Iinclude $(patsubst %,-I../%/include ,$(Idir)) $(SNUM)


OBJ= $(subst .c,.o, $(wildcard *.c))


../../symb.a:../../symb.a($(OBJ))
	$(RANLIB) ../../symb.a
	@rm -f $(OBJ)
