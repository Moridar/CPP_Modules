#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{	
	try
	{
		std::cout << "==1. Creating Bureaucrats==" << std::endl;
		
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		std::cout << "b1: " << b1 << std::endl;
		std::cout << "b2: " << b2 << std::endl;

		std::cout << std::endl << "==2. Creating Forms==" << std::endl;
		
		Form f1("f1", 1, 1);
		Form f2("f2", 150, 150);
		std::cout << "f1: " << f1 << std::endl;
		std::cout << "f2: " << f2 << std::endl;

		std::cout << std::endl << "==3. Creating illegal form==" << std::endl;
		try
		{
			Form f3("f3", 0, 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << "==4. Signing forms==" << std::endl;
		try
		{
			b2.signForm(f1);
			b2.signForm(f2);
			b1.signForm(f1);
			b1.signForm(f2);
		}
		catch(const std::exception& e)
		{
			std::cout << "Nothing is caught here at 4" << std::endl;
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl << "==5. Forms status==" << std::endl;
		std::cout << "f1: " << f1 << std::endl;
		std::cout << "f2: " << f2 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}