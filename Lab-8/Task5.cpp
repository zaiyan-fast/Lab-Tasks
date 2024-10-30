#include <stdio.h>

int main(){
	int scores[4][4] = {0};
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("Enter value for scores[%d][%d]: ", i, j);
			scanf("%d", &scores[i][j]);
		}
		printf("\n");
	}
    
	printf("Original Matrix:\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", scores[i][j]);
		}
		printf("\n");
	}
	
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - 1; j++) {
            if (scores[j][i] > scores[j + 1][i]) {
                int temp = scores[j][i];
                scores[j][i] = scores[j + 1][i];
                scores[j + 1][i] = temp;
                j = -1;
            }
        }
    }
      
	printf("Sorted Columns in Ascending Order:\n");
    for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", scores[i][j]);
		}
		printf("\n");
	}
	return 0;
}