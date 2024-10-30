#include <stdio.h>

int main(){
	int marks[4][4];
	
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter value for marks[%d][%d]: ", i, j);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("Marks: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d ", marks[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(marks[i][j] < 0)
            	marks[i][j] = 0;
		}
    }
    
    printf("\nUpdated Marks: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d ", marks[i][j]);
        }
        printf("\n");
    }
	
	return 0;
}