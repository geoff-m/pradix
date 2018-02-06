#pragma once
#include <random> // for sequential rng

int* getRandoms(int length, int minimum, int maximum);

// Gets 'length' random integers in range [minimum, maximum).
int* getRandomsFast(int length, int minimum, int maximum);

int* getSequence(int start, int stop, int step);

void CheckVslError(int num);