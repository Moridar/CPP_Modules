#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc < 2)
	{
		std::cout << "This is unacceptable, the silence is deafening! Add an argument when you call me!" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}