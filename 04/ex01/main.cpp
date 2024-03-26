#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << std::endl << "==1. Animal array==" << std::endl;
int N = 4;
Animal *animals[N];

std::cout << std::endl << "==2. Filling the array==" << std::endl;
for (int i = 0; i < N; i++)
{
	if (i % 2)
		animals[i] = new Dog();
	else
		animals[i] = new Cat();
}

std::cout << std::endl << "==3. Deleting the animals==" << std::endl;
for (Animal *animal : animals)
	delete animal;

std::cout << std::endl << "==4. Test default Animal==" << std::endl;
Animal a = Animal();
a.makeSound();
return 0;
}
