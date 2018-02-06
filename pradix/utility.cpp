#include "utility.h"

void printArray(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
		printf("%d, ", a[i]);
	printf("%d\n", a[len - 1]);
}

bool checkOrder(int* data, int length, bool ascending)
{
	if (ascending)
	{
		for (int i = 1; i < length; ++i)
		{
			if (data[i] < data[i - 1])
				return false;
		}
		return true;
	} else {
		for (int i = 1; i < length; ++i)
		{
			if (data[i] > data[i - 1])
				return false;
		}
		return true;
	}
}


void printVector(std::vector<int> vec, bool octal)
{
	if (octal)
	{
		for (int i = 0; i < vec.size() - 1; ++i)
			std::cout << std::oct << vec.at(i) << ", ";
		std::cout << std::oct << vec.back() << '\n';
	}
	else {
		for (int i = 0; i < vec.size() - 1; ++i)
			printf("%d, ", vec.at(i));
		printf("%d\n", vec.back());
	}
}