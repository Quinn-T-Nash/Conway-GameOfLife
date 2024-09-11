//Quinn Nash

#ifndef SEEDS_CELL_H
#define SEEDS_CELL_H

#include "LifeCell.h"

using namespace std;

class SeedsCell : public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int r, int c) override;
	virtual void UpdateCells() override;
public:
	SeedsCell();
};

#endif