#include <stdio.h>
#include <string.h>

struct Employee{
	int id;
	char name[50];
	char department[50];
	float salary;
};

void addEmployees(Employee employees[], int no_of_employees){
	for(int i = 0; i < no_of_employees; i++){
		printf("\nEnter Employee ID: ");
		scanf("%d", &employees[i].id);
		printf("Enter Employee Name: ");
		scanf("%s", &employees[i].name);
		printf("Enter Employee Department: ");
		scanf("%s", &employees[i].department);
		printf("Enter Employee salary: ");
		scanf("%f", &employees[i].salary);
		printf("Employee %d Added Successfully!\n", i+1);
	}
}

void displayEmployees(Employee employees[], int no_of_employees){
	if(no_of_employees < 0)
		printf("Wrong Input\n");

	printf("\nEmployees:\n");
	for(int i = 0; i < no_of_employees; i++){
		printf("---Employee %d---\n", i+1);
		printf("Employee ID: %d\n", employees[i].id);
		printf("Employee Name: %s\n", employees[i].name);
		printf("Employee Department: %s\n", employees[i].department);
		printf("Employee Salary: %.2f\n", employees[i].salary);
	}
}

int main(){
	int no_of_employees;
	printf("How many employees do you want to enter? ");
	scanf("%d", &no_of_employees);
	struct Employee employees[no_of_employees];
	
	addEmployees(employees, no_of_employees);	
	displayEmployees(employees, no_of_employees);	
	return 0;
}