#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_students, num_grades;
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    int** grades = (int**) malloc(num_students * sizeof(int*));
    for(int i = 0; i < num_students; i++){
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &num_grades);
        grades[i] = (int*) malloc(num_grades * sizeof(int));
        printf("Enter grades for student %d: \n", i + 1);
        for(int j = 0; j < num_grades; j++){
            printf("Grade %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }
    printf("\nEntered Grades\n");
    for(int i = 0; i < num_students; i++){
        printf("Student %d Grades: ", i + 1);
        for(int j = 0; j < num_grades; j++){
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < num_students; i++){
        free(grades[i]);
    }
    free(grades);
    return 0;
}