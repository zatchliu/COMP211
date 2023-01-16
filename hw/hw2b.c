/*Zachary Liu
 * COMP 211
 * HW2 b
 */
#include <stdio.h>

int main(void){
    char input;
    int key;
    char result;
    printf("Enter lower-case letter to encrypt: ");
    scanf("%c", &input);
    if ( input >= 'a' &&  input <= 'z'){
        printf ("Enter the shift amount for Caesar cipher: ");
        scanf("%d", &key);
        result = (input + (key % 26));
        if ( result > 'z'){
            result = result - 26;
        }
        printf ("Ciphertext is %c\n", result);
    } else{
        printf ("Error: user did not enter a lower case letter, exiting\n");
    }
}
