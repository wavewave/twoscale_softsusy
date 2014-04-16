ifneq ($(MAKECMDGOALS),clean)
include ../../../CalcHEP_src/FlagsForMake
endif

cpsuperh.exe: libcpsuperh.a cpsuperh2.f
	$(F77)  -o cpsuperh.exe cpsuperh2.f libcpsuperh.a

libcpsuperh.a: libcpsuperh.a(fillpara2.o fillhiggs2.o fillcoupl2.o fillgambr2.o filldhpg.o higgsedm.o fillbobs.o)
	$(RANLIB) libcpsuperh.a
	rm *.o

clean:
	 rm -f cpsuperh.exe libcpsuperh.a
