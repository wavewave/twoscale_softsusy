OPT=-I../softsusy-3.0.7-iw0630 -I../micromegas_2.2.CPC/sources/ -I../micromegas_2.2.CPC/MSSM/lib  -fsigned-char -Wstrict-prototypes -Wimplicit -Wmissing-prototypes -Wunused -rdynamic



all: dmmsoftsusy

dmmsoftsusy: dmmsoftsusy.o dmmyacc.tab.o dmmlex.o action.o
	libtool --mode=link g++ -o dmmsoftsusy dmmsoftsusy.o  dmmyacc.tab.o dmmlex.o action.o  $(CURDIR)/../softsusy-3.0.7-iw0630/libsoft.la $(CURDIR)/../micromegas_2.2.CPC/MSSM/lib/aLib.a $(CURDIR)/../micromegas_2.2.CPC/sources/micromegas.a $(CURDIR)/../micromegas_2.2.CPC/MSSM/work/work_aux.a $(CURDIR)/../micromegas_2.2.CPC/CalcHEP_src/lib/sqme_aux.so $(CURDIR)/../micromegas_2.2.CPC/CalcHEP_src/lib/model_aux.so -lm -ldl 
 
dmmsoftsusy.o: dmmsoftsusy.cpp
	g++ -c dmmsoftsusy.cpp $(OPT) 


#dmm: dmmyacc.tab.o dmmlex.o action.o
#	gcc -o dmm dmmyacc.tab.o dmmlex.o action.o -lm

dmmyacc.tab.o: dmmyacc.tab.c
	gcc -c dmmyacc.tab.c

dmmlex.o: dmmlex.c
	gcc -c dmmlex.c

dmmlex.c: dmmlex.l
	flex -odmmlex.c dmmlex.l

dmmyacc.tab.c: dmmyacc.y
	bison -d dmmyacc.y

action.o: action.h action.c
	gcc -c action.c

clean: 
	rm *.o ; rm dmmsoftsusy
