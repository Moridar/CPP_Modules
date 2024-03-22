#include "Cat.hpp"

Cat::~Cat() 
{
	std::cout << "Cat Deconstructor" << std::endl;
}

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	type = cat.type;
	std::cout << "Cat Assignment Constructor" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << " [Meow meow]" << std::endl;
}