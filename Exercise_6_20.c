#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAMES 1000

enum Status {CONTINUE, WON, LOST};
int wins[21]; //max: 21 rolls
int losses[21];
int roll = 0;

int rollDice(void);
int playCraps(void);


int main()
{   

    srand(time(NULL));
    


    for(int round = 0; round < GAMES; round++)
    {
        playCraps();
    }


    //GAMES WON FOR # OF ROLLS

    printf("NUMBER OF ROLLS\t\tWINS");

    for(int roll_value = 1; roll_value <= 20; roll_value++){

        printf("\n\t%d\t\t%d", roll_value, wins[roll_value]);
    }
    printf("\n\t%d++\t\t%d", 21, wins[21]);

    puts(" ");
    puts(" ");

    //GAMES LOST FOR # OF ROLLS
    
    printf("NUMBER OF ROLLS\t\tLOSSES");

    for(int roll_value = 1; roll_value <= 20; roll_value++){

        printf("\n\t%d\t\t%d", roll_value, losses[roll_value]);
    }
    printf("\n\t%d++\t\t%d", 21, losses[21]);

    puts(" ");
    puts(" ");

    //PORBABILITY
    int total_wins = 0;

    for(int roll_value = 1; roll_value <= 20; roll_value++){

        total_wins = total_wins + wins[roll_value];

    }

    printf("Chances of winning at craps: %.2lf", (double)total_wins/GAMES);






    return 0;
}



int playCraps(){

    roll = 0;

    int point;
    enum Status gameStatus;
    int sum = rollDice();

        switch(sum)
        {
            case 7:
            case 11:
                gameStatus = WON;
                break;

            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                break;

            default:
                gameStatus = CONTINUE;
                point = sum;
                break;
        }

        while(gameStatus == CONTINUE)
        {
            sum = rollDice();

            if(sum == point){

                gameStatus = WON;

            } else if (sum == 7){

                gameStatus = LOST;
            }
            
        }

    switch(gameStatus)
    {
        case WON:
            if(roll <= 20){
                wins[roll]++;
            } else if(roll > 20){
                wins[21]++;
            }
            break;

        case LOST:
            if(roll <= 20){
                losses[roll]++;
            } else if(roll > 20){
                losses[21]++;
            }
            break;
    }

        
}

int rollDice(void)
{   
    roll++;

    int d1 = 1 + (rand() % 6);
    int d2 = 1 + (rand() % 6);

    return d1 + d2;

}