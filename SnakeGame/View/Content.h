#pragma once
#include <string>
#include <Windows.h>

namespace View
{
	class Content
	{
	private:
		COORD _coordinates;
		std::string _content;
		WORD _color;
	public:
		// Constructors
		Content(int x, int y, std::string content, WORD color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
		{
			this->_coordinates.X = x;
			this->_coordinates.Y = y;
			this->_content = content;
			this->_color = color;
		}
		Content()
		{
			this->_color = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
			this->_content = "";
		}

		// Accessor methods
		COORD getCoordinates() const { return this->_coordinates; }
		std::string getContent() const { return this->_content; }
		WORD getColor() const { return this->_color; }
	};
}

