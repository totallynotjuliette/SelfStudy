
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isMultiple(int int1, int int2){

    if(int1 % int2 == 0){
        //is multiple
        return 1;
    } else {
        //not a multiple
        return 0;
    }

}

int main(){

    srand(time(NULL));

    for(int i = 1; i <= 5; i++){

        int num1 = 1 + rand() % 50;
        int num2 = 1 + rand() % 50;


        if(isMultiple(num1, num2) == 1){

            printf("%d is a multiple of %d\n", num2, num1);

        } else {

            printf("%d is not a multiple of %d\n", num2, num1);
        }


    }

    return 0;
}