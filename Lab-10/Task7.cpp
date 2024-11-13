#include <stdio.h>
#include <string.h>

void bubblesort(int arr[], int len){
	if(len == 0)
		return;
	int count = 0;
	for(int i = 0; i < len - 1; i++){
		if(arr[i] > arr[i + 1]){
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			count++;
		}
	}
	if(!count)
		return;
		
	bubblesort(arr, --len);
}

int main(){
	int arr[] = {62, 47, 22, 88, 2, 90, 12}; 
	
	int len = sizeof(arr)/sizeof(arr[0]);
	
	printf("Unsorted Array: ");
	for(int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	bubblesort(arr, len);
	
	printf("\nSorted array: ");
	for(int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}