#include "Dog.hpp"

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Deconstructor" << std::endl;
}

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog Default Constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		brain->setIdea(i, std::to_string(i) + " Bark bark I am humans best friend");
}

Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain(*dog.brain))
{
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog Assignment Operator" << std::endl;
	if (this == &dog)
		return (*this);
	type = dog.type;
	delete brain;
	brain = new Brain(*dog.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << " [Bark bark]" << std::endl;
}

std::string Dog::getIdea(int idx) const
{
	return brain->getIdea(idx);
}

void Dog::setIdea(int idx, std::string idea)
{
	brain->setIdea(idx, idea);
}