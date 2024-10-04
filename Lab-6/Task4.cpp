#include <stdio.h>

int main(){
	int num, sum = 0;
	
	do{
		printf("Enter a number\n");
		scanf("%d", &num);
		sum+=num;
		printf("Sum: %d\n", sum);
	}while(num!=0);
	printf("Oops! You entered zero");
	return 0;
}

