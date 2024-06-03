#include "Array.hpp"

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete [] _arr;
}

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) 
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
	std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]), _size(copy._size)
{
	std::cout << "Array copy constructor called" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << "Array operator= called" << std::endl;
	if (this != &other)
	{
		delete [] _arr;
		_arr = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}