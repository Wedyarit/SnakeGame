#pragma once

#include <cstdlib>
#include <ctime>

namespace Utils
{
	class Maths
	{
	public:
		static int randomInteger(int max, int min)
		{
			srand((unsigned)time(0));
			return (rand() % max) + min;
		}
	};
}