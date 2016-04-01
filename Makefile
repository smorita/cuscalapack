include SLmake_cuBLAS.inc

.PHONY: all clean

all:
	$(MAKE) -C PBLAS/SRC double complex16

clean:
	$(MAKE) -C PBLAS/SRC clean

cleanall: clean
	-rm -f $(SCALAPACKLIB)
