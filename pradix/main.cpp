#include <stdio.h>
#include <omp.h>
#include "DataSource.h"
#include "RadixSort.h"
#include "Radix2Sort.h"
#include "Radix2SorterParallel.h"

int main(int argc, char** argv)
{
	int maxThreads = omp_get_max_threads();
	printf("OMP max threads: %d\n\n", maxThreads);

	// let's first implement it sequentially to show i know what i'm doing
	const int COUNT = 100;
	printf("generating %d numbers...", COUNT);

	int* data = getRandomsParallel(COUNT, 0, INT_MAX);
	//int* data = getSequence(COUNT, 0, -1);

	printf("done\n");
	//printArray(data, COUNT);
	printf("sorting...\n");

	Radix2SorterParallel sorter(3);
	sorter.sort(data, COUNT);

	printf("sort done\n");
	//printArray(data, COUNT);
	printf("check order: %s\n", checkOrder(data, COUNT) ? "passed" : "failed");
	printf("\n\nPress enter to quit...");
	delete[] data;
	getchar();
	
	return 0;
}