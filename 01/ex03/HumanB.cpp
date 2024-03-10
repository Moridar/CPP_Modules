#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) 
{
	this->weapon = NULL;
}
void HumanB::attack( void )
{
	if (!weapon)
	{
		std::cout << this->name << " attacks with their bare fist (NO WEAPON)" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}