#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap name constructor" << std::endl;
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
	if (_hp == 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack because it is dead" << std::endl;
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack because it is out of energy" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
	//std::cout << "ScavTrap " << _name << " status [hp, ep, ad]: [" << _hp << ", " << _ep << ", " << _ad << "]" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}
