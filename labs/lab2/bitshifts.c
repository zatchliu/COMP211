#include <stdio.h>

int main(void){
	unsigned int input;
	unsigned int cont = 1;
	unsigned int ans;
    unsigned int shifts;
	while (cont==1){
		printf("Enter an unsigned int: ");
		scanf(" %d", &input);
        printf("Enter the exponent to a power of 2: ");
        scanf(" %d", &shifts);
		ans = input << shifts;
		printf(" %d\n", ans);
		printf ("Enter 1 to continue: ");
		scanf(" %u", &cont);
	}
}
