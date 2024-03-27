#include "Character.hpp"

Character::Character() : Character("no name") 
{
		std::cout << "Char Default Constructor" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Char Name Constructor" << std::endl;
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
	std::cout << "Char Copy Constructor" << std::endl;
	_mt = new MateriaTrash(*character._mt);
	_name = character._name;
	std::cout << "Char copying inventory" << std::endl;
	for (int i = 0; i < 4; i++)
		if(character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
}

Character &Character::operator=(const Character &character)
{
	std::cout << "Char Assignment Operator" << std::endl;
	if (this == &character)
		return (*this);
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
	}
	delete _mt;
	_mt = new MateriaTrash(*character._mt);
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
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