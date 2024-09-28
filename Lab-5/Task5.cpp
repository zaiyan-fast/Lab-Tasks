#include <stdio.h>

int main(){
	int num;
	printf("Enter a Number\t");
	scanf("%d", &num);
	num&1 ? printf("Number is Odd") : printf("Number is Even");
	return 0;
}