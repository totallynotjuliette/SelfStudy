#include <stdio.h>
#include <math.h>


int main(){


    float pi_estimate_iteration = 0;
    float pi_estimate_total = 0;

    int terms = 1;
    int odd_number;
    int power_iteration = 0;
    

    printf("Terms\tPi Estimate\n");

    for(terms = 1; terms <= 1000; terms++){

        odd_number = (2.0 * power_iteration) + 1;

        pi_estimate_iteration = (4.0/odd_number) * (pow(-1.0, terms + 1.0));
        pi_estimate_total = pi_estimate_total + pi_estimate_iteration;

        power_iteration++;

        printf("%d\t%.5f\n", terms, pi_estimate_total);
        
    }

    
    return 0;
}