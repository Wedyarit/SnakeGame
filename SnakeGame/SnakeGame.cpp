#include "Cell.h"
#include "Snake.h"
#include "Game.h"
#include "Board.h"
#include "View.h"

int main()
{
	View::View view = View::View();
	view.addContent(new View::Content(10, 10, "TestMessage", BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
	view.print();
}
