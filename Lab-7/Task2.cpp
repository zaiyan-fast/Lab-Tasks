#include <stdio.h>

int main(){
	int arr[10];
	int arr2[10];
	int length = sizeof(arr) / sizeof(arr[0]);
	
	
	for(int i = 0; i<length; i++){
		printf("Enter value for arr[%d]", i);
		scanf("%d", &arr[i]);
	}
	
	
	printf("Before: {");
    for(int i = 0; i<length; i++){
        printf("%d", arr[i]);
        if(i != (length - 1))
            printf(", ");
    }
    printf("}\n");
	
	
	for(int i = 0; i<length; i++){
		if(i!=length - 1)
			arr2[i] = arr[i+1];
		else
			arr2[i] = arr[0];
	}
	
	
	printf("After: {");
    for(int i = 0; i<length; i++){
        printf("%d", arr2[i]);
        if(i != (length - 1))
            printf(", ");
    }
    printf("}\n");
	
	
	return 0;
}