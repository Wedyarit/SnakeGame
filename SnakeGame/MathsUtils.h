#pragma once

#include <cstdlib>
#include <ctime>

using namespace std;
class MathsUtils
{
public:
	static int randomInteger(int max, int min) {
		srand((unsigned)time(0));
		return (rand() % max) + min;
	}
};

