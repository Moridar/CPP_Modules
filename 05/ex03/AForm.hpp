#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &AForm);
		AForm &operator=(const AForm &AForm);
		AForm(std::string name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
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
		virtual void execute(Bureaucrat const &executor) const = 0;
};
std::ostream& operator<<(std::ostream &out, const AForm &AForm);

#endif