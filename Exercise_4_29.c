#include <stdio.h>

/*
!(x<5) && !(y>=7)
!(a==b) || !(g !+ 5)
!((x <= 8) && (y > 4))
!((i>4) || (j<= 6))

write program to show they are equivalent

*/

int main(){

    int x = 1;
    int y = 2;

    printf("Part A:");

    if( (!(x<5) && !(y>=7)) == !((x<5) || (y>=7)) ){

        puts("!(x<5) && !(y>=7) and !((x<5) || (y>=7)) are equivalent.");

    }




    int a = 1;
    int b = 2;
    int g = 3;

    printf("Part B:");

    if( (!(a==b) || !(g != 5)) == !((a==b) && (g != 5)) ){

        puts("!(a==b) || !(g != 5) and !((a==b) && (g != 5)) are equivalent.");

    }




    printf("Part C:");

    if( !((x <= 8) && (y > 4)) == (!(x <= 8) || !(y > 4)) ){

        puts("!((x <= 8) && (y > 4)) and (!(x <= 8) || !(y > 4)) are equivalent.");

    }




    int i = 1;
    int j = 2;

    printf("Part D:");

    if( (!((i>4) || (j<= 6))) == (!(i>4) && !(j<= 6)) ){

        puts("(!((i>4) || (j<= 6))) and (!(i>4) && !(j<= 6)) are equivalent.");

    }



    return 0;
}