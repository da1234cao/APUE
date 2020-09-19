ROOT=..
include $(ROOT)/Make.defines

PROGS =	file_type file_access file_umask

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
	rm -f *.txt
