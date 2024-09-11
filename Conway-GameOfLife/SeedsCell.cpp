//Quinn Nash

#include "SeedsCell.h"


void SeedsCell::GetLivingNeighbors(int r, int c)
{
	//copy from conway cell they same thing

	//call get GetLivingNeighbors from LifeCell
	LifeCell::GetLivingNeighbors(r, c);

	//increment count for the Diagonals
	if (r == 0)
	{//nothing above

		if (c == 0)
		{//nothing left
			if (cell[r + 1][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r + 1][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r + 1][c - 1] == '*')
				count++;
			if (cell[r + 1][c + 1] == '*')
				count++;
		}

	}
	else if (r == 44)
	{//nothing below
		if (c == 0)
		{//nothing left
			if (cell[r - 1][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r - 1][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r - 1][c - 1] == '*')
				count++;
			if (cell[r - 1][c + 1] == '*')
				count++;
		}
	}
	else
	{
		if (c == 0)
		{//nothing left
			if (cell[r + 1][c + 1] == '*')
				count++;
			if (cell[r - 1][c + 1] == '*')
				count++;
		}
		else if (c == 77)
		{//nothing right
			if (cell[r + 1][c - 1] == '*')
				count++;
			if (cell[r - 1][c - 1] == '*')
				count++;
		}
		else
		{
			if (cell[r + 1][c - 1] == '*')
				count++;
			if (cell[r - 1][c - 1] == '*')
				count++;
			if (cell[r + 1][c + 1] == '*')
				count++;
			if (cell[r - 1][c + 1] == '*')
				count++;
		}
	}
}

void SeedsCell::UpdateCells()
{
	//Loop through every cell on the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); //identify the cell we at and get the neighbors

			if (cell[i][j] == ' ')
			{
				if (count == 2)
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = ' ';
				}
			}
			else
			{
				nextCellState[i][j] = ' ';
			}
		}
	}

}

SeedsCell::SeedsCell()
{
}
