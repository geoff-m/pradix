#include <stdio.h>
#include <omp.h>
#include "RadixSort.h"
#include "RandomSource.h"
#include "Radix2Sort.h"

int main(int argc, char** argv)
{
	int maxThreads = omp_get_max_threads();
	printf("OMP max threads: %d\n", maxThreads);

	// let's first implement it sequentially to show i know what i'm doing
	const int COUNT = 10000;
	printf("generating %d numbers...", COUNT);
	int* data = getRandoms(COUNT, 0, INT_MAX);
	printf("done\n");
	//printArray(data, COUNT);
	printf("sorting...\n");

	Radix2Sorter sorter(3);
	data = sorter.sort(data, COUNT);

	printf("sort done\n");
	//printArray(data, COUNT);
	printf("check order: %s\n", checkOrder(data, COUNT) ? "passed" : "failed");
	printf("\n\nPress enter to quit...");
	delete[] data;
	getchar();
	
	return 0;
}