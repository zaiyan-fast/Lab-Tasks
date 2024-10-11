#include <stdio.h>

int main(){
	int num[15];
	int sum = 0;
	
	for(int i = 0; i < 15; i++){
		printf("Enter value for num[%d]: ", i);
		scanf("%d", &num[i]);
		sum += num[i];
	}
	printf("The sum is: %d", sum);
	
	return 0;
}