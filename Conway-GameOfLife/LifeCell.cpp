//Quinn Nash

#include "LifeCell.h"

#include <iostream>
void LifeCell::InitializeBoard()
{
	ifstream input;
	stringstream ss;

	string line{ "" };
	//read the file chosen by user
	input.open(pattern);

	if (input.is_open())
	{
		//fill a ss with the input
		while (!input.eof())
		{
			getline(input, line);
			ss << line;
		}
	}
	//put each char of the ss into the proper array location
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			
			cell[i][j] = ss.get();

			if (cell[i][j] == '.')
			{
				cell[i][j] = ' ';
			}

			
			cout << cell[i][j];
			if (j == 77) cout << endl;
		}
	}
	
}


void LifeCell::GetLivingNeighbors(int r, int c)
{
	//set count to 0 before identifying neighbors
	count = 0;

	//Implement a Von Neumann neighborhood
	//Make sure cells are not at an edge to prevent array out of bounds errors 
	//  (then Check cells up r-1, down r+1, left c-1 and right c+1 of current cell)
	if (r == 0)
	{//nothing above
		if (cell[r + 1][c] == '*')
			count++;

		if (c == 0)
		{//nothing left
			if (cell[r][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r][c - 1] == '*')
				count++;
			if (cell[r][c + 1] == '*')
				count++;
		}

	}
	else if (r == 44)
	{//nothing below
		if (cell[r - 1][c] == '*')
			count++;

		if (c == 0)
		{//nothing left
			if (cell[r][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r][c - 1] == '*')
				count++;
			if (cell[r][c + 1] == '*')
				count++;
		}
	}	
	else
	{
		if (cell[r - 1][c] == '*')
			count++;
		if (cell[r + 1][c] == '*')
			count++;

		if (c == 0)
		{//nothing left
			if (cell[r][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r][c - 1] == '*')
				count++;
			if (cell[r][c + 1] == '*')
				count++;
		}
	}
}


void LifeCell::SetNextState()
{
	//use nested for loops to set each element of nextCellState into cell array
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = nextCellState[i][j];
		}
	}
}


//constructor
LifeCell::LifeCell()
{
	//initialize cell array as dead and nextCellState array
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = ' ';
			nextCellState[i][j] = ' ';
		}
	}
}


void LifeCell::SetPattern(string pat)
{ 
	pattern = pat; //easier if we make this the file name
	InitializeBoard();
}


void LifeCell::UpdateBoard()
{	
	UpdateCells();
	SetNextState();
}


string LifeCell::PrintBoard()
{
	//use ss and create a string with array on it 
	stringstream ss;

	//use nested loops to check if content of element is dead ' '
	for (int i = 0; i < ROWS; i++)
	{
		if (i != 0)
		{
			ss << endl;
		}
		for (int j = 0; j < COLS; j++)
		{
			ss << cell[i][j];
		}
	}

	return ss.str();
}


void LifeCell::Clear()
{
	//reset arrays as dead
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = ' ';
		}
	}
}
