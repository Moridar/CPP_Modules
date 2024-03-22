#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		virtual ~Animal();
		Animal();
		Animal(std::string newtype);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		std::string getType() const;
		virtual void makeSound() const;
};

#endif