#include <stdio.h>
#include <math.h>


int main(){

    
 
    for(int hypotenuse = 1; hypotenuse <= 500; hypotenuse++){

        for(int side1 = 1; side1 <= 500; side1++){

            for(int side2 = 1; side2 <= 500; side2++){
                
                if(hypotenuse == sqrt( pow(side1, 2.0) + pow(side2, 2.0))){
            
                    printf("hypotenuse: %d, side1: %d, side2: %d\n", hypotenuse, side1, side2);
                                
                } 
            
            }
        }
    }
    
               

    return 0;
    
}