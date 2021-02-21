#pragma once
#include "Utils/Maths.h"


namespace Game
{
	class Board
	{
	private:
		int _rowCount;
		int _colCount;
		Cell*** _cells;

	public:
		// Constructors
		Board(int rowCount, int colCount)
		{
			this->_rowCount = rowCount;
			this->_colCount = colCount;
			this->_cells = new Cell * *[rowCount];
			for (int i = 0; i < this->_rowCount; i++)
				_cells[i] = new Cell * [this->_colCount];

			for (int row = 0; row < this->_rowCount; ++row)
				for (int column = 0; column < this->_colCount; ++column)
					_cells[row][column] = new Cell(row, column);
		}
		Board()
		{
			this->_rowCount = 0;
			this->_colCount = 0;
			this->_cells = new Cell * *[0];
		}


		// Random food points generation
		void generateFood()
		{
			int row = Utils::Maths::randomInteger(0, this->_rowCount - 1);
			int col = Utils::Maths::randomInteger(0, this->_colCount - 1);

			this->_cells[row][col]->setType(CellType::FOOD);
		}


		// Accessor methods
		Cell*** getCells() const { return this->_cells; }
		void setCells(Cell*** cells) { this->_cells = cells; }
		int getColCount() const { return this->_colCount; }
		int getRowCount() const { return this->_rowCount; }
	};
}