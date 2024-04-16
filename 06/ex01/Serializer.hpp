#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

typedef struct s_data
{
	std::string s1;
	int n;
	std::string s2;
} Data;

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