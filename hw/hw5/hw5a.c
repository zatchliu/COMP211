/* Zachary Liu
 * COMP 211, Fall 2021, Wesleyan University
 * Homework #5, Problem 2
 * Works with n-1
 * Recursion.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "hw5a.h"

int unimodal_search_r(int A[], int a, int b) {
    int right = b;
    int left = a;
    int m = left + (right+1 - left)/2;
    if (m == left){
        return left;
    } else if (m == right){
        if(A[left] < A[m]){
            return m;
        } else{
            return left;
        }
    }
    if(A[m-1] < A[m] && A[m+1] < A[m]){
        return m;
    } else if (A[m-1] < A[m] && A[m] < A[m+1]){
        return unimodal_search_r(A, m, right);
    } else {
        return unimodal_search_r(A, left, m);
    }
    return -1;
}
