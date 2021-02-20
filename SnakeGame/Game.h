#pragma once
#include "Snake.h"
#include "Board.h"

enum class Direction
{
	NONE,
	RIGHT,
	LEFT,
	UP,
	DOWN
};

enum class GameStatus
{
	ACTIVE,
	INACTIVE,
	IN_MENU
};

class Game
{
private:
	Direction direction;
	Snake snake;
	Board board;
	GameStatus gameStatus;

	Cell* getNextCell(Cell* currentPosition)
	{
		int row = currentPosition->getRow();
		int col = currentPosition->getCol();

		switch (this->direction)
		{
		case Direction::RIGHT:
			col++;
			break;
		case Direction::LEFT:
			col--;
			break;
		case Direction::UP:
			row--;
			break;
		case Direction::DOWN:
			row++;
			break;
		}

		return this->board.getCells()[row][col];
	}

public:
	Game(const Snake& snake, const Board& board)
	{
		this->snake = snake;
		this->board = board;
	}

	void update()
	{
		if (isGameOver())
			return;
		if (this->direction == Direction::NONE)
			return;

		Cell* nextCell = getNextCell(this->snake.getHead());
		if (this->snake.checkCrashed(nextCell))
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

	Snake getSnake() const { return this->snake; }
	void setSnake(const Snake& snake) { this->snake = snake; }
	Board getBoard() const { return this->board; }
	void setBoard(const Board& board) { this->board = board; }
	bool isGameOver() const { return this->gameStatus == GameStatus::INACTIVE; }
	void setGameStatus(GameStatus gameStatus) { this->gameStatus = gameStatus; }
	Direction getDirection() const { return this->direction; }
	void setDirection(Direction direction) { this->direction = direction; }
};
