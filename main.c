//To compile everything use the following command
//gcc main.c append_table.c player_one.c player_two.c convert_point.c functions.h

#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char **argv)
{
	char **playing_table = NULL;
	int turn = 1;
	
	int x_pos = 0;
	int y_pos = 0;
	
	int *x_ptr = &x_pos;
	int *y_ptr = &y_pos;
	
	int player_choice = 0;
	
	char win_check = ' ';
	int positions = 1;
	
	//Memory allocation for the array used to play game
	//Memory is freed at the bottom of the main
	playing_table = (char **)malloc(9 * sizeof(char));
	for (int i = 0; i < 3; i++)
	{
		playing_table[i] = (char *)malloc(3 * sizeof(char));
	}
	
	//Grid is initialized with numbers for 1 - 9
	// 1 2 3
	// 4 5 6
	// 7 8 9
	//This is done to not make the function that checks for a winner to mistakenly
	//chose spaces as a match
	//This will be fixed if it poses a problem to game play
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			playing_table[i][j] = positions + 48;
			positions++;
		}
	}
	
	//For loop runs until all 9 spots are filled
	//Or until someone wins
	//After every turn, the grid is checked for a win
	//When check_winner function return a positive win
	//In the form of a player's symbol, the loop is broken and the game ends
	//The winner is announced between Player 1 and Player 2 based on the winning sysmbol
	//Player 1 is 'X' and Player 2 is 'O'
	
	//If a player's algorithm attemps to mark an already marked spots
	//Or returns a value less than 1 or greater than 9
	//The game ends and the other player wins
	for (int i = 0; i < 9; i++)
	{
		if (turn == 1) //Player One's turn
		{
			player_choice = player_one(playing_table);
			if (player_choice < 1 || player_choice > 9)
			{
				win_check = 'O';
			}
			else
			{
				convert_point(player_choice, x_ptr, y_ptr);
				if (playing_table[x_pos][y_pos] == 'X' || playing_table[x_pos][y_pos] == 'O')
				{
					win_check = 'O';
				}
				else
				{
					append_table(x_pos, y_pos, 1, playing_table);
					win_check = check_winner(playing_table);
				}
			}
			if (win_check == 'X' || win_check == 'O')
				i = 9;
			turn++;
		}
		
		else if (turn == 2) //Player Two's turn
		{
			player_choice = player_two(playing_table);
			if (player_choice < 1 || player_choice > 9)
			{
				win_check = 'X';
			}
			else
			{
				convert_point(player_choice, x_ptr, y_ptr);
			
				if (playing_table[x_pos][y_pos] == 'X' || playing_table[x_pos][y_pos] == 'O')
				{
					win_check = 'X';
				}
				else
				{
					append_table(x_pos, y_pos, 2, playing_table);
					win_check = check_winner(playing_table);
				}
			}
			if (win_check == 'X' || win_check == 'O')
				i = 9;
			turn--;
		}
		printf("\n");
		
		//Display of the grid is done here
		//This is done after every player makes a move
		//Grid always looks like
		//X O 3
		//4 5 6
		//7 8 8
		//
		//because player_one and player_two functions are still dummy functions
		//and return 1 and 2 respectively
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{	
				printf("%c%c", playing_table[i][j], ' ');
			}
			printf("\n");
		}
		printf("\n");
	}
	
	if (win_check == 'X')
		printf("Player One Wins");
	else if (win_check == 'O')
		printf("Player Two Wins");
	else
		printf("Stale! No Winner");

	//Memory Deallocation
	for(int i = 0; i < 3; i++)
	{
		free(playing_table[i]);
	}
	
	free(playing_table);
	
	return 0;
}