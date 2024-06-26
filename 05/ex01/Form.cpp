#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &Form) : _name(Form._name), _signed(Form._signed), _gradeToSign(Form._gradeToSign), _gradeToExecute(Form._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &Form)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &Form)
		return *this;
	_signed = Form._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{		
	if (_signed)
		throw std::runtime_error("The form is already signed");
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &out, const Form &Form)
{
	out << "Form " << Form.getName() << " is ";
	if (!Form.getSigned())
		out << "not ";
	out << "signed, grade to sign: " << Form.getGradeToSign() << ", grade to execute: " << Form.getGradeToExecute();
	return out;
}