#
# Makefile for misc library.
#

ROOT=..
include $(ROOT)/Make.defines

LIBMISC	= libapue.a
OBJS   = error.o

all:	$(LIBMISC)

$(LIBMISC):	$(OBJS)
	ar crv $(LIBMISC) $?
	rm -f *.o
	echo "make $(LIBMISC)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out $(LIBMISC)
