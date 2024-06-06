#include "PmergeME.hpp"

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