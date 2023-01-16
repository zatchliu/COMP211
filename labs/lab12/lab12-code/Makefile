# COMP 211 standard Makefile.
#
# Fall 2022

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

driver : driver.c set.c hash.c set.h hash.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c set.c hash.c

clean :
	rm -f driver driver.o
	rm -f set.o


