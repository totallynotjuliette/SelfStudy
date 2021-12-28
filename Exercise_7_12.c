#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 5


void shuffle(int wDeck[][FACES]);
void shuffle2(int w2Deck[][FACES]);
void deal(int wDeck[][FACES], char *wFace[], char *wSuit[], int hand[][2]);

void combos(int hand[][2], char *wFace[], int *pair, int *pair2, int *three, int *four);
void flush(int hand[][2], int *flush);
void straight(int hand[][2], int *straight);




int main(){

    srand(time(NULL));



    int deck[SUITS][FACES] = {0};
    int hand[5][2] = {0};
    int pair_counter_hand = 0;
    int pair2_counter_hand = 0;
    int three_counter_hand = 0;
    int four_counter_hand = 0;
    int flush_counter_hand = 0;
    int straight_counter_hand = 0;

    char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[FACES] = {"Ace", "Duece", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    puts("This is your hand:\n");
    //hand 1
    shuffle(deck);
    deal(deck, face, suit, hand);
    combos(hand, face, &pair_counter_hand, &pair2_counter_hand, &three_counter_hand, &four_counter_hand);
    flush(hand, &flush_counter_hand);
    straight(hand, &straight_counter_hand);


    return 0;
}

void shuffle(int wDeck[][FACES]){

    for(int c = 1; c <= CARDS; ++c){

        int row;
        int column;

        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0);

        wDeck[row][column] = c;

    }
}


void deal(int wDeck[][FACES], char *wFace[], char *wSuit[], int hand[][2]){

    for(int card = 1, n = 0; card <= CARDS; ++card, n++){
        for(int r = 0; r < SUITS; ++r){
            for(int c = 0; c < FACES; ++c){
                if(wDeck[r][c] == card){
                    hand[n][0] = c;
                    hand[n][1] = r;
                    printf("%s of %s\n", wFace[c], wSuit[r]);
                }
            }
        }
    }
}

void flush(int hand[][2], int *flush){

    char frequen[SUITS] = {0};

    for(int i = 0; i < CARDS; ++i){
        ++frequen[hand[i][1]];
    }

    for(int j = 0; j < CARDS; ++j){
        if(frequen[j] == CARDS){
            printf("\nThis hand contains a flush.\n");
            *flush += 1;
        }
    }
}

void combos(int hand[][2], char *wFace[], int *pair, int *pair2, int *three, int *four){

    char frequen[FACES] = {0};
    int a = 0;

    for(int i = 0; i < CARDS; ++i){
        ++frequen[hand[i][0]];
    }

    for(int k = 0; k < CARDS; ++k){
        for(int n = k + 1; n < CARDS; ++n){
            if(hand[k][0] == hand[n][0]){
                a++;
            }
        }
    }

    if(a==2){
        puts("\nThis hand has 2 pairs.");
        *pair2 +=1;
    }

    for(int j = 0; j < FACES; ++j){
        
        if(frequen[j] == 2){
            printf("\nThis hand contains a pair of %s\n", wFace[j]);
            *pair += 1;
        } else if (frequen[j] == 3){
            printf("\nThis hand contains three of a kind of %s\n", wFace[j]);
            *pair += 1;
        } else if (frequen[j] == 4){
            printf("\nThis hand contains four of a kind of %s\n", wFace[j]);
            *pair += 1;
        }
    }
}

void straight(int hand[][2], int *straight){
    int a[CARDS] = {0};

    for(int i = 0; i < CARDS; ++i){
        a[i] = hand[i][0];
    }

    for(int p = 0; p < CARDS; p++){

        for(int i = 0; i < CARDS; i++){
            if(a[i] < a[i + 1]){
                int h = a[i];
                a[i] = a[i + 1];
                a[i + 1] = h;
            }
        }
    }

    if( (a[0] + 1) == a[1] && (a[1] + 1) == a[2] && (a[2] + 1) == a[3] && (a[3] + 1) == a[4]){
        printf("\nThis hand contains a straight.\n");
        *straight += 1;
    }
}


