/* COMP 211, Fall 2022, Wesleyan University
 * Homework #4 testing program
 */

#include <stdbool.h>

#include "comp211.h"
#include "hw4.h"

void test_bin_search() {
    printf("*****\nBinary search tests\n*****\n");

    int B[10] = {1, 3, 3, 3, 5, 5, 7, 7, 7, 9};
    int A[] = {};
    int D[] = {1};
    int C[10] = {1, 1, 1, 1, 3, 4, 5, 6, 7, 8};
    dotest(bin_search(B, 10, 3) == 1);
    dotest(bin_search(B, 10, 4) == -1);
    dotest(bin_search(A, 0, 1) == -1);
    dotest(bin_search(C, 10, 1) == 0);
    dotest(bin_search(D, 1, 1) == 0);
}

void test_unimodal_search() {
    printf("****\nUnimodal search tests\n*****\n");

    // We put these tests in blocks so that we can repeatedly declare
    // arrays with the same names (because execution of a block statement
    // adds a binding table onto the stack, which is popped when the
    // block finishes).

    {
        int A[] = {1, 2, 3, 4, 3, 2, 1};
        dotest(unimodal_search(A, 7) == 3);
    }

    {
        int A[] = {1, 2, 3, 4, 5};
        dotest(unimodal_search(A, 5) == 4);
    }

    {
        int A[] = {5, 4, 3, 2, 1};
        dotest(unimodal_search(A, 5) == 0);
    }

    {
        int A[] = {};
        dotest(unimodal_search(A,0) == -1);
    }

    {
        int A[] = {1};
        dotest(unimodal_search(A,1) == 0);
    }
}


/*  array_eq(A, B, n) =
 *    false, if there is 0 <= i < n such that A[i] != B[i]
 *    true,  if there is no such i.
 */
bool array_eq(int A[], int B[], int n) {
    for (int i=0; i<n; ++i) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

const int N_A = 7;
const int N_B = 10;

void test_merge() {
    printf("*****\nMerge tests\n*****\n");

    // We put these tests in blocks so that we can repeatedly declare
    // arrays with the same names (because execution of a block statement
    // adds a binding table onto the stack, which is popped when the
    // block finishes).

    {
        // A, B disjoint but overlapping.
        int evens[] = {0, 2, 4, 6, 8, 10, 12};
        int odds[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int evensodds[] =
          {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 17, 19};
        int C[N_A + N_B];

        merge(evens, N_A, odds, N_B, C);
        dotest(array_eq(C, evensodds, N_A + N_B));

        merge(odds, N_B, evens, N_A, C);
        dotest(array_eq(C, evensodds, N_A + N_B));
    }
}

int main() {

    test_bin_search();
    test_unimodal_search();
    test_merge();
    return 0;
}
