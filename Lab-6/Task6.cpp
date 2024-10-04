#include <stdio.h>

int main(){	
	int num, prime = 1;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	if(num<=2){
		printf("Not a prime number");
		return 0;
	}
		
	for(int i = 2; i<num; i++){
		if(num%i == 0){
			prime = 0;
			break;
		}
	}
	
	if(prime){
		printf("%d is a prime number and The fibonacci sequence is: ", num);
		int a = 0, b = 1, x=0;
		printf("%d %d ", a,b);
	
		for(int i = 3; i<=num; i++){
			x=a+b;
			printf("%d ", x);
			a=b;
			b=x;
		}
	}
			
	else 
		printf("%d is not a prime number", num);
	
	return 0;
}

