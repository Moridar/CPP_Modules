#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		return (std::cout << "Please only 1 argument" << std::endl, 1);
	RPN(argv[1]);
}