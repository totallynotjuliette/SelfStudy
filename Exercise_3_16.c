

#include <stdio.h>

int main(){

    float gallons;
    float miles;
    float miles_per_gallon;

    float total_miles;
    float total_gallons;
    float avg_miles_per_gallon;


    while(gallons != -1){

        printf("\nEnter the gallons used (enter -1 to end program): ");
        scanf("%f", &gallons);
        total_gallons += gallons;

        if(gallons != -1){

            printf("Enter the miles driven: ");
            scanf("%f", &miles);
            total_miles += miles;

            miles_per_gallon = miles/gallons;

            printf("The miles/gallon for this tank was %.2f", miles_per_gallon);
        }

    } 

    avg_miles_per_gallon = total_miles/total_gallons;
    printf("\nThe overall average miles/gallon was %f\n", avg_miles_per_gallon);

    return 0;

}