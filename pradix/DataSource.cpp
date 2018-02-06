#include "DataSource.h"
#include <assert.h>
#include "mkl_vsl.h"
#include "mkl.h"
#define BRNG    VSL_BRNG_MT19937
#define METHOD  VSL_RNG_METHOD_UNIFORM_STD

int* getRandoms(int length, int minimum, int maximum)
{
	
	int* ret = new int[length];

	std::mt19937 gen;
	std::uniform_int_distribution<int> dist(minimum, maximum);
	std::generate(ret, ret + length, [&] () { return dist(gen); });
	return ret;
}

int* getRandomsFast(int length, int minimum, int maximum)
{
	int* ret = new int[length];
	
	// Create random stream
	int error;
	VSLStreamStatePtr stream;
	error = vslNewStream(&stream, BRNG, 12345);
	CheckVslError(error);

	// Create distribution generator
	error = viRngUniform(METHOD, stream, length, ret, minimum, maximum);
	CheckVslError(error);

	// Destroy the stream
	error = vslDeleteStream(&stream);
	CheckVslError(error);

	// Prevent memory leak.
	MKL_Free_Buffers();

	return ret;
}

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