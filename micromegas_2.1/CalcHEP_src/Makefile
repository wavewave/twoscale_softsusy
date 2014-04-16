
.PHONY: all  COMPILE clean

ifeq ($(MAKECMDGOALS),clean)
clean :
	./setPath " "
	rm -f *.a *.o FlagsFor* *.so so_locations CMessage
	cd bin; rm -f Int calc events2tab s_calchep show_distr sum_distr plot_view
endif

all:FlagsForMake COMPILE


FlagsForMake:
	./getFlags

COMPILE:FlagsForMake
	./setPath $(CURDIR)
	$(MAKE) -C c_source/getmem 
	$(MAKE) -C c_source/chep_crt
	$(MAKE) -C c_source/service2
	$(MAKE) -C c_source/polynom  
	$(MAKE) -C c_source/symb
	$(MAKE) -C c_source/plot 
	$(MAKE) -C c_source/num 
	$(MAKE) -C c_source/tab
#	@if(test -r CMessage) then cat CMessage; fi
