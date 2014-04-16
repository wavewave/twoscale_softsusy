.PHONY: all

include ../../FlagsForMake

override CFLAGS += -Iinclude -I../chep_crt/include

OBJ= $(subst .c,.o,$(wildcard *.c))

all:../../serv.a

../../serv.a:../../serv.a($(OBJ))
	$(RANLIB) ../../serv.a
	@rm -f $(OBJ)
