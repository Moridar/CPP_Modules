#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap ST1("Topper");
	
	std::cout << std::endl << "ST1 " << ST1.name() << " actions" << std::endl;
	ST1.whoAmI();
	std::cout << "DiamondTrap " << ST1.name() << " has " << ST1.ep() << " energy points" <<  std::endl;
	ST1.attack("a mouse");
	ST1.beRepaired(5);
	ST1.takeDamage(105);
	ST1.attack("a rat");
	ST1.guardGate();
	std::cout << "DiamondTrap " << ST1.name() << " has " << ST1.ep() << " energy points" <<  std::endl;
	std::cout << std::endl;
	
	DiamondTrap ST2("Bopper");
	
	std::cout << std::endl << "ST2 " << ST2.name() << " actions" << std::endl;
	ST2.whoAmI();
	ST2.takeDamage(5);
	ST2.attack("a door");
	ST2.beRepaired(5);
	std::cout << std::endl;

	DiamondTrap STTEMP("Popper");
	std::cout << std::endl;
	STTEMP.takeDamage(10);
	std::cout << "DiamondTrap " << STTEMP.name() << " has " << STTEMP.hp() << " HP and " << STTEMP.ep() << " energy points" <<  std::endl;
	std::cout << std::endl;
	
	DiamondTrap ST3(STTEMP);

	std::cout << std::endl << "ST3 " << ST3.name() << " actions" << std::endl;
	ST3.whoAmI();
	std::cout << "DiamondTrap " << ST3.name() << " has " << ST3.hp() << " HP and " << ST3.ep() << " energy points" <<  std::endl;
	ST3.attack("CT A");
	ST3.takeDamage(0);
	ST3.attack("a torch");
	std::cout << std::endl;

	DiamondTrap ST4;

	std::cout << std::endl << "ST4 " << ST4.name() << " actions" << std::endl;
	ST4.whoAmI();
	std::cout << "DiamondTrap " << ST4.name() << " has " << ST4.ep() << " energy points" <<  std::endl;
	ST4.beRepaired(5);
	ST4.attack("CT B");
	ST4.highFivesGuys();
	std::cout << std::endl;
	
	DiamondTrap STASSIGN("Dopper");
	std::cout << std::endl;
	
	STASSIGN.takeDamage(10);
	STASSIGN.beRepaired(5);
	std::cout << "DiamondTrap " << STASSIGN.name() << " has " << STASSIGN.hp() << " HP and " << STASSIGN.ep() << " energy points" <<  std::endl;
	std::cout << std::endl;
	
	ST4 = STASSIGN;

	std::cout << std::endl << "ST4 " << ST4.name() << " actions" << std::endl;
	ST4.whoAmI();
	std::cout << "DiamondTrap " << ST4.name() << " has " << ST4.hp() << " HP and " << ST4.ep() << " energy points" <<  std::endl;
	ST4.attack("CT C");
	ST4.highFivesGuys();
	ST4.takeDamage(500);
	ST4.attack("CT D");

	std::cout<< std::endl;

	return (0);
}