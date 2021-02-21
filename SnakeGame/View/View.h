#pragma once
#include <windows.h>
#include <vector>
#include "Content.h"

namespace View
{
	class View
	{
	private:
		std::vector<Content*> contents;
	public:
		// Constructor
		View() {}

		void print() const
		{
			for (Content* content : contents)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), content->getCoordinates());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), content->getColor());
				printf("%s", content->getContent().c_str());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
		}

		void addContent(Content* content) { this->contents.push_back(content); }
	};
}

