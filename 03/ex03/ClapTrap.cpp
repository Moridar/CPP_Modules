#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("No Name"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Default Constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &claptrap) : _name(claptrap._name), _hp(claptrap._hp), _ep(claptrap._ep), _ad(claptrap._ad)
{
	std::cout << "Copy Constructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "Copy assignation operator called" << std::endl;
	_name = claptrap._name;
	_hp = claptrap._hp;
	_ep = claptrap._ep;
	_ad = claptrap._ad;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack because it is dead" << std::endl;
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack because it is out of energy" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (amount > _hp)
		_hp = 0;
	else
		_hp -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " can not repair because it is dead" << std::endl;
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "ClapTrap " << _name << " can not repair because it is out of energy" << std::endl;
		return ;
	}
	_ep--;
	_hp += amount;
	std::cout << "ClapTrap " << _name << " got repaired, " << amount << " points of health restored!" << std::endl;
}