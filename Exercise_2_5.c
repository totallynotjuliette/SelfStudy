

#include <stdio.h>

int main(){

    puts("\nThis program will calculate the product of two integers.");

    puts("Please enter three integers:\n");

    int x;
    int y;
    int z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    int result = x * y * z;

    printf("\nThe product is %d\n", result);

    return 0;
}