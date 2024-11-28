#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpper(char *string) {
    while (*string) {
        if (*string >= 'a' && *string <= 'z')
            *string -= 32;
        string++;
    }
}

int main() {
    FILE *source, *target;
    char string[256];

    source = fopen("abc.txt", "r");
    if (source == NULL) {
        printf("File does not exist");
        return 0;
    }

    target = fopen("practice.txt", "w");
    if (target == NULL) {
        printf("There is no such file");
        return 0;
    }

	while(1){
	char *result = fgets(string, 256, source);
        if (result == NULL) {
            break;
        }
        toUpper(string);
        printf("%s", string);
        fputs(string, target);
	}

    fclose(source);
    fclose(target);
    return 0;
}