
#include <stdio.h>

int main(){

    puts("Please enter two integers:");

    int num1;
    int num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    int sum = num1 + num2;
    int product = num1 * num2;
    int difference = num1 - num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Difference: %d\n", difference);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);


    return 0;
}