#include <stdio.h>

void percentage(float num, int a){
	if(a > 100)
		return;
	printf("%d Percent = %.2f\n", a, a * num / 100);
	percentage(num, ++a);
}

int main(){
	float num;
	printf("Enter a number: ");
	scanf("%f", &num);
	percentage(num, 1);
	return 0;
}