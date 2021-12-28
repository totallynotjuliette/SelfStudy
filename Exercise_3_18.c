#include <stdio.h>


int main(){

    float sales;
    float salary;

    while(sales != -1){

        printf("\nEnter sales in dollars (-1 to end): ");
        scanf("%f", &sales);

        if(sales != -1){

            salary = 200 + (sales * .09);
            printf("Salary is: $%.2f\n", salary);

        }

    }

    return 0;
}