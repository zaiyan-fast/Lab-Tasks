#include <stdio.h>

int main(){
	int a,b,c;
	printf("Enter first angle\n");
	scanf("%d", &a);
	printf("Enter second angle\n");
	scanf("%d", &b);
	printf("Enter third angle\n");
	scanf("%d", &c);
	
	if(a>0 && b>0 &&c>0){
		if(a+b+c==180){
			printf("Triangle is valid");
		}else{
			printf("Invalid Angles");
		}
	}else{
		printf("Invalid Angles");
	}
	return 0;
}