#include "Bureaucrat.hpp"

int main()
{	
	try
	{
		std::cout << "==1. Creating Bureaucrats==" << std::endl;
		
		Bureaucrat b1("b1", 1);
		std::cout << "b1: " << b1 << std::endl;
		Bureaucrat b2("b2", 150);
		std::cout << "b2: " << b2 << std::endl;

		std::cout << std::endl << "==2. b1 increases grade==" << std::endl;
		try 
		{
			b1.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "b1: " << b1 << std::endl;

		std::cout << std::endl << "==3. b2 decreases grade==" << std::endl;
		try
		{
			b2.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "b2: " << b2 << std::endl;

		std::cout << std::endl << "==4. b2 increases grade==" << std::endl;
		try
		{
			b2.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "b2: " << b2 << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}