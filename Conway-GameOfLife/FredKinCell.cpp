//Quinn Nash

#include "FredKinCell.h"

void FredKinCell::UpdateCells()
{
	//Loop through every cell on the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j); //identify the cell we at and get the neighbors

			//apply rules for live and dead cells
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
	}
}

FredKinCell::FredKinCell() : LifeCell()
{
	
}
