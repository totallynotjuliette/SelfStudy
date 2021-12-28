#include <stdio.h>


int main(){

    float interest;
    float principal;
    float rate;
    float days;

    while(principal != -1){

        printf("Enter loan principal (-1 to end): ");
        scanf("%f", &principal);

        if(principal != -1){

            printf("Enter interest rate: ");
            scanf("%f", &rate);

            printf("Enter term of the loan in days: ");
            scanf("%f", &days);
            
            interest = (principal * rate * days) / 365;
            
            printf("The interest rate is %.2f\n", interest);

            
        }

    }

    return 0;
}