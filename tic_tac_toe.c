#include <stdio.h> //import function like printf()
#include <stdlib.h> //import random number generator
#include <math.h> //import math functions like sqrt()
#include <time.h> //import time

int print_intro(void);
int flip_coin(void);
int gameplay_user(char game_play[3][3], char symbol);
int gameplay_computer(char game_play[3][3], char symbol);
int current_state(char game_play[3][3]);
int check_winner(char game_play[3][3], char symbol_computer, char symbol_player);

enum Status {CONTINUE, WON, LOST};
enum Status gameStatus;

int main(){

    

    char game_play[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char taken_cells[9];
    int move_count;
    char symbol_player;
    char symbol_computer;




    print_intro();

    if(flip_coin() == 1){ //user goes first
        symbol_player = 'X';
        symbol_computer = 'O';
        printf("User goes first.");
    } else {
        symbol_player = 'O';
        symbol_computer = 'X';
        printf("Computer goes first.");
    }

    gameStatus = CONTINUE;

    while(gameStatus == CONTINUE){

        if(symbol_player == 'X'){ //user goes first
            gameplay_user(game_play, symbol_player);
            current_state(game_play);
            check_winner(game_play, symbol_computer, symbol_player);
        } else if(symbol_player == 'O'){ //computer goes first
            gameplay_computer(game_play, symbol_computer);
            current_state(game_play);
            check_winner(game_play, symbol_computer, symbol_player);
        }

        if(gameStatus == CONTINUE){ 

            if(symbol_player == 'X'){ //computer goes second
                gameplay_computer(game_play, symbol_computer);
                current_state(game_play);
                check_winner(game_play, symbol_computer, symbol_player);
            } else if (symbol_player == 'O'){ //player goes second
                gameplay_user(game_play, symbol_player);
                current_state(game_play);
                check_winner(game_play, symbol_computer, symbol_player);
            }

        }
    }

    switch(gameStatus){

        case WON:
            printf("You won! Congrats!");
            break;
        case LOST:
            printf("You lost. Better luck next time.");
            break;
        default:
            printf("ERROR IN GAMESTATUS");

    }



    return 0;
}


int print_intro(){

    puts("\nWelcome to the Tic Tac Toe game!");
    puts("You will be playing a game against the computer today!\n");

    puts("When prompted, please choose a cell number based on the");
    puts("9 cells in a game of Tic Tac Toe to make your move.");
    puts("If the cell has already been taken, then you will be prompted to");
    puts("make another choice.\n");

    puts("The cells look as follows: \n");

    puts("1     |2      |3      ");
    puts("--------------------");
    puts("4     |5      |6      ");
    puts("--------------------");
    puts("7     |8      |9      \n");

    return 0;
}

int flip_coin(){

    int user_selection;

    printf("Let's decide who goes first. Heads(1) or tails(0)? ");
    scanf("%d", &user_selection);

    srand(time(NULL));
    int flip = rand();

    if( (user_selection == 0 && flip == 0) || (user_selection == 1 && flip > 0)){
        puts("You go first! You play as X.\n");
        return 1; //user goes first
    } else {
        puts("The computer goes first! You play as O.\n");
        return 0; //computer goes first
    }

}

int gameplay_user(char game_play[3][3], char symbol){


        int box;
        printf("\nSelect the box for your move: ");
        scanf("%d", &box);

        switch(box){

            case 1:
                if(game_play[0][0] != 'X' && game_play[0][0] != 'O'){
                    game_play[0][0] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 2:
                if(game_play[0][1] != 'X' && game_play[0][1] != 'O'){
                    game_play[0][1] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 3:
                if(game_play[0][2] != 'X' && game_play[0][2] != 'O'){
                    game_play[0][2] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 4:
                if(game_play[1][0] != 'X' && game_play[1][0] != 'O'){
                    game_play[1][0] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 5:
                if(game_play[1][1] != 'X' && game_play[1][1] != 'O'){
                    game_play[1][1] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 6:
                if(game_play[1][2] != 'X' && game_play[1][2] != 'O'){
                    game_play[1][2] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 7:
                if(game_play[2][0] != 'X' && game_play[2][0] != 'O'){
                    game_play[2][0] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 8:
                if(game_play[2][1] != 'X' && game_play[2][1] != 'O'){
                    game_play[2][1] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            case 9:
                if(game_play[2][2] != 'X' && game_play[2][2] != 'O'){
                    game_play[2][2] = symbol;
                } else {
                    printf("That box is taken! Try again.\n");
                    gameplay_user(game_play, symbol);
                }
                break;
            default:
                printf("That's not a valid box! Try again.\n");
                gameplay_user(game_play, symbol);
                break;

        }

    return 0;
}

int gameplay_computer(char game_play[3][3], char symbol){


        int box = 1 + (rand() % 9);


        switch(box){

            case 1:
                if(game_play[0][0] != 'X' && game_play[0][0] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[0][0] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 2:
                if(game_play[0][1] != 'X' && game_play[0][1] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[0][1] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 3:
                if(game_play[0][2] != 'X' && game_play[0][2] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[0][2] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 4:
                if(game_play[1][0] != 'X' && game_play[1][0] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[1][0] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 5:
                if(game_play[1][1] != 'X' && game_play[1][1] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[1][1] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 6:
                if(game_play[1][2] != 'X' && game_play[1][2] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[1][2] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 7:
                if(game_play[2][0] != 'X' && game_play[2][0] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[2][0] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 8:
                if(game_play[2][1] != 'X' && game_play[2][1] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[2][1] = symbol;
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            case 9:
                if(game_play[2][2] != 'X' && game_play[2][2] != 'O'){
                    printf("\nComputer is playing... \n");
                    game_play[2][2] = symbol;
                    
                } else {
                    gameplay_computer(game_play, symbol);
                }
                break;
            default:
                printf("ERROR.\n");
                break;

        }


    return 0;
}


int current_state(char game_play[3][3]){

    printf("\n%c     |%c      |%c      \n", game_play[0][0], game_play[0][1], game_play[0][2]);
    printf("--------------------\n");
    printf("%c     |%c      |%c      \n", game_play[1][0], game_play[1][1], game_play[1][2]);
    printf("--------------------\n");
    printf("%c     |%c      |%c      \n", game_play[2][0], game_play[2][1], game_play[2][2]);

}

int check_winner(char game_play[3][3], char symbol_computer, char symbol_player){

    // there are 8 possible win combinations

    //check rows for a win
    for(int r = 0; r < 3; r++){
        
        if(game_play[r][0] == game_play[r][1] && game_play[r][1] == game_play[r][2]){

            if(game_play[r][1] = symbol_computer){

                gameStatus = LOST;
            }

            if(game_play[r][1] = symbol_player){

                gameStatus = WON;
            }

        }
    }

    //check columns for a win
    for(int c = 0; c < 3; c++){
        
        if(game_play[0][c] == game_play[1][c] && game_play[1][c] == game_play[2][c]){

            if(game_play[1][c] = symbol_computer){

                gameStatus = LOST;
            }

            if(game_play[1][c] = symbol_player){

                gameStatus = WON;
            }
            
        }
    }

    //check diagonals for a win

    if(game_play[0][0] == game_play[1][1] && game_play[1][1] == game_play[2][2]){

        if(game_play[0][0] = symbol_computer){

            gameStatus = LOST;
        }

        if(game_play[0][0] = symbol_player){

            gameStatus = WON;
        }

    }

    if(game_play[0][2] == game_play[1][1] && game_play[1][1] == game_play[2][0]){

        if(game_play[0][2] = symbol_computer){

            gameStatus = LOST;
           
        }

        if(game_play[0][2] = symbol_player){

            gameStatus = WON;
        }

    }

    if(gameStatus != WON && gameStatus != LOST){
        gameStatus = CONTINUE;
    }

    return 0;
}