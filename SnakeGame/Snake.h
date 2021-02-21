#pragma once
#include "Cell.h"
#include <vector>

namespace Game
{
	class Snake
	{
	private:
		std::vector<Cell*> snakeCells;
		Cell* head;

	public:
		// Constructors
		Snake(Cell* firstPosition)
		{
			this->head = firstPosition;
			this->snakeCells.push_back(head);
		}
		Snake() { this->head = new Cell(); }


		// Increases snake's size
		void grow() { this->snakeCells.push_back(this->head); }

		// Change the location of the snake
		void move(Cell* nextCell)
		{
			this->snakeCells[0]->setType(CellType::EMPTY);
			this->snakeCells.pop_back();

			this->head = nextCell;
			this->snakeCells.insert(this->snakeCells.begin(), this->head);
		}

		// Tracks collisions
		bool checkCrashed(Cell* nextCell) const
		{
			for (int i = 0; (size_t)i < this->snakeCells.size(); ++i)
				if (nextCell == snakeCells[i]) return true;
			return false;
		}


		// Accessor methods
		std::vector<Cell*> getSnakeCells() const { return this->snakeCells; }
		Cell* getHead() const { return this->head; }
		void setHead(Cell* head) { this->head = head; }
	};
}