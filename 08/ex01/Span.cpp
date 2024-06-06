#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Span Constructor, size: " << n << std::endl;
}

Span::~Span()
{
	std::cout << "Span Deconstructor" << std::endl;
}

Span::Span(const Span &other) : _n(other._n), _vec(other._vec)
{
	std::cout << "Span Copy Constructor" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	std::cout << "Span Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	_n = other._n;
	_vec = other._vec;
	return (*this);
}

void Span::addNumber(int num)
{
	if (_vec.size() >= _n)
		throw std::out_of_range("Span is full");
	_vec.push_back(num);
}

void Span::addNumbers(unsigned int n)
{
	srand(time(nullptr));
	while (n-- > 0)
		addNumber(rand());
}

unsigned int Span::shortestSpan()
{
	if (_vec.empty())
		throw std::logic_error("Span is empty");
	if (_vec.size() == 1)
		throw std::logic_error("Only 1 element in the Span");
	std::sort(_vec.begin(), _vec.end());
	int ret = _vec.at(1) - _vec.at(0);
	int span;
	for (size_t i = 1; i < _vec.size() - 1; i++)
	{
		span = _vec.at(i + 1) - _vec.at(i);
		if (span < ret)
			ret = span;
	}
	return (ret);
}

unsigned int Span::longestSpan()
{
	if (_vec.empty())
		throw std::logic_error("Span is empty");
	if (_vec.size() == 1)
		throw std::logic_error("Only 1 element in the Span");
	std::sort(_vec.begin(), _vec.end());
	return (*(_vec.end() - 1) - *_vec.begin());
}