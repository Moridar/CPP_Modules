#include "Dog.hpp"

Dog::~Dog() 
{
	std::cout << "Dog Deconstructor" << std::endl;
	delete brain;
}

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	type = dog.type;
	std::cout << "Dog Assignment Constructor" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << " [Bark bark]" << std::endl;
}