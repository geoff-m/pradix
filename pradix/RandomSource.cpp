#include "RandomSource.h"

int* getRandoms(int length, int minimum, int maximum)
{
	int* ret = new int[length];

	std::mt19937 gen;
	std::uniform_int_distribution<int> dist(minimum, maximum);
	std::generate(ret, ret + length, [&] () { return dist(gen); });
	return ret;
}