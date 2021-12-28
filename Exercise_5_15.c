#include <stdio.h>
#include <math.h>


double hypotenuseCalc(double side1, double side2){

    double hypotenuse = sqrt( pow(side1, 2) + pow(side2, 2) );

    return hypotenuse;

}

int main(){
    
    printf("Hypotenuse (side1: 3, side2: 4): %.2lf\n", hypotenuseCalc(3.0, 4.0));
    printf("Hypotenuse (side1: 5, side2: 12): %.2lf\n", hypotenuseCalc(5.0, 12.0));
    printf("Hypotenuse (side1: 8, side2: 15): %.2lf\n", hypotenuseCalc(8.0, 15.0));



    return 0;
}