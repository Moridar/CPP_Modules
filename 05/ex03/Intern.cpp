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

AForm* Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string _forms[3];
	AForm* (*_formCreators[3])(std::string target);

	_forms[0] = "presidential pardon";
	_forms[1] = "robotomy request";
	_forms[2] = "shrubbery creation";
	_formCreators[0] = createPresidentialPardonForm;
	_formCreators[1] = createRobotomyRequestForm;
	_formCreators[2] = createShrubberyCreationForm;
	for (int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return _formCreators[i](target);
		}
	}
	std::cerr << "Intern tried to create '" << formName << "' but it was not to be found anywhere" << std::endl;
	return NULL;
}