#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor " << _name << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor " << name << std::endl;
	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	ClapTrap::operator=(fragtrap);
	std::cout << "FragTrap Copy assignation operator " << _name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor " << _name << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " raises its hand, requesting a high five, anyone?!" << std::endl;
}
