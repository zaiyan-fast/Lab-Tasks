#include <stdio.h>

int main() {
    int time;
	printf("Enter what time is it?\t");
	scanf("%d", &time);

    if (time >= 6 && time < 12) {
        printf("Good Morning\n");
    } else if (time >= 12 && time < 18) {
        printf("Good Afternoon\n");
    } else if (time >= 18 && time < 24) {
        printf("Good Evening\n");
    } else {
        printf("Good Night\n");
    }

    return 0;
}