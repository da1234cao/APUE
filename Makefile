# ROOT ?= $(shell pwd)

# export CC=gcc
# export LDFLAGS=
# export LDDIR=-L$(ROOT)/lib
# export LDLIBS=$(LDDIR) -lapue $(EXTRALIBS)
# export LIBAPUE=$(ROOT)/lib/libapue.a
# export CFLAGS=-I$(ROOT)/include

ROOT=.
include $(ROOT)/Make.defines

DIRS = lib chapter01_UNIX的基础知识 chapter04_文件和目录

all:
	for i in $(DIRS); do \
		(cd $$i && echo "cd and making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cd and cleaning $$i" && $(MAKE) clean) || exit 1; \
	done