#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

void printArray(int* a, int len);

bool checkOrder(int* data, int length, bool ascending = true);

void printVector(std::vector<int> vec, bool octal = false);