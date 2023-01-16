#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int hash(int key){
    return key % SIZE;
}

typedef struct set{
    int B[SIZE];
}set;

set*create(){
    set*s = malloc(sizeof(set));
    for(int i = 0; i < SIZE; i++){
        s->B[i] = '\0';
        return s;
    }
}

bool set_member(set*s, int key){
    int h0 = hash(key);
    int h = h0;
    while(true){
        if(s->B[h]==key){
            return true;
        } else if(s->B[h]=='\0'){ 
            return false;
        }
        h = (h+1)%SIZE;
        if(h==h0) return false;
    }
}

void set_add(set*s, int key){
    if(set_member(s, key)) return;
    //find index
    int h0 = hash(key);
    int h = h0;
    //check if index is free
    while(s->B[h]!='\0'){
        h = (h+1)%SIZE;
        if (h==h0) return;
    }
    s->B[h] = key;
}

void set_delete(set*s, int key){
    int h0 = hash(key);
    int h = h0;
    while(true){
        //key found
        if(s->B[h]==key){
            s->B[h]=='?';
            return;
        }else if(s->B[h] == '\0'){ //key not found
            return;
        }
        h=(h+1)%SIZE;
        //wrapped around
        if(h==h0) return;
    }
}

//Problem 3 from review final
bool hasPairSum(int A[], int n){
    set*s = create();
    int sum = 0;
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            sum = A[i] + A[j];
            if(!set_member(s,sum)){
                set_add(s,sum);
            }else{
                return true;
            }
        }
    }
    return false;

}
//funciton used in problem 3 of midterm
/*
char*f(char*A, char*B){
    A[3] = B[0];
    char C[] = {'x','y','z'};
    return C;
}
*/

int main(void){
    int test[3] = {1,2,4};
    printf("%d\n", hasPairSum(test, 3));

    //problem 3 from final review
    /*
    int x;
    int *p;
    x=3;
    p=&x;
    *p=6;
    *p=*p+4;
    printf("%d\n", x);
    return 0;
    */

   //problem 3 from midterm
   /*
    char A[] = {'a','b','c','m'};
    char B[] = {'d','e','f'};
    char * C = f(A,B);
    printf("%s\n", A);
    printf("%s\n", B);
    //printf("%s\n", C);
    return 0;
    */
}