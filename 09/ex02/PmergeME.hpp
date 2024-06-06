#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <array>
#include <list>

class PmergeME
{
	private:
		static double pmerge_list();
		static double pmerge_vec();

		PmergeME();
		~PmergeME();
		PmergeME(const PmergeME &other);
		PmergeME &operator=(const PmergeME &other);
	public:
		static void pmerge(int argc, char **argv);
};
#endif