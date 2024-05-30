#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> static void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> static T min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T> static T max(T a, T b)
{
	return (a > b) ? a : b;
}

#endif