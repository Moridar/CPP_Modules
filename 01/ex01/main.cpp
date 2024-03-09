#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main (void)
{
	Zombie *horde;
	int n = 8;

	horde = zombieHorde(n, "Boomer");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}