#include "Radix2SorterParallel.h"

void Radix2SorterParallel::sort(int* data, int length)
{
	sort(data, length, max(data, length));
}

void Radix2SorterParallel::sort(int* data, int length, int maximum)
{
	int digits = (int)floor(log(maximum) / log(radix) + 1);
	printf("Maximum value has %d digits in base %d.\n", digits, radix);

	int* partlySorted;
	int effectiveExponent = 0;
	// Future iterations depend on past iterations of this loop.
	for (int place = 0; place < digits; ++place, effectiveExponent += exponent)
	{
		printf("Sorting place %d...\n", place);
		partlySorted = countingSort(data, length, effectiveExponent);
		delete[] data;
		data = partlySorted;	
	}
}

int* Radix2SorterParallel::countingSort(int* data, int length, int effectiveExponent)
{
	int* counts = new int[radix];
	memset(counts, 0, radix * sizeof(int));

	// build histogram
	for (int i = 0; i < length; ++i)
	{
		int digit = (data[i] >> effectiveExponent) & mask;
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

int Radix2SorterParallel::max(int* data, int length)
{
	int ret = INT_MIN;
	double start = omp_get_wtime();
	for (int i = 0; i < length; ++i)
	{
		int item = data[i];
		if (ret < item)
			ret = item;
	}
	double stop = omp_get_wtime();
	printf("Sequential max finished in %.4f seconds\n", stop - start);
	int pmax = parallelMax(data, length);

	return ret;
}

int Radix2SorterParallel::parallelMax(int* data, int length)
{
	int maxValue = data[0];
	double start = omp_get_wtime();
#pragma omp parallel for reduction(max : maxValue)
	for (int i = 0; i < length; ++i)
	{
		if (maxValue < data[i])
			maxValue = data[i];
	}
	double stop = omp_get_wtime();
	printf("Parallel max finished in %.4f seconds\n", stop - start);
	return maxValue;
}