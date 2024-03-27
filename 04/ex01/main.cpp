#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "==0. Brain==" << std::endl;
Brain *b = new Brain();
Brain *b1 = new Brain(*b);

std::cout << "b: " << b->getIdea(0) << std::endl;
std::cout << "b1:" << b1->getIdea(0) << std::endl;

b->setIdea(1, "My second idea is to test copy assignment");
b1->setIdea(0, "");
*b1 = *b;

std::cout << "b1:" << b1->getIdea(0) << std::endl;
std::cout << "b1:" << b1->getIdea(1) << std::endl;
delete b;
delete b1;

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

std::cout << std::endl << "==5. Dog Brain Test Constructor==" << std::endl;
Dog *d = new Dog();


std::cout << std::endl << "==5.1 Set First idea ==" << std::endl;
d->setIdea(0, "First idea changed!");

std::cout << std::endl << "==5.2 Copy ==" << std::endl;
Dog *d1 = new Dog(*d);

std::cout << std::endl << "==5.3 Assignment ==" << std::endl;
Dog *d2 = new Dog();
*d2 = *d;

d->setIdea(0, "d's idea");
d1->setIdea(0, "d1's idea");
d2->setIdea(0, "d2's idea");
std::cout << std::endl << "==5.4 Ideas ==" << std::endl;
std::cout << "d idea: " << d->getIdea(0) << std::endl;
std::cout << "d1 idea: " << d1->getIdea(0) << std::endl;
std::cout << "d2 idea: " << d2->getIdea(0) << std::endl;


std::cout << std::endl << "==5.4 Deconstruction ==" << std::endl;
delete d;
delete d1;
delete d2;

std::cout << std::endl << "==6. Cat Brain Test Constructor==" << std::endl;
Cat *c = new Cat();


std::cout << std::endl << "==6.1 Set First idea ==" << std::endl;
c->setIdea(0, "First idea changed!");

std::cout << std::endl << "==6.2 Copy ==" << std::endl;
Cat *c1 = new Cat(*c);

std::cout << std::endl << "==6.3 Assignment ==" << std::endl;
Cat *c2 = new Cat();
*c2 = *c;

c->setIdea(0, "c's idea");
c1->setIdea(0, "c1's idea");
c2->setIdea(0, "c2's idea");
std::cout << std::endl << "==6.4 Ideas ==" << std::endl;
std::cout << "c idea: " << c->getIdea(0) << std::endl;
std::cout << "c1 idea: " << c1->getIdea(0) << std::endl;
std::cout << "c2 idea: " << c2->getIdea(0) << std::endl;


std::cout << std::endl << "==6.4 Deconstruction ==" << std::endl;
delete c;
delete c1;
delete c2;

return 0;
}
