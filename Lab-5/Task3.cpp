#include <stdio.h>

int main(){
	float percentage;
	char grade;
	
	printf("Enter your percentage\n");
	scanf("%f", &percentage);
	
	percentage>=90? grade = 'A':
	(percentage>=80 && percentage<90)? grade = 'B':
	(percentage>=70 && percentage<80)? grade = 'C':
	(percentage>=60 && percentage<70)? grade = 'D':
	percentage<60? grade = 'F':printf("Invalid percentage");
	
	printf("Your Grade is %c", grade);
	return 0;
}