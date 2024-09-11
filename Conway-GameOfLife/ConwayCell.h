//Quinn Nash

#ifndef CONWAY_CELL_H
#define CONWAY_CELL

#include "LifeCell.h"

using namespace std;

class ConwayCell : public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int r, int c) override;
	virtual void UpdateCells() override;

public:
	ConwayCell();
};

#endif