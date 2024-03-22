#include "WrongCat.hpp"

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat Deconstructor" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	WrongAnimal::operator=(cat);
	std::cout << "WrongCat Assignment Constructor" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << " [Wrong Meow meow]" << std::endl;
}