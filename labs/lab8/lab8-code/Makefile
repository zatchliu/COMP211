# COMP 211 standard Makefile.
#
# Fall 2022

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

qdriver: qdriver.c queue.c queue.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o qdriver qdriver.c queue.c

clean :
	rm -f qdriver *.o


