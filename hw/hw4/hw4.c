/* Zachary Liu
 * COMP 211, Fall 2022, Wesleyan University
 * Homework #4, Problems 2-4
 * Arrays and searching.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "hw4.h"

/* bin_search(A, n, x) =
 *   i,   where A[i] == x and A[j] != x for j<i, if there is such an i
 *        such that 0 <= i < n.
 *   -1,  if there is no such i.
 *
 * Pre-conditions:  A[0] <= ... <= A[n-1] and size of A is n.
 */
int bin_search(int A[], int n, int x) {
    int l = 0;
    int h = n;
    int m;
    while(l < h){
        m = l + (h-l)/2;
        if ((A[m] == x && m >=0) && A[m-1] != x){
            return m;
        }else if(A[m]<x){
            l = m + 1;
        } else {
            h = m;
        }
    }
    return -1;
}
/* unimodal_search(A, n) = j, where A[j] = max{A[0],...,A[n-1]}.
 *
 * Pre-conditions:
 * - A has size n.
 * - There is j such that
 *     A[0] < A[1] < ... < A[j-1] < A[j] > A[j+1] > ... A[n-1].
 *   It is possible that j=0 or j=n-1.
 */
int unimodal_search(int A[], int n) {
    int l = 0;
    int h = n;
    int m;
    while(l < h){
        m = l + (h-l)/2;
        if(m >0 && m+1< n){
            if(A[m+1] < A[m] && A[m] > A[m-1]){
                return m;
            }
            if(A[m+1] > A[m] && A[m] > A[m-1]){
                l = m;
            }else{
                h = m;
            }
        }else if(A[n-1]>A[n-2]){
            return n-1;
        }else{
            return 0;
        }
    }
    return -1;
}

/* After calling merge(A, m, B, n, C):
 * - C contains all the elements of A and B;
 * - C[0] <= ... <= C[m + n -1]
 *
 * Pre-conditions:
 * - A has size m and A[0] <= ... <= A[m-1].
 * - B has size n and B[0] <= ... <= B[n-1].
 * - C has size m + n.
 */
void merge(int A[], int m, int B[], int n, int C[]) {
    int a = 0;
    int b = 0;
    int i = 0;

    while(a<m && b<n){
        if(A[a]<B[b]){
            C[i] = A[a];
            a++;
        }else{
            C[i] = B[b];
            b++;
        }
        i++;
    }
    while(a<m){
        C[i] = A[a];
        a++;
        i++;
    }
    while(b<n){
        C[i] = B[b];
        b++;
        i++;
    }

    /*
    while (a < m || b < n){
        if ((A[a] <= B[b] && a < m) || b >= n){
            C[i] = A[a];
            a++;
        }else if(b < n){
            C[i] = B[b];
            b++;
        }
        i++;
    }
    */
}
