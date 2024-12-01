#include <stdio.h>
#include <stdlib.h>

void insertAt(int **arr, int *size, int *capacity, int value, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }

    if (*size >= *capacity) {
        *capacity *= 2;
        *arr = (int *) realloc(*arr, (*capacity) * sizeof(int));
    }

    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[position] = value;
    (*size)++;
}

void deleteAt(int **arr, int *size, int position, int* capacity) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    (*size)--;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
        int n;
        scanf("%d", &n);

        int capacity = n;
        int size = 0;
        int *arr = (int *)malloc(capacity * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            size++;
        }

        while (1) {
            int choice;
            printf("1. Insert 2. Delete 3. Exit: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int value, position;
                    printf("Enter value: ");
                    scanf("%d", &value);
                    printf("Enter position: ");
                    scanf("%d", &position);
                    insertAt(&arr, &size, &capacity, value, position);
                    printArray(arr, size);
                    break;
                }
                case 2: {
                    int position;
                    printf("Enter position: ");
                    scanf("%d", &position);
                    deleteAt(&arr, &size, position, &capacity);
                    printArray(arr, size);
                    break;
                }
                case 3:
                    free(arr);
                    return 0;
                default:
                    printf("Invalid input\n");
            }
	}
    return 0;
}