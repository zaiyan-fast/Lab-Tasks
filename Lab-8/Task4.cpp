#include <stdio.h>

int main(){
	int m1row, m1col, m2row, m2col;
	
	printf("Enter rows for matrix 1: ");
	scanf("%d", &m1row);
	printf("Enter columns for matrix 1: ");
	scanf("%d", &m1col);
	printf("Enter rows for matrix 2: ");
	scanf("%d", &m2row);
	printf("Enter columns for matrix 2: ");
	scanf(" %d", &m2col);
	
	if(m1row == m2row && m1col == m2col && m1row == m1col && m2row == m2col){
	
		int matrix1[m1row][m1col]={0};
		int matrix2[m2row][m2col]={0};
		int sumarr[m1row][m1col];
		printf("----Enter values for matrix 1----\n");
		for(int i = 0; i < m1row; i++){
			for(int j = 0; j < m1col; j++){
				printf("Enter value for matrix1[%d][%d]: ", i+1, j+1);
				scanf("%d", &matrix1[i][j]);
			}
		}
		printf("----Enter values for matrix 2----\n");
		for(int i = 0; i < m2row; i++){
			for(int j = 0; j < m2col; j++){
				printf("Enter value for matrix2[%d][%d]: ", i+1, j+1);
				scanf("%d", &matrix2[i][j]);
			}
		}
		
		for(int i = 0; i < m1row; i++){
			for(int j = 0; j < m1col; j++){
				sumarr[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		
		printf("\nSum of Matrices: \n");
		for(int i = 0; i < m1row; i++){
			for(int j = 0; j < m1col; j++)
				printf("%d ", sumarr[i][j]);
			printf("\n");	
		}	
	}else
		printf("The size of matrices is not same and hence addition is not possible");
	return 0;
}