#pragma once

namespace Game
{
	class Cell
	{
	private:
		int _row;
		int _col;
		CellType _type;

	public:
		// Constructors
		Cell(int row, int col)
		{
			this->_row = row;
			this->_col = col;
			this->_type = CellType::EMPTY;
		}
		Cell()
		{
			this->_row = 0;
			this->_col = 0;
			this->_type = CellType::EMPTY;
		}


		// Operators overloading
		friend bool operator== (const Cell& c1, const Cell& c2) { return c1.getCol() == c2.getCol() && c1.getRow() == c1.getRow(); }
		Cell& operator= (const Cell& cell)
		{
			this->_row = cell._row;
			this->_col = cell._col;

			return *this;
		}


		// Accessor methods
		CellType getType() const { return this->_type; }
		void setType(CellType cellType) { this->_type = cellType; }
		int getRow() const { return this->_row; }
		int getCol() const { return this->_col; }
	};
}