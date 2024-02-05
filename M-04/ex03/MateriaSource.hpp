#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*materiaArray[4];
		int			idx;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& inst);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& inst);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};