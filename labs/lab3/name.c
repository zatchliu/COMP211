#include <stdio.h>
#include <string.h>

void mergeName(char input[], char full[], int pos){
    for (int i = 0; i < (strlen(input)+strlen(full) + 1); i++){
        full[pos + i] = input[i];
        full[strlen(input)] = ' ';
    }
}

int main(void){
    char firstName[256];
    char lastName[256];
    char fullName[256];
    printf("what is ur first name? ");
    fgets(&firstName[0], 256, stdin);
    printf("waht is yer last name? ");
    fgets(&lastName[0], 256, stdin);
    mergeName(firstName, fullName, 0);
    mergeName(lastName, fullName, strlen(firstName));
    printf("yer naem is %s", fullName);
}
