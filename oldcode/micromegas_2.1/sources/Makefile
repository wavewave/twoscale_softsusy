  
.PHONY: all clean

ifneq ($(MAKECMDGOALS),clean)
include ../CalcHEP_src/FlagsForMake
endif

all:getVAR getOdd micromegas.a 

override CFLAGS += $(FLOCK) -DMAKE=\"$(MAKE)\"

special = getVAR.c  getOdd.c
OBJ= $(notdir $(subst .c,.o,$(filter-out $(special), $(wildcard *.c )))) faux.o
micromegas.a:micromegas.a($(OBJ)) 
	$(RANLIB) micromegas.a 
	rm -f *.o


getVAR: getVAR.c
	$(CC) $(CFLAGS) -o getVAR getVAR.c

getOdd: getOdd.c
	$(CC) $(CFLAGS)  -o getOdd getOdd.c

clean:
	rm -f *.a  *.o   getVAR getOdd  *.exe
