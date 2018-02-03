#pragma once
#include <vector>
#include "utility.h"

/// Does sequential radix sort using a power of two as a base.
class Radix2Sorter
{
private:
	int exponent; // base is 2^exponent.
	int radix; // base/bucket count.
	int digits; // number of place values we need to care about.
	
	std::vector<int> countingSort(std::vector<int> data, int power);

	public:
		Radix2Sorter(int exponent)
		{
			this->exponent = exponent;
			radix = 1 << exponent;

			digits = (int)ceil(sizeof(int) * 8.0 / exponent);
			// maybe should be floor + 1 instead of ceil?
		}

		std::vector<int> sort(std::vector<int> data);

};