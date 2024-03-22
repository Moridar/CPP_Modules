#include "ClapTrap.hpp"

int main()
{
	ClapTrap ctA("CT A");
	ClapTrap ctB;

	ctA.attack("a mouse");
	ctA.beRepaired(5);
	ctA.takeDamage(10);
	ctA.attack("a rat");
	ctA.takeDamage(5);
	ctA.attack("a door");
	ctA.beRepaired(5);
	ctB.attack("CT A");
	ctB.takeDamage(0);

	ctB = ClapTrap("CT B");
	ctB.attack("a torch");
	ctB.beRepaired(5);

	ctB = ClapTrap("CT C");
	ClapTrap ctC(ctB);
	ctC.attack("CT B");
	return (0);
}