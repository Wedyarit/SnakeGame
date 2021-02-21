#pragma once
#include <string>

class ViewContent
{
private:
	int x;
	int y;
	std::string content;

public:
	ViewContent(int x, int y, std::string content)
	{
		this->x = x;
		this->y = y;
		this->content = content;
	}
};

