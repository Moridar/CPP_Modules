#include "PmergeME.hpp"

void PmergeME::pmerge(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	pmerge_vec();
	pmerge_list();
}

double PmergeME::pmerge_vec()
{
	std::cout << "==Vector tests==" << std::endl;
	return 1.0;
}

double PmergeME::pmerge_list()
{
	std::cout << "==List tests==" << std::endl;
	return 1.0;
}