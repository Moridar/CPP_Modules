#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &amateria)
{
	*this = amateria;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
	if (this == &amateria)
		return (*this);
	_type = amateria._type;
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