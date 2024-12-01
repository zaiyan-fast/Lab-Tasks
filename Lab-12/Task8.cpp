#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    printf("Enter the total number of points in the facility: ");
    scanf("%d", &n);
    
    int* arr = (int *) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        printf("Enter fee for point %d: ", i + 1);
        scanf("%d", &arr[i]);
        if(arr[i] < 0){
            printf("Fee cannot be negative!\n");
            i--;
        }else{
            sum += arr[i];
        }
    }
    printf("Total profit for the facility: $%d", sum);
    free(arr);
    return 0;
}