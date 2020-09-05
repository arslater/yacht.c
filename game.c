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


bool validateOAK(Hand* hand, int fourfive, int value)
{
    Die* tmp = hand -> dieInHand;
    int freq = 0;

    while(tmp -> next != NULL) {
        if (tmp->faceValue == value)
            freq++;
        // printf("%d == %d", value, tmp->faceValue);
        tmp = tmp ->next;
    }
    return(freq == fourfive);
}

void scoreAll()
{
    Die*  currentDie  = makeDie(roll());
    Hand* currentHand = makeHand(5,NULL);
    int   i           = 0;

    printHand(currentHand);
    printf("scoring 1s = %d\n",scoreUpperSection(currentHand, 1));
    printf("scoring 2s = %d\n",scoreUpperSection(currentHand, 2));
    printf("scoring 3s = %d\n",scoreUpperSection(currentHand, 3));
    printf("scoring 4s = %d\n",scoreUpperSection(currentHand, 4));
    printf("scoring 5s = %d\n",scoreUpperSection(currentHand, 5));
    printf("scoring 6s = %d\n",scoreUpperSection(currentHand, 6));

    for(i = 0; i<7; i++)
    {
        if(validateOAK(currentHand,3,i))
            printf("3 of a kind - %ds\n",i);
        else if (validateOAK(currentHand,4,1))
            printf("4 of a kind - %ds\n",i);
    }
}