#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		 ~Cat();
		Cat();
		Cat(const Cat &animal);
		Cat &operator=(const Cat &cat);
		void makeSound() const override;
};

#endif