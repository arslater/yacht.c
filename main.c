#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int DICE = 6;
int main()
{

	srand(time(NULL));
	int i;
	int turns;

	// TODO: Make this into a function to create players
	Player *player = (Player *) malloc(sizeof(Player));
	printf("Welcome to YAHTZEE!\n");
	
	for(i=0;i<DICE;i++)
		player->hand[i]=roll();

	//show_dice(player);
	turns = 0;

	while (turns < 3)
	{
		show_dice(player);

		printf("Reroll dice? [%d rolls remaining] (y/n):",3-turns);

		if ((i =fgetc(stdin)) == 'y')
		{
			fgetc(stdin);
			printf("Select the dice to reroll. 'd' to confirm:");
			while( (i=fgetc(stdin)) != 'd')
			{
				fgetc(stdin);	
				player->hand[i-48] = roll();	
			}	
		}
		fgetc(stdin);		
		turns++;
	}	
	show_dice(player);
	show_menu();
	i=evaluate(player,fgetc(stdin)-48);
	printf("***%d***\n",i);
	//printf("%d",evaluate(player,fgetc(stdin)));

	return 0;
}
