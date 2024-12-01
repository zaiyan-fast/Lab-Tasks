#include <stdio.h>
#include <stdlib.h>

int largestElement(int* arr, int n){
    int max = arr[0];
    
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter total numbers (1 to 100): ");
    scanf("%d", &n);
    if(n < 1 || n > 100){
        printf("Invalid Input\n");
        return 0;
    }
    int* arr = (int*) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        printf("Value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int largest = largestElement(arr, n);
    printf("The largest number in the array is: %d\n", largest);
    free(arr);
    return 0;
}
