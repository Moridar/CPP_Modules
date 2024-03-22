#include "ScavTrap.hpp"

static void initTrap(ScavTrap &scavtrap)
{
	scavtrap.setHp(100);
	scavtrap.setEp(50);
	scavtrap.setAd(20);
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	initTrap(*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor" << std::endl;
	initTrap(*this);
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "ScavTrap Copy assignation operator" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hp() == 0)
	{
		std::cout << "ScavTrap " << name() << " can not attack because it is dead" << std::endl;
		return ;
	}
	if (ep() == 0)
	{
		std::cout << "ScavTrap " << name() << " can not attack because it is out of energy" << std::endl;
		return ;
	}
	setEp(ep() - 1);
	std::cout << "ScavTrap " << name() << " attacks " << target << ", causing " << ad() << " points of damage!" << std::endl;
	//std::cout << "ScavTrap " << name() << " status [hp, ep, ad]: [" << hp() << ", " << ep() << ", " << ad() << "]" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name() << " has entered in Gate keeper mode" << std::endl;
}
