ROOT=..
include $(ROOT)/Make.defines

PROGS =	fork_exercise status_exercise race_condation exec_exercise nice

all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) *.o
	rm -f *.txt core*
