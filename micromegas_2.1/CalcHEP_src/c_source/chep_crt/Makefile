
include ../../FlagsForMake

Idir= getmem

override CFLAGS += $(FLOCK) -Iinclude $(patsubst %,-I../%/include ,$(Idir)) $(HX11)


OBJ= $(subst .c,.o,$(wildcard *.c)) X11_crt0.o

ifeq (,$(LX11))
 vpath X11_crt0.c noxwin
else 
 vpath X11_crt0.c xwin
endif


../../serv.a:../../serv.a($(OBJ))
	$(RANLIB) ../../serv.a
	@rm -f $(OBJ)
