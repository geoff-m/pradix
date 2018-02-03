#pragma once
#include <limits>
#include <vector>

int* radixSort(int* data, int length, int max);

int* radixSort(int* data, int length);

std::vector<int> countingSort(std::vector<int> data, int power);

int* countingSort(int* data, int length, int power);
