#include "FragTrap.hpp"

int main()
{
	FragTrap ST1("Topper");
	std::cout << std::endl;
	
	FragTrap ST2("Bopper");
	std::cout << std::endl;
	
	FragTrap ST3(ST1);
	std::cout << std::endl;
	
	FragTrap ST4;
	std::cout << std::endl;

	std::cout << std::endl << "ST1 actions " << std::endl;
	ST1.attack("a mouse");
	ST1.beRepaired(5);
	ST1.takeDamage(105);
	ST1.attack("a rat");

	std::cout << std::endl << "ST2 actions " << std::endl;
	ST2.takeDamage(5);
	ST2.attack("a door");
	ST2.beRepaired(5);

	std::cout << std::endl << "ST3 actions " << std::endl;
	ST3.attack("CT A");
	ST3.takeDamage(0);
	ST3.attack("a torch");

	std::cout << std::endl << "ST4 actions " << std::endl;
	ST4.beRepaired(5);
	ST4.attack("CT B");
	ST4.highFivesGuys();

	std::cout << std::endl;
	ST4 = ST2;

	std::cout << std::endl << "ST4 actions" << std::endl;
	ST4.attack("CT C");
	ST4.highFivesGuys();
	ST4.takeDamage(500);
	ST4.attack("CT D");

	std::cout<< std::endl;

	return (0);
}