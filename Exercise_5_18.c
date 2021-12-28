#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int evenOrOdd(int num){

    if(num % 2 == 0){
        //is even
        return 1;
    } else {
        //is odd
        return 0;
    }

}


int main(){

    srand(time(NULL));

    for(int i = 1; i <= 10; i++){

        int num = 1 + rand() % 50;

        if(evenOrOdd(num) == 1){

            printf("%d is even\n", num);

        } else {

            printf("%d is odd\n", num);

        }
    }

    return 0;
}