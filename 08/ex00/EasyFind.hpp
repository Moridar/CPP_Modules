#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>
#include <exception>

template <typename T, typename Var> static Var *easyfind(T &container, Var value)
{
	Var *it;
	if (container.getVarType() != typeid(value).name())
		throw std::runtime_error("Array has different var type");
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	return it;
}
#endif