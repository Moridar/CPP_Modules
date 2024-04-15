#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		static AForm *createPresidentialPardonForm(std::string target);
		static AForm *createRobotomyRequestForm(std::string target);
		static AForm *createShrubberyCreationForm(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &Intern);
		Intern &operator=(const Intern &Intern);

		AForm *makeForm(std::string formName, std::string target);
};
#endif