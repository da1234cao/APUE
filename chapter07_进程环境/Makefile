ROOT=..
include $(ROOT)/Make.defines

PROGS =	atexit longjmp getrlimit

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
	rm -f *.txt
