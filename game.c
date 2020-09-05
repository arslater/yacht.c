#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "die.h"
#include "game.h"

void runGame()
{
    // main game loop here
    printf("   ");
}

int scoreUpperSection(Hand *hand, int value)
{
    Die* tmp  = hand ->dieInHand;
    int total = 0;

    while(tmp -> next!= NULL)
    {
        if(tmp ->faceValue == value) {
            total += value;
           // printf("%d == %d", value, tmp->faceValue);
        }
        tmp = tmp-> next;
    }
   // printf("***%d***", total);
    return total;
}


bool validateOAK(Hand* hand, int twoorthree, int value)
{
    Die* tmp = hand -> dieInHand;
    int freq = 0;

    while(tmp -> next != NULL) {
        if (tmp->faceValue == value)
            freq++;
        // printf("%d == %d", value, tmp->faceValue);
        tmp = tmp ->next;
    }
    return(freq == twoorthree);
}

