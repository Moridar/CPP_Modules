#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{	
	try
	{
		std::cout << "==1. Creating Bureaucrats==" << std::endl;
		
		Bureaucrat b1("b1", 1);
		Bureaucrat b150("b150", 150);
		std::cout << "b1: " << b1 << std::endl;
		std::cout << "b150: " << b150 << std::endl;

		std::cout << std::endl << "==2. Creating Forms==" << std::endl;
		
		PresidentialPardonForm f1("Donal Trump");
		RobotomyRequestForm f2("A human");
		ShrubberyCreationForm f3("Home");
		PresidentialPardonForm unsignedform("No target");
		std::cout << "f1: " << f1 << std::endl;
		std::cout << "f2: " << f2 << std::endl;
		std::cout << "f3: " << f3 << std::endl;
		std::cout << "unsignedform: " << unsignedform << std::endl;

		std::cout << std::endl << "==3. Signing Forms==" << std::endl;
		try
		{
			b150.signForm(f2);
			b1.signForm(f1);
			b1.signForm(f2);
			b150.signForm(f1);
			b1.signForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cout << "Nothing is caught here at 3" << std::endl;
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl << "==4. Executing Forms==" << std::endl;
		b1.executeForm(f1);
		b150.executeForm(f2);
		b1.executeForm(f2);
		b1.executeForm(f3);
		b1.executeForm(unsignedform);

		std::cout << std::endl << "==5. AForms status==" << std::endl;
		std::cout << "f1: " << f1 << std::endl;
		std::cout << "f2: " << f2 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}