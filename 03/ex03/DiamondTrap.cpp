#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("No Name_clap_name")
{
	_name = "No Name";
	setEp(50);
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	setEp(50);
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
	std::cout << "ClapTrap name: " << ClapTrap::name() << std::endl;
}

std::string DiamondTrap::name() const
{
	return (_name);
}
