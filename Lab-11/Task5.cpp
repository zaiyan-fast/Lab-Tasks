#include <stdio.h>
struct Phone{
    int area;
    int exchange;
    int number;
};

int main() {
    struct Phone user;
    struct Phone mine;
    
    mine.area = 200;
    mine.exchange = 777;
    mine.number = 7890;

    printf("Enter area code: ");
    scanf("%d", &user.area);
    printf("Enter exchange: ");
    scanf("%d", &user.exchange);
    printf("Enter number: ");
    scanf("%d", &user.number);
    
    printf("My number is (%d) %d-%d\n", mine.area, mine.exchange, mine.number);
    printf("Your number is (%d) %d-%d\n", user.area, user.exchange, user.number);

    return 0;
}