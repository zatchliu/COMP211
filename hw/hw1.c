/* Zachary Liu
 * COMP 211
 * 
 * A program to compute the sum of the integers from 1 to max where 
 * max is an integer specified by the user.
 */
#include <stdio.h>

int main(void)
{
	int sum = 0; // Stores the sum fo the integers
	int max = 0; // User-entered max integer to sum to
	int i = 1;

	printf("Enter the maximum integer to sum until: ");
	scanf(" %d", &max);

	// Compute sum of integers from 1 to max
	for (i = 1; i<= max; i++){
		sum += i;
		printf("i: %d Sum: %d\n", i, sum);
	}

	printf("Sum of integers from 1 to %d: %d\n", max, sum);
	return 0;
}
