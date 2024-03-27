#include "Brain.hpp"

static void copy_ideas(std::string dest[100], const std::string src[100])
{
	for (int i = 0; i < 100; i++)
		dest[i] = src[i];
}

static void idea_init(std::string ideas[100])
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	ideas[0] = "my first idea is to make a new idea";
}

Brain::Brain()
{
	std::cout << "Brain Default Constructor" << std::endl;
	idea_init(_ideas);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	copy_ideas(_ideas, brain._ideas);
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain Assignment Operator" << std::endl;
	if (this != &brain)
		copy_ideas(_ideas, brain._ideas);
	return (*this);
}

std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return ("");
	return (_ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea)
{
	if (idx < 0 || idx >= 100)
		return;
	_ideas[idx] = idea;
}