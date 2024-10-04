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
	if(prime)
		printf("%d is a prime number", num);
	else 
		printf("%d is not a prime number", num);
	return 0;
}

