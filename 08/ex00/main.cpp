#include "EasyFind.hpp"
#include <algorithm>
#include <iostream>
#include <array>

int main()
{
	std::cout << "==Array tests==" << std::endl;
	std::cout << "==1. Initailise array (1,2,3,4,5)==" << std::endl;
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	
	std::cout << std::endl <<  "==2. Using std::find, Find value 3==" << std::endl;
	int value = 3;
	std::cout << std::find(arr.begin(), arr.end(), value) << std::endl;
	
	std::cout << std::endl <<  "==3. Using std::find, Find value 6==" << std::endl;
	value = 6;
	try
	{
		std::cout << std::find(arr.begin(), arr.end(), value) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error" <<  e.what() << '\n';
	}

	std::cout << std::endl <<  "==4. Using easyfind, Find value 3==" << std::endl;
	std::cout << easyfind(arr, 3) << std::endl;

	std::cout << std::endl <<  "==5. Using easyfind, Find value 6==" << std::endl;
	try
	{
		std::cout << easyfind(arr, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl <<  "==6. Using std::find, Find value a==" << std::endl;
	try
	{
		std::cout << std::find(arr.begin(), arr.end(), 'a') << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error" <<  e.what() << '\n';
	}
	std::cout << std::endl <<  "==7. Using easyfind, Find value a==" << std::endl;
	try
	{
		std::cout << easyfind(arr, 'a') << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
