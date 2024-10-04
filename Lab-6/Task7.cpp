#include <stdio.h>

int main(){	
	int num, sum = 0, numOriginal, rem;

	printf("Enter a number: ");
	scanf("%d", &num);
	
	numOriginal = num;
	
	while(num>0){
		rem = num%10;
		sum += rem * rem * rem;
		num = num/10;
	}
	
	if(sum == numOriginal)
		printf("%d is an Armstrong number", numOriginal);
	else
		printf("%d is not an Armstrong number", numOriginal);
	
	return 0;
}
