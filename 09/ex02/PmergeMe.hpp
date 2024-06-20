#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <exception>

using t_pair = std::pair<unsigned int, unsigned int>;

using t_pairlist = std::list<t_pair>;
using t_intlist = std::list<unsigned int>;
using t_listiterator = t_intlist::iterator;

using t_pairvec = std::vector<t_pair>;
using t_intvec = std::vector<unsigned int>;
using t_veciterator = t_intvec::iterator;

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vec;
		std::list<unsigned int>		_list;
		
		void fill_containers(int argc, char **argv);
		void		pmerge_vec();
		void 		pmerge_list();
		t_pairvec 	mergeSort(int, int);
		t_pairlist	mergeSort(t_listiterator, t_listiterator);
		t_pairvec	merge(t_pairvec, t_pairvec);
		t_pairlist	merge(t_pairlist &, t_pairlist &);
		void		insertion(t_pairvec &);
		void		insertion(t_pairlist &);
		t_veciterator	vec_binary_search(int l, int r, unsigned int n);
		t_listiterator	list_binary_search(t_listiterator l, t_listiterator r, unsigned int n);
		
		template <typename T>
		void print(std::string str, T list)
		{
			std::cout << str;
			for (unsigned int i : list)
				std::cout << i << " ";
			std::cout << std::endl;
		};

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
	public:
		static void pmerge(int argc, char **argv);
};

#endif