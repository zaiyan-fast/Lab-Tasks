#include <stdio.h>

int sumofdigits(int num, int sum){
	if(num == 0)
		return sum;
	int rem = num%10;
	sum += rem;
	num /= 10;
	return sumofdigits(num, sum);
}

int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	int sum = sumofdigits(num, 0);
	
	printf("Sum: %d", sum);
	return 0;
}