#ifndef MATERIATRASH_HPP
#define MATERIATRASH_HPP

#include "AMateria.hpp"

class MateriaTrash
{
	private:
		AMateria *_materia;
		MateriaTrash *_next;
	public:
		MateriaTrash();
		~MateriaTrash();
		MateriaTrash(const MateriaTrash &Materia);
		MateriaTrash &operator=(const MateriaTrash &Materia);

		void add(AMateria *materia);
};

#endif