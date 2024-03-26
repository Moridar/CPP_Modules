#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
		{	
			std::cout << "MateriaSource deleted materia [" << i << "]: " << materias[i]->getType() << std::endl; 
			delete materias[i];
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this == &materiaSource)
		return (*this);
	count = materiaSource.count;
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
		materias[i] = materiaSource.materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL || count == 4)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			std::cout << "MateriaSource learned on slot " << i << ": " << materia->getType() << std::endl;
			materias[i] = materia;
			count++;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
		{
			std::cout << "Found " << type << " from MateriaSource, giving a copy" << std::endl;
			return (materias[i]->clone());
		}
	}
	return (NULL);
}