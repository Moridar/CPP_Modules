#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "One argument please, i need something to work with, a char or a number please!" << std::endl, 1);
	if (argc > 2)
		return (std::cout << "Oh no no no, only one argument please" << std::endl, 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}