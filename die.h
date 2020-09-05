#ifndef DIE_H
#define DIE_H

///////////////////
// Die Struct
struct die
{
	int faceValue;
	struct die *next;
}; typedef struct die Die;

//////////////////
// Hand struct
struct hand
{
	Die* dieInHand;
}; typedef struct hand Hand;

// give a random number b/w 1 and 6
int roll();

// make die 
Die* makeDie();

// Make a hand of specified length, appended
// to (if existing) hand
Hand* makeHand(int,Hand *);

// print current hand of dice
void printHand(Hand*);

#endif
