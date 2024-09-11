//Quinn Nash

#ifndef SURPRISE_H
#define SURPRISE_H

#include "LifeCell.h"

using namespace std;

class SurpriseCell : public LifeCell
{
protected:
	//Only looks at diagonals fr living neighbors
	virtual void GetLivingNeighbors(int r, int c) override;


	virtual void UpdateCells() override;
public:
	SurpriseCell();
};

#endif