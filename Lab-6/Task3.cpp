#include <stdio.h>

int main(){
	int num;
	
	do{		
		printf("Enter a positive number\n");
		scanf("%d", &num);
		if(num<0)
			printf("That's a negative number!!!\n");
	}while(num<0);
	
	printf("Now that's a positive number!!!\n");
	
	return 0;
}