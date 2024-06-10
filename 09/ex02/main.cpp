#include "PmergeME.hpp"

//to test multiple number: ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

int main(int argc, char **argv)
{
	PmergeME::pmerge(argc, argv);
}