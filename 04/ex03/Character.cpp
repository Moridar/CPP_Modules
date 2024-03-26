#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_mt = new MateriaTrash();
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			std::cout << "Deleting materia[" << i << "]: " << _inventory[i]->getType() << " from " << _name << std::endl; 
			delete _inventory[i];
		}
	}
	delete _mt;
}

Character::Character(const Character &character)
{
	*this = character;
}

Character &Character::operator=(const Character &character)
{
	if (this == &character)
		return (*this);
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = character._inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			std::cout << _name << " is equipping on slot " << i << ": " << m->getType() << std::endl;
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	std::cout << "Unequipping " << _inventory[idx]->getType() << " from " << _name << std::endl;
	_mt->add(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}