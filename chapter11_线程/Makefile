ROOT=..
include $(ROOT)/Make.defines

PROGS =	thread_create
all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
	rm -f *.txt core*
