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

	const int COUNT = 100;
	printf("generating numbers...");
	int* data = getRandoms(COUNT, 0, 100);
	printf("done\n");
	//int data[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//printArray(data, COUNT);
	printf("sorting...\n");

	std::vector<int> vec(data, data + COUNT);
	Radix2Sorter sorter(3);
	vec = sorter.sort(vec);

	printf("sort done\n");
	//printArray(data, COUNT);
	//printVector(vec);
	printf("check order: %s\n", checkOrder(vec.data(), COUNT) ? "passed" : "failed");
	printf("\n\nPress enter to quit...");
	getchar();
	return 0;
}