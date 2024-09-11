//Quinn Nash

#include "ModifiedFredkinCell.h"

void ModifiedFredkinCell::GetLivingNeighbors(int r, int c)
{
	//is VonNeumann to start, note every is all Fredkin till they get older
	FredKinCell::GetLivingNeighbors(r, c);

	if (age[r][c] > 2) //Then copy conway diagonal logic
	{//increment count for the Diagonals
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
}


void ModifiedFredkinCell::UpdateCells()
{
	//clear age if they come through again
	ClearAge();

	//create nested for loops
	//Loop through every cell on the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); //identify the cell we are at and get the neighbors

			//apply the rules depending on the age of the cell

			if (age[i][j] > 2)
			{//Conway rules
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
			else
			{//fredkin rules
				if (cell[i][j] == '*')
				{//alive becomes dead if even number or 0 neighbors
					if (count % 2 == 0)
					{
						nextCellState[i][j] = ' ';
					}
				}
				else
				{//dead becomes alive if odd number of neighbors
					if (count % 2 != 0)
					{
						nextCellState[i][j] = '*';
					}
				}
			}

			//if the cell is live and stays live, increment age
			if (cell[i][j] == '*' && nextCellState[i][j] == '*')
			{
				age[i][j]++;
			}
			else if (cell[i][j] == '*' && nextCellState[i][j] == ' ')
			{//cell is alive then dies, reset age
				age[i][j] = 0;
			}
		}
	}


}


ModifiedFredkinCell::ModifiedFredkinCell()
{
	ClearAge();
}


void ModifiedFredkinCell::ClearAge()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			age[i][j] = 0;
		}
	}

}
