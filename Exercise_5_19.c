#include <stdio.h>

int square(int sideLength){

    for(int i = 1; i <= sideLength; i++){

        for(int i = 1; i <= sideLength; i++){
        
            printf("*");

        }

    puts("");

    }
}

int main(){

    int length;
    
    puts("Please enter the length of your square");
    scanf("%d", &length);

    square(length);

    return 0;
}