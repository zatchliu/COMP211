/*
 * Fall 2022, COMP 211: Lab 4
 * Variations on binary search
 */

#include <stdio.h>

int binsearch_good1(int A[], int n, int x)
{
    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int m = lo + (hi - lo) / 2;

        if (A[m] == x) {
            return m;
        } else if (A[m] > x) {
            hi = m;
        } else { // A[m] < x
            lo = m + 1;
        }
    }
    return -1;
}

int binsearch_good2(int A[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;

        if (A[m] == x) {
            return m;
        } else if (A[m] > x) {
            hi = m - 1;
        } else { // A[m] < x
            lo = m + 1;
        }
    }
    return -1;
}

int binsearch_bad1(int A[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;

    while (lo < hi) {
        int m = lo + (hi - lo) / 2;

        if (A[m] == x) {
            return m;
        } else if (A[m] > x) {
            hi = m - 1;
        } else { // A[m] < x
            lo = m + 1;
        }
    }
    return -1;
}


int binsearch_bad2(int A[], int n, int x)
{
    int lo = 0;
    int hi = n;

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;

        if (A[m] == x) {
            return m;
        } else if (A[m] > x) {
            hi = m;
        } else { // A[m] < x
            lo = m + 1;
        }
    }
    return -1;
}

int main()
{
    int A[] = {0, 1, 2, 7, 22, 34, 44, 55, 56, 79, 89, 99};
    int n = 12;
    int x = 7; // Works for all
    //int x = 55; // Problem for bad 1
    //int x = 8; // Problem for bad 2

    {
        int idx = binsearch_good1(A, n, x);
        if (idx != -1) {
            printf("binsearch_good1: found x=%d at A[%d] = %d\n", x, idx, A[idx]);
        } else {
            printf("binsearch_good1: x=%d is not found \n", x);
        }

    }

    {
        int idx = binsearch_good2(A, n, x);
        if (idx != -1) {
            printf("binsearch_good2: found x=%d at A[%d] = %d\n", x, idx, A[idx]);
        } else {
            printf("binsearch_good2: x=%d not found \n", x);
        }
    }


    {
        int idx = binsearch_bad1(A, n, x);
        if (idx != -1) {
            printf("binsearch_bad1: found x=%d at A[%d] = %d\n", x, idx, A[idx]);
        } else {
            printf("binsearch_bad1: x=%d not found \n", x);
        }
    }

    {
        int idx = binsearch_bad2(A, n, x);
        if (idx != -1) {
            printf("binsearch_bad2: found x=%d at A[%d] = %d\n", x, idx, A[idx]);
        } else {
            printf("binsearch_bad2: x=%d not found \n", x);
        }
    }

    return 0;
}
