//Quinn Nash

#include "SurpriseCell.h"

void SurpriseCell::GetLivingNeighbors(int r, int c)
{
	count = 0;
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

void SurpriseCell::UpdateCells()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); //identify the cell we at and get the neighbors

			if (cell[i][j] == ' ')
			{
				if (count % 2 == 0)
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
				if (count > 1)
				{
					nextCellState[i][j] = ' ';
				}
				else
				{
					nextCellState[i][j] = '*';
				}
			}

		}
	}
}

SurpriseCell::SurpriseCell()
{
}
