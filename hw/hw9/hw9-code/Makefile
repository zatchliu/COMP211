# COMP 211 standard Makefile.
#
# Fall 2022

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

driver : driver.c hw9.c hw9.h comp211.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c hw9.c

tests : tests.c hw9.c hw9.h comp211.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o tests tests.c hw9.c

clean :
	rm -f driver driver.o
	rm -f tests tests.o
	rm -f hw9.o


