//Quinn Nash

#include "ConwayCell.h"

void ConwayCell::GetLivingNeighbors(int r, int c)
{
	//Conway cell is a Moore Neighborhood

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
			if (cell[r -1][c - 1] == '*')
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

void ConwayCell::UpdateCells()
{
	//Apply the rule to each cell seperately

	//Loop through every cell on the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); //identify the cell we at and get the neighbors

			//then apply the conway rules
			// for live cells
			if (cell[i][j] == '*')
			{
				if (count < 2 || count > 3) //cell dies
				{
					nextCellState[i][j] = ' '; //set state dead
				}
				else
				{
					nextCellState[i][j] = '*';
				}
			}
			else
			{
				if (count == 3) //3 dead neighbors
				{
					nextCellState[i][j] = '*'; //set alive
				}
				else
				{
					nextCellState[i][j] = ' ';
				}
			}

		}
	}
}

ConwayCell::ConwayCell() : LifeCell()
{
	//todo
}
