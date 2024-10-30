#include <stdio.h>

int main(){
	int scores[3][3];
	
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for scores[%d][%d]: ", i, j);
            scanf("%d", &scores[i][j]);
        }
    }
	
	int sumofrows[3] = {0};
	int sumofcolumns[3] = {0};
	
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			sumofrows[i] += scores[i][j];
			sumofcolumns[j] += scores[i][j];
		}	
	}
	
	for(int i = 0; i < 3; i++){
		printf("Sum of Row %d: %d\n",i+1, sumofrows[i]);
	}
	
	for(int i = 0; i < 3; i++){
		printf("Sum of Column %d: %d\n",i+1, sumofcolumns[i]);
	}
	
	return 0;
}