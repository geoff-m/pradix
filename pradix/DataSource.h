#pragma once
#include <random>
#include <omp.h>

int* getRandoms(int length, int minimum, int maximum);

int* getRandomsParallel(int length, int minimum, int maximum);

int* getSequence(int start, int stop, int step);