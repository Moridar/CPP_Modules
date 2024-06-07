#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <chrono>

class PmergeME
{
	private:
		std::vector<unsigned int> _vec;
		std::list<unsigned int> _list;
		std::list<unsigned int> pmerge_list();
		std::vector<unsigned int> pmerge_vec();
		void fill_containers(int argc, char **argv);
		void print(std::string str, std::vector<unsigned int> vec);
		void print(std::string str, std::list<unsigned int> list);

		PmergeME();
		~PmergeME();
		PmergeME(const PmergeME &other);
		PmergeME &operator=(const PmergeME &other);
	public:
		static void pmerge(int argc, char **argv);
};
#endif