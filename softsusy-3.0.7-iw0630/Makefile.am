bin_PROGRAMS = softsusy.x softpoint.x rpvsoftsusy.x

noinst_LTLIBRARIES = libsoft.la

softsusy_x_SOURCES = main.cpp

softsusy_x_LDADD = libsoft.la

softpoint_x_SOURCES = softpoint.cpp 
softpoint_x_LDADD = libsoft.la

rpvsoftsusy_x_SOURCES = rpvmain.cpp
rpvsoftsusy_x_LDADD = libsoft.la

EXTRA_DIST = slha2Input slha2Output outputTest rpvOutputTest lesHouchesInput lesHouchesOutput rpvHouchesInput rpvHouchesOutput 
#EXTRA_DIST = lesHouchesInput

noinst_HEADERS = def.h     main.h       numerics.h  softpars.h   susy.h \
linalg.h  physpars.h  softpoint.h  twoloophiggs.h \
lowe.h    mycomplex.h  rge.h       softsusy.h   utils.h    rpvsoft.h \
rpvsusypars.h   tensor.h   rpvmain.h flavoursoft.h

libsoft_la_SOURCES = linalg.cpp lowe.cpp mycomplex.cpp numerics.cpp \
physpars.cpp rge.cpp softpars.cpp softsusy.cpp susy.cpp utils.cpp \
twoloophiggs.f tensor.cpp rpvsusypars.cpp rpvsoft.cpp flavoursoft.cpp \
softsusy2.cpp softsusy3.cpp
libsoft_la_LDFLAGS = $(FLIBS)

slha2Output: softpoint.x slha2Input
	./softpoint.x leshouches < $(srcdir)/slha2Input > slha2Output

rpvHouchesOutput: softpoint.x rpvHouchesInput
	./softpoint.x leshouches < $(srcdir)/rpvHouchesInput > rpvHouchesOutput

lesHouchesOutput: softpoint.x lesHouchesInput
	./softpoint.x leshouches < $(srcdir)/lesHouchesInput > lesHouchesOutput

outputTest: softsusy.x
	./softsusy.x > outputTest

rpvOutputTest: rpvsoftsusy.x
	./rpvsoftsusy.x > rpvOutputTest

