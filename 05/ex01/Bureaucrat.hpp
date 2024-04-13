#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &Bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &Bureaucrat);
		Bureaucrat(std::string name, int grade);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void signForm(Form &form) const;
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);
#endif