/*Zachary Liu
 * COMP 211
 * HW2 a
 */
#include <stdio.h>

int main(void){
    unsigned int decimal = 0;
    unsigned int max_pow = 15;
    unsigned int curr_pow = max_pow;
    unsigned int pow2 = 1;
    unsigned int i = 0;

    /* Read in non-negative decimal integer */
    printf("Enter non-negative decimal integer to convert: ");
    scanf(" %u", &decimal);

    /* Perform conversion to binary */
    printf("Conversion to binary: ");
    do {
        /* Compute pow2 = 2^i */
        pow2 = 1;
        for (i = 0; i < curr_pow; i++) {
            pow2 = pow2 * 2;
        }

        /* Print appropriate binary digit */
        if (pow2 <= decimal) {
            printf("1");
            decimal = decimal - pow2;
        } else {
            printf("0");
        }
        curr_pow--;
    } while ((curr_pow + 1) > 0);

    printf("\n");
    if (decimal != 0) {
        printf("Error occurred\n");
    }

    return 0;
    /*
    int input;
    int max = 65536;
    printf("Enter non-negative decimal integer to convert: ");
    scanf("%d", &input);
    if ( input >= max){
        printf("Conversion to binary: 1111111111111111\nError Occured\n");
        return 0;
    }
    printf("Conversion to binary: ");
    for (int i = 16; i>0; i--){
        max = max / 2;
        if (input - max < 0){
            printf ("0");
        } else{
            printf("1");
            input = input - max;
        }
    }
    printf("\n");
    return 0;
    */
}

