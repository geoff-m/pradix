#include "DataSource.h"
#include <assert.h>

int* getRandoms(int length, int minimum, int maximum)
{
	int* ret = new int[length];

	std::mt19937 gen;
	std::uniform_int_distribution<int> dist(minimum, maximum);
	std::generate(ret, ret + length, [&] () { return dist(gen); });
	return ret;
}



std::mt19937* gen;
std::uniform_int_distribution<int>* dist;
#pragma omp threadprivate(gen, dist)

int* getRandomsParallel(int length, int minimum, int maximum)
{
	int* ret = new int[length];

#pragma omp threadprivate(gen, dist)
	{
		//std::mt19937 gen;
		//std::uniform_int_distribution<int> dist(minimum, maximum);
		gen = new std::mt19937();
		dist = new std::uniform_int_distribution<int>(minimum, maximum);
#pragma omp for
		for (int i = 0; i < length; ++i)
		{
			ret[i] = (*dist)(gen);
		}
	}
	return ret;
}


// todo: add ability to get data from file.

int* getSequence(int start, int stop, int step)
{
	if (start < stop)
		_ASSERT(step > 0);
	else if (start > stop)
		_ASSERT(step < 0);

	int* ret = new int[(stop - start) / step];

	int index = 0;
	for (int i = start; i < stop; i += step)
	{
		ret[index++] = i;
	}

	return ret;
}