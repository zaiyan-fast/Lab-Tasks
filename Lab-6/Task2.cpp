#include <stdio.h>

int main(){
	int num,i = 1;
	printf("Enter a number till which you want to print even numbers\t");
	scanf("%d", &num);
	if(num<1){
		printf("Invalid number");
		return 0; 
	}
	while(i<num/2.0){
		printf("%d ", 2*i);
		i++;
	}
	return 0;
}