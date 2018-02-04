#include "Radix2Sort.h"

int* Radix2Sorter::sort(int* data, int length)
{
	return sort(data, length, max(data, length));
}

int* Radix2Sorter::sort(int* data, int length, int maximum)
{
	// number of place values we need to care about.
	int digits = (int)floor(log(maximum) / log(radix) + 1);

	int effectiveExponent = 0;
	for (int place = 0; place < digits; ++place, effectiveExponent += exponent)
	{
		data = countingSort(data, length, effectiveExponent);
	}
	return data;
}

int* Radix2Sorter::countingSort(int* data, int length, int effectiveExponent)
{
	int* counts = new int[radix];
	memset(counts, 0, radix * sizeof(int));

	// build histogram
	for (int i = 0; i < length; ++i)
	{
		int digit = (data[i]  >> effectiveExponent) & mask;
		counts[digit]++;
	}

	// do cumsums
	for (int i = 1; i < radix; ++i)
	{
		counts[i] += counts[i - 1];
	}

	int* output = new int[length];

	for (int i = length - 1; i >= 0; --i) // going 0->size here means we lose stability.
	{
		int item = data[i];
		int digit = (item >> effectiveExponent) & mask;
		counts[digit]--;
		int thisCount = counts[digit];
		output[thisCount] = item;
	}

	delete[] counts;
	return output;
}

int Radix2Sorter::max(int* data, int length)
{
	int ret = INT_MIN;
	for (int i = 0; i < length; ++i)
	{
		int item = data[i];
		if (ret < item)
			ret = item;
	}
	return ret;
}