#include "Cat.hpp"

Cat::~Cat() 
{
	delete brain;
	std::cout << "Cat Deconstructor" << std::endl;
}

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat Default Constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		brain->setIdea(i, std::to_string(i) + " Meow meow I am a cat");
}

Cat::Cat(const Cat &cat) : Animal(cat), brain(new Brain(*cat.brain))
{
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Assignment Operator" << std::endl;
	if (this == &cat)
		return (*this);
	type = cat.type;
	*brain = *cat.brain; 
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << " [Meow meow]" << std::endl;
}

std::string Cat::getIdea(int idx) const
{
	return brain->getIdea(idx);
}

void Cat::setIdea(int idx, std::string idea)
{
	brain->setIdea(idx, idea);
}