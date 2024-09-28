#include <stdio.h>

int main(){
int total_price;
char membership;

printf("Enter your total purchase amount\t");
scanf("%d", &total_price);

printf("Enter 'y' if you have membership and 'n' if you dont have membership\t");
scanf(" %c", &membership);

(total_price>100 && (membership == 'y' || membership == 'Y'))? printf("You are eligible for discount") : printf("You are not eligible for discount");
	return 0;
}