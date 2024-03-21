#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &scavtrap);
		FragTrap &operator=(const FragTrap &scavtrap);
		~FragTrap();
		void highFivesGuys();
};
#endif