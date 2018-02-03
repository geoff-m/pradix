#include "Radix2Sort.h"

int exponent = 3; // base is 2^exponent.
int radix = 1 << exponent; // 2 ^ 3 is our base (bucket count).
int digits = (int)ceil(sizeof(int) * 8.0 / exponent); // number of place values we need to care about.

std::vector<int> Radix2Sorter::sort(std::vector<int> data)
{
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

	for (int i = data.size() - 1; i >= 0; --i) // going 0..size here means we lose stability.
	{
		int item = data.at(i);
		int digit = (item / power) % radix;
		counts[digit]--;
		int thisCount = counts[digit];
		output[thisCount] = item;
	}

	return output;
}
