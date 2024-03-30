#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &amateria)
{
	_type = amateria._type;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	if(amateria.getType() != _type)
		std::cout << "AMateria Assignment Operator can not assign different type" << std::endl;
	else
		std::cout << "AMateria Assignment Operator" << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Unkown type used on " << target.getName() << std::endl;
}