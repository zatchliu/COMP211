/* Zachary Liu
 * COMP 211
 * HW3 a
 * Attended help sessions on Sunday and Monday
 * */
#include <stdio.h>
#include <string.h>

const int MAX_LEN = 256;
const char MIN_CHAR = ' ';
const char MAX_CHAR = '~';
char encrypt(char c, int shift){
    return MIN_CHAR + (c - MIN_CHAR + shift) % (MAX_CHAR-MIN_CHAR-1);
}

int main(void){
    char input [MAX_LEN];
    int key;
    char output[MAX_LEN];

    printf("Enter a string to encrypt: ");
    fgets(&input[0], MAX_LEN, stdin);
    int a = strlen(input);

    printf("Enter the shift amount for Caesar cipher: ");
    scanf("%d", &key);
    encrypt(input, output, key);

    printf("Ciphertext is: ");
    for(int i = 0; i < a-1; i++){
        output[i] = encrypt(input[i], key);
    }
    printf("\n");
}

