#include <stdio.h>

int maxCuts(int length) {
    if (length == 0) 
        return 0;
    if (length < 0)
        return -1;

    int cut1 = maxCuts(length - 1);
    int cut2 = maxCuts(length - 2);
    int cut3 = maxCuts(length - 3);
    int maxCut;
    if(cut1 > cut2){
        if(cut1 > cut3)
            maxCut = cut1;
        else
            maxCut = cut3;
    }else{
        if(cut2 > cut3)
            maxCut = cut2;
        else
            maxCut = cut3;
    }
    
    if(maxCut == -1)
        return -1;
    else
        return maxCut + 1;

}

int main() {
    int length;
    printf("Enter length of rope: ");
    scanf("%d", &length);
    int result = maxCuts(length);
    if (result == -1)
        printf("No cut possible");
    else
        printf("Max pieces: %d", result);
    return 0;
}
