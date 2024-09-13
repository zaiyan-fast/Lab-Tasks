#include <stdio.h>

int main(){
	float cost, discount, price_discount, final_amount;
	
	printf("Enter the cost\t");
	scanf("%f", &cost);
	
	if(cost<1500){
		discount = 7;
	}else if(cost>=1500 && cost<3000){
		discount = 12;
	}else if(cost>=3000 && cost<=5000){
		discount = 22;
	}else if(cost>5000){
		discount = 30;
	}
	
	price_discount = cost * (discount/100);
	final_amount = cost - price_discount;
	
	printf("The initial bill was %f\n", cost);
	printf("The saved amount is %f\n", price_discount);
	printf("The final bill is %f\n", final_amount);

	return 0;
}