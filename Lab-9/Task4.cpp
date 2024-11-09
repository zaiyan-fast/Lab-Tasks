#include <stdio.h>
#include <string.h>

int main(){
	char names[][10] = {"Zaiyan", "Ali", "Ahmed", "Qaim", "Yahya"};
	char name[10];	
	int found = 0;
	
	int length = sizeof(names) / sizeof(names[0]);
	printf("Enter a name to search: ");
	scanf("%s", &name);
	
    for(int i = 0; i < length; i++){
        if(!strcmp(names[i], name)) {
            printf("Found\n");
            found = 1;
            break;
        }
    }
	
	if(!found)
		printf("Not Found\n");
	
	return 0;
}
