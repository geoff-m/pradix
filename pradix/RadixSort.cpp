#include "RadixSort.h"
#include "utility.h"

// reference implementation of radix sort using arbitrary radix.
// not part of build.
std::vector<int> countingSort(std::vector<int> data, int power)
{
	int* counts = new int[PLACES];
	memset(counts, 0, PLACES * sizeof(int));

	// build histogram
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		printArray(counts, PLACES);
		int digit = (*it / power) % RADIX;
		counts[digit]++;
	}

	// do cumsums
	for (int i = 1; i < PLACES; ++i)
	{
		counts[i] += counts[i - 1];
	}

	std::vector<int> output(data.size());

	for (int i = data.size() - 1; i >= 0; --i) // going 0..size here means we lose stability.
	{
		int item = data.at(i);
		int digit = (item / power) % RADIX;
		counts[digit]--;
		output[counts[digit]] = item;
	}

	return output;
}

int* countingSort(int* data, int length, int power)
{
	int* counts = new int[PLACES];
	memset(counts, 0, PLACES * sizeof(int));

	// build histogram
	for (int i = 0; i < length; ++i)
	{
		int item = data[i];
		int digit = (item / power) % RADIX;
		counts[digit]++;
	}

	// do cumsums
	for (int i = 1; i < PLACES; ++i)
	{
		counts[i] += counts[i - 1];
	}

	//std::vector<int> output(data.size());
	int* output = new int[length];

	for (int i = length - 1; i >= 0; --i) // going 0..size here means we lose stability.
	{
		int item = data[i];
		int digit = (item / power) % RADIX;
		counts[digit]--;
		output[counts[digit]] = item;
	}

	delete[] counts;
	return output;
}
