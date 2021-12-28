#include <stdio.h>


int integerPower(int base, int power){

    int finalValue = 1;

    for(int i = 1; i <= power; i++){

        finalValue = finalValue * base;
    }

    return finalValue;
}

int main(){

    printf("3 to the power of 3: %d\n", integerPower(3, 3)); //test 
    printf("5 to the power of 6: %d\n", integerPower(5, 6)); //test 
    printf("4 to the power of 2: %d\n", integerPower(4, 2)); //test 

    return 0;
}