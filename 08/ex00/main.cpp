#include "EasyFind.hpp"
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
	std::cout << std::endl <<  "==8. Using easyfind, replace 5 with 6==" << std::endl;
	try
	{
		int *it = easyfind(arr, 5);
		std::cout << "Address of value 5: " << it << std::endl;
		*it = 6;
		std::cout << "Address of value 6: " << easyfind(arr, 6) << std::endl;
		std::cout << "Address of value 5: " << easyfind(arr, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl <<  "==9. Test with vector==" << std::endl;
	std::vector<int> vec = {1, 2, 3, 4, 100};

	vec.push_back(1337);
	try
	{
		std::cout << easyfind(vec, 1337) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
