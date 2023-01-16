/*
 * Fall 2022, COMP 211: Lab 4
 * Checking correctness of binary search
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/* notin(A, x, k0, k1) = true,  if x != x[i] for k0 <= i < k1
 *                     = false, otherwise.
 */
bool notin(int A[], int x, int k0, int k1) {
    for (int i = k0; i < k1; ++i) {
        if (A[i] == x) {
            return false;
        }
    }
    return true;
}

/* is_sorted(A, n) = true, if A[0] <= A[1] <= ... <= A[n-1]
 *                 = false, otherwise.
 */
bool is_sorted(int A[], int n) {
    for (int i=1; i<n; ++i) {
        if (A[i-1] > A[i]) {
            return false;
        }
    }
    return true;
}

int binsearch(int A[], int n, int x) {
    assert(is_sorted(A, n));

    int i = 0;
    int j = n;

    /* Loop invariant:
     * 0 <= i <= j <= n
     * A[k] != x for 0 <= k < i
     * A[k] != x for j <= k < n
     */
    assert(0 <= i);
    assert(i <= j);
    assert(j <= n);
    assert(notin(A, x, 0, i));
    assert(notin(A, x, j, n));

    while (i < j) {
        printf("i, j = %d, %d\n", i, j);
        assert(0 <= i);
        assert(i <= j);
        assert(j <= n);
        assert(notin(A, x, 0, i));
        assert(notin(A, x, j, n));

        int m = i + (j - i) / 2;
        assert(i <= m);
        assert(m < j);

        if (A[m] == x) {
            return m;
        } else if (A[m] < x) {
            i = m + 1;
        } else {
            j = m;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    int A[] = {1, 2, 3, 4, 5};

    assert(binsearch(A, 5, 0) == -1);
    assert(binsearch(A, 5, 1) == 0);
    assert(binsearch(A, 5, 2) == 1);
    assert(binsearch(A, 5, 3) == 2);
    assert(binsearch(A, 5, 4) == 3);
    assert(binsearch(A, 5, 5) == 4);
    assert(binsearch(A, 5, 6) == -1);

    return 0;
}
