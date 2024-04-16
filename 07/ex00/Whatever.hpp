#ifndef WHATEVER_HPP
#define WHATEVER_HPP

class Whatever
{
	public:
	template <typename T> static void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T> static T min(T a, T b)
	{
		return (a < b) ? a : b;
	}

	template <typename T> static T max(T a, T b)
	{
		return (a > b) ? a : b;
	}
};

#endif