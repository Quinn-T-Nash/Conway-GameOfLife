//Quinn Nash

#ifndef FREDKIN_CELL_H
#define FREDKIN_CELL_H

#include "LifeCell.h"

using namespace std;


class FredKinCell : public LifeCell
{
protected:
	virtual void UpdateCells() override;
public:
	FredKinCell();
};

#endif