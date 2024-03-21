#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap ST1("Topper");
	
	std::cout << std::endl << "ST1 " << ST1.name() << " actions" << std::endl;
	ST1.whoAmI();
	ST1.attack("a mouse");
	ST1.beRepaired(5);
	ST1.takeDamage(105);
	ST1.attack("a rat");
	std::cout << std::endl;
	
	DiamondTrap ST2("Bopper");
	
	std::cout << std::endl << "ST2 " << ST2.name() << " actions" << std::endl;
	ST2.whoAmI();
	ST2.takeDamage(5);
	ST2.attack("a door");
	ST2.beRepaired(5);
	std::cout << std::endl;

	DiamondTrap STTEMP("Popper");
	DiamondTrap ST3(STTEMP);

	std::cout << std::endl << "ST3 " << ST3.name() << " actions" << std::endl;
	ST3.whoAmI();
	ST3.attack("CT A");
	ST3.takeDamage(0);
	ST3.attack("a torch");
	std::cout << std::endl;

	DiamondTrap ST4;

	std::cout << std::endl << "ST4 " << ST4.name() << " actions" << std::endl;
	ST4.whoAmI();
	ST4.beRepaired(5);
	ST4.attack("CT B");
	ST4.highFivesGuys();
	std::cout << std::endl;
	
	DiamondTrap STASSIGN("Dopper");
	ST4 = STASSIGN;

	std::cout << std::endl << "ST4 " << ST4.name() << " actions" << std::endl;
	ST4.whoAmI();
	ST4.attack("CT C");
	ST4.highFivesGuys();
	ST4.takeDamage(500);
	ST4.attack("CT D");

	std::cout<< std::endl;

	return (0);
}