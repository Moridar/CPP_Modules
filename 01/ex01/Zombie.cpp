#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie ( void )
{
	this->name = "";
}
Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << ": is dead, for real this time" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}