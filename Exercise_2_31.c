
#include <stdio.h>

int main(){

    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;
    int num7 = 7;
    int num8 = 8;
    int num9 = 9;
    int num10 = 10;

    int sq1 = num1 * num1;
    int sq2 = num2 * num2;
    int sq3 = num3 * num3;
    int sq4 = num4 * num4;
    int sq5 = num5 * num5;
    int sq6 = num6 * num6;
    int sq7 = num7 * num7;
    int sq8 = num8 * num8;
    int sq9 = num9 * num9;
    int sq10 = num10 * num10;

    int cb1 = num1 * num1 * num1;
    int cb2 = num2 * num2 * num2;
    int cb3 = num3 * num3 * num3;
    int cb4 = num4 * num4 * num4;
    int cb5 = num5 * num5 * num5;
    int cb6 = num6 * num6 * num6;
    int cb7 = num7 * num7 * num7;
    int cb8 = num8 * num8 * num8;
    int cb9 = num9 * num9 * num9;
    int cb10 = num10 * num10 * num10;

    printf("number     square     cube\n");
    printf("%d          %d          %d\n", num1, sq1, cb1);
    printf("%d          %d          %d\n", num2, sq2, cb2);
    printf("%d          %d          %d\n", num3, sq3, cb3);
    printf("%d          %d         %d\n", num4, sq4, cb4);
    printf("%d          %d         %d\n", num5, sq5, cb5);
    printf("%d          %d         %d\n", num6, sq6, cb6);
    printf("%d          %d         %d\n", num7, sq7, cb7);
    printf("%d          %d         %d\n", num8, sq8, cb8);
    printf("%d          %d         %d\n", num9, sq9, cb9);
    printf("%d         %d        %d\n", num10, sq10, cb10);
    
    return 0;
}