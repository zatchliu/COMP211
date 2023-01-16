# COMP 211, Fall 2022, Wesleyan University
#

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

tests : tests.c array_func.c array_func.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o tests tests.c array_func.c

clean :
	rm -f driver driver.o
	rm -f tests tests.o
	rm -f array_func.o


