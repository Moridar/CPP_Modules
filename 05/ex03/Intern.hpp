#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &Intern);
		Intern &operator=(const Intern &Intern);

		AForm *makeForm(std::string formName, std::string target);
};
#endif