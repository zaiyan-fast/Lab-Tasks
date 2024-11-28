#include <stdio.h>
#include <string.h>

struct Invoice{
    char number[10];
    char description[50];
    int quantity;
    float price_per_item;
};

void initialize(struct Invoice* invoice, char num[], char desc[], int quant, float price){
    strcpy((*invoice).number, num);
    strcpy((*invoice).description, desc);

    if(quant > 0)
        (*invoice).quantity = quant;
    else
        (*invoice).quantity = 0;
        
    if(price > 0)
        (*invoice).price_per_item = price;
    else
        (*invoice).price_per_item = 0;
}

int main() {
    struct Invoice invoice;
    initialize(&invoice, "ABC", "XYZ", 15, 22.5);
    
    float amount = invoice.quantity * invoice.price_per_item;
    printf("Part Number: %s\n", invoice.number);
    printf("Part Description: %s\n", invoice.description);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price per item: %.2f\n", invoice.price_per_item);

    return 0;
}