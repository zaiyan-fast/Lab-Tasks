#include <stdio.h>
	
int main(){
	int marks;
	printf("Enter your marks");
	scanf("%d",&marks);
	if(marks>=90 && marks<=100){
		printf("A");
	}else if(marks>=80 && marks<=89){
		printf("B");
	}else if(marks>=70 && marks<=79){
		printf("C");
	}else if(marks>=60 && marks<=69){
		printf("D");
	}else if(marks<=60){
		printf("F");
	}
	return 0;
}
