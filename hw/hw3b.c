/*Zachary Liu
 * COMP 211
 * HW3 b
 * Attended help sessions on Sunday and Monday
 */

#include <stdio.h>
#include <string.h>

const int MAX_LEN = 256;
const char MIN_CHAR = ' ';
const char MAX_CHAR = '~';

char decrypt(char c, int shift){
    int range = MAX_CHAR - MIN_CHAR + 1;
    return MIN_CHAR + (c - MIN_CHAR + (range - shift))%range;
}

int main(void){
    char input[MAX_LEN];
    char output[MAX_LEN];
    
    printf("Enter a string to decrypt: ");
    fgets(&input[0], MAX_LEN, stdin);
    int a = strlen(input);

    for (int shift = 0; shift <= MAX_CHAR-MIN_CHAR; shift++){
        for(int j = 0; j < a - 1; j++){
            output[j] = decrypt(input[j], shift);
        }
        printf("Possible plaintext is %s using shift of %d\n", output, shift);
    }
}

