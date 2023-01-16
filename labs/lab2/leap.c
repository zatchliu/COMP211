#include <stdio.h>

int main(void){
	int year;
	int con=1;
	int isLeap(int year){
		if(year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0))){
			return 1;
		}
		return 0;
	}
	do{
		printf("Enter a year: ");
		scanf(" %d", &year);
		if(isLeap(year)==1){
			printf ("%d is a leap year\n", year);
		} else {
			printf ("%d is not a leap year\n", year);
		}
		printf("Enter 1 to continue: ");
		scanf(" %d", &con);
	} while (con==1);
}
