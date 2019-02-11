#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//int DICE=6;

int roll(){
	return((rand()%6)+1);	
}

Player *update_dice(Player *player,int size_of_indexes)
{
	int i;

	for(i=0;i<size_of_indexes;i++)
	{	
	//	printf("[%d]:%d --->",i,player->hand[i]);
		player->hand[i]=roll();
	//	printf("%d\n",player->hand[i]);
	}
	return player;
}
void show_dice(Player *player)
{
	int i;

	printf("DICE   |");
	for(i=0;i<DICE;i++)
		printf("[%d] ",player->hand[i]);
	printf("\nINDEXES|");
	for(i=0;i<DICE;i++)
		printf(" %d  ",i);
	printf("\n");
}
int evaluate(Player *player, int index)
{
	int i;
	int score = 0;
	if ( index != 0 && index < 7)
	{
		for(i=0;i<DICE;i++)
		{
			printf("%d:",player->hand[i]);
			if(player->hand[i] == index)
				score+=index;
		}
	}
	return score;
}
void show_menu()
{
	printf("\t[0].....Chance\n");
	printf("\t[1].....Ones\n");
	printf("\t[2].....Twos\n");
	printf("\t[3].....Threes\n");
	printf("\t[4].....Fours\n");
	printf("\t[5].....Fives\n");
	printf("\t[6].....Sixes\n");
	printf("\t[7].....3 of a kind\n");
	printf("\t[8].....4 of a kind\n");
	printf("\t[9].....Small straght\n");
	printf("\t[10]....Large Straight\n");
	printf("\t[11]....Full House\n");
	printf("\t[12]....YAHTZEE!\n");
}
