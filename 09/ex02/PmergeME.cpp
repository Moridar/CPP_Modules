#include "PmergeME.hpp"

PmergeME::PmergeME() {}
PmergeME::~PmergeME() {}

void PmergeME::pmerge(int argc, char **argv)
{
	PmergeME me;

	try
	{
		me.fill_containers(argc, argv);
		me.print("Before: ", me._vec);
		auto vecstart = std::chrono::high_resolution_clock::now();
		me._vec = me.pmerge_vec();
		auto vecend = std::chrono::high_resolution_clock::now();
		auto lstart = std::chrono::high_resolution_clock::now();
		me._list = me.pmerge_list();
		auto lend = std::chrono::high_resolution_clock::now();
		me.print("After vector: ", me._vec);
		me.print("After list  : ", me._list);
		double vdur = std::chrono::duration_cast<std::chrono::nanoseconds>(vecend - vecstart).count();
		double ldur = std::chrono::duration_cast<std::chrono::nanoseconds>(lend - lstart).count();
		std::cout << "Time to process a range of " << me._vec.size() << " elements with std::vector : " << vdur/1000 << " us" << std::endl;
		std::cout << "Time to process a range of " << me._list.size() << " elements with std::list   : " << ldur/1000 << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void PmergeME::print(std::string str, std::vector<unsigned int> vec)
{
	std::cout << str;
	for (unsigned int i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}

void PmergeME::print(std::string str, std::list<unsigned int> list)
{
	std::cout << str;
	for (unsigned int i : list)
		std::cout << i << " ";
	std::cout << std::endl;
}
void PmergeME::fill_containers(int argc, char **argv)
{
	unsigned int n;

	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> n))
			throw std::invalid_argument("bad argument");	
		_vec.push_back(n);
		_list.push_back(n);
	}
}


static int get_jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (get_jacobsthal(n - 1) + 2 * get_jacobsthal(n - 2));
}

static int is_jacobsthal(int n)
{
	int i = 0;
	while (get_jacobsthal(i) < n)
		i++;
	return (get_jacobsthal(i) == n);
}

static int get_next_jacobsthal(int n, int &jacob_seq, size_t size)
{
	if (!is_jacobsthal(n))
		return (n - 1);
	if (n + 1 == (int) size)
		return (n + 1);
	if (get_jacobsthal(jacob_seq) >= (int) size)
		return (size);
	return (std::min(get_jacobsthal(++jacob_seq) - 1, (int) size - 1));
}


std::vector<unsigned int> PmergeME::pmerge_vec()
{
	std::vector<std::pair<unsigned int, unsigned int>> pair_vec;
	if (_vec.size() <= 1)
		return (_vec);
	
	//1. Creates Pair
	while (_vec.size() > 1)
	{
		pair_vec.push_back(std::make_pair(_vec[0], _vec[1]));
		_vec.erase(_vec.begin(), _vec.begin() + 2);
	}
	
	//2. Determines larger in pair, sets it to first. 
	for (auto &p : pair_vec)
		if (p.second > p.first)
			std::swap(p.first, p.second);
	
	//3. Sorts pair_vec
	std::sort(pair_vec.begin(), pair_vec.end());
	
	//3.1 Creates a sorted sequence S of the larger numbers of each pair.
	std::vector<unsigned int> vec;
	for (auto &p : pair_vec)
		vec.push_back(p.first);
	
	//4. Insert at the start of S, the elemented paired with smallest element in S.
	vec.insert(vec.begin(), pair_vec.begin()->second);
	
	//5. Insert the remaining, following Jacobsthal sequence.
	if (pair_vec.size() != 1)
	{
		int jacob_seq = 3;
		int inserted = 1;
		for (size_t i = std::min((int) pair_vec.size() - 1, 2); i < pair_vec.size(); i = get_next_jacobsthal(i, jacob_seq, pair_vec.size()))
		{
			for (size_t j = 0; j <= i + inserted; j++)
			{
				if (pair_vec[i].second < vec[j])
				{
					vec.insert(vec.begin() + j, pair_vec[i].second);
					inserted++;
					break ;
				}
			}
		}
	}
	//6. If the orignal vector is odd, insert the last element.
	if (!_vec.empty())
	{
		if (_vec[0] > vec.back())
			vec.push_back(_vec[0]);
		else
			for (size_t j = 0; j <= vec.size(); j++)
				if (_vec[0] < vec[j])
				{
					vec.insert(vec.begin() + j, _vec[0]);
					break ;
				}
	}
	return (vec);
}

std::list<unsigned int>  PmergeME::pmerge_list()
{
	std::list<std::pair<unsigned int, unsigned int>> pair_list;
	if (_list.size() <= 1)
		return (_list);
	
	//1. Creates Pair
	auto it = _list.begin();
	auto it1 = std::next(_list.begin(), 1);
	auto ite = _list.end();
	while (it != ite && it1 != ite)
	{
		pair_list.push_back(std::make_pair(*it, *it1));
		std::advance(it, 2);
		std::advance(it1, 2);
	}
	
	//2. Determines larger in pair, sets it to first. 
	for (auto &p : pair_list)
		if (p.second > p.first)
			std::swap(p.first, p.second);
	
	//3. Sorts pair_list
	pair_list.sort();
	
	// 3.1 Creates a sorted sequence S of the larger numbers of each pair.
	std::list<unsigned int> list;
	for (auto &p : pair_list)
		list.push_back(p.first);
	
	// 4. Insert at the start of S, the elemented paired with smallest element in S.
	list.insert(list.begin(), pair_list.begin()->second);
	
	// 5. Insert the remaining, following Jacobsthal sequence.
	if (pair_list.size() > 1)
	{
		int jacob_seq = 3;
		int inserted = 1;
		for (size_t i = std::min((int) pair_list.size() - 1, 2); i < pair_list.size(); i = get_next_jacobsthal(i, jacob_seq, pair_list.size()))
		{
			ite = std::next(list.begin(), i + inserted);
			int insert_num = std::next(pair_list.begin(), i)->second;
			it = list_binary_search(list.begin(), ite, insert_num);
			list.insert(it, insert_num);
			inserted++;
		}
	}
	//6. If the orignal list is odd, insert the last element.
	if (_list.size() % 2 == 1)
		list.insert(list_binary_search(list.begin(), list.end(), _list.back()), _list.back());
	return (list);
}

std::list<unsigned int>::iterator PmergeME::list_binary_search(std::list<unsigned int>::iterator l, std::list<unsigned int>::iterator r, unsigned int n)
{
	while (1)
	{
		std::list<unsigned int>::iterator m = std::next(l, std::distance(l, r) / 2);
		if (*m == n)
			return (m);
		if (n > *m)
			l = std::next(m);
		else
			r = std::prev(m);
		if (std::distance(l, r) < 2)
			return n < *l ? l : r;
	}
}
