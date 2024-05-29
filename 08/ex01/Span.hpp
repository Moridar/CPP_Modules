#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span 
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();		
};

#endif