#include "ClapTrap.hpp"

int main()
{

	std::cout << std::endl << "==Constructors==" << std::endl;
	ClapTrap ctA("CT A");
	ClapTrap ctB;

	std::cout << std::endl << "==CtA actions==" << std::endl;
	ctA.attack("a mouse");
	ctA.beRepaired(5);
	ctA.takeDamage(10);
	ctA.attack("a rat");
	ctA.takeDamage(5);
	ctA.attack("a door");
	ctA.beRepaired(5);
	ctB.attack("CT A");

	std::cout << std::endl << "==CtB actions==" << std::endl;
	ctB.takeDamage(0);

	std::cout << std::endl << "==CtB assignment==" << std::endl;
	ctB = ClapTrap("CT B");

	std::cout << std::endl << "==Assigned CtB actions==" << std::endl;
	ctB.attack("a torch");
	ctB.beRepaired(5);

	std::cout << std::endl << "==Reassigned CtB and copied to CtC==" << std::endl;
	ctB = ClapTrap("CT C");
	ClapTrap ctC(ctB);

	std::cout << std::endl << "==CtC Actions==" << std::endl;
	ctC.attack("CT B");
	return (0);
}