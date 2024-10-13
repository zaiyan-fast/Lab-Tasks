#include <stdio.h>

int main(){
	int arr[12];
	int arr2[6];
	int length1 = sizeof(arr) / sizeof(arr[0]);
	int length2 = sizeof(arr2) / sizeof(arr2[0]);
	
	for(int i = 0; i<length1; i++){
		printf("Enter value for arr[%d]", i);
		scanf("%d", &arr[i]);
	}
	
	
	printf("Input Array: {");
    for(int i = 0; i<length1; i++){
        printf("%d", arr[i]);
        if(i != (length1 - 1))
            printf(", ");
    }
    printf("}\n");
    
    
    for(int i = 0; i<length2; i++){
    	arr2[i] = arr[2*i] + arr[2*i+1];
	}
	
	
	printf("Pair Sum Array: {");
    for(int i = 0; i<length2; i++){
        printf("%d", arr2[i]);
        if(i != (length2 - 1))
            printf(", ");
    }
    printf("}\n");
    
	return 0;
}