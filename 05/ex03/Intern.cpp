#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &Intern)
{
	(void)Intern;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &Intern)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &Intern)
		return *this;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm* ptr;

	!formName.compare("presidential pardon") ? ptr = new PresidentialPardonForm(target) : !formName.compare("robotomy request") ? ptr = new RobotomyRequestForm(target) :
		!formName.compare("shrubbery creation") ? ptr = new ShrubberyCreationForm(target) : ptr = NULL;
	std::cout << (ptr ? "Intern creates " : "Intern tried to create '") << formName << (!ptr ? "' but it was not to be found anywhere" : "") << std::endl;
	return ptr;
}