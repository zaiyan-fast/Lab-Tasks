#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **array = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
        array[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    int modRow, modCol, newVal;
    printf("Enter row and column to modify: ");
    scanf("%d %d", &modRow, &modCol);
    printf("Enter new value: ");
    scanf("%d", &newVal);
    if (modRow >= 0 && modRow < rows && modCol >= 0 && modCol < cols) {
        array[modRow][modCol] = newVal;
    } else {
        printf("Invalid index!\n");
    }

    printf("Updated array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}