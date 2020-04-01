#include <stdio.h>

//The user gives the point they want to choose as a single digit integer
//This function converts that to x,y position numbers
//This is done because the grid is a 2D Array
//This is essential for the function append_table to work

//1 2 3   0,0 0,1 0,2
//4 5 6 = 1,0 1,1 1,2
//7 8 9   2,0 2,1 2,2

void convert_point(int point, int *x_pos, int *y_pos)
{
	if (point == 1)
	{
		*x_pos = 0;
		*y_pos = 0;
	}
	
	else if (point == 2)
	{
		*x_pos = 0;
		*y_pos = 1;
	}
	
	else if (point == 3)
	{
		*x_pos = 0;
		*y_pos = 2;
	}
	
	else if (point == 4)
	{
		*x_pos = 1;
		*y_pos = 0;
	}
	
	else if (point == 5)
	{
		*x_pos = 1;
		*y_pos = 1;
	}
	
	else if (point == 6)
	{
		*x_pos = 1;
		*y_pos = 2;
	}
	
	else if (point == 7)
	{
		*x_pos = 2;
		*y_pos = 0;
	}
	
	else if (point == 8)
	{
		*x_pos = 2;
		*y_pos = 1;
	}
	
	else if (point == 9)
	{
		*x_pos = 2;
		*y_pos = 2;
	}
}