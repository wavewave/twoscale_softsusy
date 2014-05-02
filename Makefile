 
# Makefile for SOFTSUSY library and test program
# Ben Allanach 

.KEEP_STATE:

# Choose your c++ compiler here: if you want to use the link to fortran, 
# it's probably going to have to be g++ on linux
CC=	g++
# fortran compiler
FF=     gfortran

.SUFFIXES:	.o .cpp .h .f
.PRECIOUS:	.cpp .h .f libsoft.a

#Optimisation level, eg: -O2 -march=i686, speeds by a factor of 2 on my machine
OPT= -I$(CURDIR)/micromegas_2.1/sources/ -I$(CURDIR)/micromegas_2.1/MSSM/lib  -fsigned-char -Wstrict-prototypes -Wimplicit -Wmissing-prototypes -Wunused -rdynamic
#OR debug level: -g(n=1,2,3)
DEBUG=
CFLAGS= -I. -L. $(DEBUG) $(OPT)

.cpp.o:
	$(CC) -c $(CFLAGS) $<
.cpp.a:
	$(CC) -c $(CFLAGS) $<
	ar r $@ $*.o; rm $*.o
.f.o:
	$(FF) $(OPT) -c $< 
.f.a:
	$(FF) $(OPT) -c $< 
	ar r $@ $*.o; rm $*.o

# Chooses whether to use ranlib - not if your system is a linux one
all: softsusy.x softpoint.x softpoint3.x softpointscan3.x softpointscan3ft.x softpointscan3gn.x softpoint4.x softpointscan4.x
	case `uname` in \
	   Linux) RANL=;;\
	   OSF1) CFLAGS="$(CFLAGS) -ieee";;\
	   *) RANL="ranlib libnr.a";;\
	   esac

# Example C++ Softsusy calling program
softsusy.x: Makefile main.o libsoft.a
	$(CC) -o softsusy.x $(CFLAGS) main.o -lm -lsoft -lgfortran;\
	touch softsusy.x

# Command-line program interface
softpoint.x: Makefile softpoint.o libsoft.a
	$(CC) -o softpoint.x $(CFLAGS) softpoint.o -lm -lsoft -lgfortran;\
	touch softpoint.x

#softpoint2.x: Makefile softpoint2.o libsoft.a
#	$(CC) -o softpoint2.x $(CFLAGS) softpoint2.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/lib/mLib.so $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so -lm -ldl -lsoft -lgfortran;\
#	touch softpoint2.x


softpoint3.x: Makefile softpoint3.o libsoft.a
	$(CC) -o softpoint3.x $(CFLAGS) softpoint3.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpoint3.x

softpoint4.x: Makefile softpoint4.o libsoft.a
	$(CC) -o softpoint4.x $(CFLAGS) softpoint4.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpoint4.x

#softpointscan.x: Makefile softpointscan.o libsoft.a
#	$(CC) -o softpointscan.x $(CFLAGS) softpointscan.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/lib/mLib.so $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran;\
#	touch softpointscan.x

softpointscan3.x: Makefile softpointscan3.o libsoft.a
	$(CC) -o softpointscan3.x $(CFLAGS) softpointscan3.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpointscan3.x

softpointscan3ft.x: Makefile softpointscan3ft.o libsoft.a
	$(CC) -o softpointscan3ft.x $(CFLAGS) softpointscan3ft.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpointscan3ft.x

softpointscan3gn.x: Makefile softpointscan3gn.o libsoft.a
	$(CC) -o softpointscan3gn.x $(CFLAGS) softpointscan3gn.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpointscan3gn.x


softpointscan4.x: Makefile softpointscan4.o libsoft.a
	$(CC) -o softpointscan4.x $(CFLAGS) softpointscan4.o $(CURDIR)/micromegas_2.1/MSSM/lib/aLib.a $(CURDIR)/micromegas_2.1/sources/micromegas.a $(CURDIR)/micromegas_2.1/MSSM/work/work_aux.a $(CURDIR)/micromegas_2.1/CalcHEP_src/sqme_aux.so $(CURDIR)/micromegas_2.1/CalcHEP_src/alpha_s.so -lm -ldl -lsoft -lgfortran -lgsl -lblas -lgslcblas;\
#	touch softpointscan4.x

# twoloop higgs not deleted because it takes so long to compile
clean:
	ar x libsoft.a twoloophiggs.o; \
	rm *.a main.o sabine.o softpoint.o *.x *~; \
	ar r libsoft.a twoloophiggs.o; rm twoloophiggs.o

libsoft.a: libsoft.a(rge.o) libsoft.a(utils.o) \
	libsoft.a(linalg.o) libsoft.a(lowe.o) \
	libsoft.a(susy.o) libsoft.a(softsusy.o) \
	libsoft.a(mycomplex.o) libsoft.a(numerics.o) \
	libsoft.a(physpars.o) libsoft.a(softpars.o) libsoft.a(twoloophiggs.o)
	$(RANL)

backup: 
	uufiles < .backupinstructions; 

softpointscan.o: softpointscan.cpp linalg.h utils.h softsusy.h def.h
softpointscan3.o: softpointscan3.cpp linalg.h utils.h softsusy.h def.h
softpointscan3ft.o: softpointscan3ft.cpp linalg.h utils.h softsusy.h def.h
softpointscan3gn.o: softpointscan3gn.cpp linalg.h utils.h softsusy.h def.h
softpointscan4.o: softpointscan4.cpp linalg.h utils.h softsusy.h def.h
softpoint2.o: softpoint2.cpp linalg.h utils.h softsusy.h def.h
softpoint3.o: softpoint3.cpp linalg.h utils.h softsusy.h def.h
softpoint4.o: softpoint4.cpp linalg.h utils.h softsusy.h def.h
softpoint.o: softpoint.cpp linalg.h utils.h softsusy.h def.h
main.o: main.cpp linalg.h utils.h softsusy.h def.h
libsoft.a(numerics.o): numerics.cpp numerics.h linalg.h def.h
libsoft.a(rge.o): rge.cpp rge.h def.h
libsoft.a(softpars.o): softpars.cpp softpars.h susy.h def.h linalg.h
libsoft.a(physpars.o): physpars.cpp physpars.h
libsoft.a(mycomplex.o): mycomplex.cpp mycomplex.h utils.h
libsoft.a(utils.o): utils.cpp utils.h linalg.h
libsoft.a(linalg.o): linalg.cpp linalg.h utils.h 
libsoft.a(lowe.o): lowe.cpp lowe.h linalg.h rge.h def.h
libsoft.a(susy.o): susy.cpp susy.h lowe.h utils.h linalg.h rge.h def.h
libsoft.a(utils.o): utils.cpp utils.h linalg.h def.h
libsoft.a(softsusy.o): softsusy.cpp mycomplex.h softsusy.h susy.h lowe.h \
	linalg.h rge.h def.h utils.h numerics.h softpars.h
libsoft.a(twoloopshiggs.o): twoloophiggs.f twoloophiggs.h

