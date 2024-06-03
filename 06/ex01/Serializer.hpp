#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &src);
		~Serializer();
};

#endif