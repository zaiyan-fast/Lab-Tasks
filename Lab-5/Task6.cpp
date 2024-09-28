#include<stdio.h>

int main (){
	int num,i;
	printf("Enter a number: ");
	scanf("%d",&num);
	
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}
	if(num!=0){
		i+=1;
		num=num & (num-1);
	}

	printf("Number of 1s are %d",i);
	return 0;	
}