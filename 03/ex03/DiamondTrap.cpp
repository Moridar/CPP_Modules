#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	ClapTrap::_name = "No Name_clap_name";
	_name = "No Name";
	_ep = 50;
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_ep = 50;
	std::cout << "DiamondTrap name constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	_name = diamondtrap._name;
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	_name = diamondtrap._name;
	ClapTrap::operator=(diamondtrap);
	std::cout << "DiamondTrap Copy assignation operator" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}