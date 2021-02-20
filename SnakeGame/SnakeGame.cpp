#include "Cell.h"
#include "Snake.h"
#include "Game.h"
#include "Board.h"

int main()
{
	// Temp testing notes
	Cell* initPos = new Cell(0, 0);
	Snake snake = Snake(initPos);
	Board board = Board(10, 10);
	Game game = Game(snake, board);
	game.setGameStatus(GameStatus::ACTIVE);
	game.setDirection(Direction::RIGHT);
	game.update();
}
