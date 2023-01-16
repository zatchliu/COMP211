#include <stdio.h>

int mod(int a, int b){
    int c = a - b;
    if(c < b){
        return c;
    }else{
        c = mod(c,b);
    }
}

int main(void){
    int a;
    int b;
    int res;
    printf("first num: ");
    scanf("%d", &a);
    printf("second num: ");
    scanf("%d", &b);
    res = mod(a,b);
    printf("mod: %d\n", res);
}

