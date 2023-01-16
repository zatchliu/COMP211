/*
 * Fall 2022, COMP 211: Lab 4
 *
 * Linear search, multi-file programs.
 *
 * This is a standard linear search implementation.  Notice that there is no
 * main function defined in this file.  This file cannot be used to define a
 * standalone program.  It must be combined with at least one other file of
 * source code that defines the main function.  A file like this one that has
 * no main function is sometimes called a library file.
 *
 * Library files usually have an associated header file, commonly named the
 * same as the library file, but with ".c" replaced with ".h".  The header file
 * has function declarations for the functions that are defined in the library
 * file.
 */

// We include the header file for this library file to make sure that the
// signature for the definition matches the signature in the header file.
#include "linsearch.h"

int linsearch(char A[], int n, char x) {

    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i;
        }
    }

    return -1;
}
