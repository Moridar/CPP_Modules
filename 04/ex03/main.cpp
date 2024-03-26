#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "==Creating MateriaSource and learning new mats==" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	std::cout << std::endl << "==Equipping==" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << std::endl << "==Using materias==" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl << "==Unequipping==" << std::endl;
	me->unequip(1);
	me->unequip(0);
	std::cout << std::endl << "==Deleting==" << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}