#pragma once


namespace Game
{
	class Game
	{
	private:
		Direction _direction;
		Snake _snake;
		Board _board;
		GameStatus _gameStatus;

		// Returns the next cell based on direction
		Cell* getNextCell(Cell* currentPosition)
		{
			int row = currentPosition->getRow();
			int col = currentPosition->getCol();

			switch (this->_direction)
			{
			case Direction::RIGHT:
				if (col + 2 > this->_board.getColCount()) return nullptr;
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
				if (row + 2 > this->_board.getRowCount()) return nullptr;
				row++;
				break;
			}

			return this->_board.getCells()[row][col];
		}


	public:
		// Constructors
		Game(const Snake& snake, const Board& board)
		{
			this->_snake = snake;
			this->_board = board;
		}
		Game()
		{
			this->_snake = Snake();
			this->_board = Board();
		}

		// Basic direction update. Accounting for pressed key
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

		// Basic motion update. Accounting for direction, food slots and collisions
		void update()
		{
			if (isGameOver() || this->_direction == Direction::NONE)
				return;

			Cell* nextCell = getNextCell(this->_snake.getHead());
			if (nextCell == nullptr || this->_snake.checkCrashed(nextCell))
			{
				setDirection(Direction::NONE);
				setGameStatus(GameStatus::INACTIVE);
			}
			else
			{
				_snake.move(nextCell);
				if ((*nextCell).getType() == CellType::FOOD)
				{
					this->_snake.grow();
					this->_board.generateFood();
				}
			}
		}


		// Accessor methods
		Snake getSnake() const { return this->_snake; }
		void setSnake(const Snake& snake) { this->_snake = snake; }
		Board getBoard() const { return this->_board; }
		void setBoard(const Board& board) { this->_board = board; }
		bool isGameOver() const { return this->_gameStatus == GameStatus::INACTIVE; }
		void setGameStatus(GameStatus gameStatus) { this->_gameStatus = gameStatus; }
		Direction getDirection() const { return this->_direction; }
		void setDirection(Direction direction) { this->_direction = direction; }
	};
}