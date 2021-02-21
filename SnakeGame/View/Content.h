#pragma once
#include <string>
#include <Windows.h>

namespace View
{
	class Content
	{
	private:
		COORD coordinates;
		std::string content;
		WORD color;
	public:
		// Constructors
		Content(int x, int y, std::string content, WORD color)
		{
			this->coordinates.X = x;
			this->coordinates.Y = y;
			this->content = content;
			this->color = color;
		}
		Content()
		{
			this->color = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
			this->content = "";
		}

		COORD getCoordinates() const { return this->coordinates; }
		std::string getContent() const { return this->content; }
		WORD getColor() const { return this->color; }
	};
}

