#ifndef ARRAY_HPP
 #define ARRAY_HPP

template <typename T> class Array
{
	private:
		T *_arr;
		unsigned int _size;
	public:
		~Array();
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int i);
		unsigned int size() const;
};

#include "Array.tpp"

#endif