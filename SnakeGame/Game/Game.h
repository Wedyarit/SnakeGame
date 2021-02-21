#pragma once
#include "Snake.h"
#include "Board.h"

namespace Game
{
	class Game
	{
	private:
		Direction direction;
		Snake snake;
		Board board;
		GameStatus gameStatus;

		// Returns the next cell based on direction
		Cell* getNextCell(Cell* currentPosition)
		{
			int row = currentPosition->getRow();
			int col = currentPosition->getCol();

			switch (this->direction)
			{
			case Direction::RIGHT:
				if (col + 2 > this->board.getColCount()) return nullptr;
				col++;
				break;
			case Direction::LEFT:
				if (col - 1 < 0) return nullptr;
				col--;
				break;
			case Direction::UP:
				row--;
				if (row - 1 < 0) return nullptr;
				break;
			case Direction::DOWN:
				if (row + 2 > this->board.getRowCount()) return nullptr;
				row++;
				break;
			}

			return this->board.getCells()[row][col];
		}


	public:
		// Constructors
		Game(const Snake& snake, const Board& board)
		{
			this->snake = snake;
			this->board = board;
		}
		Game()
		{
			this->snake = Snake();
			this->board = Board();
		}

		void updateDirection(char key)
		{
			switch (key)
			{
			case 72:
				this->setDirection(Direction::UP);
				break;
			case 80:
				this->setDirection(Direction::DOWN);
				break;
			case 77:
				this->setDirection(Direction::RIGHT);
				break;
			case 75:
				this->setDirection(Direction::LEFT);
				break;
			}
		}

		// Basic motion update. Accounting for direction, food slots and collisions.
		void update()
		{
			if (isGameOver() || this->direction == Direction::NONE)
				return;

			Cell* nextCell = getNextCell(this->snake.getHead());
			if (nextCell == nullptr || this->snake.checkCrashed(nextCell))
			{
				setDirection(Direction::NONE);
				setGameStatus(GameStatus::INACTIVE);
			}
			else
			{
				snake.move(nextCell);
				if ((*nextCell).getType() == CellType::FOOD)
				{
					this->snake.grow();
					this->board.generateFood();
				}
			}
		}

		// Accessor methods
		Snake getSnake() const { return this->snake; }
		void setSnake(const Snake& snake) { this->snake = snake; }
		Board getBoard() const { return this->board; }
		void setBoard(const Board& board) { this->board = board; }
		bool isGameOver() const { return this->gameStatus == GameStatus::INACTIVE; }
		void setGameStatus(GameStatus gameStatus) { this->gameStatus = gameStatus; }
		Direction getDirection() const { return this->direction; }
		void setDirection(Direction direction) { this->direction = direction; }
	};
}