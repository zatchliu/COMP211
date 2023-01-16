/*
 * Fall 2022, COMP 211: Lab 4
 *
 * comp211.h - Standard COMP 211 include file.
 *
 * This file contains macros related to contracts, debugging, and testing.
 */

#ifndef COMP211_H
#define COMP211_H

#include <assert.h>
#include <stdio.h>

// Contracts.
#ifdef VDEBUG
#define ENSURE(E) fprintf(stderr, "%s: ENSURE(%s)\n", __PRETTY_FUNCTION__, #E) ; fflush(stderr) ; assert(E)
#define REQUIRES(E) fprintf(stderr, "%s: REQUIRES(%s)\n", __PRETTY_FUNCTION__, #E) ; fflush(stderr) ; assert(E)
#else
#define ENSURE(E) assert(E)
#define REQUIRES(E) assert(E)
#endif

// Debugging printing.
#ifdef VDEBUG
#define dprintf(...) fprintf(stderr, __VA_ARGS__) ; fflush(stderr)
#else
#define dprintf(...) (void)0
#endif

// Testing.
#define dotest(TEST) fprintf(stderr, "%s...", #TEST) ; if (TEST) {fprintf(stderr, "pass.\n") ;} else {fprintf(stderr, "FAIL.\n") ;}

#endif

