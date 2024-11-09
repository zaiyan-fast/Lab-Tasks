#include <stdio.h>
#include <string.h>

int main() {
	char str[100];
	char key[100];
    printf("Enter a text to encrypt: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    
    int len = strlen(str);
    int key_len = strlen(key);
    
    char adjkey[len], cipher[len];
    int j = 0;
    
    for(int i = 0; i < len; i++){
        adjkey[i] = key[j++];
        if(j==key_len)
            j=0;
    }
    adjkey[len] = '\0';
    
    for(int i = 0; i < len; i++){
        adjkey[i] -= 64;
        if(str[i] != ' ')
            str[i] -= 64;
        else
            str[i] = 20;
    }
    
    for(int i = 0; i < len; i++){
        cipher[i] = str[i] + adjkey[i];
        cipher[i] = cipher[i] % 26;
        if (cipher[i] == 0)
            cipher[i] = 26;
        cipher[i] += 64;
    }
    cipher[len] = '\0';
    printf("Encrypted text: %s", cipher);
    return 0;
}