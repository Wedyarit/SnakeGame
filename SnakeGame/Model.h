#pragma once
#include "Game/Cell.h"
#include "Game/Snake.h"
#include "Game/Game.h"
#include "Game/Board.h"
#include "View/View.h"
#include "Utils/GameOptions.h"
#include <conio.h>
#include <chrono>
#include <thread>

class Model
{
public:
	Game::Game static setupOptions(Utils::GameOptions gameOptions)
	{
		Game::Game game = Game::Game(Game::Snake(new Game::Cell(gameOptions.getSnakeInitX(), gameOptions.getSnakeInitY())), Game::Board(gameOptions.getBoardRowCount(), gameOptions.getBoardColCount()));
		game.setGameStatus(Game::GameStatus::ACTIVE);
		game.setDirection(gameOptions.getDirection());
		game.getBoard().generateFood();

		return game;
	}

	void static gameCycle(char& key)
	{
		Game::Game game = setupOptions(Utils::GameOptions());

		while (!game.isGameOver())
		{
			View::View view = View::View();

			game.updateDirection(key);
			game.update();

			for (Game::Cell* cell : game.getSnake().getSnakeCells())
				view.addContent(new View::Content(cell->getCol(), cell->getRow(), "*", BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));

			for (int i = 0; i < game.getBoard().getRowCount(); i++)

				for (int j = 0; j < game.getBoard().getColCount(); j++)
				{
					Game::Cell* cell = game.getBoard().getCells()[i][j];
					if (cell->getType() == Game::CellType::EMPTY)
						view.addContent(new View::Content(cell->getCol(), cell->getRow(), " ", BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
					else
						view.addContent(new View::Content(cell->getCol(), cell->getRow(), "@", BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
				}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			view.print();
		}

		exit(0);
	}
};

