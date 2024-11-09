#include <stdio.h>

int main() {
    int n;
    printf("Enter no of rows: ");
    scanf("%d", &n);
    
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++)
            printf("* ");
            
        for(int j = 0; j <= i; j++)
            printf("o");
        printf("\n");
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++)
            printf("* ");
            
        for(int j = i; j <= n; j++)
            printf("o");
        printf("\n");
    }

    return 0;
}