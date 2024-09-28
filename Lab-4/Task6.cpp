#include <stdio.h>
	
int main(){
	int a,b;
	printf("Enter first number\t");
	scanf("%d", &a);
	printf("Enter second number\t");
	scanf("%d", &b);

	if(a>b){
		if(a>100){
			printf("First number is significantly larger\n");
		}else{
			printf("First number is larger\n");
		}
	}else if(a<b){
		printf("First number is smaller");
	}else if(a==b){
		printf("Both numbers are equal");
	}

	return 0;
}
