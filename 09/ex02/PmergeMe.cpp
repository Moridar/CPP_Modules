#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::pmerge(int argc, char **argv)
{
	PmergeMe me;

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


void PmergeMe::fill_containers(int argc, char **argv)
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

//4. Insert at the start of S, the elemented paired with smallest element in S.
//5. Insert the remaining, following Jacobsthal sequence.
t_intvec PmergeMe::pmerge_vec()
{
	t_pairvec pair_vec;
	if (_vec.size() <= 1)
		return (_vec);
	
	//1. Creates Pair
	while (_vec.size() > 1)
	{
		pair_vec.push_back(std::make_pair(_vec[0], _vec[1]));
		_vec.erase(_vec.begin(), _vec.begin() + 2);
	}
	
	//2. Determines larger in pair, sets it to first. 
	for (t_pair &p : pair_vec)
		if (p.second > p.first)
			std::swap(p.first, p.second);
	
	//3. Sorts pair_vec
	std::sort(pair_vec.begin(), pair_vec.end());
	
	//3.1 Creates a sorted sequence S of the larger numbers of each pair.
	t_intvec vec;
	for (auto &p : pair_vec)
		vec.push_back(p.first);
	
	insertion(pair_vec, vec);
	//6. If the orignal vector is odd, insert the last element.
	if (_vec.size() % 2 == 1)
	{
		t_veciterator it = vec_binary_search(vec, 0, vec.size() - 1, _vec.back());
		vec.insert(it, _vec.back());
	}
	return (vec);
}

void PmergeMe::insertion(t_pairvec &pair_vec, t_intvec &vec)
{
	vec.insert(vec.begin(), pair_vec.begin()->second);
	
	if (pair_vec.size() != 1)
	{
		int jacob_seq = 3;
		int inserted = 1;
		for (size_t i = std::min((int) pair_vec.size() - 1, 2); i < pair_vec.size(); i = get_next_jacobsthal(i, jacob_seq, pair_vec.size()))
		{
			t_veciterator it = vec_binary_search(vec, 0, i + inserted, pair_vec[i].second);
			vec.insert(it, pair_vec[i].second);
			inserted++;
		}
	}
}
t_veciterator PmergeMe::vec_binary_search(t_intvec &vec, int l, int r, unsigned int n)
{
	while (1)
	{
		int size = r - l + 1;
		if (l >= r)
			return n < vec[l] ? vec.begin() + l : vec.begin() + l + 1;
		int m = l + size / 2;
		if (vec[m] == n)
			return vec.begin() + m;
		if (n > vec[m])
			l = m + 1;
		else
			r = m - 1;
	}
}
	
	// 1. MergeSort: Splits the input list until there is two elements
	// 1.1 Creates Pair, sets the larger number to first.
	///1.2 Reclusive sort
	// 2. Copies larger elements from pair list into sorted list
	// 3. Insertion
	// 3.1 Insert at the start of S, the elemented paired with smallest element in S.
	// 3.2 Insert the remaining, following Jacobsthal sequence.
	// 4. If the orignal list is odd, insert the last element.
std::list<unsigned int>  PmergeMe::pmerge_list()
{
	std::list<unsigned int> sorted_list;

	if (_list.size() <= 1)
		return (_list);
	
	t_pairlist pair_list = mergeSort(_list.begin(), std::prev(_list.end()));
	for (t_pair &p : pair_list)
		sorted_list.push_back(p.first);
	insertion(sorted_list, pair_list);
	if (_list.size() % 2 == 1)
	{
		unsigned int insert_num = _list.back();
		sorted_list.insert(list_binary_search(sorted_list.begin(), sorted_list.end(), insert_num), insert_num);
	}
	return (sorted_list);
}



t_pairlist PmergeMe::merge(t_pairlist &left, t_pairlist &right)
{
	t_pairlist::iterator l_it = left.begin();
	t_pairlist::iterator r_it = right.begin();

	while (r_it != right.end() && l_it != left.end())
	{
		if (*r_it < *l_it)
		{
			l_it = left.insert(l_it, *r_it);
			r_it++;
		}
		l_it++;
	}
	while (r_it != right.end())
	{
		left.push_back(*r_it);
		r_it++;
	}
	return left;
}

t_pairlist PmergeMe::mergeSort(t_listiterator l, t_listiterator r)
{
	int size = std::distance(l, r) + 1;
	if (size <= 3)
	{
		t_pairlist pair_list;
		int first = *l;
		int second = *std::next(l, 1);
		t_pair pair = (first > second) ? std::make_pair(first, second) : std::make_pair(second, first);
		pair_list.push_back(pair);
		return pair_list;
	}
	int leftsize = size / 2;
	if (leftsize % 2 == 1)
		leftsize++;
	t_listiterator m = std::next(l, leftsize - 1);

	t_pairlist left = mergeSort(l, m);
	t_pairlist right = mergeSort(std::next(m), r);
	return merge(left, right);
}

void PmergeMe::insertion(t_intlist &list, t_pairlist &pair_list)
{
	list.push_front(pair_list.front().second);

	if (pair_list.size() > 1)
	{
		int jacob_seq = 3;
		int inserted = 1;
		for (size_t i = std::min((int) pair_list.size() - 1, 2); i < pair_list.size(); i = get_next_jacobsthal(i, jacob_seq, pair_list.size()))
		{
			t_listiterator r = std::next(list.begin(), i + inserted);
			int insert_num = std::next(pair_list.begin(), i)->second;
			t_listiterator it = list_binary_search(list.begin(), r, insert_num);
			list.insert(it, insert_num);
			inserted++;
		}
	}
}

t_listiterator PmergeMe::list_binary_search(t_listiterator l, t_listiterator r, unsigned int n)
{
	while (1)
	{
		int distance = std::distance(l, r);
		if (distance < 2)
			return n < *l ? l : next(l);
		std::list<unsigned int>::iterator m = std::next(l, distance / 2);
		if (*m == n)
			return (m);
		if (n > *m)
			l = std::next(m);
		else
			r = std::prev(m);
	}
}
