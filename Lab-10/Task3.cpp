#include <stdio.h>
#include <string.h>

struct Car{
	char make[20];
	char model[20];
	int year;
	float price;
	int mileage;
};

void addCars(Car cars[], int* no_of_cars){
	printf("Enter Car make: ");
	scanf("%s", &cars[*no_of_cars].make);
	printf("Enter Car model: ");
	scanf("%s", &cars[*no_of_cars].model);
	printf("Enter Car year: ");
	scanf("%d", &cars[*no_of_cars].year);
	printf("Enter Car price: ");
	scanf("%f", &cars[*no_of_cars].price);
	printf("Enter Car mileage: ");
	scanf("%d", &cars[*no_of_cars].mileage);
	(*no_of_cars)++;
	printf("Car added successfully");
}

void displayCars(Car cars[], int no_of_cars){
	if(no_of_cars == 0)
		printf("No cars available\n");
	printf("\nAvailabe Cars:\n");
	for(int i = 0; i < no_of_cars; i++){
		printf("%d. Car:\n", i+1);
		printf("Make: %s\n", cars[i].make);
		printf("Model: %s\n", cars[i].model);
		printf("Year: %d\n", cars[i].year);
		printf("Price: %.3f\n", cars[i].price);
		printf("Mileage: %d\n", cars[i].mileage);
	}
}

void search(Car cars[], int no_of_cars, char make[], char model[]){
	int found = 0;
	for(int i = 0; i < no_of_cars; i++){
		if(!strcmp(cars[i].make, make) || ! strcmp(cars[i].model, model)){
			found = 1;
			printf("Car Found!\n");
			printf("Car %d\n", i+1);
			printf("Make: %s\n", cars[i].make);
			printf("Model: %s\n", cars[i].model);
			printf("Year: %d\n", cars[i].year);
			printf("Price: %f\n", cars[i].price);
			printf("Mileage: %d\n", cars[i].mileage);
		} 
	}
	if(!found)
	printf("No cars found!");
}

int main(){
	struct Car cars[10];
	int no_of_cars = 0;
	char make_search[10], model_search[10];
	int a;
	while(1){
		printf("\nCars Dealership:\n");
		printf("Press 1 to add a Car: \n");
		printf("Press 2 to display availabe cars: \n");
		printf("Press 3 to search cars by make: \n");
		printf("Press 4 to search cars by model: \n");
		scanf("%d", &a);
		switch(a){
			case 1:
				addCars(cars, &no_of_cars);
				break;
			case 2:
				displayCars(cars, no_of_cars);
				break;
			case 3:
				printf("Enter make to search: ");
				scanf("%s", &make_search);
				search(cars, no_of_cars, make_search, "0");
				break;
			case 4:
				printf("Enter Model to search: ");
				scanf("%s", &model_search);
				search(cars, no_of_cars, "0", model_search);
				break;
			default:
				printf("Wrong Option, Exiting Program!!!");
				return 0;
		}
	}
	return 0;
}