#include <stdio.h>
#include <stdlib.h>

void addNumber(float **arr, int *n, int *cap) {
    if (*n >= *cap) {
        *cap *= 2;
        float *temp = (float*) realloc(*arr, (*cap) * sizeof(float));
        *arr = temp;
    }
    printf("Enter value %d: ", (*n) + 1);
    scanf("%f", &(*arr)[*n]);
    (*n)++;
    printf("Number added\n");
}

void displayNum(float arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void removeLast(float **arr, int *n, int *cap) {
    if (*n > 0) {
        (*n)--;
        if (*n < *cap / 4 && *cap > 4) {
            *cap /= 2;
            float *temp = (float*) realloc(*arr, (*cap) * sizeof(float));
            *arr = temp;
        }
        printf("Last element removed\n");
    } else {
        printf("Array is already empty\n");
    }
}

int main() {
    int n = 0, cap = 4;
    float *arr = (float *)malloc(cap * sizeof(float));
    int choice = 0;
    while (choice != 4) {
        printf("1. Add new number to the array\n");
        printf("2. Display all numbers in the array\n");
        printf("3. Remove last number from the array\n");
        printf("4. End\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addNumber(&arr, &n, &cap);
                break;
            case 2:
                displayNum(arr, n);
                break;
            case 3:
                removeLast(&arr, &n, &cap);
                break;
            case 4:
                free(arr);
                printf("Exiting!\n");
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    free(arr);
    return 0;
}