#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 20

int main(){

    int a[ARRAY_SIZE];

    srand(time(NULL));

    //generate 20-number array
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = 10 + rand() % 100;
    }

    //print entire array
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf(" %d", a[i]);
    }
    
    puts(" ");


    for(int array_count_to_test = 0; array_count_to_test < ARRAY_SIZE; array_count_to_test++) // for each number
    {
        //start off unmarking it
        int times_printed_before = 0;

        for(int comparison_number = 0; comparison_number < array_count_to_test; comparison_number++) //scan each number before the current one being tested
        {
            if(a[array_count_to_test] == a[comparison_number]){ //if equals another number at some point, mark num as duplicate
                //duplicate
                times_printed_before++;
            }
        }

        if(times_printed_before == 0){
            printf(" %d", a[array_count_to_test]);
        }
        //after comparison is done, if num has not been marked, then print it
    }

    






    return 0;

}