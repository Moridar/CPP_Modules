#include "iter.hpp"
#include <iostream>

template <typename T>
static void print(T &i)
{
	std::cout << i << std::endl;
}

template <typename T>
static void addone(T &i)
{
	i += 1;
}

int main()
{
	std::cout << "==1. Creates an array {1, 2, 3, 4, 5}==" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "==2. Iter and print every element==" << std::endl;
	iter(arr, len, print<const int>);
	std::cout << "==3. Iter and add one to every element==" << std::endl;
	iter(arr, len, addone<int>);
	std::cout << "==4. Iter and print every element==" << std::endl;
	iter(arr, len, print<const int>);

	std::cout << "==5. Creates a new array {a, b, c, d, e} and print every element==" << std::endl;
	char arr1[] = {'a', 'b', 'c', 'd', 'e'};
	len = sizeof(arr) / sizeof(arr[0]);
	iter(arr1, len, print<const char>);
	std::cout << "==6. Iter and add one to every element==" << std::endl;
	iter(arr1, len, addone<char>);
	std::cout << "==7. Iter and print every element==" << std::endl;
	iter(arr1, len, print<const char>);
}