//Quinn Nash

#ifndef MODIFIED_FREDKIN_CELL_H
#define MODIFIED_FREDKIN_CELL_H

#include "FredKinCell.h"

using namespace std;

class ModifiedFredkinCell : public FredKinCell
{
private:
	int age[ROWS][COLS]{};

protected:
	virtual void GetLivingNeighbors(int r, int c) override;
	virtual void UpdateCells() override;

public:
	ModifiedFredkinCell();
	void ClearAge();
};

#endif
