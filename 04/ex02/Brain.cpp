#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default Constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy Constructor" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignment operator" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = brain.ideas[i];
	}
	return (*this);
}