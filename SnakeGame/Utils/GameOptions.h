#pragma once
#include "Game/Enumerations.h"

namespace Utils
{
	class GameOptions
	{
	private:
		// Board sizes
		int _boardRowCount;
		int _boardColCount;

		// Snake's init position
		int _snakeInitX;
		int _snakeInitY;
		Game::Direction _direction;

		// Game delay (in ms)
		int _gameDelay;

	public:
		// Constructor
		GameOptions()
		{
			this->_boardRowCount = 15;
			this->_boardColCount = 30;

			this->_snakeInitX = 7;
			this->_snakeInitY = 15;
			this->_direction = Game::Direction::RIGHT;

			this->_gameDelay = 100;
		}


		// Config file parser
		void parseOptions()
		{
			// TODO
		}


		// Accessor methods
		int getBoardRowCount() const { return this->_boardRowCount; }
		int getBoardColCount() const { return this->_boardColCount; }
		int getSnakeInitX() const { return this->_snakeInitX; }
		int getSnakeInitY() const { return this->_snakeInitY; }
		Game::Direction getDirection() const { return this->_direction; }
		int getGameDelay() const { return this->_gameDelay; }
	};
}
