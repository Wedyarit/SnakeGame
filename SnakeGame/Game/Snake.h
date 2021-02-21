#pragma once
#include <vector>

namespace Game
{
	class Snake
	{
	private:
		std::vector<Cell*> _snakeCells;
		int _size;
		Cell* _head;

	public:
		// Constructors
		Snake(Cell* firstPosition)
		{
			this->_head = firstPosition;
			this->_snakeCells.push_back(_head);
			this->_size = 1;
		}
		Snake()
		{
			this->_head = new Cell();
			this->_size = 1;
		}


		// Increases snake's size
		void grow()
		{
			this->_snakeCells.push_back(this->_head);
			this->_size++;
		}

		// Change the location of the snake
		void move(Cell* nextCell)
		{
			this->_snakeCells[0]->setType(CellType::EMPTY);
			this->_snakeCells.pop_back();

			this->_head = nextCell;
			this->_snakeCells.insert(this->_snakeCells.begin(), this->_head);
		}

		// Tracks collisions
		bool checkCrashed(Cell* nextCell) const
		{
			for (int i = 0; (size_t)i < this->_snakeCells.size(); ++i)
				if (nextCell == _snakeCells[i]) return true;
			return false;
		}


		// Accessor methods
		std::vector<Cell*> getSnakeCells() const { return this->_snakeCells; }
		Cell* getHead() const { return this->_head; }
		void setHead(Cell* head) { this->_head = head; }
		int getSize() const { return this->_size; }
	};
}