#include "iter.hpp"
#include <iostream>

void print(int &i)
{
	std::cout << i << std::endl;
}

void addone(int &i)
{
	i += 1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(arr[0]);

	iter(arr, len, print);
	iter(arr, len, addone);
	std::cout << "==After adding one to each element==" << std::endl;
	iter(arr, len, print);

	return 0;
}