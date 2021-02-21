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
		std::vector<Content*> _contents;
		HANDLE _outputHandle;

		// Returns index of content if it is already in vector.
		int containmentIndex(Content* content)
		{
			for (int i = 0; (size_t)i < this->_contents.size(); i++)
			{
				Content* vContent = this->_contents[i];
				if (vContent->getCoordinates().Y == content->getCoordinates().Y && vContent->getCoordinates().X == content->getCoordinates().X)
					return i;
			}
			return -1;
		}
	public:
		// Constructor
		View()
		{
			this->_outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO cursorInfo;
			GetConsoleCursorInfo(_outputHandle, &cursorInfo);
			cursorInfo.bVisible = false;
			SetConsoleCursorInfo(_outputHandle, &cursorInfo);
		}


		// Main method printing contents in console.
		void print() const
		{
			system("CLS");
			for (Content* content : _contents)
			{
				SetConsoleCursorPosition(this->_outputHandle, content->getCoordinates());
				SetConsoleTextAttribute(this->_outputHandle, content->getColor());
				printf("%s", content->getContent().c_str());
			}

			SetConsoleTextAttribute(this->_outputHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		}

		// Adds content to vector.
		void addContent(Content* content)
		{
			int containmentContentIndex = containmentIndex(content);
			if (containmentContentIndex != -1)
				return;
			this->_contents.push_back(content);
		}

		// Key listener
		static void control(char& key)
		{
			while (true)
				key = _getch();
		}


		// Accesoor methods
		Content* getContent(int index) { return this->_contents[index]; }
		int getSize() const { return this->_contents.size(); }
	};
}

