# COMP 211 standard Makefile.
#
# Fall 2022

# Required flags for compilation.
CFLAGS+=-std=c99 -Wall

driver : driver.c list.c list.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o driver driver.c list.c

check :
	for f in list.h list.c driver.c ; do \
		$(CC) $(CFLAGS) -c -o /dev/null $$f ; \
	done

clean :
	rm -f driver driver.o
	rm -f list.o


