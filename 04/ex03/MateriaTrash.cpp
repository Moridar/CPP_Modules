#include "MateriaTrash.hpp"

MateriaTrash::MateriaTrash()
{
	_materia = NULL;
	_next = NULL;
}

MateriaTrash::~MateriaTrash()
{
	if (_materia)
	{
		std::cout << "Deleting " << _materia->getType() << " from trash" << std::endl;
		delete _materia;
	}
	if (_next)
		delete _next;
}

MateriaTrash::MateriaTrash(const MateriaTrash &Materia)
{
	*this = Materia;
}

MateriaTrash &MateriaTrash::operator=(const MateriaTrash &materia)
{
	
	_materia = materia._materia;
	_next = materia._next;
	return *this;
}

void MateriaTrash::add(AMateria *materia)
{
	if (!materia)
		return ;
	if (!_materia)
	{
		_materia = materia;
		return ;
	}
	if (!_next)
		_next = new MateriaTrash();
	_next->add(materia);
}