#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{	
	std::cout << "==1. Creating Intern" << std::endl;
	Intern someRandomIntern;
	
	std::cout << "==1.1 Creating Bureaucrat" << std::endl;
	Bureaucrat b1("Finlands President", 1);
	Bureaucrat b2("FBIs Director", 50);
	Bureaucrat b3("King of England", 5);

	std::cout << std::endl << "==2. Creating Forms" << std::endl;
	AForm* rrf = NULL;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;

	std::cout << std::endl << "==3. Presidential Pardon Form" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (rrf)
	{
		std::cout << std::endl << "==3.1 Status" << std::endl;
		std::cout << *rrf << std::endl;
		
		std::cout << std::endl << "==3.3 Sign" << std::endl;
		b1.signForm(*rrf);
		std::cout << std::endl << "==3.4 Execute" << std::endl;
		b2.executeForm(*rrf);
		b3.executeForm(*rrf);
		std::cout << std::endl << "==3.5 Delete" << std::endl;
		delete rrf;
	}

	std::cout << std::endl << "==4. Nonexisting Form" << std::endl;
	rrf = someRandomIntern.makeForm("nonexisting form", "Bender");

	std::cout << std::endl;

}