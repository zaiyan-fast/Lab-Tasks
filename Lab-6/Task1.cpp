#include <stdio.h>

int main(){
	int num, factorial = 1;
	printf("Enter a positive integer: \t");
	scanf("%d", &num);
	if(num<0){
		printf("Invalid number");
		return 0;
	}
	for(int i = 1; i<=num;i++){
		factorial *= i;
	}
	printf("The factorial of %d is %d\n", num, factorial);
	return 0;
}