#include <stdio.h>

void printarr(int arr[], int size){
	if(!size)
		return;
	printf("%d ", arr[0]);
	printarr(++arr, --size);
}

int main(){
	int arr[] = {5, 65, 21, 1, 36, 94};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printarr(arr, size);
	
	return 0;
}