#include <stdio.h>

int main(){
	int arr[20];
	int reverseArr[20];
	int length = sizeof(arr) / sizeof(arr[0]);
	

	for(int i = 0; i < length; i++){
		printf("Enter value for arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < length; i++){
		reverseArr[i] = arr[length - i -1];
		printf("%d ", reverseArr[i]);
	}
	
	return 0;
}