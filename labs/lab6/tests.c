#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "array_func.h"

void test_all_distinct(){
    char A[] = {1,1,2,3,4,5,6,7,8,8,9,10};
    char B[] = {'a','b','c','d','e','f','g','g','h','i','j'};
    all_distinct(A,6);
    all_distinct(B,5);
    all_distinct(B,8);
}

int main(void){
    test_all_distinct();
}
