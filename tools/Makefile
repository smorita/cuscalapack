include ../SLmake_cuBLAS.inc

OBJS = init.o

.PHONY: all clean

all: $(OBJS)
	$(ARCH) $(ARCHFLAGS) ../$(SCALAPACKLIB) $(OBJS)
	$(RANLIB) ../$(SCALAPACKLIB)

clean:
	-rm -f $(OBJS)

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
