#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBER_OF_ROLLS 36000

int main(){

    srand(time(NULL));

    int d1;
    int d2;
    int sum;

    int dieSum[NUMBER_OF_ROLLS];

    for(int roll = 0; roll < NUMBER_OF_ROLLS; roll++)
    {
        d1 = 1 + rand() % 6;
        d2 = 1 + rand() % 6;
        sum = d1 + d2;

        dieSum[roll] = sum;

    }

    int frequency[10] = {0};
    
    for(int r = 0; r < NUMBER_OF_ROLLS; r++) 
    {
        frequency[dieSum[r]]++;
    }



    //printing results

    printf("\tSUM\t\tFREQUENCY");

    for(int histogram_value = 2; histogram_value <= 12; histogram_value++){

        printf("\n\t%d\t\t%d", histogram_value, frequency[histogram_value]);
    }
    


    return 0;
}