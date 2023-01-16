/*
 * Fall 2022, COMP 211: Lab 4
 *
 * Testing program for linear search, multi-file programs.
 *
 * Testing code for linsearch.  This is another program (i.e., it defines main,
 * just like driver.c does).  But this program is rather different than the
 * program from driver.c.  Instead of interacting with the user, it calls
 * linsearch many times, using the dotest function to report on whether the
 * value returned by linsearch is the value that we expect.
 *
 * The dotest function is defined in comp211.h.  You'll notice that there is no
 * corresponding comp211.c file.  That is because header files can contain some
 * items that are not function declarations.  We will learn about those soon.
 * For now, you can treat dotest as a built-in function, but you must inlcude
 * comp211.h to use it.
 *
 * Compile this file with:  gcc -o tests tests.c linsearch.c
 */

#include <stdio.h>
#include <string.h>

#include "comp211.h"
#include "linsearch.h"

int main() {
    // The following instruction declares a char array and initializes it to
    // the given string.  That means that s will be declared to be an array
    // of length 1 more than the number of characters in the string, and the
    // last char in s will be set to '\0'.  Strings are just about the only
    // time you should not explicitly set the size of the array when you
    // declare it.
    char s[] = "Hello, my name is Victoria";
    int len = strlen(s);

    // dotest(e) takes a bool expression e and does the following:
    // - Prints e as a string to the terminal.
    // - Evaluates e;
    //   - If e evaluates to true, prints "pass" to the terminal.
    //   - If e evaluates to false, prints "FAIL" to the terminal.
    // dotest is defined in comp211.h.

    dotest(linsearch(s, len, 'H') == 0);
    dotest(linsearch(s, len, 'c') == 20);
    dotest(linsearch(s, len, 'V') == 18);
    dotest(linsearch(s, len, 'x') == -1);
    dotest(linsearch(s, len, 'h') == -1);
    dotest(linsearch(s, len, 'l') == 2);
    return 0;
}
