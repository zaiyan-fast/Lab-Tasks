#include <stdio.h>
#include <string.h>

void revstr(char str[], int a, int b){
	if(a >= b)
		return;
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
	revstr(str, ++a, --b);
}


int main(){
	char str[100];
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	int len = strlen(str);
	if(str[len - 1] == '\n'){
		str[len - 1] = '\0';
		len--;
	}
	
	revstr(str, 0, len - 1);
	
	printf("%s", str);
	return 0;
}