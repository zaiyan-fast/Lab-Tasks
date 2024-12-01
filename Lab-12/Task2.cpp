#include <stdio.h>
#include <stdlib.h>

void decreaseOdd(int arr[], int num){
    for(int i = 0; i < num; i++){
        if(arr[i] % 2 != 0){
            arr[i] -= 1;
        }
    }
}

int main() {
    int n;
    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    decreaseOdd(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
}