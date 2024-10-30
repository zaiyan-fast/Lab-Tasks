#include<stdio.h>

int main() {
    int n;
    printf("Number of Rows : ");
    scanf("%d", &n);
    
    for(int i = n; i > 0; i--) {
        for(int j = n; j > i; j--) {
            printf(" ");
        }
        for(int j = i; j > 0; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = n; j > i; j--) {
            printf(" ");
        }
        for(int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}