#ifndef YSTRUCT_H
#define YSTRUCT_H

//int TURNS = 13;
extern int DICE;

typedef struct player_struct
{
	int hand[6];;

	int ones;
	int twos;
	int threes;
	int fours;
	int fives;
	int sixes;
	int chance;
	int toak;
	int foak;
	int smst;
	int lgst;
	int yhtz;

	int score;

	int rolls;
	// possibly add turns here?
} Player;

int roll();
Player* update_dice(Player *player,int size_of_indexes);
int evaluate(Player *player, int index);
void show_menu();
void show_dice(Player *player);
#endif
