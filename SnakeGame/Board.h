#pragma once
#include "Cell.h"
#include "MathsUtils.h"
#include <vector> 

class Board
{
private:
	int ROW_COUNT;
	int COL_COUNT;
	Cell*** cells;;

public:
	// Constructors
	Board(int rowCount, int colCount)
	{
		this->ROW_COUNT = rowCount;
		this->COL_COUNT = colCount;
		this->cells = new Cell * *[ROW_COUNT];
		for (int i = 0; i < this->ROW_COUNT; i++)
			cells[i] = new Cell * [this->COL_COUNT];

		for (int row = 0; row < this->ROW_COUNT; ++row)
			for (int column = 0; column < this->COL_COUNT; ++column)
				cells[row][column] = new Cell(row, column);
	}
	Board()
	{
		this->ROW_COUNT = 0;
		this->COL_COUNT = 0;
		this->cells = new Cell * *[0];
	}


	// Random food points generation
	void generateFood()
	{
		int row = MathsUtils::randomInteger(0, ROW_COUNT);
		int col = MathsUtils::randomInteger(0, COL_COUNT);

		this->cells[row][col]->setType(CellType::FOOD);
	}


	// Accessor methods
	Cell*** getCells() const { return this->cells; }
	void setCells(Cell*** cells) { this->cells = cells; }
};

