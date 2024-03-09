#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main (void)
{
	randomChump("Zombie1");
	randomChump("Zombie2");
	randomChump("Zombie3");
	randomChump("Zombie4");
	randomChump("Zombie5");
	Zombie *zombie = newZombie("Zombie6");
	Zombie *zombie2 = newZombie("Zombie7");
	Zombie *zombie3 = newZombie("Zombie8");
	Zombie *zombie4 = newZombie("Zombie9");
	Zombie *zombie5 = newZombie("Zombie10");
	zombie->announce();
	zombie2->announce();
	zombie3->announce();
	zombie4->announce();
	zombie5->announce();
	delete zombie;
	delete zombie2;
	delete zombie3;
	delete zombie4;
	delete zombie5;
	return (0);
}