#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 5


void shuffle(int deck_placeholder[][FACES]);
void shuffle2(int deck_placeholder2[][FACES]);

void deal(int deck_placeholder[][FACES], char *wFace[], char *wSuit[], int hand[][2]);
void combos(int hand[][2], char *wFace[], int *pair, int *pair2, int *three, int *four);
void flush(int hand[][2], int *flush);
void straight(int hand[][2], int *straight);

int winner(int pair_1, int pair_2, int pair_1_two, int pair_2_two, int three1, int three2, int four1, int four2, int flush1, int flush2, int straight1, int straight2);




int main(){

    srand(time(NULL));

    char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *face[FACES] = {"Ace", "Duece", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    int pair2_counter_hand1 = 0;
    int pair2_counter_hand2 = 0;

    int three_counter_hand1 = 0;
    int three_counter_hand2 = 0;

    int four_counter_hand1 = 0;
    int four_counter_hand2 = 0;

    int flush_counter_hand1 = 0;
    int flush_counter_hand2 = 0;

    int straight_counter_hand1 = 0;
    int straight_counter_hand2 = 0;

    int deck1[SUITS][FACES] = {0};
    int deck2[SUITS][FACES] = {0};

    int hand1[5][2] = {0};
    int hand2[5][2] = {0};

    int pair_counter_hand1 = 0;
    int pair_counter_hand2 = 0;



    //hand 1
    shuffle(deck1);
    puts("\n-------- HAND 1 --------");
    deal(deck1, face, suit, hand1);
    combos(hand1, face, &pair_counter_hand1, &pair2_counter_hand1, &three_counter_hand1, &four_counter_hand1);
    flush(hand1, &flush_counter_hand1);
    straight(hand1, &straight_counter_hand1);

    //hand 2
    shuffle2(deck2);
    puts("\n-------- HAND 2 --------");
    deal(deck2, face, suit, hand2);
    combos(hand2, face, &pair_counter_hand2, &pair2_counter_hand2, &three_counter_hand2, &four_counter_hand2);
    flush(hand2, &flush_counter_hand2);
    straight(hand2, &straight_counter_hand2);

    puts("");

    winner(pair_counter_hand1, pair_counter_hand2, pair2_counter_hand1, pair2_counter_hand2, three_counter_hand1, three_counter_hand2, 
    four_counter_hand1, four_counter_hand2, flush_counter_hand1, flush_counter_hand2, straight_counter_hand1, straight_counter_hand2);


    return 0;
}

void shuffle2(int deck_placeholder2[][FACES]){

    for(int c = 1; c <= CARDS; ++c){

        int row;
        int column;

        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(deck_placeholder2[row][column] != 0);

        deck_placeholder2[row][column] = c;

    }
}

void shuffle(int deck_placeholder[][FACES]){

    for(int c = 1; c <= CARDS; ++c){

        int row;
        int column;

        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(deck_placeholder[row][column] != 0);

        deck_placeholder[row][column] = c;

    }
}


void deal(int deck_placeholder[][FACES], char *wFace[], char *wSuit[], int hand[][2]){

    for(int card = 1, n = 0; card <= CARDS; ++card, n++){
        for(int r = 0; r < SUITS; ++r){
            for(int c = 0; c < FACES; ++c){
                if(deck_placeholder[r][c] == card){
                    hand[n][0] = c;
                    hand[n][1] = r;
                    printf("%s of %s\n", wFace[c], wSuit[r]);
                }
            }
        }
    }
}

void combos(int hand[][2], char *wFace[], int *pair, int *pair2, int *three, int *four){

    char freq[FACES] = {0};
    int a = 0;

    for(int i = 0; i < CARDS; ++i){

        ++freq[hand[i][0]];
    }

    for(int k = 0; k < CARDS; ++k){
        for(int n = k + 1; n < CARDS; ++n){
            if(hand[k][0] == hand[n][0]){
                a++;
            }
        }
    }

    if(a==2){
        *pair2 +=1;
    }

    for(int j = 0; j < FACES; ++j){
        
        if(freq[j] == 2){
            *pair += 1;
        } else if (freq[j] == 3){
            *pair += 1;
        } else if (freq[j] == 4){
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
        *straight += 1;
    }
}


void flush(int hand[][2], int *flush){

    char freq[SUITS] = {0};

    for(int i = 0; i < CARDS; ++i){
        ++freq[hand[i][1]];
    }

    for(int j = 0; j < CARDS; ++j){
        if(freq[j] == CARDS){
            *flush += 1;
        }
    }
}

int winner(int pair_1, int pair_2, int pair_1_two, int pair_2_two, int three1, int three2, int four1, int four2, int flush1, int flush2, int straight1, int straight2){

    while(1 == 1){
        if(straight2 > straight1){
            printf("Hand 2 wins.");
            return 0;
        }
        if(straight2 < straight1){
            printf("Hand 1 wins.");
            return 0;
        }
        if( (straight1 == straight2) && (straight1 != 0)){
            printf("Tie!");
            return 0;
        }
        if(flush2 > flush1){
            printf("Hand 2 wins.");
            return 0;
        }
        if(flush2 < flush1){
            printf("Hand 1 wins.");
            return 0;
        }
        if(four2 < four1){
            printf("Hand 1 wins.");
            return 0;
        }
        if(four2 > four1){
            printf("Hand 2 wins.");
            return 0;
        }
        if(three2 < three1){
            printf("Hand 1 wins.");
            return 0;
        }
        if(three2 > three1){
            printf("Hand 2 wins.");
            return 0;
        }
        if(pair_1_two > pair_2_two){
            printf("Hand 1 wins.");
            return 0;
        }
        if(pair_2_two > pair_1_two){
            printf("Hand 2 wins.");
            return 0;
        }
        if(pair_1 > pair_2){
            printf("Hand 1 wins.");
            return 0;
        }
        if(pair_2 > pair_1){
            printf("Hand 2 wins.");
            return 0;
        }

        //ties
        if( (straight1 == straight2) && (straight1 != 0)){
            printf("Tie!");
            return 0;
        } else if( (flush1 == flush2) && (flush1 != 0)){
            printf("Tie!");
            return 0;
        } else if( (four1 == four2) && (four1 != 0)){
            printf("Tie!");
            return 0;
        } else if( (three1 == three2) && (three1 != 0)){
            printf("Tie!");
            return 0;
        } else if( (pair_1_two == pair_2_two) && (pair_1_two != 0)){
            printf("Tie!");
            return 0;
        } else if( (pair_1 == pair_2) && (pair_1 != 0)){
            printf("Tie!");
            return 0;
        } else {
            printf("Nobody got any points. Tie!");
            return 0;
        }

    }
}