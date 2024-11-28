#include <stdio.h>

struct Rectangle{
    float length;
    float width;
};

float perimeter(struct Rectangle rectangle){
    return 2 * (rectangle.length+rectangle.width);
}

float area(struct Rectangle rectangle){
    return rectangle.length * rectangle.width;
}

int check(struct Rectangle rectangle){
    if(rectangle.width >= 0 && rectangle.width <= 20 && rectangle.length >=0 && rectangle.length <= 20) 
        return 1;
    else
        return 0;
}

int main() {
    struct Rectangle rectangle;
    
    printf("Enter Length: ");
    scanf("%f", &rectangle.length);
    printf("Enter Width: ");
    scanf("%f", &rectangle.width);
    
    int valid = check(rectangle);
    
    if(valid){
    float p = perimeter(rectangle);
    float a = area(rectangle);
    
    printf("Perimeter: %.2f\n", p);
    printf("Area: %.2f\n", a);
    }else{
        printf("Incorrect Dimensions!");
    }
    return 0;
}