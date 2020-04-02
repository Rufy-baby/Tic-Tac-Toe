#include <stdio.h>

//This file handles checking for a win
//Only X marked spots are checked for a win
// X X X
// X 5 6
// X 8 9
//Only these spots are checked because every win
//has at least one of those spots chose

//All functions are recursive except "check_winner"
//When a match is found in the direction the function is searching
//The function calls itself until 3 matches are found
//Rows and Cols are index from 0 to 2

//This checks vertically from the top
void check_down (char **playing_table, int row, int col, int *count_ptr)
{
	if ((row < 2) && (playing_table[row + 1][col] == playing_table[row][col]) && *count_ptr < 3)
	{
		*count_ptr = *count_ptr + 1;
		check_down(playing_table, row + 1, col, count_ptr);
	}
}

//This checks horizontally from the right
void check_side (char **playing_table, int row, int col, int *count_ptr)
{
	if ((col < 2) && (playing_table[row][col + 1] == playing_table[row][col]) && *count_ptr < 3)
	{
		*count_ptr = *count_ptr + 1;
		check_side(playing_table, row, col + 1, count_ptr);
	}
}

//This checks diagonally from top left to bottom right
void check_diag_down (char **playing_table, int row, int col, int *count_ptr)
{
	if ((col < 2) && (playing_table[row + 1][col + 1] == playing_table[row][col]) && *count_ptr < 3)
	{
		*count_ptr = *count_ptr + 1;
		check_diag_down(playing_table, row + 1, col + 1, count_ptr);
	}
}

//This checks diagonally from bottom left to top right
void check_diag_up (char **playing_table, int row, int col, int *count_ptr)
{
	if ((row > 0) && (col < 2) && (playing_table[row - 1][col + 1] == playing_table[row][col]) && *count_ptr < 3)
	{
		*count_ptr = *count_ptr + 1;
		check_diag_up(playing_table, row - 1, col + 1, count_ptr);
	}
}


//This function handles all the calling of all the above recursive functions
//Once a match is found it says in witch direction the match is 
//Then it returns the player symbol(character) in which a match was found
//The default return value is '-' to indicate no matches were found
char check_winner(char **playing_table)
{
	int count = 1;
	int *count_ptr = &count;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 0)
			{
				count = 1;
				check_down(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Straight Vertical\n");
					return playing_table[i][j];
				}
				
				count = 1;
				check_side(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Straight Horizontal\n");
					return playing_table[i][j];
				}
				
				count = 1;
				check_diag_down(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Diagonal Right To Left\n");
					return playing_table[i][j];
				}
			}
			
			else if ((i == 0 && j == 1) || (i == 0 && j == 2))
			{
				count = 1;
				check_down(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Straight Vertical\n");
					return playing_table[i][j];
				}
			}
				
			else if (i == 1 && j == 0)
			{
				count = 1;
				check_side(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Straight Horizontal\n");
					return playing_table[i][j];
				}
			}
			
			else if (i == 2 && j == 0)
			{
				count = 1;
				check_side(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Straight Horizontal\n");
					return playing_table[i][j];
				}
				
				count = 1;
				check_diag_up(playing_table, i, j, count_ptr);
				if (count == 3)
				{
					printf("Diagonal Left To Right");
					return playing_table[i][j];
				}
			}
			
		}
	}
	return '-';
}