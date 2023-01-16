#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "array_func.h"

bool all_distinct(char A[], int n){
    for (int i = 1; i < n; i++){
        if(A[i-1] == A[i]){
            printf("false\n");
            return false;
        }
    }
    printf("true\n");
    return true;
}

int count_distinct(char A[], int n){
    int count = 1;
    for (int i = 1; i < n; i++){
        if(A[i-1] != A[i]){
            count++;
        }
    }
    return count;
}

void remove_duplicates(char A[], int n, char B[], int m){
    for (int i = 0; i < n; i++){



