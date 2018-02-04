#pragma once
#include <vector>
#include "utility.h"

/// Does sequential radix sort using a power of two as the base.
class Radix2Sorter
{
	private:
	int exponent; // base is 2^exponent.
	int radix; // base/bucket count.
	int mask; // bit mask for modulus operation
	
	std::vector<int> countingSort(std::vector<int> data, int power);
	int* countingSort(int* data, int length, int power);

	static int max(int* data, int length);
	static int max(std::vector<int> data);

	public:
		Radix2Sorter(int exponent)
		{
			this->exponent = exponent;
			radix = 1 << exponent; // a power of 2.
			mask = radix - 1;

			//digits = (int)ceil(sizeof(int) * 8.0 / exponent);
		}

		std::vector<int> sort(std::vector<int> data, int maximum);
		std::vector<int> sort(std::vector<int> data);
		int* sort(int* data, int length, int maximum);
		int* sort(int* data, int length);

};