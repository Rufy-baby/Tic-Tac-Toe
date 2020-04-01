#include <unistd.h>

//After a player has chosen a point on the grid to mark
//This is used to change the grid so the players mark is put there
//Refer to convert_point.c

char **append_table(int x_pos, int y_pos, int player, char **playing_table)
{	
	char player_one = 'X';
	char player_two = 'O';
	
	if (player == 1)
	{
		playing_table[x_pos][y_pos] = player_one;
	}
	else if (player == 2)
	{
		playing_table[x_pos][y_pos] = player_two;
	}
	
	return playing_table;
}