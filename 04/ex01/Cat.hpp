#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		 ~Cat();
		Cat();
		Cat(const Cat &animal);
		Cat &operator=(const Cat &cat);
		void makeSound() const override;
		std::string getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
};

#endif