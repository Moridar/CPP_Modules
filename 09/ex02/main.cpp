#include "PmergeME.hpp"

//to test multiple number: ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

int main(int argc, char **argv)
{
	try
	{
		PmergeME::pmerge(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}