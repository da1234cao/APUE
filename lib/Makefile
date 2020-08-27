#
# Makefile for misc library.
#
LIBMISC	= libapue.a
OBJS   = error.o

all:	$(LIBMISC)

$(LIBMISC):	$(OBJS)
	ar crv $(LIBMISC) $?
	echo "make $(LIBMISC)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out $(LIBMISC)
