#pragma once
#include <omp.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>

class Radix2SorterParallel
{
private:
	int exponent; // base is 2^exponent.
	int radix; // base/bucket count.
	int mask; // bit mask for modulus operation

	int* countingSort(int* data, int length, int power);

	static int max(int* data, int length);

	static int parallelMax(int* data, int length);

public:
	Radix2SorterParallel(int exponent)
	{
		this->exponent = exponent;
		radix = 1 << exponent; // a power of 2.
		mask = radix - 1;
	}

	void sort(int** data, int length, int maximum);
	void sort(int** data, int length);

};

