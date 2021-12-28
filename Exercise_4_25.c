#include <stdio.h>

int main(){

    int integer;
    int remainder1;
    int remainder2;
    int remainder3;
    int remainder4;
    int remainder5;
    int remainder6;
    int remainder7;
    int remainder8;
    int remainder9;

    printf("Binary\tOctal\tHexidecimal\n");

    for(int num = 1; num <= 256; num++){

        integer = num;

        remainder1 = integer % 2;
        integer = integer/2;

        remainder2 = integer % 2;
        integer = integer/2;

        remainder3 = integer % 2;
        integer = integer/2;

        remainder4 = integer % 2;
        integer = integer/2;

        remainder5 = integer % 2;
        integer = integer/2;

        remainder6 = integer % 2;
        integer = integer/2;

        remainder7 = integer % 2;
        integer = integer/2;

        remainder8 = integer % 2;
        integer = integer/2;

        remainder9 = integer % 2;
        integer = integer/2;

        printf("%d%d%d%d%d%d%d%d%d\t%o\t%X\n", remainder9, remainder8, remainder7, remainder6, remainder5, remainder4, remainder3, remainder2, remainder1, num, num);

        }

    

    return 0;
}