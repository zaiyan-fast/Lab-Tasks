#include <stdio.h>

int main(){
	int bolts, nuts, washers, total;
	
	printf("Enter no of bolts: ");
	scanf("%d", &bolts);
	printf("Enter no of nuts: ");
	scanf("%d", &nuts);
	printf("Enter no of washers: ");
	scanf("%d", &washers);
	
	total = (bolts * 5) + (washers * 1) + (nuts * 3);
	
	if(nuts < bolts)
		printf("Check Order: Too few nuts\n");
	if(2 * washers < bolts)
		printf("Check Order: Too few washers\n");
		
	if(nuts >= bolts && 2*washers >= bolts)
		printf("Check Order: OK\n");
		
	printf("Total Cost: %d\n", total);
	
	return 0;
}