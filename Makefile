ROOT ?= $(shell pwd)

export CC=gcc
export LDFLAGS=
export LDDIR=-L$(ROOT)/lib
export LDLIBS=$(LDDIR) -lapue $(EXTRALIBS)
export LIBAPUE=$(ROOT)/lib/libapue.a
export CFLAGS=-I$(ROOT)/include

DIRS = lib chpater01_UNIX的基础知识

all:
	for i in $(DIRS); do \
		(cd $$i && echo "cd and making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cd and cleaning $$i" && $(MAKE) clean) || exit 1; \
	done