//Quinn Nash

#ifndef LIFE_CELL_H
#define LIFE_CELL_H

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class LifeCell
{
protected:
	static const int ROWS{ 45 };
	static const int COLS{ 78 };
	int count{ 0 }, rows{ 0 }, cols{ 0 };	//count is the number of neighbors alive counted
	string pattern;		//the index of the initial pattern chosen.
	bool bOpen{ false };		//states whether the file was opened successfully

	char cell[ROWS][COLS];	//Grid of cells.  If '*' -> cell is alive, if '.' -> cell is dead 
	char nextCellState[ROWS][COLS];

	void InitializeBoard();	//reads the pattern file and initializes the board
	virtual void GetLivingNeighbors(int r, int c); //use von Neumann neighborhood
	virtual void UpdateCells() = 0;		//apply the rules here	
	void SetNextState();		//set new states into the cells	

public:
	LifeCell();			//default constructor.  All cells are dead initially.
	void SetPattern(string pat);	//Sets the initial pattern and calls InitializeBoard		
	void UpdateBoard();	//Calculates the next generation, sets the new values into the grid    and calls SetNextState()	
	string PrintBoard();	      //returns a string of the board for display
	void Clear();		      //Reset the board to all dead cells	

};


#endif

