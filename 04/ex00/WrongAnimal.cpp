#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal Deconstructor" << std::endl;
}

WrongAnimal::WrongAnimal() 
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) 
{
	std::cout << "WrongAnimal Type Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type(animal.type)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	this->type = animal.type;
	std::cout << "WrongAnimal Assignment Constructor" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << " [Wrong sound from some wrong animal] " << std::endl;
}