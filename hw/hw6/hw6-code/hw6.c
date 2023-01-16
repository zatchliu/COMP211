/* Zachary Liu
 * COMP 211, Fall 2022, Wesleyan University
 * Homework #6
 *
 * Palindromes and sorting.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "hw6.h"

/* palindrome_check(A, n) =
 *   true, where A[i] == A[n-1-i] for all i < (n-1-i)
 *   false otherwise
 *
 * Pre-conditions:
 */
bool is_palindrome(char A[]){
    int lo = 0;
    int hi = strlen(A) - 1;
    while(lo < hi){
        if(A[lo] != A[hi]){
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}

/*  Insertion sort
 *
 */
void insertion_sort(int A[], int n){
    for(int i = 1; i < n; i++){
        if(A[i]<A[i-1]){
            int val = A[i];
            int idx =  i-1;
            while(idx >= 0 && A[idx] > val){
                A[idx+1] = A[idx];
                idx--;
            }
            A[idx+1] = val;
        }
    }
    /*
    int temp;
    int j;
    for ( int i = 1; i < n; i++){
        temp = A[i];
        j = i-1;
        while (j >= 0 && A[j] > temp){
            A[j+1] = A[j];
            j -= 1;
        }
        A[j + 1] = temp;
    }
    */
}

/*  merge3: performs a 3-way merge
 *
 *  A is divided into 3 sub-arrays which are merged in sorted order
 *     -> lo:m1, m1:m2, m2:hi
 */
void merge3(int A[], int lo, int m1, int m2, int hi){
    int i = lo;
    int j = m1;
    int k = m2;
    int curr = 0;
    int B[hi - lo];

    while ((i < m1) && (j < m2) && (k < hi)){
        if (A[i] <= A[j] && A[i] <= A[k] ){
            B[curr++] = A[i++];
        } else if (A[j] <= A[i] && A[j] <= A[k]) {
            B[curr++] = A[j++];
        } else {
            B[curr++] = A[k++];
        }
     }


    while (i < m1 && j < m2){
        if (A[i] <= A[j]){
            B[curr++] = A[i++];
        } else{
            B[curr++] = A[j++];
        }
    }

    while (j < m2 && k < hi){
        if(A[j] <= A[k]){
            B[curr++] = A[j++];
        } else{
            B[curr++] = A[k++];
        }
    }

    while(i < m1 && k < hi){
        if(A[i] <= A[k]){
            B[curr++] = A[i++];
        }else{
            B[curr++] = A[k++];
        }
    }

    while(i < m1){
        B[curr++] = A[i++];
    }
    while(j < m2){
        B[curr++] = A[j++];
    }
    while(k < hi){
        B[curr++] = A[k++];
    }

    for (int a = 0; a < hi - lo; a++){
        A[lo + a] = B[a];
    }
}
/*
 * Implements a recursive 3-way mergesort
 *   -> Divide array into thirds.
 *   -> Recursively sort each third.
 *   -> Merge thirds.
 */
void merge_sort3(int A[], int lo, int hi){
    if((hi-lo) <= 1) return;

    int m1 = lo + ((hi-lo)/3);
    int m2 = lo +  (2 * (hi-lo) / 3);

    merge_sort3(A, lo, m1);
    merge_sort3(A, m1, m2);
    merge_sort3(A, m2, hi);

    merge3(A, lo, m1, m2, hi);
}
