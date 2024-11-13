#include <stdio.h>
#include <string.h>

struct Package{
	char name[10];
	char destination[10];
	int duration;
	int cost;
	int no_of_seats_available;
};

void addPackage(Package packages[], int *no_of_packages){
	printf("Enter Package Name: ");
	scanf("%s", &packages[*no_of_packages].name);
	printf("Enter Destination: ");
	scanf("%s", &packages[*no_of_packages].destination);
	printf("Enter Duration (in days): ");
	scanf("%d", &packages[*no_of_packages].duration);
	printf("Enter Cost: ");
	scanf("%d", &packages[*no_of_packages].cost);
	printf("Enter no of seats available: ");
	scanf("%d", &packages[*no_of_packages].no_of_seats_available);
	printf("\nPackage Added Successfully!\n");
	(*no_of_packages)++;
}

void displayPackage(Package packages[], int no_of_packages){
	if(no_of_packages == 0)
		printf("No packages available rn\n");

	printf("Availabe Packages:\n");
	for(int i = 0; i < no_of_packages; i++){
		printf("---%d---\n", i+1);
		printf("Package Name: %s\n", packages[i].name);
		printf("Destination: %s\n", packages[i].destination);
		printf("Duration (in days): %d\n", packages[i].duration);
		printf("Cost: %d\n", packages[i].cost);
		printf("No of seats availabe: %d\n", packages[i].no_of_seats_available);
	}
}

void bookPackage(Package packages[], int no_of_packages, int package_no){
	if(package_no <= no_of_packages){
		if(packages[package_no-1].no_of_seats_available>0){
			packages[package_no-1].no_of_seats_available--;
			printf("Seat Booked\n");
			printf("Availabe seats in package %d: %d", package_no, packages[package_no - 1].no_of_seats_available);
		}else
			printf("Seat Not Availabe!\n");
	}else
		printf("No such package availabe\n");
}

int main(){
	struct Package packages[10];
	int no_of_packages = 0, package_no, a;
	
	while(1){
		printf("\n-----Package Booking System-----\n");
		printf("Press 1 to add a package: \n");
		printf("Press 2 to display availabe packages: \n");
		printf("Press 3 to book a package: \n");
		scanf("%d", &a);
		
		switch(a){
			case 1:
				addPackage(packages, &no_of_packages);
				break;
			case 2:
				displayPackage(packages, no_of_packages);
				break;
			case 3:
				printf("Enter Package number to book: ");
				scanf("%d", &package_no);
				bookPackage(packages, no_of_packages, package_no);
				break;
			default:
				printf("Sorry! Wrong Option!\n Exiting Program!");
				return 0;	
		}
	}	
	return 0;
}