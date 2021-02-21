#pragma once
#include <vector> 
#include "Cell.h"
#include "Utils/Maths.h"


namespace Game
{
	class Board
	{
	private:
		int rowCount;
		int colCount;
		Cell*** cells;

	public:
		// Constructors
		Board(int rowCount, int colCount)
		{
			this->rowCount = rowCount;
			this->colCount = colCount;
			this->cells = new Cell * *[rowCount];
			for (int i = 0; i < this->rowCount; i++)
				cells[i] = new Cell * [this->colCount];

			for (int row = 0; row < this->rowCount; ++row)
				for (int column = 0; column < this->colCount; ++column)
					cells[row][column] = new Cell(row, column);
		}
		Board()
		{
			this->rowCount = 0;
			this->colCount = 0;
			this->cells = new Cell * *[0];
		}


		// Random food points generation
		void generateFood()
		{
			int row = Utils::Maths::randomInteger(0, this->rowCount - 1);
			int col = Utils::Maths::randomInteger(0, this->colCount - 1);

			this->cells[row][col]->setType(CellType::FOOD);
		}


		// Accessor methods
		Cell*** getCells() const { return this->cells; }
		void setCells(Cell*** cells) { this->cells = cells; }
		int getColCount() const { return this->colCount; }
		int getRowCount() const { return this->rowCount; }
	};
}