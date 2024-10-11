#include <stdio.h>

int main(){
	int arr[30];
	int length = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 0; i < length; i++){
		printf("Enter value for arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	
	int max = arr[0];
	int min = arr[0];
	
	for(int i = 0; i < length; i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	
	printf("Maximum value is %d\n", max);
	printf("Minimum value is %d\n", min);
	
	return 0;
}