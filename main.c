#include <stdlib.h>
#include <time.h>
#include "die.h"
#include "game.h"
#include <stdio.h>

int main()
{
    srand(time(0));
    Die*  currentDie  = makeDie(roll());
    Hand* currentHand = makeHand(5,NULL);

    printf("currentDie face value:%d\n",currentDie->faceValue);
    printHand(currentHand);
    printf("scoring 1s = %d\n",scoreUpperSection(currentHand, 1));
    printf("scoring 2s = %d\n",scoreUpperSection(currentHand, 2));
    printf("scoring 3s = %d\n",scoreUpperSection(currentHand, 3));
    printf("scoring 4s = %d\n",scoreUpperSection(currentHand, 4));
    printf("scoring 5s = %d\n",scoreUpperSection(currentHand, 5));
    printf("scoring 6s = %d\n",scoreUpperSection(currentHand, 6));

    if(validateOAK(currentHand,3,1))
        printf("3 of a kind -1s\n");
    if(validateOAK(currentHand,3,2))
        printf("3 of a kind -2s\n");
    if(validateOAK(currentHand,3,3))
        printf("3 of a kind -3s\n");
    if(validateOAK(currentHand,3,4))
        printf("3 of a kind -4s\n");
    if(validateOAK(currentHand,3,5))
        printf("3 of a kind -5s\n");
    if(validateOAK(currentHand,3,6))
        printf("3 of a kind -6s\n");
    return(0);
}

