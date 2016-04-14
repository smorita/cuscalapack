include SLmake_cuBLAS.inc

.PHONY: all clean cleanall

all:
	$(MAKE) -C PBLAS/SRC double complex16
	$(MAKE) -C tools

clean:
	$(MAKE) -C PBLAS/SRC clean
	$(MAKE) -C tools clean

cleanall: clean
	-rm -f $(SCALAPACKLIB)
