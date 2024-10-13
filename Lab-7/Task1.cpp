#include <stdio.h>

int main() {
    int arr[] = {1,5,6,9,0,7,4,2,3,8};
    int num, i;
    int length = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: {");
    for(int i = 0; i<length; i++){
        printf("%d", arr[i]);
        if(i != (length - 1))
            printf(", ");
    }
    printf("}\n");
    
    printf("Enter an integer to search: ");
    scanf("%d", &num);
    
    for(i = 0; i<length; i++){
        if(num == arr[i]){
            break;
        }
    }
    if(i<length)
        printf("%d found at index %d", num, i);
    else
        printf("%d not found", num);

    return 0;
}