#include <stdio.h>
#include <omp.h>
#include "RadixSort.h"


const int RADIX = 10;
int PLACES = (int)ceil(log(INT_MAX) / log(RADIX));

int main(int argc, char** argv)
{
	int maxThreads = omp_get_max_threads();
	printf("OMP max threads: %d\n", maxThreads);

	// let's first implement it sequentially to show i know what i'm doing
	
	// sort by LSD.
	int nums[] = { 523, 855, 631, 739, 684, 687 };
	std::vector<int> data(nums, nums + sizeof(nums) / sizeof(int));

	countingSort(&data, 10);
	

	printf("\n\nPress enter to quit...");
	getchar();
	return 0;
}

void countingSort(std::vector<int>* data, int power)
{
	int* counts = new int[PLACES];
	memset(counts, 0, PLACES * sizeof(int));

	// build histogram
	for (auto it = data->begin(); it != data->end(); ++it)
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

	std::vector<int> output;
	output.reserve(data->size());

	for (int i = 0; i < data->size(); ++i)
	{
		
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
		printf("%d, ", a[i]);
	printf("%d\n", a[len - 1]);
}