#include "Radix2Sort.h"

std::vector<int> Radix2Sorter::sort(std::vector<int> data)
{
	return sort(data, max(data));
}

std::vector<int> Radix2Sorter::sort(std::vector<int> data, int maximum)
{
	int digits = (int)(log(maximum) / log(radix)) + 1;
	for (int place = 0; place < digits; ++place)
	{
		//printf("so far: ");
		//printVector(data);
		data = countingSort(data, (1 << exponent * place));
	}
	return data;
}


// todo: once this works, change it to int* instead of vector<int>.
std::vector<int> Radix2Sorter::countingSort(std::vector<int> data, int power)
{
	int* counts = new int[radix];
	memset(counts, 0, radix * sizeof(int));

	//printf("octal: ");
	//printVector(data, true);

	// build histogram
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		int digit = (*it / power) % radix;
		printf("%d's digit of %d is %d\n", power, *it, digit);
		counts[digit]++;
	}
	
	printf("buckets: ");
	printArray(counts, radix);

	// do cumsums
	for (int i = 1; i < radix; ++i)
	{
		counts[i] += counts[i - 1];
	}

	std::vector<int> output(data.size());

	for (int i = data.size() - 1; i >= 0; --i) // going 0->size here means we lose stability.
	{
		int item = data.at(i);
		int digit = (item / power) % radix;
		counts[digit]--;
		int thisCount = counts[digit];
		output[thisCount] = item;
	}

	delete[] counts;
	return output;
}

int Radix2Sorter::max(std::vector<int> data)
{
	int ret = INT_MIN;
	for (auto it = data.begin(); it != data.end(); ++it)
		if (ret < *it)
			ret = *it;
	return ret;
}