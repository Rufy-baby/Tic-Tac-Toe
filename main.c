//To compile everything use the following command
//gcc main.c append_table.c player_one.c player_two.c convert_point.c functions.h

#include <stdlib.h>
#include "functions.h"

int main()
{
	char **playing_table = NULL;
	int turn = 1;
	
	int x_pos = 0;
	int y_pos = 0;
	
	int *x_ptr = &x_pos;
	int *y_ptr = &y_pos;
	
	//Memory allocation for the array used to play game
	//Memory is freed at the bottom of the main
	playing_table = (char **)malloc(9 * sizeof(char));
	for (int i = 0; i < 3; i++)
	{
		playing_table[i] = (char *)malloc(3 * sizeof(char));
	}
	
	//To show an empty spot, a '.' is used
	//That is initialised here
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			playing_table[i][j] = '.';
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (turn == 1)
		{
			convert_point(player_one(playing_table), x_ptr, y_ptr);
			append_table(x_pos, y_pos, 1, playing_table);
			turn++;
		}
		else if (turn == 2)
		{
			convert_point(player_two(playing_table), x_ptr, y_ptr);
			append_table(x_pos, y_pos, 2, playing_table);
			turn--;
		}
		printf("\n");
		
		//Display of the grid is done here
		//This is done after every player makes a move
		//Grid always looks like
		//X O .
		//. . .
		//. . .
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
	
	//Memory Deallocation
	for(int i = 0; i < 3; i++)
	{
		free(playing_table[i]);
	}
	
	free(playing_table);
	
	return 0;
}