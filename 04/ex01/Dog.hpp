#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		 ~Dog();
		Dog();
		Dog(const Dog &animal);
		Dog &operator=(const Dog &dog);
		void makeSound() const override;
		std::string getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
};

#endif