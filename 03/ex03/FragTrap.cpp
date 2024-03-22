#include "FragTrap.hpp"

static void initTrap(FragTrap &fragtrap)
{
	fragtrap.setHp(100);
	fragtrap.setEp(100);
	fragtrap.setAd(30);
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor " << name() << std::endl;
	initTrap(*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor " << name << std::endl;
	initTrap(*this);
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor " << name() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	ClapTrap::operator=(fragtrap);
	std::cout << "FragTrap Copy assignation operator " << name() << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor " << name() << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name() << " raises its hand, requesting a high five, anyone?!" << std::endl;
}
