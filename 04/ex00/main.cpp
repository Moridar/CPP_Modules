#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "==1. Default Constructor==" << std::endl;
const Animal* meta = new Animal();

std::cout << std::endl << "==2. Dog Constructor==" << std::endl;
const Animal* j = new Dog();

std::cout << std::endl << "==3. Cat Constructor==" << std::endl;
const Animal* i = new Cat();

std::cout << std::endl << "==3. WrongCat Constructor==" << std::endl;
const WrongAnimal* k = new WrongCat();

std::cout << std::endl << "==4. getType()==" << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << k->getType() << " " << std::endl;

std::cout << std::endl << "==5. makeSound()==" << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
k->makeSound();

std::cout << std::endl << "==6. Destructors==" << std::endl;
delete i; 
delete j;
delete meta;
delete k;
return 0;
}
