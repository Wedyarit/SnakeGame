#pragma once
#include "Cell.h"
#include <vector>
class Snake
{
private:
	std::vector<Cell*> snakeCells;
	Cell* head;

public:
	Snake(Cell* firstPosition)
	{
		this->head = firstPosition;
		this->snakeCells.push_back(head);
	}
	Snake()
	{
		this->head = new Cell();

	}

	void grow()
	{
		this->snakeCells.push_back(this->head);
	}

	void move(Cell* nextCell)
	{
		this->snakeCells[0]->setType(CellType::EMPTY);
		this->snakeCells.pop_back();

		this->head = nextCell;
		this->snakeCells.insert(this->snakeCells.begin(), this->head);
	}

	bool checkCrashed(Cell* nextCell) const
	{
		for (int i = 0; (size_t)i < this->snakeCells.size(); ++i)
			if (nextCell == snakeCells[i]) return true;
		return false;
	}

	std::vector<Cell*> getSnakeCells() const { return this->snakeCells; }
	Cell* getHead() { return this->head; }
	void setHead(Cell* head) { this->head = head; }
};

