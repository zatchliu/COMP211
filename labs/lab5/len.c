# include <stdio.h>

int stringLen(char A[]){
    if (A[0] == '\n'){
        return 0;
    }else{
        return 1+stringLen(&A[1]);
    }
}


int main(void){
    char input[256];
    int len = 0;
    printf("Enter a string: ");
    fgets(&input[0], 256, stdin);
    len = stringLen(input);
    printf("The length of the array is %d\n", len);
}
