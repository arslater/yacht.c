//
// Created by anita on 9/5/20.
// Not playing against anyone
//
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

#ifndef GAME_H
#define GAME_H

struct score
{
    int ones;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;

    int fullhouse;
    int threeoak;
    int fouroak;
    int smstrait;
    int lgstrait;

    int yahtzee;
    int chance;
}; typedef struct score Score;

void runGame();

// Validate selections
bool validateOAK(Hand*, int,int);
bool validateFH(Hand*);
bool validateYZ(Hand*);
bool validateST(Hand*, char);

// Calculate the scores for the upper section(ones, twos, etc)
// Since pass in the number that you want to score
int scoreUpperSection(Hand*,int);

//Lower section scoring
int scoreLowerSection(Hand*,int);

void scoreAll();
#endif //YACHT_C_GAME_H
