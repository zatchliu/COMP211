/*
 * Fall 2022, COMP 211: Lab 4
 *
 * Linear search, multi-file programs.
 *
 * Assuming this program is in a directory that also has the files
 * linsearch.c and linsearch.h, compile with:
 *
 *      gcc -o driver driver.c linsearch.c
 */

#include <stdio.h>
#include <string.h>

// linsearch.h has the function declaration for the linsearch function
// that is defined in linsearch.c and that we use in this program.  This
// directive tells the compiler to insert the contents of linsearch.h
// at this point in this file before proceeding.
#include "linsearch.h"

const int MAX_LEN = 256;

int main() {
    char s[MAX_LEN]; // String to be entered by the user.
    char c; // Character to search for in s.
    int len; // Length of s.

    printf("Enter a string: ");
    fgets(s, MAX_LEN, stdin);

    printf("Enter a character to search for: ");
    scanf(" %c", &c);

    // Remember, fgets includes the newline character as part of s, so we
    // will replace that newline with a null character.
    len = strlen(s);
    s[len-1] = '\0';
    --len;

    printf("Index of first occurrence of '%c' in \"%s\": %d\n", c, s,
            linsearch(s, len, c));

    return 0;
}
