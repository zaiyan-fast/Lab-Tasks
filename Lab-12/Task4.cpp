#include <stdio.h>
#include <stdlib.h>

int highestFreq(int arr[], int n) {
    int maxFreq = 0, maxElem = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxFreq || (count == maxFreq && arr[i] < maxElem)) {
            maxFreq = count;
            maxElem = arr[i];
        }
    }
    
    return maxElem;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    
    int *highest = (int *)malloc(testCases * sizeof(int));

    for (int t = 0; t < testCases; t++) {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        highest[t] = highestFreq(arr, n);
        free(arr);
    }

    for (int i = 0; i < testCases; i++) {
        printf("%d\n", highest[i]);
    }

    free(highest);
    return 0;
}