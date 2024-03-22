#include "Animal.hpp"

Animal::~Animal() 
{
	std::cout << "Animal Deconstructor" << std::endl;
}

Animal::Animal() 
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type) 
{
	std::cout << "Animal Type Constructor" << std::endl;
}
Animal::Animal(const Animal &animal) : type(animal.type)
{
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	this->type = animal.type;
	std::cout << "Animal Assignment Constructor" << std::endl;
	return (*this);
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound()
{
	std::cout << " [Unknown sound from some animal] " << std::endl;
}