#include "MateriaTrash.hpp"

MateriaTrash::MateriaTrash()
{
	std::cout << "Trash Default Constructor" << std::endl;	
	_materia = nullptr;
	_next = nullptr;
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
	std::cout << "Trash Copy Constructor" << std::endl;
	_materia = nullptr;
	_next = nullptr;
	if (Materia._materia)
		_materia = Materia._materia->clone();
	if (Materia._next)
		_next = new MateriaTrash(*Materia._next);
}

MateriaTrash &MateriaTrash::operator=(const MateriaTrash &materia)
{
	std::cout << "Trash Assignment Operator" << std::endl;
	if (_materia)
	{
		delete _materia;
		_materia = nullptr;
	}
	if (_next)
	{
		delete _next;
		_next = nullptr;
	}
	if (materia._materia)
		_materia = materia._materia->clone();
	if (materia._next)
			_next = new MateriaTrash(*materia._next);
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