#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char string[256];
    int lineNumber = 1;

    fptr = fopen("abc.txt", "r");
    if (fptr == NULL) {
        printf("Error");
        return 0;
    }

  while (1) {
        char *result = fgets(string, 256, fptr);
        if (result == NULL) {
            break;
        }
        printf("%d: %s", lineNumber, string);
        lineNumber++;
    }

    fclose(fptr);
    return 0;
}