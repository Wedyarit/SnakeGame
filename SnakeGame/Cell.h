#pragma once
#include "Enumerations.h"

class Cell
{
private:
	int row;
	int col;
	CellType type;

public:
	// Constructors
	Cell(int row, int col)
	{
		this->row = row;
		this->col = col;
		this->type = CellType::EMPTY;
	}
	Cell()
	{
		this->row = 0;
		this->col = 0;
		this->type = CellType::EMPTY;
	}


	// Operators overloading
	friend bool operator== (const Cell& c1, const Cell& c2)
	{
		return c1.getCol() == c2.getCol() && c1.getRow() == c1.getRow();
	}
	Cell& operator= (const Cell& cell)
	{
		this->row = cell.row;
		this->col = cell.col;

		return *this;
	}


	// Accessor methods
	CellType getType() const { return this->type; }
	void setType(CellType cellType) { this->type = cellType; }
	int getRow() const { return this->row; }
	int getCol() const { return this->col; }
};

