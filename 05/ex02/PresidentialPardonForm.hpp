#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardonForm);
		void execute(Bureaucrat const &executor) const override;
};

#endif