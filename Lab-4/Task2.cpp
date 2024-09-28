#include <stdio.h>

int main(){
	float totBill, unitsCons, surchargeAdd;
	printf("Enter electricity units\t");
	scanf("%f", &unitsCons);	
	
		if(unitsCons<=30){
			totBill = unitsCons * 0.60;
		}else if(unitsCons<=110){
			totBill = (30 * 0.60) + ((unitsCons-30)*0.85);
		}else if(unitsCons<=210){
			totBill = (30 * 0.60) + (80 * 0.85) + ((unitsCons - 110) * 1.30);
		}else{
			totBill = (30 * 0.60) + (80*0.85) + (100*1.30) + ((unitsCons - 210)*1.60);
		}
		
		surchargeAdd = totBill * (15/100);
		totBill = totBill + surchargeAdd;
		printf("The final bill is: %f", totBill);
		
	return 0;
}
