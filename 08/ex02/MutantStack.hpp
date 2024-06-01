#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &assign)
		{
			std::stack<T>::operator=(assign);
			return *this;
		}
		
		template <typename InputIterator>
		MutantStack(InputIterator begin, InputIterator end) : std::stack<T>() 
		{
			while (&*begin < &*end)
			{
				this->push(*begin);
				begin++;
			}
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin()
		{
			return std::stack<T>::c.begin();
		}
		
		iterator end() 
		{
			return std::stack<T>::c.end();
		}
};

#endif