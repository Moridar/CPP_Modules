#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat &animal);
		WrongCat &operator=(const WrongCat &cat);
		void makeSound() const;
};

#endif