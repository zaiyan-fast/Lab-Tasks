#include <stdio.h>

struct Employee{
    char name[10];
    char dob[10];
    int id;
    char dep[10];
    int salary;
};

void addEmployee(Employee employees[], int *count){
    printf("Enter Employee's Name: ");
    scanf("%s", &employees[*count].name);
    printf("Enter Employee's Date of Birth: ");
    scanf("%s", &employees[*count].dob);
    printf("Enter Employee's ID: ");
    scanf("%d", &employees[*count].id);
    printf("Enter Employee's Department: ");
    scanf("%s", &employees[*count].dep);
    printf("Enter Employee's Salary: ");
    scanf("%d", &employees[*count].salary);
    (*count)++;
}

void delEmployee(Employee employees[], int *count){
    if(!*count){
        printf("No Employees to delete!\n");
        return;
    }
    int del;
    printf("Enter Employee's ID: ");
    scanf("%d", &del);
    
    for(int i = 0; i < *count; i++){
        if(employees[i].id  == del){
            for(int j = 0; j < *count; j++){
                employees[j] = employees[j+1];
            }
            printf("Employee %d deleted!\n", del);
            break;
        }else{
            printf("Employee not Found!\n");
        }
    }
    (*count)--;
}

void displayEmployees(Employee employees[], int count){
    if(!count){
        printf("No Employees to Show!\n");
        return;
    }
    for(int i = 0; i < count; i++){
    	printf("\n---%d Employee---\n", i+1);
        printf("Employee's Name: %s\n", employees[i].name);
        printf("Employee's Date of Birth: %s\n", employees[i].dob);
        printf("Employee's ID: %d\n", employees[i].id);
        printf("Employee's Department: %s\n", employees[i].dep);
        printf("Employee's Salary: %d\n", employees[i].salary);
    }
}

int main() {
    struct Employee employees[10];
    int count = 0;
    
    while(1){
        int opt;
        printf("----Employee Management System----\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. List all Employees\n");
        printf("4. Exit\n");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                delEmployee(employees, &count);
                break;
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                printf("Exiting Program!");
                return 0;
            default:
                printf("Wrong Input!\n");
                break;
        }
    } 
    return 0;
}