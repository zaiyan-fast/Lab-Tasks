#include <stdio.h>

int main(){
	int n;
	printf("Enter value for side of square: ");
	scanf("%d", &n);
	
	if(n > 1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == 0 || i == n-1 || j == 0 || j == n-1  || i == j || i + j == n - 1)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
	}
	else{
		printf("Invalid input\n");
	}
	return 0;
}