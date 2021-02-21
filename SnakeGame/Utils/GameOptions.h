#pragma once
#include "Game/Enumerations.h"

namespace Utils
{
	class GameOptions
	{
	private:
		// Board sizes
		int boardRowCount;
		int boardColCount;

		// Snake's init position
		int snakeInitX;
		int snakeInitY;
		Game::Direction direction;

		// Game delay (in ms)
		int gameDelay;

	public:
		GameOptions()
		{
			this->boardRowCount = 15;
			this->boardColCount = 30;

			this->snakeInitX = 7;
			this->snakeInitY = 15;
			this->direction = Game::Direction::RIGHT;

			this->gameDelay = 100;
		}

		void parseOptions()
		{
			// TODO
		}

		// Accessor methods
		int getBoardRowCount() const { return this->boardRowCount; }
		int getBoardColCount() const { return this->boardColCount; }
		int getSnakeInitX() const { return this->snakeInitX; }
		int getSnakeInitY() const { return this->snakeInitY; }
		Game::Direction getDirection() const { return this->direction; }
		int getGameDelay() const { return this->gameDelay; }
	};
}
