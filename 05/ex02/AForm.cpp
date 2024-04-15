#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &AForm) : _name(AForm._name), _signed(AForm._signed), _gradeToSign(AForm._gradeToSign), _gradeToExecute(AForm._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &AForm)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this == &AForm)
		return *this;
	_signed = AForm._signed;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{		
	if (_signed)
		throw std::runtime_error("The form is already signed");
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw std::runtime_error("The form is not signed");
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << " is ";
	if (!AForm.getSigned())
		out << "not ";
	out << "signed, grade to sign: " << AForm.getGradeToSign() << ", grade to execute: " << AForm.getGradeToExecute();
	return out;
}

