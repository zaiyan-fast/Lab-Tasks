#include <stdio.h>
#include <string.h>

int main(){
	char username[] = "admin";
	char password[] = "1234";
	char enteredname[10], enteredpass[10];
	
	printf("Enter username: ");
	scanf("%s", &enteredname);
	printf("Enter password: ");
	scanf("%s", &enteredpass);
	
	if(!strcmp(username, enteredname) && !strcmp(password, enteredpass))
		printf("Access granted");
	else
		printf("Access denied");
	
	return 0;
}
