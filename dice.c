#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"

int roll()
{

	return( (rand() % 6) + 1);
}

Hand* makeHand(int howMany, Hand* existingHand)
{
	Hand* newHand = (Hand *) malloc(sizeof(Hand));
	Die * tmp     = makeDie(roll());

	tmp->faceValue = roll();
	newHand -> dieInHand = tmp;
	printf("making new hand w/ face value: --%d--\n",newHand -> dieInHand-> faceValue);
	
	while(howMany > 0)
	{
		tmp -> next = makeDie(roll());
		tmp = tmp -> next;
		howMany--;
	}

	 // appending the existing dice
	return(newHand);
}

Die* makeDie(int newFaceValue)
{
	// initalize the die
	Die* newDie = (Die *) malloc(sizeof(Die));
	newDie -> faceValue = newFaceValue;

	newDie -> next = NULL;

	return(newDie);
}

void printHand(Hand *handToPrint)
{
	Die *tmp = handToPrint -> dieInHand;

	while( tmp -> next != NULL)
	{
		printf("[%d] ", tmp -> faceValue);
		tmp = tmp -> next;
	}
	printf("\n");
}

int main()
{
    srand(time(0));
    Die*  currentDie  = makeDie(roll());
	Hand* currentHand = makeHand(5,NULL);

	printf("currentDie face value:%d\n",currentDie->faceValue);
	printHand(currentHand);

	return(0);
}
