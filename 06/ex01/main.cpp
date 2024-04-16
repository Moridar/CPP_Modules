#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	std::cout << "Original Data    : " << data.s1 << " " << data.n << " " << data.s2 << std::endl;
	std::cout << "Deserialized Data: " << deserialized->s1 << " " << deserialized->n << " " << deserialized->s2 << std::endl;
	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << "Adress of original Data    : " << &data << std::endl;
	std::cout << "Adress of deserialized Data: " << deserialized << std::endl;
	return (0);
}