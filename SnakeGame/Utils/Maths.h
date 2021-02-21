#pragma once

#include <cstdlib>
#include <ctime>

namespace Utils
{
	class Maths
	{
	public:
		static int randomInteger(int min, int max)
		{
			srand((unsigned)time(0));
			return (rand() % max) + min;
		}
	};
}