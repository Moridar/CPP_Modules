#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &RobotomyRequestForm);
		void execute(Bureaucrat const &executor) const override;
};

#endif