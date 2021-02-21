#pragma once
#include <windows.h>
#include <vector>
#include "Content.h"
#include <stdio.h>
#include <conio.h>

namespace View
{
	class View
	{
	private:
		std::vector<Content*> contents;
		HANDLE outputHandle;

		int containmentIndex(Content* content)
		{
			for (int i = 0; (size_t)i < this->contents.size(); i++)
			{
				Content* vContent = this->contents[i];
				if (vContent->getCoordinates().Y == content->getCoordinates().Y && vContent->getCoordinates().X == content->getCoordinates().X)
					return i;
			}
			return -1;
		}
	public:
		// Constructor
		View()
		{
			this->outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO cursorInfo;
			GetConsoleCursorInfo(outputHandle, &cursorInfo);
			cursorInfo.bVisible = false;
			SetConsoleCursorInfo(outputHandle, &cursorInfo);
		}


		void print() const
		{
			system("CLS");
			for (Content* content : contents)
			{
				SetConsoleCursorPosition(this->outputHandle, content->getCoordinates());
				SetConsoleTextAttribute(this->outputHandle, content->getColor());
				printf("%s", content->getContent().c_str());
			}

			SetConsoleTextAttribute(this->outputHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		}
		void addContent(Content* content)
		{
			int containmentContentIndex = containmentIndex(content);
			if (containmentContentIndex != -1)
				return;
			this->contents.push_back(content);
		}

		// Key listener
		static void control(char& key)
		{
			while (true)
				key = _getch();
		}

		// Accesoor methods
		Content* getContent(int index) { return this->contents[index]; }
		int getSize() const { return this->contents.size(); }
	};
}

