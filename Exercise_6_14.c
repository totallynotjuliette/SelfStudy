#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RESPONSE_SIZE 99
#define FREQUENCY_SIZE 10


void mean(const int answer[], int answer_size);
void median(int answer[], int answer_size);
void mode(int freq[], const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);


int main()
{
    int frequency[FREQUENCY_SIZE] = {0};
    int response[RESPONSE_SIZE];

    srand(time(NULL));

    for(int i = 0; i < RESPONSE_SIZE; i++){
        response[i] = i + rand() % 9;
    }

    mean(response, RESPONSE_SIZE);
    //median(response);
    //mode(frequency, response);

    return 0;
}


void mean(const int answer[], int answer_size)
{
    printf("MEAN:");

    int total = 0;

    for(int i = 0; i < answer_size; i++){

        total += answer[i];
    }

    printf("%d / %d = %.4lf", total, answer_size, (double)total/answer_size);
}


void median(int answer[], int answer_size)
{
    printf("MEDIAN: ");

    printArray(answer);
    bubbleSort(answer);

    printf("Sorted array:");

    printArray(answer);

    printf("Median value: %d", answer(answer_size/2));
}


void mode(int freq[], const int answer[], int frequency_size, int answer_size)
{
    printf("MODE: ");

    for(int rating = 1; rating < frequency_size; rating++)
    {
        freq[rating] = 0;
    }



}